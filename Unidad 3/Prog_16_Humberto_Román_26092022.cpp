#include <iostream>

int readNumber(int x)
{
	std::cout << "Por favor ingrese un número: ";
	std::cin >> x;
	return x;
}

void writeAnswer(int x)
{
	std::cout << "La suma es: "<< x;
}

int main()
{
	int x{0};
	readNumber(x);
	x = x + readNumber(x);
	writeAnsmer(x);
	
	return 0;
}
