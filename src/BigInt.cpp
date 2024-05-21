#include "../headers/BigInt.hpp"


BigInt::BigInt()
{
    size = 64;
    number.resize(size);
}


BigInt::BigInt(const long long& num, const int& s)
{
    size = s;
    number.reserve(size);
    bool sign = num >= 0 ? 0 : 1;
    int minsize = size < sizeof(num) * 8 ? size : sizeof(num)*8;
    for (int i = 0; i < minsize; ++i)
    {
        number.push_back(num & (static_cast<long long>(1ll) << i));
    }
    for (int i = minsize; i < size; ++i)
    {
        number.push_back(sign);
    }

}

void BigInt::resize(const long& num)
{
    number.resize(num);
    size = num;
}

BigInt::BigInt(const long long& num)
{
    size = 256;
    number.reserve(size);
    bool sign = num >= 0 ? 0 : 1;
    int minsize = size < sizeof(num) * 8 ? size : sizeof(num) * 8;
    for (int i = 0; i < minsize; ++i)
    {
        number.push_back(num & (static_cast<long long>(1) << i));
    }
    for (int i = minsize; i < size; ++i)
    {
        number.push_back(sign);
    }


}

BigInt::BigInt(const BigInt& num)
{
    number = num.number;
    size = num.get_size();
}

BigInt& BigInt::operator+=(const BigInt& num)
{
    bool temp1 = 0, temp2 = 0;
    for (int i = 0; i < num.get_size(); ++i)
    {
        temp2 = number[i];
        number[i] = (number[i] ^ num.number[i]) ^ temp1;
        temp1 = temp2 && (num.number[i]) || num.number[i] && temp1 || temp2 && temp1;
    }
    return *this;
}

BigInt& BigInt::operator>>(const int& num)
{
    bool youthbit = number[size-1];
    for (int i = num; i < size; ++i)
    {
        number[i - num] = number[i];
    }
    for (int i = size - num; i < size; ++i)
    {
        number[i] = youthbit;
    }
    return *this;
}

BigInt& BigInt::operator<<(const int& num)
{
    for (int i = size - num - 1; i >= 0; --i)
    {
        number[i + num] = number[i];
    }

    for (int i = num-1; i >= 0; --i)
    {
        number[i] = 0;
    }
    return *this;
}


long BigInt::get_size() const
{
    return size;
}

void BigInt::reverse()
{
    for (int i = 0; i < size; ++i) number[i] = !number[i];
    if (number[size-1]) *this += 1;
    else *this += -1;
}

BigInt BigInt::operator-() const
{
    BigInt temp(*this);
    temp.reverse();
    return temp;
}

void BigInt::add_ignor_overflow(const BigInt& num)
{
    bool temp1 = 0, temp2 = 0;
    int last = -1;
    for (int i = 0; i < size; ++i)
    {
        temp2 = number[i];
        if (temp2 || num.number[i]) last = i;
        number[i] = (number[i] ^ num.number[i]) ^ temp1;
        //if (temp2 != number[i]) last = i;
        temp1 = temp2 && (num.number[i]) || num.number[i] && temp1 || temp2 && temp1;
    }
    if(last < size-1) number[last+1] = 0;
}

bool BigInt::getbit(const long& num) const
{
    return number[num];
}

void BigInt::print() const
{
    for (int i = size-1; i >= 0; --i)
    {
        std::cout << number[i];
    }
}


BigInt& BigInt::operator=(const BigInt& num)
{
    size = num.get_size();
    number = num.number;
    return *this;
}


std::string BigInt::decode() 
{
    BigInt temp(*this);
    unsigned long long chunk = 0;
    std::string ans = "";
    if (temp.number[size-1]) temp.reverse();
    for (int i = 0; i < size; ++i)
    {
        if (i % 64 == 0 && i != 0)
        {
            ans += std::to_string(chunk) + " + 2**" + std::to_string((i/64)*64) + " * ";
            chunk = 0;
        }
        chunk += temp.number[i] * (static_cast<unsigned long long>(1) << (i % 64));
    }
    ans += std::to_string(chunk);
    return ans;
    
}

BigInt BigInt::operator+(const BigInt& num)
{
    BigInt temp(*this);
    return temp += num;
}



//Алгоритм бута(очень медленный из-за сдвигов числа)
BigInt& BigInt::operator *=(const BigInt& num)
{
    long x = size, y = num.get_size();
    BigInt A(*this);
    A.resize(x + y + 1);
    A << y + 1;
    BigInt S(-*this);
    S.resize(x + y + 1);
    S << y + 1;
    BigInt P(num);
    P.resize(x + y + 1);
    P << 1;
    for (int i = 0; i < y; ++i)
    {
        if (P.getbit(1) ^ P.getbit(0))
        {
            if (P.getbit(0)) P.add_ignor_overflow(A);
            else P.add_ignor_overflow(S);
        }
        P >> 1;
    }
    this->resize(x + y);
    P >> 1;
    *this = P;
    return *this;


}