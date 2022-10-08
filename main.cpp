#include "Bigint.h"
using namespace std;

int main()
{
    cout << "enter first number:\n";
    BigInt a;
    cout << "enter second number:\n";
    BigInt b;
    char operation;
    cout << "enter the operation(+ or -)\n";
    cin >> operation;
    if (operation == '+')
        cout << "a + b = \n" << (a + b);

    else
        cout << "a - b = \n" << (a - b);

    return 0;
}

//+-9877777543322222222"
// +-99999999999999999999999999999999999