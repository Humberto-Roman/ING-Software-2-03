#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
// add() toma dos enteros como parametros y devuelve el resultado de su suma
// Los valores de x e y están determinados por la funcion que llama a add()
int add (int x, int y)
{
	return x + y;
}

//mian no toma parámetros
int main(int argc, char** argv) {
	
	std::cout<< add (4, 5) << '\n'; // Los argumentos 4 y 5 se pasan a la función add ()
	return 0;
}
