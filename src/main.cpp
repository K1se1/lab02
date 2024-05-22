#include<iostream>
#include "../headers/BigInt.hpp"


BigInt& fact(BigInt& num, long long power)
{
	for (int i = 1; i <= power; ++i)
	{
		num *= BigInt(i);
	}
	return num;
}

BigInt& exp(BigInt &num, long long power)
{
	if (power == 0) return num = 1;
	num << power-1;
	return num;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	BigInt A(1, 128);
	BigInt B(1, 128);
	int input_1, input_2;
	std::cout << "Введите  число: "; 
	std::cin >> input_1;
	fact(A, input_1);
	std::cout << "\nФакториал: " << A.decode() << "\n";
	//////
	std::cout << "\nВведите число: ";
	std::cin >> input_1;
	A = 2;
	exp(A, input_1);
	std::cout << "2 в степени " << input_1 << ": " << A.decode() << "\n";
	///////
	std::cout << "\nВведите 1 число: ";
	std::cin >> input_1;
	std::cout << "\nВведите 2 число: ";
	std::cin >> input_2;
	A = 2;
	B = 2;
	exp(A, input_1);
	exp(B, input_2);
	A += B;
	std::cout << "2^" << input_1 <<" + 2^" <<   input_2 << " = " << A.decode() << "\n";
	/////
	std::cout << "\nВведите 1 число: ";
	std::cin >> input_1;
	std::cout << "\nВведите 2 число: ";
	std::cin >> input_2;
	A = 2;
	B = 2;
	exp(A, input_1);
	exp(B, input_2);
	A += -B;
	std::cout << "2^" << input_1 << " - 2^" << input_2 << " = " << A.decode() << "\n";
	/// 
	std::cout << "\nВведите число: ";
	std::cin >> input_1;
	//input_1 -= 1;
	A = 0;
	//A.resize(256);
	B = 1;
	//B.resize(256);
	while (input_1 != 0) // Фибоначчи
	{
		A += B;
		B = A + -B;
		--input_1;
	}
	std::cout << A.decode();

}