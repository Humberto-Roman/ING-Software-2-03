#include <iostream>

int readNumber()
{
	std::cout << "Por favor ingrese un n�mero:";
	int x{};
	std::cin >> x;
	return x;
}

void writeAnswer(int x)
{
	std:cout << "El cociente es:" << x;
}

int main()
{
	int x{ 0 };
	int y{ 0 };
	x = readNumber();
	y = readNumber();
	writeAnswer(x/y);
	
	return 0;
}
