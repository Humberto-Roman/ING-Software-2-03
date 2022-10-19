#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string>

int x, xf{100}, op, caj, cant, prod, proid[10], producpre[10], producex[10];
float y;
using namespace std;



void lclientes()
{
	system("cls");
	cout<<"Lista de clientes:\n";
	cout<<"=================\n";
}
void regisventas()
{
	string regiventas[100][5];
	system("cls");
	cout<<"Registro de ventas\n";
	cout<<"==================\n";
	for(int i = 1; i <= 100; i++)
	{
		cout<< regiventas[i][1] << regiventas[i][2] << regiventas[i][3] << regiventas[i][4] << regiventas[i][5];
	}
}
void inventario()
{
	system("cls");
	cout<<"Realiza el inventario \n";
}
void proveedores()
{
	system("cls");
	cout<<"Resibe proveedor \n";
}
void cortecaja()
{
	system("cls");
	cout<<"Corte de caja \n";
}

int main() {
	string cajeros[5], clientes[100][4], regiventas[100][5], prodes[10], listcompra[xf][5];
	cajeros[1] = "Román Zamora José Humberto";
	cajeros[2] = "Filomenos Acosta";
	cajeros[3] = "Perla Janeth";
	cajeros[4] = "Paola Guadalupe";
	cajeros[5] = "Bety Sinmas";
	//			 |id|					|Descripcion|				   |Precio|		 	 |Existencia|
	  	proid[1] = 1;	 prodes[1] = "Coca Cola 600ml";	   producpre[1] = 16; 	 producex[1] = 50;
	  	proid[2] = 2;	 prodes[2] = "Malboro Rojos 20S";  producpre[2] = 63; 	 producex[2] = 20;
	  	proid[3] = 3;	 prodes[3] = "Vapurub 80 grs";	   producpre[3] = 18; 	 producex[3] = 20;
	  	proid[4] = 4; 	 prodes[4] = "Condones sico 3 pz"; producpre[4] = 63; 	 producex[4] = 20;
	  	proid[5] = 5; 	 prodes[5] = "Halls Gold";		   producpre[5] = 10; 	 producex[5] = 10;
	  	proid[6] = 6; 	 prodes[6] = "Ciel 1L";			   producpre[6] = 12; 	 producex[6] = 40;
	  	proid[7] = 7; 	 prodes[7] = "Tonayan 440ml"; 	   producpre[7] = 23; 	 producex[7] = 20;
	 	proid[8] = 8; 	 prodes[8] = "Tonayan 960ml"; 	   producpre[8] = 33; 	 producex[8] = 15;
	  	proid[9] = 9; 	 prodes[9] = "Cafe Americano ch";  producpre[9] = 20; 	 producex[9] = 60;
	  proid[10] = 10; 	prodes[10] = "Capuchino ch"; 	  producpre[10] = 24; 	producex[10] = 60;
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
			case 1: system("cls");
					cout<<"Bienvenido a OXXO \n\n";
					cout<<"Que va a llevar?: \n";
					cout<<"| ID | Descripcion | precio |\n";
					for (int i = 1; i <= 10; i++)
					{
						cout<<proid[i]<<prodes[i]<<producpre[i] << "\n";
					}
					cout<<"0: Cerrar Venta / 11: cancelar";
					do 
					{
					cin >> prod; cout << prodes[prod] << "\n";
					} while (prod >= 1 and prod < 11);
					if (prod = 0)
					{	}
					else if (prod = 11)
					{	}
					break;
			case 2: lclientes(); break;
			case 3: regisventas(); break;
			case 4: inventario(); break;
			case 5: proveedores(); break;
			case 6: cortecaja(); break;
			default: op = 0; cout << "Opcion no disponible, presione cualquier tecla para continuar \n"; getch(); goto CoutMenu; break; 
		}
	return 0;
}
