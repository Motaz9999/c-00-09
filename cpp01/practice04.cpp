/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   practice04.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 15:05:22 by moodeh            #+#    #+#             */
/*   Updated: 2026/06/30 20:16:02 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//having 
//std::istream ->input stream -> std::ifstream- > input file stream  READING FROM A FILE  >>   LIKE CIN FROM FILE 
//std::ostream -> output stream -> std::ofstream -> output file stream WRITING IN A FILE  <<  LIKE COUT TO A FILE 
//both are the same as cin and cout bur now with files 
//opining a file stream 
// std::ifstream infile("data.txt");//opening a file for  puting an input using constructor safe way
//or i can open a file via open fun 
// std::ifstream infile2;//file name is unknow so i cant use with the constrctr
// infile2.open("data.txt");
//both are equals but the constructer is preferred bc its RAII form die with the end of {} 
//OK FOR opening there are mods i can put FLAGS 
//bc i have flags i can use genreic class called fstream and decide what the use for it
//or i can change the behaver of input or output 
// open(fileName , flags with | with them (multible flags));
//open ("data.txt" , ) ///
//ios is where the flags are 
//flags are
//std::ios::in -> open for reading default for (ifstream)
//std::ios::out -> open for writing on for (ofstream)
//std::ios::app -> append to the end of the file (its for out)
//std::ios::trunc -> truncate file to zero when open (clear the old input (default with out))
//std::ios::binary -> open in binary mode 
//std::ios::ate -> seek to the end of file immediately after open 
// std::fstream log;
// log("log.txt" ,std::ios::out |std::ios::app);
//now after every open i must have close 
//log.close(); thats it and btw the destructor
//do it auto bc its obj thats why the RAII is the best
//there is mutilble fun to know wh ythe stream have an error 



// std::ifstream infile("data.txt");
// if(!infile)//not open but why 
// {
// }
//but here i bc its objs i have fun that tell me everything i need to know like:
//infile.is_open()  return true (its the same as up)
//infile.eof() is the file end ? return true or false 
//infile.good () no errors or no EOF
//infile.fail() logical error (bad formate or failed extraction)
//infile.bad() disk error -> hard desk 




//now i talk about all taking input but but how i am really reading
//line by line GNL fun 
//std::getline(infile , line) reads until \n
//or word by word using >> infile  infile >> word_var
//>> skips white spaces and read until next word
//u can use this with and gnl with loop to read the entire file 
//or char by char infile.get(char c) reading it in a loop char by char even white spaces is included
//OR u can have the entire file in 1 read 
//std::ostringstream ss;
//ss << infile.rdbuf();
//std::string countent = ss.string(); the whole file now is a big string 

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

void createSampleFile(std::string const& fileName)
{
    std::ofstream outfile(fileName.c_str());//this is creating the file 
    if (!outfile)
    {
        std::cerr << "Error : could not create '"<< fileName<< "' "<<std::endl;
        return ;
    }
    //put some thing inside the created file 
    outfile << "The quick brown fox jumps over the lazy dog." << std::endl;
    outfile << "The dog did not appreciate being jumped over." << std::endl;
    outfile << "The fox and the dog eventually became friends." << std::endl;
    outfile << "The end. The fox went home. The dog had dinner." << std::endl;
    std::cout << "  Created: " << fileName << std::endl;
    //closed is auto called bc of destrcuter
}

//i will read the whole file line by line
//ok what IN mean its mean that i want to go inside the file and take data i want 
//and outFile it mean i will give data to the file
void demoLineByLine(std::string const &fileName)
{
        std::cout << "\n--- Demo 1: Line-by-Line Reading ---" << std::endl;

        std::ifstream infile(fileName.c_str());
        if (!infile)
        {
 std::cerr << "  Error: could not open '" << fileName << "'" << std::endl;
        return;
        }
        std::string line;
        int lineNum = 0;
        while ((std::getline(infile ,line)))
        {
            lineNum++;
            std::cout << "  Line " << lineNum << ": " << line << std::endl;
        }
        
                std::cout << "  Total lines read: " << lineNum << std::endl;
 //auto close
}
void demoWordByWord(std::string const &filename)
{    std::cout << "\n--- Demo 2: Word-by-Word Reading ---" << std::endl;
    std::ifstream infile(filename.c_str());
    if(!infile)
    {
                std::cerr << "  Error: could not open '" << filename << "'" << std::endl;
        return;
    }
    std::string word;
    int wordCount = 0 , theCount = 0;
    while (infile >> word)
    {
        wordCount++;
    if (word == "The" || word == "the" || word == "The.")
            theCount++;
    }
    std::cout << "  Total words:          " << wordCount << std::endl;
    std::cout << "  Occurrences of 'the': " << theCount  << std::endl;
}
void demoReadAll(std::string const& filename)
{
        std::cout << "\n--- Demo 3: Read Entire File ---" << std::endl;

    std::ifstream infile(filename.c_str());

    if (!infile) {
        std::cerr << "  Error: could not open '" << filename << "'" << std::endl;
        return;
    }
    std::ostringstream ss;
    ss << infile.rdbuf();
    std::string wholeFileAsOneStr = ss.str();
        std::cout << "  File size (chars): " << wholeFileAsOneStr.size()<<std::endl;;
        std::cout <<"  First 40 chars:    '"
              << wholeFileAsOneStr.substr(0, 40) << "...'" << std::endl;
}
void demoAppend(std::string const &filename)
{
 {       std::cout << "\n--- Demo 4: Append to File ---" << std::endl;
    std::ofstream outfile;
    outfile.open(filename.c_str() , std::ios::app | std::ios::out);
    if (!outfile)
    {
        std::cerr << "  Error: could not open for append." << std::endl;
            return;
    }
    outfile << " Appended line: The fox wrote a memoir "<<std::endl;
            std::cout << "  Appended one line." << std::endl;
}
    //make sure u read the line
    std::ifstream infile(filename.c_str());
    std::string line; 
    int count = 0;
    while (std::getline(infile , line))
    {
     count++;
        /* code */
    }
        std::cout << "  File now has " << count << " lines." << std::endl;
}

