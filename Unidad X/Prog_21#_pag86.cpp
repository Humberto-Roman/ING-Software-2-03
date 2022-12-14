#include <fstream>
#include <iostream>
#include <string>

int main()
{
	std::fstream iofile{ "Sample.dat", std::ios::in | std::ios::out };
	if (!iofile)
	{
		std:: cerr << "Uh oh, Sample.dat no se puede abrir! \n";
		return 1;
	}
	char chChar{};
	while (iofile.get(chChar))
	{
		switch (chChar)
		{	//si encontramos una vocal
			case 'a': case 'e': case 'i': case 'o': case 'u':
			case 'A': case 'E': case 'I': case 'O': case 'U':
			
			iofile.seekg(-1, std::ios::cur);
			iofile << '#';
			iofile.seekg(iofile.tellg(), std::ios::beg);
			
			break;
		}
	}
	
	return 0;
}
