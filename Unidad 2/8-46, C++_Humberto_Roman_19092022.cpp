#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int getValueFromUser() // esta funcion ahora devuelve un valor entero
{
	std::cout << "Ingrese un entero: ";
	int input{};
	std::cin >> input;
	
	return input;
}
int main(int argc, char** argv) {
	int num{getValueFromUser()}; // inicializa num con el valor de retorno de getValueFromUser ()
	std:: cout << num << " duplicado es: " << num * 2 << '\n';
	return 0;
}
