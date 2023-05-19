/// @file 20230518_LiveSession3.cpp
/// @author Adam T Koehler, PhD
/// @date May 18, 2023
/// @brief Code and lecture notes from the live session on loops & functions.

// Copyright Notice
// This document is protected by U.S. copyright law. Reproduction and 
// distribution of this work, including posting or sharing through any medium, 
// is explicitly prohibited by law, and also violates UIC's Student 
// Disciplinary Policy (A2-c. Unauthorized Collaboration; and A2-e3. 
// Participation in Academically Dishonest Activities: Material Distribution). 

#include <iostream>
#include <string>

using namespace std;

// function parts:
// return_type function_name (parameters list)
//      function body

// We can declare function prototypes before our code that may invoke
// a function to allow the compiler to know how the function should
// be utilized.
//
// Function prototypes do not require variable names for the parameters,
// but sometimes they are useful to have to make code more readable.
int fibo(int);
void split(const string&, string&, string&);

int main()
{
    // Let's go over loops again, calculating the Nth Fibonnaci number
    int fib = 1, x = 1, y = 1;
    int N;
    cout << "Enter the Fibonacci sequence number to calculate: ";
    cin >> N;
    cout << endl;

    // Fibonacci numbers 1 and 2 are base cases and knowns.
    if (N == 1 || N == 2)
    {
        fib = 1;
    }
    else
    {
        // Other Fibonacii numbers must be calculated based on adding the 
        // two previous numbers in the sequence.
        //
        // We start at 3 because we already handled 1 and 2. We include N
        // because we want the Nth number in the sequence.
        for(int i = 3; i <= N; ++i)
        {
            fib = x + y;
            x =  y;
            y = fib;
        }
    }
    cout << "Fib number " << N << " is " << fib << endl;
    cout << endl;

    // Objects in C++ have member functions. The at() function is a string
    // member function that allows us to acquire a specific character or
    // set the value of a specific character. The at() function takes an
    // index value and will throw an out of range exception if that value
    // is not a valid index.

    // In this example we want to convert every third character to a space
    string s, o;
    cin.ignore(); // we used >> before, and it leaves the "\n" in buffer
    cout << "Enter a string (one or more words):" << endl;
    getline(cin, s);
    cout << endl;

    // store the original as our algorithms are destructive
    o = s;

    // Looping over strings uses the size_t variable type to be more
    // portable between system architectures as size() is an unsigned value.
    // In this version we have a single line in our loop body, start at 
    // the index value of 2 (the third character) and use the for loop 
    // update step to skip over 3 spots.
    for(size_t i = 2; i < s.size(); i=i+3)
    {
        s.at(i) = ' ';
    }
    cout << o << endl;
    cout << s << endl;
    cout << endl;
    
    // reset to original string
    s = o;

    // Alternatively, we can use the mod operator to determine when we are
    // processing a third character. This loop iterates over every character
    // in the string and only performs the at() call for "third" characters.
    for(size_t i = 0; i < s.size(); ++i)
    {
        // We use i+1 to convert from zero-based indexing to one-based
        // counting. Meaning the first character (1) is at index 0, so 
        // the third character will be at index 2.
        // We mod by 3 because we want every third value, and we compare
        // to 0 to check if the remainder of the division (from %) is 0
        // because that means the value is evenly divisible by 3.
        if ((i+1) % 3 == 0)
        {
            s.at(i) = ' ';
        }
    }


    // Another use of loops is for input validation. We often want to check
    // whether a specific type of value or values have been entered and only
    // proceed with the algorithm with valid values.
    string val, val2;
    cout << "Enter stop or Stop: ";
    getline(cin, val);

    // DeMorgan's Law allows us to distribute or extract negations across 
    // compound conditional operators to create equivalent logical statements.
    // !(val == "stop" || val == "Stop") <==> (val != "stop" && val != "Stop")
    
    // Keep asking for an input until the user enters a valid word
    // where the only valid words are stop and Stop
    while (val != "stop" && val != "Stop")
    {
        cout << "Enter stop or Stop: ";
        getline(cin, val);   
    }
    cout << "You entered: " << endl;
    cout << val << endl;
    cout << endl;

    cout << "Enter two values, one per line. (both must be stop)" << endl;
    getline(cin, val);
    getline(cin, val2);
    cout << endl;
    // Keep asking for an input until the user enters two valid words
    // where the only valid words are stop, so both must be stop to 
    // proceed after the loop
    while (val != "stop" || val2 != "stop")
    {
        cout << "Enter two values, one per line. (both must be stop)" << endl;
        getline(cin, val);   
        getline(cin, val2);
    }
    cout << "You entered: " << endl;
    cout << val << endl;
    cout << val2 << endl;
    cout << endl;



    // Let's cover some basics of string parsing using string member
    // functions substr and find. Member functions are invoked using
    // the dot operator and the variable name.
    string lookInMe;
    cout << "Enter a string to search for a \"c\" in:" << endl;
    getline(cin, lookInMe);
    cout << endl;

    // The find() member function gives the index of what is being searched for
    // find can be called in multiple ways, but the basic call starts at the
    // beginning of the string. When what is being searched for is not found 
    // then the function will return string::npos 
    int loc = lookInMe.find("c");
    cout << lookInMe << endl;
    if(string::npos == loc)
    {
        cout << "We did not find a c :(" << endl;
    }
    if(string::npos != loc)
    {
        cout << "We found a c!" << endl;
    }
    cout << endl;

    // We can use a more advanced call for find() to search starting with a 
    // specific index, and could use that to count how many instances of 
    // what we are searching for exist within the search string.
    int count = 0;
    loc = lookInMe.find("c");
    while(string::npos != loc)
    {
        cout << "Found a c at index: " << loc << endl;
        loc = lookInMe.find("c", loc+1);
        count++;
    }
    cout << endl;
    cout << "With the algorithm that uses only find()," 
        << endl << "we discovered " << count << " \"c\" characters" << endl;
    cout << endl;

    // We can also use a combination of find() and substr() to count 
    // instead of using the find call with two arguments. 
    // this is a destructive algorithm, so save the original value
    string original = lookInMe;
    count = 0;
    loc = lookInMe.find("c");
    while(string::npos != loc)
    {
        // create a substr starting just after the discovered "c"
        // without other arguments, substr goes to the end of the string
        lookInMe = lookInMe.substr(loc+1);
        loc = lookInMe.find("c");
        count++;
    }
    cout << "With the algorithm that uses find() and substr()," 
        << endl << "we discovered " << count << " \"c\" characters" << endl;
    cout << endl;
    cout << endl;

    // Let's reset as our algorithm was destructive.
    lookInMe = original;

    // We can also create a substr of a specific number of characters
    // starting at a specific spot, here we go from index 2 for a 
    // new string length of 4 characters.
    cout << lookInMe.substr(2, 4) << endl;



    // We can create a function based on our previously written code
    // to calculate the Nth Fibonacci number, and this will allow us
    // to call the function multiple times to calculate many different
    // Fibonacci numbers.
    int funN;
    cout << "Enter the Fibonacci sequence number to calculate: ";
    cin >> funN;
    cout << endl;

    // We can call and output two possibilities directly
    cout << "Fib number " << funN << " is " << fibo(funN) << endl;
    cout << "Fib number " << funN+1 << " is " << fibo(funN+1) << endl;
    cout << endl;

    // Output all Fibanocci numbers up to and including N
    cout << "The first " << funN << " Fibonacii numbers are: " << endl;
    for(int f = 1; f <= funN; ++f)
    {
        // We can call and store a possibility for later use
        // in this case later is almost immediately in the output.
        int calc = fibo(f);
        cout << "Fib number " << f << " is " << calc << endl;
    }
    cout << endl;

    string str, a, b;
    cout << "Enter a bunch of space separated words:" << endl;
    cin.ignore(); // ignore the "\n" from prior >> use
    getline(cin,str);
    cout << endl;

    // Using a function that has reference parameters requires
    // variables to be sent as arguments, we cannot use literal values.
    split(str,a,b);

    // The split function updates the values for a and b
    cout << "Entry: " << endl << str << endl;
    cout << "First word: " << endl << a << endl;
    cout << "Remainder of the string: " << endl << b << endl;

    return 0;
}


// function parts:
// return_type function_name (parameters list)
//      function body

/// @brief calculate the Nth Fibonacci number
/// @param N the number in sequence to calculate
/// @return the integer value of the Nth Fibonacci number
int fibo(int N)
{
    // set our initial values
    int fib = 1, x = 1, y = 1;

    // base cases
    if (N == 1 || N == 2)
    {
        return fib;
    }
    
    // numbers in the sequence beyond the second
    for(int i = 3; i <= N; ++i)
    {
        // each fibonacci number is the sum of the two prior numbers
        fib = x + y;
        x =  y;
        y = fib;
    }
    
    return fib; 
}


// We can use reference parameters to return multiple things in C++
// Each reference parameter points back to a variable in the scope
// of the function that invoked the function with reference 
// parameters. Updating a reference parameter's value will change
// the value of the parameter within the callee's function.

/// @brief given a string, split it into two on the first space
/// @param s the string to split
/// @param one the first part of the split string
/// @param two the second part of the split string
void split(const string &s, string &one, string &two)
{
    // The find member function allows us to look for certain characters,
    // and we can combine it with the substring member funtion to split
    // a string into two different pieces.
    one = s.substr(0,s.find(" "));
    two = s.substr(s.find(" ")+1);
}