#include <iostream>

int main()
{
	char strBuf[100];
	std::cin.getline(strBuf, 11);
	std::cout << strBuf << '\n';
	std::cout << std::cin.gcount() << " catacteres fuereon leidos" << std::endl;
	
	return 0;
}
