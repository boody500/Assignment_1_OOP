// bigint with oop
// Author: abdelrahman elsayed korany mohamed , farah walid ahmed , marwan mohamed abdelmonem
// ID's:                  20210222            ,       20210290    ,         20210378
// Date: 24 october 2022
// Version: 4.0

#include "Bigint.h"
using namespace std;

int main() {
    int menu;

    while (1) {
        cout << "Welcome to BigInt please select want you want to do:\n1) add two numbers\n2) subtract two numbers\n3) check which of two numbers is smaller or greater\n";
        cout << "4) check is two numbers are equal\n5) make a copy of a number in another one\n6) display size and sign\n7) exist\n>>";
        cin >> menu;

        switch (menu)
        {
            case 1: {
                string str1 = "", str2 = "";
                cout << "Please enter the first number :\n>>";
                cin >> str1;
                BigInt num1(str1);
                cout << "Please enter the second number :\n>>";
                cin >> str2;
                BigInt num2(str2);

                cout << "num1 = " << num1 << endl;
                cout << "num2 = " << num2 << endl;

                //     adding two obj a+b
                BigInt num3 = num1 + num2;
                cout << "num1 + num2 = " << num3 << endl;
                break;
            }

            case 2: {
                string str1 = "", str2 = "";
                cout << "Please enter the first number :\n>>";
                cin >> str1;
                BigInt num1(str1);
                cout << "Please enter the second number :\n>>";
                cin >> str2;
                BigInt num2(str2);

                cout << "num1 = " << num1 << endl;
                cout << "num2 = " << num2 << endl;

                // subtracting two obj a-b
                BigInt num3 = num1 - num2;
                cout << "num1 - num2 = " << num3 << endl;
                break;


            }

            case 3: {
                string str1 = "", str2 = "";
                cout << "Please enter the first number :\n>>";
                cin >> str1;
                BigInt num1(str1);
                cout << "Please enter the second number :\n>>";
                cin >> str2;
                BigInt num2(str2);

                cout << "num1 = " << num1 << endl;
                cout << "num2 = " << num2 << endl;

                // compare two obj with less than and more than
                if (num1 < num2) {
                    cout << "The first number is less than the second number. \n";
                } else if (num1 > num2) {
                    cout << "The first number is more than the second number. \n";
                }
                break;

            }

            case 4: {
                string str1 = "", str2 = "";
                cout << "Please enter the first number :\n>>";
                cin >> str1;
                BigInt num1(str1);
                cout << "Please enter the second number :\n>>";
                cin >> str2;
                BigInt num2(str2);

                cout << "num1 = " << num1 << endl;
                cout << "num2 = " << num2 << endl;

                // check two obj are equal or not
                if (num1 == num2) {
                    cout << "Two numbers are equal.\n";
                } else {
                    cout << "Two numbers are NOT equal.\n";
                }
                break;


            }

            case 5: {
                string str1 = "", str2 = "";
                cout << "Please enter the first number :\n>>";
                cin >> str1;
                BigInt num1(str1);
                cout << "Please enter the second number :\n>>";
                cin >> str2;
                BigInt num2(str2);

                cout << "num1 = " << num1 << endl;
                cout << "num2 = " << num2 << endl;

                // put obj in other obj
                num2 = num1;
                cout << "num1 = " << num1 << "\n";
                cout << "num2 = " << num2 << "\n";

                break;

            }

            case 6: {
                string str1 = "", str2 = "";
                cout << "Please enter the first number :\n>>";
                cin >> str1;
                BigInt num1(str1);
                cout << "Please enter the second number :\n>>";
                cin >> str2;
                BigInt num2(str2);

                cout << "size of num1 = " << num1.size() << endl;
                cout << "sign of num1 = " << num1.Sign() << endl;
                cout << "size of num2 = " << num2.size() << endl;
                cout << "sign of num2 = " << num2.Sign() << endl;

                break;

            }

            case 7:
                return 0;

            default:
                return 0;

        }

    }

}

