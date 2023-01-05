#include <iostream>
#include <conio.h>

using namespace std;

int idprod{0}, idcli{0};
float nucredito{10000}, abo{0.00}, totalcom{0.00}, CortecajaTotal{0.00};

struct prod{
	int id;
	string nomprod;
	float prec;
	int invcant;
}invprod[100];

struct prods{
	int id;
	string nomprod;
	float prec;
	int invcant;
}invprodres[100];

struct regis{
	int id;
	string nomprod;
	float prec;
	int cant;
	float subtotal;
}registeel[100];
struct clients{
	int id;
	string nombre;
	string numtel;
	float credit;
}clientes[100];

struct compra{
	int id;
	string nomprod;
	float prec;
	int cant;
	float subtotal;
}lcompra[100];

void ventapro()
{
	for(int i = 1; i <= 100; i++)
	{
		invprodres[i].id 		= invprod[i].id;
		invprodres[i].nomprod 	= invprod[i].nomprod;
		invprodres[i].prec		= invprod[i].prec;
		invprodres[i].invcant	= invprod[i].invcant;
	}
reini:
	int x{1}, y{1}, op{0}, opp{0}, cant;
	idprod = 0; 
	cout<<"||Venta de productos|| 0 = cerrar venta \n" << endl;
	cout<<"Que producto quiere llevar? (id): "; cin >> idprod; cout << endl;
	if(idprod == 0)
	{
		goto salirci;
	}
	while(invprod[x].id > 0)
	{
		if(idprod = invprod[x].id)
		{
			lcompra[y].id = invprod[x].id;
			lcompra[y].nomprod = invprod[x].nomprod;
			lcompra[y].prec = invprod[x].prec;
remuestra:
			cout<< lcompra[y].id << " | " << lcompra[y].nomprod << " | " << lcompra[y].prec << " | " << endl 
			<< "cuanto quiere llevar?: "; cin >> cant; cout << endl;
			while(cant >invprod[x].invcant or cant < 0)
			{	
				if (cant >invprod[x].invcant)
				{cout << "Cantidad en stock insuficiente \n\n";}
				if (cant < 0)
				{cout << "La cantidad no puede ser negativa \n\n";}
				goto remuestra;
			}
			
			lcompra[y].cant = lcompra[y].cant + cant;
			lcompra[y].subtotal = lcompra[y].cant * lcompra[y].prec;
			y = y + 1;
			goto reini;
		}
		x = x + 1;
	}
salirci:
	x = 0;
	while(lcompra[x].id > 0)
	{
		cout<< lcompra[x].id << " | " << lcompra[x].nomprod << " | " << lcompra[x].prec << " | " << lcompra[x].cant << " | " << lcompra[x].subtotal << endl;
		x = x + 1;
	}	
// damos a elegir si quiere cerrar la orden de una vez
	cout << "-------------------- \n";
	cout << "1-cerrar orden\n";
	cout << "2-modificar orden\n";
	do{
		cout << "todo en orden?: "; cin >> op; cout << endl << endl;
	}while(op <= 0 or op >= 3);
//editamos orden:
	if(op == 1)
	{
		goto cerrar;
	}
	if(op == 2)
	{	x = 1;
		while(lcompra[x].id > 0)
		{
			cout<< lcompra[x].id << " | " << lcompra[x].nomprod << " | " << lcompra[x].prec << " | "; cin>> lcompra[x].cant; lcompra[y].subtotal = lcompra[y].cant * lcompra[y].prec;
			cout << " | " << lcompra[x].subtotal << endl;
			x = x + 1;
		}	
		goto salirci;
	}
// aplicamos los cambios a el inventario
cerrar:
	x = 1;
	while(lcompra[x].id > 0)
	{
		invprod[lcompra[x].id].invcant = invprod[lcompra[x].id].invcant - lcompra[x].cant;
		x = x + 1;
	}
	x = 1;
	while(lcompra[x].id > 0)
	{
		cout<< lcompra[x].id << " | " << lcompra[x].nomprod << " | " << lcompra[x].prec << " | " << lcompra[x].cant << " | " << lcompra[x].subtotal << endl;
		totalcom = totalcom + lcompra[x].subtotal;
		x = x + 1;	
	}
creditfail:
	cout << "Total: " << totalcom << endl;
	cout << "Metodo de pago: \n";
	cout << "1- effectivo \n";
	cout << "2- credito \n\n";
	cin >> opp; cout <<endl;
	if(opp == 1)
	{
		cout << "Que tenga un buen dia \n";
	}
	if(opp == 2)
	{
		cout << "Ingrese su id: "; cin >> idcli; cout << endl;
		cout << clientes[idcli].id << " | " << clientes[idcli].nombre << " | " << clientes[idcli].numtel << " | " << clientes[idcli].credit << endl;
		if(clientes[idcli].credit < totalcom)
		{
			cout << "Credito insuficiente \n";
			goto creditfail;	
		}
		else
		{
			clientes[idcli].credit = clientes[idcli].credit - totalcom;
			cout << "Saldo restante: " << clientes[idcli].credit << endl;
		}  
	}
	CortecajaTotal = CortecajaTotal + totalcom;
	getch();
}

