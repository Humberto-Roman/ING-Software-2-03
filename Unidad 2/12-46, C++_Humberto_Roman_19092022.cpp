#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void doSomething ()
{
	std :: cout << "¡Hola! \n";
}
int main(int argc, char** argv) {
	int x{0}; //la vida de x comienza aqui
	doSomething(); // x sigue vivo durante esta llamada a la función
	return 0;
} // La vida de x termina aqui
