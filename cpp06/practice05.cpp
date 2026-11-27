/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   practice05.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/27 12:18:08 by moodeh            #+#    #+#             */
/*   Updated: 2026/11/27 14:51:57 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// first we get str input from the user
// next is to know what kind of input we have
// CLASSIFICATION

// char: Length == 1 AND printable (std::isprint) AND not a digit (!std::isdigit)
//"a", "Z", "*", " ", "~"   ("0"–"9" have length 1, but they belong to INT, not CHAR.)

// int :INT_MIN - INT_MAX int  Optional +/-,
//"0", "42", "-42", "+100"
// followed by 1+ digits (0–9), no ., no 'f'

// float: Optional +/-, digits, exactly one ., digits, ending in 'f'
// "0.0f", "-4.2f", "+42.5f"  (Must contain a (.) — "42f" without a decimal point is INVALID.)

// double: Optional +/-, (digits+ exactly one .+ digits), no 'f'
//"0.0", "-4.2", "+42.5"  (Same structure as FLOAT, just without the trailing 'f'.)

// FLOAT_PSEUDO : Literally "-inff", "+inff", "nanf" (and optionally "inff")
//  "-inff", "+inff", "nanf", "inff" (Must be detected before general float parsing because they have no digits or .)

// DOUBLE_PSEUDO:Literally "-inf", "+inf", "nan" (and optionally "inf")
//"-inf", "+inf", "nan", "inf" (Notice "nanf" ends in 'f', while "nan" does not.)

// INVALID : Anything that fails all 6 rules above (make it like exception)
//"", "abc", "42f", "4.2.1", "++4", "4.2ff", ".", ".f", "\n"
//(Immediately prints "impossible" for all four types.)

// starting with 1.char ./convert a
// internally char also has numeric var 'A' == 65
// so we can represent like double value = static_cast<double>('A')
// now we have it as double value
// now we can convert it to other int , float , double

// 2. integer ./convert 42;
// must check first if it valid int -int -> +int
// thats it

// 3.float literal ./convert 42.5f
// f tell is this number is float or not
// double is same as it but without f

// we use double as the main converter bc its the bigger and can be converted to anything we want
// double value = 42.0; it also more precision than float so no data losing we inter a double 
// char c = static_cast<char>(value);
//  int i = static_cast<int>(value);
//  float f = static_cast<float>(value);
//  double d = static_cast<double>(value);

// Why static_cast?
// Because you're converting between ordinary built-in scalar types.



//impossible vs Non displayed
//when we have a char it has 2 separate requirements 
//1.The numeric value must fit inside the char range.
//2.The character must be printable if you want to display it.

//impossible mean that the value too big to but it inside char 
//so we cant convert it 
// ./convert 1000
//the char is  8bit length so it can be from 
//-128 <= char <= 128
//so 1000 is outside this range 
//so char print impossible   ,char: impossible.
// The value cannot be represented by that char type.
//Non display ./convert 7
//7 fit inside char but it ascii its nonprintable 
// so it -->char: Non displayable
// ./convert 65
//this output A  ///we stop here for now (complete  after finishing studying )
#include <iostream>
using std::cout;
using std::endl;
int main(int argc, char **argv)
{
    if (argc < 2)
    {
        cout << "Error : no value entered" << endl;
        return 0;
    }
}