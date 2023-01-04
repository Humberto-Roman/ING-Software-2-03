#include <iostream>
using std::cout;
using std::cin;
using std::endl;
 
#include <cstring>
using std::string;
 
#include <cstdlib> 

void menu();                                      
void Ingresar(struct Datos Persona[],int,int);
void Mostrar(struct Datos Persona[],int);           
void ImprFicha(struct Datos Persona[],int,int);
void Buscar(struct Datos Persona[],int);          
void BuscaFicha(struct Datos Persona[],int);      
void BuscaNombre(struct Datos Persona[],int);   
void Modificar(struct Datos Persona[],int);
void Eliminar(struct Datos Persona[],int);
  

struct Cuando
{
    string Hacer;
};
 
struct Datos
{
    string Asunto;
    string Descripcion;
 
    Cuando Fecha;
};

int main()
{
    const int LEN = 2;   
 
    Datos Persona[LEN];  
 
    int index = 0;  
    int opcion;     
    bool salir;     
 
    do
    {
        menu(); 
 
        cout << "Elija la opcion: "<<endl;
        cin >> opcion;
        cin.ignore();
 
        switch (opcion)    
        {
            case 1:
                    system("clear");
                    Ingresar(Persona,index,LEN);
                    index++;
                    break;
            case 2:
                    system("clear");
                    Mostrar(Persona,index); 
                    break;
            case 3:
                    system("clear");
                    Buscar(Persona,index);
                    break;
            case 4:
                    system("clear");
                    Modificar(Persona,index);
                    break;
            case 5:
                    system("clear");
                    Eliminar(Persona,index);
                    break;
            case 6:
                    salir = true;
                    break;
            default:
                    system("clear");
                    cout << "Ingrese Opcion valida\n\n";
                    break;
        }
    }while(salir == false);
 
    return 0;
}

void menu()
{
    cout << "TRELLO "<<endl<<endl;
 
    cout << " 1. CREAR NOTA." << endl;
    cout << " 2. MOSTRAR NOTAS." << endl;
    cout << " 3. BUSCAR NOTA." << endl;
    cout << " 4. MODIFICAR NOTA." << endl;
    cout << " 5. ELIMINAR NOTA." << endl;
    cout << " 6. SALIR." << endl;
}

void Ingresar(struct Datos Persona[], int numero, int TAM)  
{
    if(numero < TAM)  
    {
        cout << " Igresar Datos De la Nota: #" << numero << endl << endl;
 
        cout << " ASUNTO: ";
        getline(cin,Persona[numero].Asunto);
        cout << " DESCRIPCION: ";
        getline(cin,Persona[numero].Descripcion);
        cout << " FECHA (DD/MM/AAAA): ";
        getline(cin, Persona[numero].Fecha.Hacer);
        cout << endl << endl;
    }
    else
        cout << "LLEGO AL LIMITE DE NOTAS" << endl << endl;
}

void ImprFicha(struct Datos Persona[], int x) 
{
    cout << "Nota: #" << x << endl << endl;
    cout << " Asunto: " << Persona[x].Asunto << endl;
    cout << " Descripcion: " << Persona[x].Descripcion << endl;
    cout << " Fecha (DD/MM/AAAA): " << Persona[x].Fecha.Hacer;
    cout << endl << endl;
}

void Mostrar(struct Datos Persona[], int numero)
{
    for(int i=0 ; i<numero ; i++)
    {
        ImprFicha(Persona,i);    
    }
    cin.get();       
    system("clear");  
}

void Buscar(struct Datos Persona[], int numero)
{
    bool exit;  
    do
    {   
        cout << "\t BUSQUEDA: \n\n";
        cout << " 1. # Nota" << endl;
        cout << " 2. Asunto" << endl;
        cout << " 3. SALIR" << endl << endl;
 
        unsigned int op;
        cout << " Indique Opcion: ";
        cin >> op;
        cin.ignore();
        cout << endl;
 
        switch(op)
        {
            case 1:
                system("clear");
                BuscaFicha(Persona,numero); 
                break;
            case 2:
                system("clear");
                BuscaNombre(Persona,numero); 
                break;
            case 3:
                exit = true;
                break;
 
            default:
                cout << "ERROR, DIGITE OPCION CORRECTA\n";
                break;
        }
    }while(exit == false);
 
    system("clear");     
}

void BuscaFicha(struct Datos Persona[], int numero)
{
    cout << "\t Busqueda por Nota: \n\n";
 
    unsigned int Nota;
    cout << " Digite # Nota: ";
    cin >> Nota;
    cin.ignore();
    cout << endl;
 
    for(int i=0 ; i<numero ; i++)
    {
        if(Nota == i)
        {
            ImprFicha(Persona,i);
        }
    }
    cin.get();       
    system("clear");  
}

void BuscaNombre(struct Datos Persona[], int numero)
{
    cout << "\t Busqueda por Asunto: \n\n";
 
    string asun;
    cout << " Digite el Asunto: ";
    getline(cin,asun);
    cout <<  endl;
 
    for(int i=0 ; i<numero ; i++)
    {
        if(asun == Persona[i].Asunto)
        {
            ImprFicha(Persona,i);
        }
    }
    cin.get();
    system("clear");
}

void Modificar(struct Datos Persona[], int numero)
{
    cout << " Modificar o Editar la informacion: "<<endl<<endl;
 
    string asun;
    cout << "Digite Asunto: ";
    getline(cin,asun);
    cout << endl;
 
    for(int i=0 ; i<numero ; i++)
    {
        if(asun == Persona[i].Asunto)
        {
            ImprFicha(Persona,i);
 
            cout << " Asunto: ";
            getline(cin,Persona[i].Asunto);
            cout << " Descripcion: ";
            getline(cin,Persona[i].Descripcion);
            cout << " Fecha  (DD/MM/AAAA): ";
            getline(cin, Persona[i].Fecha.Hacer);
            cout << endl << endl;
        }
    }
}

void Eliminar(struct Datos Persona[], int numero)
{
    cout<<"Eliminar NOTA"<<endl<<endl;

    unsigned int Nota;
    cout<<"Digite # NOTA: "<<endl;
    cin>>Nota;
    cout<<endl;

    for(int i=0 ; i<numero ; i++)
    {
        if(Nota == i)
        {
            delete(Nota);
        }
    }
    cin.get();       
    system("clear");  

    
}
