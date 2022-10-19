
// A structure and functions to handle very
// long integers
// Author:  Mohammad El-Ramly
// Date:    15 May 2022
// Version: 1.0

#ifndef BIGINT_BIGINT_H
#define BIGINT_BIGINT_H


#include <bits/stdc++.h>
#include <regex>
#include <iomanip>

using namespace std;

class BigInt {
private:
    string number;
    char sign;
public:
    //bool is_valid(string b);

    BigInt (string &num );
    BigInt (int n );
    BigInt();
    bool is_valid(string &b);

    string  get_num() const;
    string& StrSize(BigInt& a);
    BigInt operator+ (BigInt& anotherDec);
    BigInt operator- (BigInt& anotherDec);
    bool operator< (const BigInt& anotherDec);
    bool operator>(const BigInt& anotherDec);
    BigInt&operator=(const BigInt&anotherDec);
    bool operator== (const BigInt& anotherDec);
    int size();

//    BigInt operator= (BigInt& anotherDec);

    friend ostream& operator<< (ostream& a,  const BigInt& num);

};


ostream& operator<< (ostream& a,  const BigInt& num);

#endif //BIGINT_BIGINT_H
