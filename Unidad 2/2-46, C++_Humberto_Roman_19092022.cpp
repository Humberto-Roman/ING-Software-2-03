#include <iostream> //para std :: cout
 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void doPrint()
{
	std:: cout << "En doPrint () \n";
}

// Definicion de la funcion main ()
int main(int argc, char** argv) {
	
	std :: cout << "Iniciando main () \n";
	doPrint (); // doPrint () llamado por primera vez
	doPrint (); // doPrint () llamado por segunda vez
	std :: cout << "Finalizando main () \n"; //esta sentencia se ejecuta despues de que termine doPrint()
	
	return 0;
}