void agreuser()
{	int x{1};
    string nombre{""}, numtelefono{""};
	while(clientes[x].id > 0)
	{
		x = x + 1;
	}
	clientes[x].id = x;
	cout<<"id: "<< x;
	cout<<"(Max 40 long)Nombre: "; cin >>nombre; cout << endl;
	cout<<"Numero de telefono: "; cin >>numtelefono; cout << endl << endl;
	while(numtelefono.length() < 10 or numtelefono.length() > 10)
	{
		cout<<"Longitud de telefono incorrecta \n\n";
		cout<<"Numero de telefono:"; cin >>numtelefono; cout << endl;
	}
	clientes[x].nombre = nombre.substr(0.40);
	clientes[x].numtel = numtelefono.substr(0.10);
	clientes[x].credit = nucredito;
	
	system("cls");
	cout<<"id: "<< clientes[x].id << endl;
	cout<<"Nombre: "<< clientes[x].nombre << endl;
	cout<<"Telefono: "<< clientes[x].numtel << endl;
	cout<<"Credito: "<< clientes[x].credit << endl;
	
	getch();
}

void lista_clientes()
{	int x{1}, op{0};
	cout<<"||Lista de clientes||" << endl;
	while(clientes[x].id > 0)
	{
		cout<<clientes[x].id << " | " << clientes[x].nombre << " | " << clientes[x].numtel << " | " << clientes[x].credit << endl;
		x = x + 1;
	}
	do
	{
		cout<<"Opciones: " << endl;
		cout<<"1- agregar \n";
		cout<<"2- salir \n";
	}while(op <=0 or op >=3);
	switch(op)
	{
		case 1: agreuser(); break;
		case 2: break;
	}
	getch();
}
void regigigas()
{	int x{1}, y{1};
	cout<<"||Registros de ventas||" << endl;
	while(registeel[x].id > 0)
	{
		x= x + 1;
		y = x;
	}
	x = 1;
	while(lcompra[x].id > 0)
	{
		registeel[y].id = lcompra[x].id;
		registeel[y].nomprod = lcompra[x].nomprod;
		registeel[y].prec = lcompra[x].prec;
		registeel[y].cant = lcompra[x].cant;
		registeel[y].subtotal = lcompra[x].subtotal;
		x = x + 1;
		y = y + 1;
	}
	getch();
}
void inventario()
{
	int x{1};
	cout<<"||Inventario||" << endl;
	while(invprod[x].id > 0)
	{
		cout<<invprod[x].id << " | " << invprod[x].nomprod << " | " << invprod[x].prec << " | " << invprod[x].invcant << endl;
		x = x + 1;
	}

	getch();
}
void recpro()
{	int x{1}, idp{0}, canta{0};
	cout<<"||Recibir producto||" << endl;
	cout<<"Ingrese id: "; cin >>idp; cout<< endl;
	while(invprod[x].id > 0)
	{
		if (idp = invprod[x].id)
		{
			cout<<invprod[x].id << " | " << invprod[x].nomprod << " | " << invprod[x].prec << " | " << invprod[x].invcant << endl;
			goto fina;
		}
		x = x + 1;
	}
fina:
	do{
		cout<<"Cantidad a agregar: "; cin >>canta; cout<< endl;	
		if(canta < 0)
		{
			cout << "La cantidad a agregar no puede ser negativa \n";
		}
	}while(canta < 0);
	invprod[x].invcant = invprod[x].invcant + canta;
	cout<<invprod[x].id << " | " << invprod[x].nomprod << " | " << invprod[x].prec << " | " << invprod[x].invcant << endl;
	getch();

}
void corca()
{
	cout<<"||Corte de caja||" << endl;
	cout<<"Total del corte: " << CortecajaTotal;
	CortecajaTotal = 0;
	getch();
}

