// A structure and functions to handle very
// long integers
// Author:  Mohammad El-Ramly
// Date:    15 May 2022
// Version: 1.0

#include "Bigint.h"

using namespace std;

bool BigInt::is_valid(string &b)
{
    regex valid_num("[+-]?[0-9]{1,}");
    return regex_match(b, valid_num);
}

BigInt::BigInt() {
    string num;
    cin >> num;
    while (!is_valid(num)){
        cout << "invalid number,try again\n";
        cin >> num;
    }

    if (!isdigit(num[0]))
    {
        sign = num[0];
        num.erase(num.begin() ,num.begin()+1);

    }

    else
    {
        sign = '+';
    }

    number =  num;

}
BigInt:: BigInt (string num )
{
    number = num;

}
string& BigInt:: get_num()
{
    return number;
}



string& BigInt :: StrSize(BigInt& a)
{
    int size1 = number.size();
    int size2 = a.get_num().size();
    string temp(abs(size1 - size2), '0');

    if (size1 < size2)
    {
        number = temp + number;
        return number;
    }
    else {
        a.get_num() = temp + a.get_num();
        return a.get_num();
    }

}


BigInt BigInt:: operator+ (BigInt& b)
{
    BigInt c("");
    BigInt d("");
    d.number = number;
    d.sign = sign;
    StrSize(b);

    if (sign == '+' and b.sign == '+'){
        int carry = 0;
        for (int i = number.size() - 1; i >= 0; i--)
        {
            int temp =number[i] + b.number[i] - 2 * '0' + carry;
            carry = (temp > 9) ? 1 : 0;
            c.number = to_string(temp % 10) + c.number;
        }

        if (carry)
        {
            c.number = to_string(carry) + c.number;
        }
    }

    else if ((sign =='-') && (b.sign == '-'))
    {
        int carry = 0;
        for (int i = number.size() - 1; i >= 0; i--)
        {
            int temp =number[i] + b.number[i] - 2 * '0' + carry;
            carry = (temp > 9) ? 1 : 0;
            c.number = to_string(temp % 10) + c.number;
        }

        if (carry)
        {
            c.number = to_string(carry) + c.number;
        }
        c.number = '-' + c.number;

    }


    else if (sign == '+' and b.sign == '-'){
        b.sign = '+';
        c = d - b;

    }

    else if (sign == '-' and b.sign == '+')
    {

    }

    return c;
}

/*BigInt BigInt:: operator- ( BigInt& b)
{
    BigInt c("");
    StrSize(b);

    bool min = true;
    if (number >= b.get_num())
    {
        min = false;
    }

    for (int i = number.size()-1; i >= 0 ; --i)
    {
        int temp;
        if (number[i] >= b.get_num()[i])
        {
            temp = number[i] - b.get_num()[i];
            c.number = to_string(temp) + c.number;
        }

        else{
            temp = b.number[i] - number[i];
            c.number = to_string(temp) + c.number;
        }
    }


    if (min)
        c.number = '-' + c.number;


    cout << sign << number << endl;
    cout << b.sign << b.number << endl;
    return c;
}*/

BigInt BigInt:: operator- (BigInt& b)
{
    BigInt c("");
    BigInt d("");
    d.number = number;
    d.sign = sign;
    StrSize(b);
    if (sign == '+' and b.sign == '+')
    {
        if (number >= b.number)
            for(int i = number.size()-1 ; i >= 0  ;i--)
            {
                int borrow = 0;
                int temp = 0;
                if (number[i] >= b.number[i]){
                    temp = number[i] - b.number[i];
                    c.number = to_string(temp) + c.number;
                }

                else{
                    borrow = 10;
                    number[i-1] = char((number[i-1] -  '1') + '0');
                    temp = (borrow + number[i]) - b.number[i];
                    c.number = to_string(temp) + c.number;
                }
            }

        else{
            c.number = number;
            number = b.number;
            b.number = c.number;
            c.number = "";
            for(int i = number.size()-1 ; i >= 0  ;i--)
            {
                int borrow = 0;
                int temp = 0;
                if (number[i] >= b.number[i]){
                    temp = number[i] - b.number[i];
                    c.number = to_string(temp) + c.number;
                }

                else{
                    borrow = 10;
                    number[i-1] = char((number[i-1] -  '1') + '0');
                    temp = (borrow + number[i]) - b.number[i];
                    c.number = to_string(temp) + c.number;
                }
            }
            c.number = '-' + c.number;
        }

    }

    else if (sign == '+' and b.sign == '-'){
        b.sign = '+';
        c = d + b;
    }


    else if (sign == '-' and b.sign == '+'){
        b.sign = '-';
        c = d + b;


    }

    else
    {
        number = b.number;
        b.number = d.number;

        if (number >= b.number)
            for(int i = number.size()-1 ; i >= 0  ;i--)
            {
                int borrow = 0;
                int temp = 0;
                if (number[i] >= b.number[i]){
                    temp = number[i] - b.number[i];
                    c.number = to_string(temp) + c.number;
                }

                else{
                    borrow = 10;
                    number[i-1] = char((number[i-1] -  '1') + '0');
                    temp = (borrow + number[i]) - b.number[i];
                    c.number = to_string(temp) + c.number;
                }
            }

        else{
            c.number = number;
            number = b.number;
            b.number = c.number;
            c.number = "";
            for(int i = number.size()-1 ; i >= 0  ;i--)
            {
                int borrow = 0;
                int temp = 0;
                if (number[i] >= b.number[i]){
                    temp = number[i] - b.number[i];
                    c.number = to_string(temp) + c.number;
                }

                else{
                    borrow = 10;
                    number[i-1] = char((number[i-1] -  '1') + '0');
                    temp = (borrow + number[i]) - b.number[i];
                    c.number = to_string(temp) + c.number;
                }
            }
            c.number = '-' + c.number;
        }


    }

    return c;
}




//bool BigInt:: operator< (const BigInt& C) {
//    bool min = true;
//
//}
ostream &operator<<(ostream &out, BigInt num)
{
    out << num.get_num();
    return out;
}