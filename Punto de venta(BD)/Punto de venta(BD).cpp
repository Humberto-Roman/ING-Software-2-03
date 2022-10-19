#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string>
//Version: 0.8 Del No hay Sistema (Proxima actualizacion: promociones variables entre los dias de la semana)
//Alumno: Román Zamora José Humberto
//Ps: no cambien de tipo los datos mejor utilizar vectores
int x, xf{100}, op, caj, cant, prod, proid[10], producpre[10], producex[10], aum{0};
float y, subtotal, total;
using namespace std;


int main() {
	string cajeros[5], clientes[100][4], regiventas[100][5], prodes[10], listcompra[xf][5], nom_cli;
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
	  	proid[5] = 5; 	 prodes[5] = "Halls Gold";		   producpre[5] = 10; 	 producex[5] = 15;
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
//Especificamos quien atiende al cliente/proveedor
	cout<<"Bienvenido a OXXO le atiende: " << cajeros[caj] << "\n\n";
//Mostramos un menu con las opciones del programa
	cout<<"__________________\n";
	cout<<"|Menu de opciones|\n";
	cout<<"==================\n";
	cout<<"| 1-Venta a clientes | 2-Lista de clientes | 3-Registro de ventas | 4-Inventario | 5-Recepcion de producto | 6- Corte de caja |\n\n";
	cout<<"Opcion: "; cin>> op; cout << "\n";
	switch(op)
		{
//Ventas a clientes
			case 1: system("cls");
					cout<<"Bienvenido a OXXO \n\n";
					cout<<"Nombre de cliente: "; getline(cin, nom_cli); cout<<"\n";
					cout<<"Que va a llevar?: \n";
					cout<<"| ID | Descripcion | precio |\n";
					for (int i = 1; i <= 10; i++)
					{
						cout<<" | "<<proid[i]<<" | "<<prodes[i]<<" | "<<producpre[i] << "\n";
					}
					cout<<"0: Cerrar Venta / 11: cancelar\n";
					do 
					{
						if (prod >= 1 and prod < 11)
							{ 
							do{ if (cant > producex[prod])
								{
									cout<<"No hay suficientes existencias, elija otra cantidad(menor) \n\n";
								}
							cout<<"Cantidad: "; cin >> cant; subtotal= (producpre[prod] * cant) ;cout<<" "<< subtotal<<"\n";}
							while(cant > producex[prod]);}
						total = total + subtotal;
						prod = 0;
						cout<<"Id del producto: ";cin >> prod; cout << prodes[prod] << "\n";
					
					} while (prod >= 1 and prod < 11);
//Cierre de orden:
					if (prod == 0)
					{cout << "El total fue de: " << total << " pesos \n";
					x= x + 1;
					getch(); system("cls"); goto CoutMenu;}
//Cancelar la compra
					else if (prod == 11)
					{cout << "Se cancelo la compra, que tenga un buen dia...\n\n"; getch();	system("cls"); goto CoutMenu;}
					break; //Sera necesario este break?
//Listado de clientes
			case 2: ; break;
//Registros de ventas
			case 3: ; break;
//Inventario
			case 4: cout <<" | ID |  Descripcion  |  Precio  |  Existencias  |\n";
					for (int i = 1; i <=10; i++)
						{
							cout <<" | "<<proid[i]<<" | "<<prodes[i]<<" | "<<producpre[i]<<" | "<<producex[i]<<" | \n";
						}; getch();	system("cls"); goto CoutMenu; break;
//Recepcion de producto(reabastecimiento)
			case 5: 	cout <<" | ID |  Descripcion  |  Precio  |  Existencias  |  Aumento  |\n";
						for (int i = 1; i <=10; i++)
						{
							cout <<" | "<<proid[i]<<" | "<<prodes[i]<<" | "<<producpre[i]<<" | "<<producex[i]<<" | "; cin>> aum;cout <<" | \n";
							producex[i] = producex[i] + aum;
							aum = 0;
						} getch();	system("cls"); goto CoutMenu; break;
//Corte de caja(Lo unico que no se hacer en el oxxo :D)
			case 6: ; break;
			default: op = 0; cout << "Opcion no disponible, presione cualquier tecla para continuar \n"; getch(); goto CoutMenu; break; 
		}
	return 0;
}