int main()
{
	invprod[1].id = 1; invprod[1].nomprod  = "Coca Cola 600ml"; 	invprod[1].prec = 16; invprod[1].invcant = 50;
	invprod[2].id = 2; invprod[2].nomprod  = "Malboro Rojos 20S"; 	invprod[2].prec = 63; invprod[2].invcant = 20;
	invprod[3].id = 3; invprod[3].nomprod  = "Vapurub 80 grs"; 		invprod[3].prec = 18; invprod[3].invcant = 20;
	invprod[4].id = 4; invprod[4].nomprod  = "Condones sico 3 pz"; 	invprod[4].prec = 63; invprod[4].invcant = 15;
	invprod[5].id = 5; invprod[5].nomprod  = "Halls Gold"; 			invprod[5].prec = 10; invprod[5].invcant = 20;
	int opc{0};
	
	clientes[1].id = 1;  clientes[1].nombre = "Joaquin Lopez Doriga";  			clientes[1].numtel = "6684971325";  clientes[1].credit = nucredito;
	clientes[2].id = 2;  clientes[2].nombre = "Roman Zamora Jose Humberto";  	clientes[2].numtel = "6684196962";  clientes[2].credit = nucredito;
	clientes[3].id = 3;  clientes[3].nombre = "Elotes filomas";  				clientes[3].numtel = "6684326849";  clientes[3].credit = nucredito;
	clientes[4].id = 4;  clientes[4].nombre = "Walt Disney de Jesus";  			clientes[4].numtel = "6687495886";  clientes[4].credit = nucredito;
	clientes[5].id = 5;  clientes[5].nombre = "Harry potter de bao";  			clientes[5].numtel = "6687965481";  clientes[5].credit = nucredito;
	
reiniciomenu:	
	cout<<"Bienvenido a el abarrote express \n\n";
//Mostramos un menu con las opciones del programa
	cout<<"==================\n";
	cout<<"|Menu de opciones|\n";
	cout<<"==================\n";
	cout<<"| 1-Venta a clientes | 2-Lista de clientes | 3-Registro de ventas | 4-Inventario | 5-Recepcion de producto | 6- Corte de caja | 7- Salir |\n\n";
	cout<<"Opcion: "; cin>> opc; cout << "\n";
	switch(opc)
	{
//llamada de ventas // 2 horas
		case 1: ventapro(); system("cls"); goto reiniciomenu; break; 
//llamada a mostrar los clientes frecuentes(tambien se pueden agregar) // 3 horas
		case 2: lista_clientes(); system("cls");  goto reiniciomenu; break;
//llamada a mostrar registro de ventas // 30 minutos
		case 3: regigigas(); system("cls");  goto reiniciomenu; break;
//llamada a mostrar inventario // 15 minutos
		case 4: inventario(); system("cls");  goto reiniciomenu; break;
//llamada a recibir producto // 30 minutos
		case 5: recpro(); system("cls");  goto reiniciomenu; break;
//llamada a corte de caja // 20 minutos
		case 6: corca(); system("cls");  goto reiniciomenu; break;
//Salir del programa // 10 horas
		case 7: cout<< "Hasta luego...\n"; goto salir; break;
	}
salir:
	return 0;
}
