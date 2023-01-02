#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>

using namespace std;

int tablaCuentas[11][4], clim{10}; 
int x{1}, y{0}, op{0}, opc{0}, ops{0}, tempo;
string vecmov[6], userli, temps, overtext;

ifstream archivo;

void datmat()
{
	while(getline(archivo, userli))
	{
	//	cout << "Numero de cuenta \n";
		tablaCuentas[x][1] = stoi(userli.substr(0,9));
	//	cout << "Pin  \n";
		tablaCuentas[x][2] = stoi(userli.substr(12,4));
	//	cout << "Money  \n";
		tablaCuentas[x][3] = stoi(userli.substr(19,10));
		x += 1;
	//	cout<<userli<<endl;
	}
}
void leertxt()
{	
	archivo.open("Regis_Bank_2.txt",ios::in);
	if(archivo.is_open())
	{
		datmat();
		archivo.close();
	}
	else
	{
		cout<<"Lo siento no se encontro el archivo...";
	}
}
void guardar()
{
	ofstream archivo2("Regis_Bank_2.txt");
	for(int i= 1; i<= clim; ++i)
		{
		overtext += to_string(tablaCuentas[i][1]);
		overtext += " | ";
		overtext += to_string(tablaCuentas[i][2]);
		overtext += " | ";
		temps = to_string(tablaCuentas[i][3]);
		tempo = 10 - temps.length();
		for (int i = 1; i <= tempo; i++)
		{
			overtext += '0';
		}
		overtext += to_string(tablaCuentas[i][3]);
		overtext += '\n';  
		}
	archivo2 << overtext;
}

void mosta()
{
	for(int i= 1; i<= clim; ++i)
	{
		cout<<tablaCuentas[i][1]<<" "<<tablaCuentas[i][2]<<" "<<tablaCuentas[i][3]<<endl;  
	}
}

