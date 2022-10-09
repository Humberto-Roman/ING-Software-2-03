#include <iostream>

int main()
{
	std::cout << "Ingrese un caracter: ";
	
	char ch{};
	std::cin >> ch;
	std::cout << ch << " tiene el código ASCII " << static_cast<int>(ch) << '\n';
	
	return 0;
}
