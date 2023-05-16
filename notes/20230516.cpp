#include <iostream>
#include <string>
// #include <math>

using namespace std;

int main()
{
    string str1, str2;
    string str3;

    // char, bool, double, int, float
    // uint unsigned;
    unsigned int xx = 0;
    // string
    char b = 'a';
    bool f = true; //false
    // unsigned double bb = 0.5;

    getline(cin, str1);
    cin >> str3;

    cout << str1 << str2 << str3 << endl;
    cin >> str3;
    cout << str1 << str2 << str3 << endl;


    int x, y = 7, z=-20;

    x = 5;
    int sum = x + y + z;
    cout << sum << endl;
    sum = abs(sum);
    cout << sum << endl;
    return 0;
}