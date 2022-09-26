#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//int es el tipo de retorno
//Un tipo de retorno de int significa que la funcion devolvera algun valor entero a la persona que llama (el valor especifico)
int returnFive()
{
	//la declaracion de retorno indica el valor especifico que se devolverá
	return 5; //devuelve el valor especifico 5 a la persona que llama
}

int main(int argc, char** argv) {
	std :: cout << returnFive() << '\n'; //impreme 5
	std :: cout << returnFive() + 2 << '\n'; // imprime 7
	returnFive(); //bien: se devuelve el valor 5, pero se ignora ya que main () no hace nada con el
	return 0;
}
