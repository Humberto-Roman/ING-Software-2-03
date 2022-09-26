#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
// x no esta dentro del alcance en ninguna parte de esta función
void doSomething()
{
	std :: cout << "¡Hola! \n";
}

int main(int argc, char** argv) {
	// x no se puede usar aqui porque aun no esta dentro del alcance
	int x {0}; // x ingresa al alcance aqui y ahora se puede usar
	doSomething();
	return 0;
} // x se sale del alcance aqui y ya no se puede usar
