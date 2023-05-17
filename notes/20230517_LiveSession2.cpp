/// @file 20230517_LiveSession2.cpp
/// @author Adam T Koehler, PhD
/// @date May 17, 2023
/// @brief Code and lecture notes from the live session on strings, branches, 
///         and loops.

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
    // when doing math with various datatypes we
    // must determine what are the two datatypes
    // as that will determine the result's datatype
    int x, y, z;
    double a, b, c;

    // only integers -> integer result
    x = 13; 
    y = 5;
    z = x + y;
    cout << z << endl; // 18

    a = 5.2;
    b = 12.0;

    // mixed integer and double (any floating point type)
    // yields a double (the floating point type)
    // however we are placing it back into an integer
    z = a + y;
    cout << z << endl; // 10

    // The modulo (%) operator calculates the remainder
    // of an integer division statement
    z = x % y;
    cout << z << endl; // 3


    // integer division is division with two integers
    // since we do not have a floating point type 
    // the result will be an integer. In long division
    // this number is often referred to as the quotient.
    z = x / y;
    cout << z << endl; // 2

    // Question: How can we get the 4 from 1234, / or %?
    z = 1234 % 1230;
    z = 1234 % 10;
    cout << z << endl;

    // Question: How can we get the 123 from 1234, / or %?
    z = 1234 / 10;    
    cout << z << endl;    

    // When we mix datatypes, it is imporant to know which
    // operations happen first because this will determine
    // when a result becomes a floating point number
    z = 5;
    b = y / x + a * z;   // 26.0 as x / y is 0 (integer division)
    cout << b << endl;
    c = y / (x + a * z); // 0.128205 as the denominator is a double
    cout << c << endl;


    // Let's talk about strings 
    string s = "Hello";
    string r = "World";

    // We can compare strings just like numbers
    // We can also store the conditional result versus always
    // needing to use it a branch or loop.
    bool same = r == s;
        
    // A common error is to accidentally use a single = for equality
    // and this then performs an assignment and another assignment.
    x = 13;
    y = 5;
    same = x=y;

    // Recall in C++ true is any non-zero number
    // same will be assign true because x != 0
    if (same)
    {
        cout << "true!!!" << endl;
    }

    x = 13;
    y = 5;
    same = x==y;
    if (!same)
    {
        cout << "false!" << endl;
    }

    // This common error can lead to infinite loops and logical
    // bugs in loop iteration counts. In this case the 
    // expectation is the loop iterates until y does not match x
    // should be 0 times. However, it assigns y into x
    // and therefore will iterate until y is 0 (aka false).
    x = 13;
    y = 13;
    while(x = y) // BAD
    {
        y--;
    }
    cout << y << endl;

    x = 13;
    y = 13;
    while(x == y) // GOOD
    {
        y--;
    }
    cout << y << endl;

    // string member functions: at()
    // at() allows us to access characters and set characters
    // size() provides us the quantity of characters
    //      size() is a constant time call, it does not
    //      iterate over each character to count
    cout << s.size() << endl;
    cout << s.at(0) << endl;
    s.at(0) = 'J';
    cout << s.at(0) << endl;

    // Loops: for loops
    // We use for loops when we know or can calculate the iteration
    // count. for loops have the 3 non-body parts of a loop combined
    // into the for loop header (first line)

    // We can iterate over a string character by character.
    // We will almost always use for loops to iterate over a string.
    // size_t allows us to be more system independent as the
    //  size() function is an unsigned value but unsigned int or uint
    //  is considered more system dependent
    for(size_t i = 0; i < s.size(); i=i+1)
    {
        // we can modify and use the character
        // on the same line, the right-hand side
        // is always evaluated completely before
        // the assignment into the left-hand side
        s.at(i) = s.at(i) + i;
    }

    // When modifying unsigned numbers we have to be careful as 
    // subtracting 1 from 0 does not go to -1, so instead we will add
    // to our looping variable
    // for(size_t i = 0; i+1 < s.size(); i=i+1)
    // instead of:
    // for(size_t i = 0; i < s.size()-1; i=i+1)
    
    // We can write any for loop as a while loop, which has all
    // four loop parts initialization, condition, update, and body
    // separated out versus the condensed format of the for loop.
    size_t i = 0;
    while (i < s.size())
    {
        cout << s.at(i) << ' ';
        i=i+1;   
    }
    cout << endl;

    
    // To go backwards we want to end at -1, so j must be a signed integer
    int j = s.size()-1;
    while (j >= 0)
    {
        cout << s.at(j) << ' ';
        j=j-1;   
    }
    cout << endl; 

    return 0;
}