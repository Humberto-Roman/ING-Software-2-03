#include <iomanip> // para std::setprecision ()
#include <iostream>

int main ()
{
	std :: cout << std :: setprecision (16); // muestra 16 digitos de precisión
	std :: cout << 3.333333333333333333333333333333333333f << '\n';
	std :: cout << 3.33333333333333333333333333333333333333 << '\n';
	return 0;
}
