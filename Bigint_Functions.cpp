// bigint with oop
// Author:
// Date: 14 october 2022
// Version: 2.0

#include "Bigint.h"

using namespace std;

bool BigInt::is_valid(string &b)
{
    regex valid_num("[+-]?[0-9]{1,}");
    return regex_match(b, valid_num);
}

BigInt::BigInt()
{
    string num = "";
    number = num;

}
BigInt:: BigInt (string &num )
{

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
BigInt::BigInt(int n) {
    string num ;
    cin >> num;
    num = to_string(n);
    while (!is_valid(num))
    {
        cout << "invalid number,try again\n";
        cin >> num;
    }

    if ((!isdigit(num[0])) && (num[0]== '-' ))
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

string BigInt:: get_num() const
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
        a.number = temp + a.get_num();
        return a.number;
    }

}


BigInt BigInt:: operator+ (BigInt& anotherDec)
{
    BigInt c;
    BigInt d;
    d.number = number;
    d.sign = sign;
    StrSize(anotherDec);

    if (sign == '+' and anotherDec.sign == '+'){
        int carry = 0;
        for (int i = number.size() - 1; i >= 0; i--)
        {
            int temp =number[i] + anotherDec.number[i] - 2 * '0' + carry;
            carry = (temp > 9) ? 1 : 0;
            c.number = to_string(temp % 10) + c.number;
        }

        if (carry)
        {
            c.number = to_string(carry) + c.number;
        }
    }

    else if ((sign =='-') && (anotherDec.sign == '-'))
    {
        int carry = 0;
        for (int i = number.size() - 1; i >= 0; i--)
        {
            int temp =number[i] + anotherDec.number[i] - 2 * '0' + carry;
            carry = (temp > 9) ? 1 : 0;
            c.number = to_string(temp % 10) + c.number;
        }

        if (carry)
        {
            c.number = to_string(carry) + c.number;
        }
        c.number = '-' + c.number;

    }


    else if (sign == '+' and anotherDec.sign == '-'){
        anotherDec.sign = '+';
        c = d - anotherDec;

    }

    else if (sign == '-' and anotherDec.sign == '+')
    {
        d.sign = '+';
        c = anotherDec - d;
    }

    return c;
}


BigInt BigInt:: operator- (BigInt& anotherDec)
{
    BigInt c;
    BigInt d;
    d.number = number;
    d.sign = sign;
    StrSize(anotherDec);
    if (sign == '+' and anotherDec.sign == '+')
    {
        if (number >= anotherDec.number)
            for(int i = number.size()-1 ; i >= 0  ;i--)
            {
                int borrow = 0;
                int temp = 0;
                if (number[i] >= anotherDec.number[i]){
                    temp = number[i] - anotherDec.number[i];
                    c.number = to_string(temp) + c.number;
                }

                else{
                    if (number[i-1] >= '1')
                    {
                        borrow = 10;
                        number[i-1] = char((number[i-1] -  '1') + '0');
                        temp = (borrow + number[i]) - anotherDec.number[i];
                        c.number = to_string(temp) + c.number;
                    }

                    else{

                    }

                }
            }

        else{
            c.number = number;
            number = anotherDec.number;
            anotherDec.number = c.number;
            c.number = "";
            for(int i = number.size()-1 ; i >= 0  ;i--)
            {
                int borrow = 0;
                int temp = 0;
                if (number[i] >= anotherDec.number[i]){
                    temp = number[i] - anotherDec.number[i];
                    c.number = to_string(temp) + c.number;
                }

                else{
                    borrow = 10;
                    number[i-1] = char((number[i-1] -  '1') + '0');
                    temp = (borrow + number[i]) - anotherDec.number[i];
                    c.number = to_string(temp) + c.number;
                }
            }
            c.number = '-' + c.number;
        }

    }

    else if (sign == '+' and anotherDec.sign == '-'){
        anotherDec.sign = '+';
        c = d + anotherDec;
    }


    else if (sign == '-' and anotherDec.sign == '+'){
        anotherDec.sign = '-';
        c = d + anotherDec;


    }

    else
    {
        number = anotherDec.number;
        anotherDec.number = d.number;

        if (number >= anotherDec.number)
            for(int i = number.size()-1 ; i >= 0  ;i--)
            {
                int borrow = 0;
                int temp = 0;
                if (number[i] >= anotherDec.number[i]){
                    temp = number[i] - anotherDec.number[i];
                    c.number = to_string(temp) + c.number;
                }

                else{
                    borrow = 10;
                    number[i-1] = char((number[i-1] -  '1') + '0');
                    temp = (borrow + number[i]) - anotherDec.number[i];
                    c.number = to_string(temp) + c.number;
                }
            }

        else{
            c.number = number;
            number = anotherDec.number;
            anotherDec.number = c.number;
            c.number = "";
            for(int i = number.size()-1 ; i >= 0  ;i--)
            {
                int borrow = 0;
                int temp = 0;
                if (number[i] >= anotherDec.number[i]){
                    temp = number[i] - anotherDec.number[i];
                    c.number = to_string(temp) + c.number;
                }

                else{
                    borrow = 10;
                    number[i-1] = char((number[i-1] -  '1') + '0');
                    temp = (borrow + number[i]) - anotherDec.number[i];
                    c.number = to_string(temp) + c.number;
                }
            }
            c.number = '-' + c.number;
        }


    }

    return c;
}

bool BigInt:: operator< (const BigInt& anotherDec)   // a < b
{
    bool check = false;
    //int n = number.size(), m = anotherDec.number.size();

    if (sign == '+' )
    {
        if(anotherDec.sign == '+')
        {
            if (number < anotherDec.number)
                check = true;
        }
        else if (anotherDec.sign == '-')
            check = true;

    }

    else if (sign == '-')
    {
        if(anotherDec.sign == '-')
        {
            if (number > anotherDec.number)
                check = true;
        }

        else
            check = true;
    }

    return check;

}
bool BigInt:: operator>(const BigInt& anotherDec)
{
    bool check = true;
    BigInt temp;
    temp.number = number;
    temp.sign = sign;
    if(temp < anotherDec)
    {
        check = false;
    }

    return check;
}


bool BigInt:: operator== (const BigInt& anotherDec)
{
    if((this->number == anotherDec.number )&&( this->sign == anotherDec.sign))
    {
        return true;
    }

    return false;
}

BigInt &BigInt::operator=(const BigInt &anotherDec)
{   sign = anotherDec.sign;
    number = anotherDec.number;
    return *this;
}

int BigInt:: size(){
    return number.size();
}


ostream &operator<<(ostream &out, const BigInt& num)
{
    out << num.sign << num.get_num();
    return out;
}