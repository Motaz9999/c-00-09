/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 21:03:32 by moodeh            #+#    #+#             */
/*   Updated: 2026/07/04 22:01:10 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

std::string replace(std::string str , std::string const s1 , std::string const s2)
{
    std::string rebuild_str = "";//no need to know where i am inside this bc i will just add to it
    size_t found;
    size_t i = 0;//where i am inside the str
    if ((found = str.find(s1 , i)) == std::string::npos)
    return str;
    while ((found = str.find(s1 , i)) != std::string::npos)
    {
        rebuild_str += str.substr(i , found - i);//cut the str before the finding s1 then 
        rebuild_str += s2;//add s1
        i = found + s1.size();//ok now i want to skip before s1 and after together 
    }
    return rebuild_str;
}

int main(int argc , char *argv[])
{
    if (argc != 4)
    {
        std::cerr <<"Error: some element not found . "<<std::endl;
        return 1;
    }
    
    std::string fileName = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    std::string wholeFile;
    std::stringstream ss;//take the whole file as 1 time then convert to str
    
    std::ifstream file;
    file.open(fileName.c_str(), std::ios::in);//read the whole file as 1 str
    if (!file)
    {
        std::cerr <<"Error: cant open the file . "<<std::endl;
        return 2;
    }
    ss << file.rdbuf();
    file.close();//end using the file 
    wholeFile = ss.str();//this is the whole file as 1 big str so what i must do is to 
    //search s1 inside this big str and delete it or skip it and but s2
    std::string newFile = replace(wholeFile , s1 , s2);
    //next step is creating the file 
    std::ofstream outfile;
    std::string newFileName = fileName+".replace";
    outfile.open(newFileName.c_str() , std::ios::out);
    if (!outfile)
    {
          std::cerr <<"Error: cant make replace file . "<<std::endl;
        return 3;
    }
    outfile << newFile;
    return 0;
}