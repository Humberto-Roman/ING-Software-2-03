#include <iostream>// para std:: cout

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void doB()
{
	std::cout << "En doB \n";
}
void doA()
{
	std::cout <<"Iniciando doA () \n";
	doB();
	std::cout <<"Finalizando doA () \n";
}
//Definicion de la funcion main()
int main(int argc, char** argv) {
	std::cout <<"Iniciando main () \n";
	doA();
	std::cout <<"Finalizando main() \n";
	return 0;
}
