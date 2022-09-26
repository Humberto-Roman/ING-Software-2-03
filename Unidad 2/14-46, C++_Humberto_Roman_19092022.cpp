#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int add (int x, int y) // xey se crean e ingresan el alcance aqui
{
	// xey son visibles / utilizables solo dentro de esta funcion
	return x + y;
}// "y" y "x" salen del alcance y se destruten aqui

int main(int argc, char** argv) {
	int a{5}; //a se crea, se inicializa y entra al alcance aqui
	int b{6}; //b se crea, se inicializa y entra al alcance aqui
	
	// a y b solo se pueden usar dentro de esta funcion
	std :: cout << add (a, b) << '\n'; // llama a la funcion add () con x = 5 e y = 6
	
	return 0;
} // a y b salen del alcance y se destruyen aqui