int main() 
{
	leertxt();
	mosta();
/*establezco valores de modenas aleatorios en la matriz
         for(int i = 1; i <= 50; ++i)
         {
         	tablaCuentas[i][1] = i;
         	tablaCuentas[i][2] = 50 - i;
         	tablaCuentas[i][3] = 10000 + rand()% 20000;
		 }
*/
	while (op != 2)
	{
		int nCuenta{0}, clave{0}, a{0}, lim{1}, cuPass, trPass;
	 	cout << "Bienvenido al cajero automatico\n";
		cout << "Ingrese El Numero de cuenta: "; cin >> nCuenta; cout << "\n";
verific:
// verificamos que la cuenta este dentro de los margenes de la matriz
		for(int i= 1; i<= clim; ++i)
		{
			if (nCuenta == tablaCuentas[i][1])
			{
				cuPass = i;
				goto correct;
			}
		}
		{
			cout << "¡Numero de cuenta invalido!\n";
			cout << "Ingrese El Numero de cuenta: "; cin >> nCuenta; cout << "\n";
			goto verific;	
		}
correct:
			cout << "Cuenta correcta\n\n";
			//cout <<tablaCuentas[cuPass][2] << endl << endl;
			cout << "Ingrese la clave: ";
			cin >> clave;
			if(clave == tablaCuentas[cuPass][2])
			{
				goto npass;
			}
//Buscamos que la clave concuerde con la cuenta
		while (clave != tablaCuentas[cuPass][2])
			{
			 a = a + 1;
	   		 cout << "Clave incorrecta le quedan  " << 4 - a << " intentos";
			 cout << " Ingrese la clave: "; cin >> clave; cout << "\n";
			 if (a == 3)
			 {
			 	cout << "intentos agotados \n";
			 	goto npass;
			 }	 
			}
npass:
// En caso de pasar los 2 filtros anteriores damos por hecho que es un acceso idoneo.
			if(a < 3)
			{cout << "Bienvenido al cajero usuario: " <<tablaCuentas[cuPass][1]<<"\n";
				do 
				{
					cout << "\n |1) Retiro |2) Deposito | 3) Consulta de saldo |4) cambio de nip | 5)Transferencias | 6)Revisar los movimientos |  7)Salir  |\n";
					cout << "Que operacion requiere: "; cin >> ops;
				   	switch ( ops )
				   	{
// Retiro
					    case 1:
					        cout << "Cual es la cantidad a retirar?: $"; cin >> y; cout << "\n";
					        while (y > (tablaCuentas[cuPass][3]))
							{
								cout << "\n No cuenta con saldo suficiente de otro valor: "; cin >> y; cout << "\n";
							}
							cout<<"Retiro exitoso de "<< y << " pesos"; cout << "\n";
							tablaCuentas[cuPass][3] = tablaCuentas[cuPass][3] - y;
//desplazamos en el vector la descripción del movimiento
									if (vecmov[1] != "")
									{
										vecmov[5] = vecmov[4];
										vecmov[4] = vecmov[3];
										vecmov[3] = vecmov[2];
										vecmov[2] = vecmov[1];
										vecmov[1] = "";
									}
//agregamos al vector la descripción del movimiento
								if (vecmov[1] == "")
								{
									vecmov[1] = "La cuenta ";
									vecmov[1] += to_string(nCuenta);
									vecmov[1] += " retiro: ";
									vecmov[1] += to_string(y);
								}
							break;
//Deposito
						case 2: 
							cout << "Cuanto quiere depositar?: "; cin >> x;
			            	cout << "\n";
			            	cout<<" Deposito exitoso de "<< x << " pesos";
			            	tablaCuentas[cuPass][3] = tablaCuentas[cuPass][3] + x;
//desplazamos en el vector la descripción del movimiento
									if (vecmov[1] != "")
									{
										vecmov[5] = vecmov[4];
										vecmov[4] = vecmov[3];
										vecmov[3] = vecmov[2];
										vecmov[2] = vecmov[1];
										vecmov[1] = "";
									}
//agregamos al vector la descripción del movimiento
								if (vecmov[1] == "")
								{
									vecmov[1] = "Se depositaron a la cuenta #";
									vecmov[1] += to_string(nCuenta);
									vecmov[1] += " ";
									vecmov[1] += to_string(x);
									vecmov[1] += " pesos";
								}
					            break;
							break;
								
			        	case 3:
		         			cout << "Su saldo actual es: $"<<tablaCuentas[cuPass][3] << "\n\n";
		            	break;
//Cambio de nip   
		            	case 4:
		            		cout<< "ingrese su antiguo Nip: "; cin >> x; cout << "\n";
		            		a = 0;
		            		while(x != tablaCuentas[cuPass][2])
							{
							 a = a + 1;
	   						 cout << "Nip incorrecta le quedan  " << 3 - a << " intentos";
							 cout << "Ingrese su antiguo nip: "; cin >> x; cout << "\n";	 
							}
		            		cout<< "ingrese su nuevo Nip (Numero de 4 digitos): "; cin >> y; cout << "\n";
		            		while(y < 0 or y >9999)
							{
	   						 cout << "Nip no aceptado";
							 cout << "Ingrese su nuevo nip: "; cin >> y; cout << "\n";	 
							}
							if (y != x)
							{
								tablaCuentas[cuPass][2] = y;
									if (vecmov[1] != "")
									{
										vecmov[5] = vecmov[4];
										vecmov[4] = vecmov[3];
										vecmov[3] = vecmov[2];
										vecmov[2] = vecmov[1];
										vecmov[1] = "";
									}
									if (vecmov[1] == "")
									{
										vecmov[1] = "El nip de la cuenta ";
										vecmov[1] += to_string(nCuenta);
										vecmov[1] += " ha cambiado ";
									}
							}
		            		break;
//Tranferencia
					    case 5:
			            	cout << "A que cuenta quiere hacer transferencia?: "; cin >> x;
			            	cout << "\n";
trverific:
							for(int i= 1; i<= clim; ++i)
							{
								if (x = tablaCuentas[i][1])
								{
									trPass = i;
									goto trcorrect;
								}
							}
								cout << "\n Cuenta no valida: "; cin >> x;
								cout << "\n";
								goto trverific;
trcorrect:
					    	cout << "Cual es la cantidad a transferir?: "; cin >> y;
					    	cout << "\n";
					    	while (y > (tablaCuentas[cuPass][3]))
							{
								cout << "\n No cuenta con saldo suficiente de otro valor: "; cin >> y; cout << "\n";
							}
							cout<<"Transferencia exitosa de  "<< y << " pesos a la cuenta " << x; cout << "\n";
							tablaCuentas[trPass][3] = tablaCuentas[trPass][3] + y;
							tablaCuentas[cuPass][3] = tablaCuentas[cuPass][3] - y;
//desplazamos en el vector la descripción del movimiento
									if (vecmov[1] != "")
									{
										vecmov[5] = vecmov[4];
										vecmov[4] = vecmov[3];
										vecmov[3] = vecmov[2];
										vecmov[2] = vecmov[1];
										vecmov[1] = "";
									}
//agregamos al vector la descripción del movimiento
								if (vecmov[1] == "")
								{
									vecmov[1] = "La cuenta ";
									vecmov[1] += to_string(nCuenta);
									vecmov[1] += " transfirio ";
									vecmov[1] += to_string(y);
									vecmov[1] += " a la cuenta ";
									vecmov[1] += to_string(x);
								}
					            break;
//Muestra los ultimos 5 movimientos
					    case 6:
					        for (int i = 1; i <= 5; i++)
					        {
					         	cout << "Mov #"<< i << " " << vecmov[i] << "\n";
							}
							cout << "Presione cualquier tecla para continuar... \n";
							getch();
					        break;
					    case 7:
					        opc = 2;
					        system("cls");
					        cout << "Hasta a luego"; cout << "\n"; getch();
					        break;
					    default:
					    cout << "No ha seleccionado ninguna opcion se saldra del sistema"; getch(); return 0;
						break;
					    }
					    if (ops != 7)
					    {
					    cout << "\n";
					    cout<<"Desea hacer otra accion? [1-Si 2-No]: "; cin >> opc; cout << "\n";
					    system("cls");
						}
					    
				    }while(opc != 2);
				}
			op = 2;      
// preguntamos si quiere acceder a otra cuenta
			cout<<"Desea acceder a otra cuenta?: [1-Si 2-No]"; cin >> op; cout << "\n";
			system("cls");
	}
	guardar();
// Con return detenemos la ejecución del programa
    		return 0;
	}
