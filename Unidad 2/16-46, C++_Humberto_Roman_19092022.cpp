#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std; // hace que std :: cout se accesible como "cout"

int cout()// declara nuestra propia funcion "cout"
{
	return 5;
}

int main(int argc, char** argv) {
	//Error de compilacion ¿Que cout queremos aqui? ¿el del espacio de nombres standar o el que definimos anteriormente?
	cout << "¡Hola, mundo!";
	
	return 0;
}

