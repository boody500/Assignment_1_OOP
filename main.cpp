// A demo of using very long integers
// Date:    15 May 2022
// Version: 2.0

#include "Bigint.h"
using namespace std;

int main()
{
    string str1 = "", str2 = "";

    cout << "Please enter the first number :\n";
    cin >> str1;
    cout << "Please enter the second number :\n";
    cin >> str2;

    // initialize two objects

    BigInt num1(str1);
    BigInt num2(str2);
    cout <<"num1 = " << num1 << endl;
    cout << "num2 = " << num2 << endl;

//     adding two obj a+b
    BigInt num3 = num1 + num2;
    cout << "num1 + num2 = " << num3 << endl;

    // subtracting two obj a-b
    BigInt num4 = num1 - num2;
    cout << "num1 - num2 = " << num4 << endl;




    // compare two obj with less tan
    if(num1 < num2)
    {
        cout << "Yup,The first number is more than the second number. \n";
    }
    else
    {
        cout << "Nope ,The first number is less than the second number. \n";
    }



//     compare two obj with less than
//    if(num3 > num4)
//    {
//        cout << "Yup ,The first number is more than the second number. \n";
//    }
//    else
//    {
//        cout << "Nope ,The first number is less than the second number. \n";
//    }

// check two obj are equal or not
    if(num1 == num2)
    {
        cout << "Two numbers are equal.\n";
    }
    else
    {
        cout << "Two numbers are NOT equal.\n";
    }



//    put obj in other obj


}

//+-9877777543322222222"
// +-99999999999999999999999999999999999
