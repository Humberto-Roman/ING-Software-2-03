#include <bitset> //
#include <iostream>

int main()
{
	// std::bitset<8> queremos almacenar 8 bits
	std::bitset<8> bin1{ 0b11000101 }; //literal binario 1100 0101
	std::bitset<8> bin2{ 0xC5 }; // literal hexadecimal 0 1100 0101
	
	std::cout << bin1 << ' ' << bin2 << '\n';
	std::cout << std::bitset<4>{ 0b1010 } << '\n'; // podemos imprimir directamente de std::bitset
	
	return 0;
}
