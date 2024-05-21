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
    void resize(const long& n); // меняем  битовый размер
    long get_size() const; // Получаем размер числа
    BigInt();
    BigInt(const long long& num);
    BigInt(const long long& num, const int& s);
    BigInt(const BigInt& num);
    bool  getbit(const long& num) const; // получаем бит числа
    void print() const; // функция вывода 
    void reverse(); // инвертируем биты числа 
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