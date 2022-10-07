#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string>

using namespace std;

int tablaCuentas[100][3], op{0}, opc{0}, ops{0};
string vecmov[6];

int main() 
{
//establezco valores de modenas aleatorios en la matriz (pregunta: se puede con base de datos en access?)
         for(int i = 1; i <= 100; ++i)
         {
         	tablaCuentas[i][1] = i;
         	tablaCuentas[i][2] = 10000 - i;
         	tablaCuentas[i][3] = 10000 + rand()% 20000;
		 }
	while (op != 2)
	{
		int nCuenta{0}, clave{0}, a{0}, x{0}, y{0};
	 	cout << "Bienvenido al cajero automático\n";
		cout << "Ingrese El Numero de cuenta: "; cin >> nCuenta; cout << "\n";
// verificamos que la cuenta este dentro de los margenes de la matriz
		while(nCuenta > 100 or nCuenta < 1)
		{
			cout << "¡Numero de cuenta invalido! (Cuenta limite 100) \n";
			cout << "Ingrese El Numero de cuenta: "; cin >> nCuenta; cout << "\n";	
		}
		cout << "Cuenta correcta\n\n";
		cout << "Ingrese la clave: ";
		cin >> clave;
//Buscamos que la clave concuerde con la cuenta
		while (clave != tablaCuentas[nCuenta][2])
			{
			 a = a + 1;
	   		 cout << "Clave incorrecta le quedan  " << 4 - a << " intentos";
			 cout << " Ingrese la clave: "; cin >> clave; cout << "\n";
			 if (a == 3)
			 {
			 	clave = tablaCuentas[nCuenta][2];
			 	cout << "intentos agotados \n";
			 }	 
			}
	   		
// En caso de pasar los 2 filtros anteriores damos por hecho que es un acceso idoneo.
			if(a < 3)
			{cout << "Bienvenido al cajero usuario: " <<tablaCuentas[nCuenta][1]<<"\n";
				do 
				{
					cout << "\n |1) Retiro |2) Deposito | 3) Consulta de saldo |4) cambio de nip | 5)Transferencias | 6)Revisar los movimientos |  7)Salir  |\n";
					cout << "Que operacion requiere: "; cin >> ops;
				   	switch ( ops )
				   	{
// Retiro
					    case 1:
					        cout << "Cual es la cantidad a retirar?: $"; cin >> y; cout << "\n";
					        while (y > (tablaCuentas[nCuenta][3]) or y < 0)
							{
								cout << "\n No cuenta con saldo suficiente de otro valor: "; cin >> y; cout << "\n";
							}
							cout<<"Retiro exitoso de "<< y << " pesos"; cout << "\n";
							tablaCuentas[nCuenta][3] = tablaCuentas[nCuenta][3] - y;
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
						while (x < 0)
							{cout << "Cuanto quiere depositar?: "; cin >> x;
			            	cout << "\n";}
			            	cout<<" Deposito exitoso de "<< x << " pesos";
			            	tablaCuentas[nCuenta][3] = tablaCuentas[nCuenta][3] + x;
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
		         			cout << "Su saldo actual es: $"<<tablaCuentas[nCuenta][3] << "\n\n";
		            	break;
//Cambio de nip   
		            	case 4:
		            		cout<< "ingrese su antiguo Nip: "; cin >> x; cout << "\n";
		            		a = 0;
		            		while(x != tablaCuentas[nCuenta][2])
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
								tablaCuentas[nCuenta][2] = y;
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
					   	 	while (x > 100 or x < 1)
							{
								cout << "\n Cuenta no valida: "; cin >> x;
								cout << "\n";
							}
					    	cout << "Cual es la cantidad a transferir?: "; cin >> y;
					    	cout << "\n";
					    	while (y > (tablaCuentas[nCuenta][3]) or y < 0)
							{
								cout << "\n No cuenta con saldo suficiente de otro valor: "; cin >> y; cout << "\n";
							}
							cout<<"Transferencia exitosa de  "<< y << " pesos a la cuenta " << x; cout << "\n";
							tablaCuentas[x][3] = tablaCuentas[x][3] + y;
							tablaCuentas[nCuenta][3] = tablaCuentas[nCuenta][3] - y;
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
			                            vecmov[5] = "";
										vecmov[4] = "";
										vecmov[3] = "";
										vecmov[2] = "";
										vecmov[1] = "";
// preguntamos si quiere acceder a otra cuenta
			cout<<"Desea acceder a otra cuenta?: [1-Si 2-No]"; cin >> op; cout << "\n";
			system("cls");
	}
// Con return detenemos la ejecución del programa
    		return 0;
	}
