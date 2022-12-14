#include <fstream>
#include <iostream>
#include <string>

int main()
{
	std::ifstream inf{ "Sample.dat" };
	if (!inf)
	{
		std:: cerr << "Uh oh, Sample.dat no se puede abrir para la escritura!" << std::endl;
		return 1;
	}
	
	std::string strData;
	
	inf.seekg(5);
	std::getline(inf, strData);
	std::cout << strData << '\n';
	
	inf.seekg(8, std::ios::cur);
	std::getline(inf, strData);
	std::cout << strData << '\n';
	
	inf.seekg(-15, std::ios::end);
	std::getline(inf, strData);
	std::cout << strData << '\n';
	
	return 0;
}
