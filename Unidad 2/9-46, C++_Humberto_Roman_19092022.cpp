#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//voud significa que la funcion no devulve un valor a la persona que llama

void returnNothing()
{
	std::cout << "Hola" << '\n';
	//Esta funcion no devuelve un valor, por lo que no necesita una declaracion de devolución
}
int main(int argc, char** argv) {
	returnNothing(); // bien: se llama a la funcion returnNothing (), no se devuelve ningun valor
	//std::cout << returnNothing (); //error: esta linea no se compilara. devera comentarlo para continuar.
	return 0;
}
