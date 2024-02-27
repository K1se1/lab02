#include<iostream>
#include<vector>
#include<string>

//Класс для работы с большими числами
class BigInt
{
private:
    std::vector<bool> number;
    long size;
public:
    void resize(const long& n);
    long get_size() const;
    BigInt();
    BigInt(const long long& num);
    BigInt(const long long& num, const int& s);
    BigInt(const BigInt& num);
    bool  getbit(const long& num) const;
    void print() const;
    void reverse();
    void add_ignor_overflow(const BigInt& num); 
     std::string decode();
    BigInt& operator+=(const BigInt& num);
    BigInt& operator>>(const int& num);
    BigInt& operator<<(const int& num);
    BigInt operator-() const;
    BigInt& operator=(const BigInt& num);
    BigInt& operator *=(const BigInt& num);
    BigInt operator +(const BigInt& num);
    BigInt operator * (const BigInt& num);
};