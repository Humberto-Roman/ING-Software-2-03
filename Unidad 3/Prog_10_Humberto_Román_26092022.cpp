#include <iostream>

int getUserInput()
{
	std::cerr << "llamada a getUserInput() \n";
	std::cout << "Ingrese un n�mero: ";
	int x{};
	std::cin >> x;
	return x;
}

int main()
{
	std::cerr << "llamada a main()\n";
	int x{ getUserInput() };
	std::cout << "Usted ingres�: " << x;
	
	return 0;
}

