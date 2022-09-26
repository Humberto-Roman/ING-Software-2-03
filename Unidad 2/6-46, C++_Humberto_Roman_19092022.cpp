#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	//obtener un valor del usuario
	std::cout << "Ingrese un entero: ";
	int num{};
	std::cin >> num;
	
	//Impreme el valor duplicado
	std::cout << num << " duplicado es: " << num * 2 << '\n';
	
	return 0;
}
