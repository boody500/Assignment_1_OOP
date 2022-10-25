// bigint with oop
// Author: abdelrahman elsayed korany mohamed , farah walid ahmed , marwan ahmed abdelmonem
// ID's:                  20210222            ,       20210290    ,         20210378
// Date: 25 october 2022
// Version: 4.0

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
        num.erase(num.begin());

    }

    else
    {
        sign = '+';
    }

    number =  num;

}
BigInt::BigInt(int n) {
    string num = to_string(n) ;
    while (!is_valid(num))
    {
        cout << "invalid number,try again\n";
        cin >> num;
    }

    if ((!isdigit(num[0])))
    {
        sign = num[0];
        num.erase(num.begin());

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

bool remove_zeros_from_left(string &num)
{
    int i = 0;
    while(num[i] == '0'){
        num.erase(num.begin());
    }
    if (num.empty())
        num = "0";
    return true;

}

BigInt BigInt:: operator+ (BigInt& anotherDec)
{
    BigInt c;
    BigInt d;
    c.sign = '+';
    StrSize(anotherDec);
    d.number = number;
    d.sign = sign;

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

    else if (sign =='-' and anotherDec.sign == '-')
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
        c.sign = '-';

    }


    else if (sign == '+' and anotherDec.sign == '-'){
        anotherDec.sign = '+';
        c = d - anotherDec;
        anotherDec.sign = '-';

    }

    else if (sign == '-' and anotherDec.sign == '+')
    {
        d.sign = '+';
        sign = '+';
        c = anotherDec - d;
        sign = '-';
        d.sign = '-';


    }

    remove_zeros_from_left(c.number);
    return c;
}

bool can_borrow(string &num,int i){

    for (int j = i; j >=0 ; j--)
    {
        if (num[j] >= '1'){
            num[j] -= '1';
            num[j] += '0';
            return true;
        }
        else{
            num[j] = '9';
        }


    }
}
BigInt BigInt:: operator- (BigInt& anotherDec) {
    BigInt c;
    BigInt d;
    c.sign = '+';
    StrSize(anotherDec);
    d.number = number;
    d.sign = sign;
    if (sign == '+' and anotherDec.sign == '+')
    {
        if (number >= anotherDec.number)
            for (int i = number.size() - 1; i >= 0; i--) {

                int temp = 0;
                if (number[i] >= anotherDec.number[i]) {
                    temp = number[i] - anotherDec.number[i];
                    c.number = to_string(temp) + c.number;
                }

                else
                {
                    if (can_borrow(number, i - 1))
                    {
                        temp = number[i] + 10 - anotherDec.number[i];
                        c.number = to_string(temp) + c.number;
                    }


                }
            }

        else {
            c.number = number;
            number = anotherDec.number;
            anotherDec.number = c.number;
            c.number = "";
            for (int i = number.size() - 1; i >= 0; i--) {

                int temp = 0;
                if (number[i] >= anotherDec.number[i]) {
                    temp = number[i] - anotherDec.number[i];
                    c.number = to_string(temp) + c.number;
                }
                else
                {
                    if (can_borrow(number, i - 1))
                    {

                        temp = number[i] + 10 - anotherDec.number[i];
                        c.number = to_string(temp) + c.number;
                    }


                }
            }
            c.sign = '-';
        }

    }


    else if (sign == '+' and anotherDec.sign == '-')
    {

        anotherDec.sign = '+';
        c = d + anotherDec;
        anotherDec.sign = '-';
    }

    else if (sign == '-' and anotherDec.sign == '+')
    {

        anotherDec.sign = '-';
        c = d + anotherDec;
        anotherDec.sign = '+';


    }

    else
    {
        number = anotherDec.number;
        anotherDec.number = d.number;

        if (number >= anotherDec.number)
            for (int i = number.size() - 1; i >= 0; i--) {

                int temp = 0;
                if (number[i] >= anotherDec.number[i]) {
                    temp = number[i] - anotherDec.number[i];
                    c.number = to_string(temp) + c.number;
                } else {
                    if (can_borrow(number, i - 1)) {

                        temp = number[i] + 10 - anotherDec.number[i];
                        c.number = to_string(temp) + c.number;
                    }


                }
            }

        else {
            c.number = number;
            number = anotherDec.number;
            anotherDec.number = c.number;
            c.number = "";
            for (int i = number.size() - 1; i >= 0; i--) {

                int temp = 0;
                if (number[i] >= anotherDec.number[i]) {
                    temp = number[i] - anotherDec.number[i];
                    c.number = to_string(temp) + c.number;
                } else {
                    if (can_borrow(number, i - 1)) {
                        temp = number[i] + 10 - anotherDec.number[i];
                        c.number = to_string(temp) + c.number;
                    }


                }
            }
            c.sign = '-';
        }
    }

    remove_zeros_from_left(c.number);
    return c;

}


bool BigInt:: operator< ( BigInt& anotherDec)   // a < b
{
    StrSize(anotherDec);
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
bool BigInt:: operator>( BigInt& anotherDec)
{
    StrSize(anotherDec);
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

BigInt & BigInt::operator=(const BigInt &anotherDec)
{   sign = anotherDec.sign;
    number = anotherDec.number;
    return *this;
}

int BigInt:: size(){
    return number.size();
}

int BigInt:: Sign(){
    return sign;
}


ostream &operator<<(ostream &out, const BigInt& num)
{
    out << num.sign << num.get_num();
    return out;
}