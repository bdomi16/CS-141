/// @file 20230516_LiveSession1.cpp
/// @author Adam T Koehler, PhD
/// @date May 16, 2023
/// @brief Code and lecture notes from the live session on basic C++.

// Copyright Notice
// This document is protected by U.S. copyright law. Reproduction and 
// distribution of this work, including posting or sharing through any medium, 
// is explicitly prohibited by law, and also violates UIC's Student 
// Disciplinary Policy (A2-c. Unauthorized Collaboration; and A2-e3. 
// Participation in Academically Dishonest Activities: Material Distribution). 


// We always want to be specific with our included libraries.
// We should only include what we use, and not just everything
// that we might use. We also want to avoid hidden inclusions
// so that we are aware of our program's library dependencies.
#include <iostream>
#include <string>
#include <math>

// In CS 141 and many UIC CS classes that use C++ you will use
// the std namespace. This allows us to not have to specify the
// namespace for certain things we use a lot such as cout.
// Without this line we would need to put std::cout for each cout use.
using namespace std;

int main()
{
    // C++ has several built in (native/primitive) data types
    // such as char, bool, double, int, float
    // there are many other primitive data types (long, short, etc).
    // None of these native data types are initialized
    
    // Declaring a variable is not the same as defining its value.
    // These are declarations and the variables have garbage values.
    char c;
    bool isOver;
    double m, n, o;
    float a, b;

    // Declaring can involve an initialization and with that defines
    // a variable value.
    int q = 5, r = 4;
    

    // Defining a variable's value can happen at any point by using
    // an assignment statement    
    m = 4;


    // Integers can also be unsigned and we have various shorthands
    // to say unsigned int such as uint and unsigned    
    unsigned int xVal = 0;
    unsigned yVal = 0;
    uint zVal = 0;

    
    // floating point numeric datatypes cannot be unsigned
    // unsigned double bb = 0.5;


    // a string is a special data type known as an object
    // a string is not a primitive datatype
    // a string is initialized to a default value of the empty string ""
    // an empty string is a size 0 string, " " is a space, it is not empty
    string str1, str2;
    string str3;

    // There are two types of input that we deal with, acquiring a single 
    // sequence of characters without whitespace, and acquiring an entire
    // line of characters including whitespace.
    //
    // Whitespace can include a space (' '), a tab ('\t'), or a newline ('\n')

    // To acquire an entire line we use the getline function and say where
    // the data should come from (cin in this case) and what string it should 
    // go to (str1 in this case). getline() is one way we can read in 
    // whitespace on a line.
    getline(cin, str1);

    // We can split expressions across multiple vertical lines to avoid 
    // overly long individual lines.
    // Every extraction (>>) or insertion (<<) operator must be paired with 
    // a variable (extraction) or a value (insertion). The data flows in 
    // the direction of the arrows and the operators ignore whitespace.
    cin >> str1 >> str2
        >> str3;

    // We can combine multiple extraction (>>) and insertion (<<) operations
    // into a single C++ statement
    cout << str1 << str2 << str3 << endl;
    cin >> str3;

    // We can split our output statement similar to other expression splits.
    cout << str1 << str2 
        << str3 << endl;

    // cin and cout are the console input and console output buffers
    // whenever we use cin or cout we are using them as a data source or 
    // data endpoint and the extraction or insertion operators interact 
    // with the input and output buffers. We will use the insertion and
    // extraction operators with cin, cout, and file stream buffers.


    // Numeric datatypes can be utilized to perform mathematical operations
    int x, y = 7, z, sum;
    x = 5;
    
    // In this example we are setting the sum variable to the mathematical
    // summation of the values contained in x, y, and z. Note that x is
    // assigned 5 above, and y is initialized to 7, but z has no defined
    // value and therfore will be a garbage value. So by using z,
    // whatever value existing in z's memory location will be used.
    sum = x + y + z;

    // This means we have no idea what will be output on this line.
    // When we see a value of 12 output, we can easily convince ourselves
    // that our program is correct when it is not.
    cout << sum << endl;

    // Setting z to -20, gives it a value but doesn't recalculate sum
    z = -20;
    cout << sum << endl;

    sum = x + y + z;

    // abs is an example of a math function from the math library
    // many library functions (not just math) can be understood
    // just by their name. This is the absolute value function.
    // The absolute value provides the magnitude of a numerical value.
    // This function is for whole number datatypes 
    sum = abs(sum);

    // This final summation's magnitude is 8.
    cout << sum << endl;
    
    return 0;
}