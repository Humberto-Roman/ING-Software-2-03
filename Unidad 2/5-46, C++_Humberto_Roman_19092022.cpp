#include <iostream> //std::cout

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void doB()
{
	std::cout << "En doB()\n";
}
void doA()
{
	std::cout << "En doA()\n";
	doB();
}

//Definicion de la función main()
int main(int argc, char** argv) {
	std::cout << "Iniciando main() \n";
	doA();
	doB();
	std::cout << "Finalizando main() \n";
	return 0;
}
