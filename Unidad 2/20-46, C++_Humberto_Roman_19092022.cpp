#include <iostream>
#include "add.h" // Inserte el contenido de add.h en este punto. Tenga en cuenta el uso de comillas dobles aqui.

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int add(int x, int y);

int main(int argc, char** argv) {
	std::cout << "La suma de 3 y 4 es: " << add(3,4) << '\n';
	return 0;
}
