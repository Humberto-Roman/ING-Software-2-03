#include <iostream>

bool isAllowedToTakeFunRide()
{
	std::cout << "�Qu� tal alto eres? (cm)\n";
	
	double height{};
	std::cin >> height;
	
	if (height > 140.0)
		return true;
	else
		return false;
}

int main()
{
	if (isAllowedToTakeFunRide())
		std::cout << "Diviertete!\n";
	else
		std::cout << "Lo siento, eres demasiad@ peque�@.\n";
	
	return 0;
}