std::string replaceAll(std::string const &content , std::string const &find ,  std::string const &replace)
{
    if(find.empty())//there is noting to search off
    {
        return content;
    }
    std::string result;
    std::size_t pos    = 0;
    std::size_t found;
    while((found = content.find(find , pos)) != std::string::npos)
    {
        result += content.substr(pos , found - pos);
        result +=replace;
        pos = found + find.size();
    }
        // Append any remaining content after the last match
    result += content.substr(pos);

    return result;
}
// ── Demo 5: The 42 replacement exercise ───────────────────────────────────
// Replace every occurrence of 'find' with 'replace' in inFilename.
// Write result to inFilename + ".replace".
// std::string::replace is FORBIDDEN.
void demoReplaceExercise(std::string const &filename , std::string const &find ,  std::string const &replace)
{
    std::cout << "\n--- Demo 5: 42 Replacement Exercise ---" << std::endl;
    std::cout << "  Replacing '" << find << "' with '" << replace << "'" << std::endl;
    //ok first i will try to open the file 
    std::ifstream infile(filename.c_str());
    if (!infile)
    {
        std::cerr << "Error there is no file with this name " << std::endl;
        return ;
    }//what i will to do is reading the whole file as str then edit on it then but in the file again 
    std::ostringstream ss;
    ss << infile.rdbuf();
    std::string wholeFile = ss.str();
    //now i am having the file as str
    //next step is to loop on every word inside the str
    std::string newStr = replaceAll(wholeFile , find , replace);
    
    std::ofstream out((filename + ".replace").c_str());
    if (!out )
    {
              std::cerr << "  Error: could not create output file." << std::endl;
        return;
    }
    out << newStr;
    std::cout << "  Written to: " << (filename + ".replace") << std::endl;
    out.close();
    std::ifstream verify((filename + ".replace").c_str());
    std::string   line;
    std::cout << "Result:" << std::endl;
    while (std::getline(verify, line))
      std::cout << "    " << line << std::endl;
    
}
int main() {
    std::string const filename = "sample.txt";

    createSampleFile(filename);
    demoLineByLine(filename);
    demoWordByWord(filename);
    demoReadAll(filename);
    demoAppend(filename);
    demoReplaceExercise(filename, "The", "A");

    std::cout << "\n--- All demos complete. ---" << std::endl;
    return 0;
}