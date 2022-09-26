#include <iostream> //para std :: cout
 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//Definicion de la funcion definida por el usuario doPrint()
void doPrint() // doPrint () es la funcion llamada en este ejemplo
{
	std:: cout << "En doPrint () \n";
}

// Definicion de la funcion main ()
int main(int argc, char** argv) {
	
	std :: cout << "Iniciando main () \n";
	doPrint (); //Interrumpe main () haciendo una llamada de función a doPrint (). main() es la persona que llama.
	std :: cout << "Finalizando main () \n"; //esta sentencia se ejecuta despues de que termine doPrint()
	
	return 0;
}
