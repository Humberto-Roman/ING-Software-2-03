#include <iostream>

int main()
{
	std::cout << "Ingrese un numero: ";
	int value{};
	std::cin >> value;
	
	int b = 0;
	
	if((!value) != (!b))
		std::cout << "True\n";
	else
		std::cout << "False";
	return 0; 
}
