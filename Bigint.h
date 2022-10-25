// bigint with oop
// Author: abdelrahman elsayed korany mohamed , farah walid ahmed , marwan mohamed abdelmonem
// ID's:                  20210222            ,       20210290    ,         20210378
// Date: 24 october 2022
// Version: 4.0

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

    bool is_valid(string &b);
    BigInt (string &num );
    BigInt (int n );
    BigInt();


    string  get_num() const;
    string& StrSize(BigInt& a);
    BigInt operator+ (BigInt& anotherDec);
    BigInt operator- (BigInt& anotherDec);
    bool operator< ( BigInt& anotherDec);
    bool operator>( BigInt& anotherDec);
    BigInt&operator=(const BigInt&anotherDec);
    bool operator== (const BigInt& anotherDec);
    int size();
    int Sign();




    friend ostream& operator<< (ostream& a,  const BigInt& num);

};

bool can_borrow(string &num,int i);
bool remove_zeros_from_left(string &num);
ostream& operator<< (ostream& a,  const BigInt& num);

#endif //BIGINT_BIGINT_H
