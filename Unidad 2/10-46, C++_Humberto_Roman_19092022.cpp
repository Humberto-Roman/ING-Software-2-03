#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int getValueFromUser()
{
	std :: cout << "Ingrese un entero: ";
	int input{};
	std :: cin >> input;
	
	return input;
}
int main(int argc, char** argv) {
	int x{getValueFromUser()}; // primera llamada a getValueFromUser
	int y{getValueFromUser()}; // segunda llamada a getValueFromUser
	
	std :: cout << x << " + " << y << " = " << x + y << '\n';
	
	return 0;
}
