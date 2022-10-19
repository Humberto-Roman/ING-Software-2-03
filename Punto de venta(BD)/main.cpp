#include <iostream>
#include <stdlib.h>
#include <conio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int x, op, caj{0};
float y;
using namespace std;

int main() {
	string cajeros[5], clientes[100][4], regiventas[100][5];
	cajeros[1] = "Román Zamora José Humberto";
	cajeros[2] = "Filomenos Acosta";
	cajeros[3] = "Perla Janeth";
	cajeros[4] = "Paola Guadalupe";
	cajeros[5] = "Bety Sinmas";
	do{
		cout<<"Cajero: "; cin >> caj; cout<<"\n";
	}while(caj <=0 or caj >5);
	CoutMenu:
	system("cls");
	cout<<"Bienvenido a OXXO le atiende: " << cajeros[caj] << "\n\n";
	cout<<"__________________\n";
	cout<<"|Menu de opciones|\n";
	cout<<"==================\n";
	cout<<"| 1-Venta a clientes | 2-Lista de clientes | 3-Registro de ventas | 4-Inventario | 5-Recepcion de proveedor | 6- Corte de caja |\n\n";
	cout<<"Opcion: "; cin>> op; cout << "\n";
	switch(op)
		{
			case 1: break;
			case 2: break;
			case 3: break;
			case 4: break;
			case 5: break;
			case 6: break;
			default: op = 0; cout << "Opcion no disponible, presione cualquier tecla para continuar \n"; goto CoutMenu;  getch(); break; 
		}
}
