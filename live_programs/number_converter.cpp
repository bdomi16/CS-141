/// @file number_converter.cpp
/// @author Adam T Koehler, PhD
/// @date May 17, 2023
/// @brief A short program to convert a binary, octal, or hexadecimal number
///        from the string format to a decimal number. This program is used
///        to reinforce basic C++ syntax and understanding relating to input,
///        strings, branches, and loops.

// Copyright Notice
// This document is protected by U.S. copyright law. Reproduction and 
// distribution of this work, including posting or sharing through any medium, 
// is explicitly prohibited by law, and also violates UIC's Student 
// Disciplinary Policy (A2-c. Unauthorized Collaboration; and A2-e3. 
// Participation in Academically Dishonest Activities: Material Distribution). 

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    string str_number;
    int decimal = 0, base = 10;

    // example entries b101010, o607, x7F
    cout << "Enter a number with a preceding base character." << endl;
    cout << "b for binary, o for octal, x for hex: ";
    cin >> str_number;

    // update the base value for binary, octal, or hexadecimal
    if (str_number.at(0) == 'b')
    {
        base = 2;
    }
    else if (str_number.at(0) == 'o')
    {
        base = 8;
    }
    else if (str_number.at(0) == 'x')
    {
        base = 16;
    }

    // If we have a base-10 number, let's use the string to integer 
    //  function. This is simply to show an example use. Our
    //  algorithm works perfectly fine with base-10 as well so we
    //  do not really need a separate base-10 case.
    if (base == 10)
    {
        decimal = stoi(str_number);
    }
    else
    {
        // example entries b101010, o607, x7F
        // iterate over the string, accumulating the decimal conversion
        for (size_t i = 1; i < str_number.size(); ++i)
        {
            int value; 
            // is it a digit or a letter?
            // if ('0' <= str_number.at(i) && str_number.at(i) <= '9')
            if (isdigit(str_number.at(i)))
            {
                // use character math to shift to 0 based number
                value = str_number.at(i) - '0';
            }
            else
            {
                // convert to uppercase letters, e.g. handle 'a' and 'A'
                // then use character math to shift to 0 based number
                // finally shift 10, accounting for numeric values 0-9
                value = toupper(str_number.at(i)) - 'A' + 10;
            }

            decimal = decimal + value * pow(base, str_number.size() - (i+1));
        }
    }

    // Output the result to the user
    cout << "Our number " << str_number << " is " 
        << decimal << " in base-10." << endl;

    return 0;
}