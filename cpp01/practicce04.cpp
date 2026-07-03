/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   practicce04.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 20:41:24 by moodeh            #+#    #+#             */
/*   Updated: 2026/07/03 19:32:24 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

void createSampleLog(std::string const &filename)
{
    std::ofstream out(filename.c_str());
        if (!out) {
        std::cerr << "Error: could not create '" << filename << "'" << std::endl;
        return;
    }

    out << "[2024-01-15 08:00:01] [INFO] System boot sequence initiated\n";
    out << "[2024-01-15 08:00:02] [DEBUG] Config loaded: /etc/app/config.ini\n";
    out << "[2024-01-15 08:00:03] [INFO] Listening on port 8080\n";
    out << "[2024-01-15 08:00:04] [DEBUG] Thread pool initialised: 4 workers\n";
    out << "[2024-01-15 08:01:12] [INFO] Client connected: 192.168.1.10\n";
    out << "[2024-01-15 08:01:13] [DEBUG] Request received: GET /api/status\n";
    out << "[2024-01-15 08:01:14] [INFO] Request served in 42ms\n";
    out << "[2024-01-15 08:05:00] [WARNING] Memory usage above 75%: 768MB/1024MB\n";
    out << "[2024-01-15 08:05:01] [WARNING] Response time degraded: avg 200ms\n";
    out << "[2024-01-15 08:06:30] [ERROR] Database connection timeout after 5000ms\n";
    out << "[2024-01-15 08:06:31] [ERROR] Retry 1/3 failed: database unreachable\n";
    out << "[2024-01-15 08:06:32] [ERROR] Retry 2/3 failed: database unreachable\n";
    out << "[2024-01-15 08:06:33] [WARNING] Falling back to cached data\n";
    out << "[2024-01-15 08:06:34] [INFO] Cache hit: serving stale data\n";
    out << "MALFORMED LINE — no brackets, should be skipped\n";
    out << "[2024-01-15 08:10:00] [DEBUG] Garbage collection: freed 128MB\n";
    out << "[2024-01-15 08:10:01] [INFO] System health check: OK\n";
    std::cout << "  Created: " << filename << std::endl;
}

//represent one parsed line from a log file 
// all instances are heap allocated and owned by LogProcessor 
class LogEntry{
    public:
    std::string _timestamp;
    std::string _level;
    std::string _message;
    LogEntry(std::string const& timestamp , std::string const& level , std::string const& message) : _timestamp(timestamp) ,_level(level) ,_message(message) 
    {
        
    }
    ~LogEntry(){}
    private :
    LogEntry(LogEntry const&);
    LogEntry & operator = (LogEntry const &);
};
//loads a log file , stores entires on the heap , dispatch  each entry 
//through a member fun pointer table , writes filtered output files
class LogProcessor{
    private :
    LogEntry **_entries;//heap-allocated array of pointers
    int _count;//entries current stored in the pointer array
    int _capacity;//current array capacity 
    std::string _sourceFile;
    //per-level counters updated by handler
    int _debugCount;
    int _infoCount;
    int _warningCount;
    int _errorCount;
    //dynamic array growth 
    void grow()
    {
        int newCapcity = _capacity * 2;
        LogEntry **newEntries = new LogEntry*[newCapcity];//array of pointers 
        for (int i = 0; i < _count; i++)
        {
            newEntries[i] = _entries[i];//copy pointers not objs
        }
        delete []_entries;
        _entries = newEntries;
        _capacity = newCapcity;
        std::cout << "[grow] Capacity expanded to " << _capacity << std::endl;
    }
    //log line parser
    //expected formate [Timestamp] [LEVEL] message
    //given  [2024-01-15 08:10:01]
    // [INFO]
    // System health check: 
    // OK\n
    //[timestamp] [Level] Message
    bool parseLine(std::string const& line ,
        std::string& timestamp ,
        std::string &level ,
        std::string &message) const 
    {
        std::size_t ts_open = line.find('[' , 0);
        std::size_t ts_close = line.find(']' , 0);//starts from zero
        if (ts_open == std::string::npos || ts_close == std::string::npos)//dont find any []
            return false;

        timestamp = line.substr(ts_open + 1 , ts_close - ts_open - 1);//the pos of time stamp
        std::size_t lv_open = line.find('[' , ts_open+1);//after the first find of open for timestamp
        std::size_t lv_close = line.find(']' , ts_close+1);//same here
        if ( lv_open == std::string::npos || lv_close == std::string::npos )
            return false;
        level = line.substr(lv_open +1 , lv_close -1 - lv_open);//close - open the len of the word and the  -1 to not include ] 
        message = (lv_close +2  < line.size() ) ?line.substr(lv_close+2):"";
        return true;
    }
    void handleDebug(LogEntry const& entry)
    {
        _debugCount++;
        std::cout << "    [DEBUG] " << entry._timestamp << " | " << entry._message << std::endl;
    }
    void handleInfo(LogEntry const& entry) {
        _infoCount++;
        std::cout << "    [INFO]  " << entry._timestamp
                  << " | " << entry._message << std::endl;
    }

    void handleWarning(LogEntry const& entry) {
        _warningCount++;
        std::cerr << "    [WARN]  " << entry._timestamp
                  << " | " << entry._message << std::endl;
    }

    void handleError(LogEntry const& entry) {
        _errorCount++;
        std::cerr << "    [ERROR] " << entry._timestamp
                  << " | " << entry._message << std::endl;
    }

    public:
        LogProcessor(std::string const& sourceFile)
        : _entries(new LogEntry*[8])
        , _count(0)
        , _capacity(8)
        , _sourceFile(sourceFile)
        , _debugCount(0)
        , _infoCount(0)
        , _warningCount(0)
        , _errorCount(0)
    {}
    ~LogProcessor(){
          for (int i = 0; i < _count; i++) {
            delete _entries[i];     // destroy each LogEntry
            _entries[i] = NULL;
        }
               delete[] _entries;          // destroy the pointer array
        _entries = NULL;
    }
};

int	main(void)
{
    std::string const logFile = "server.log";
    std::string const outputPrefix = "processed";
    std::cout << "=== Chapter 2 Capstone: Multi-File Log Processor ===" << std::endl;
    std::cout << "\n[Step 1] Creating sample log file..." << std::endl;
    createSampleLog(logFile);
    std::cout << "\n[Step 2] Loading log file..." << std::endl;
    logProcessor processor(logFile);
    
}