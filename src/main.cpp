/* 
    CARLOS GONZÁLEZ VAN LIEMPT - JUAN CARLOS SÁNCHEZ  --  | La Biblioteca |   --   

            *Requisitos
               _ Alojar 20(libros) con su info.
                   ^Tener control de que libros están disponibles o no, y saber quién los tiene
               _ Tener un registro de usuario con datos e historial
                   ^Nombre,apellidos,dni,Libro que tiene ahora, Historial,...
            *Funciones
               _Comprobar libros disponibles
               _Ver historial de libros de una persona
               _Ver si una persona tiene un libro o no
               _Sacar/Devolver Libro

*/

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

//Funciones Declaradas

void crearFichero(string);
void escribirEnFichero(string,string);
void leerFicheroLogin(string);
int contarfilas(string);
int contarcolumnas(string);



//------------------------------------------------------------------------------------

int main(){ 
    int opcionInicioSesion;
    std::ifstream archivoLogin ("login.txt");
     while(!archivoLogin.is_open()){ 
             escribirEnFichero("login.txt","DNI;contraseña");
        } 
        string dni;
        string nombre;
        string apellido;
        string contraseña;
        string matrizLogin[0][1];
        string matrizFichero[contarfilas("login.txt")][contarcolumnas("login.txt")];

    do{
        cout<<"\n\n\n------------ La Biblioteca ------------"<<endl
                <<"-Bienvenido!" <<endl
                <<"1 - Iniciar sesion"<<endl
                <<"2 - Registrase"<<endl
                <<"3 - Salir"<<endl
                <<"-->"<<endl;
                cout<<"filas:"<<contarfilas("login.txt")<<endl;
              cout<<"columnas:"<<contarcolumnas("login.txt")<<endl;

            cin >> opcionInicioSesion;

        switch (opcionInicioSesion)
        {
            
        case 1:
             cout<<"\n\n\n------------ La Biblioteca ------------"<<endl
        <<"\tLogin"<<endl
        <<"DNI:"<<endl
        <<"->;";cin>>matrizLogin[0][0];
        cout<<"\n\n\n------------ La Biblioteca ------------"<<endl
        <<"\tLogin"<<endl
        <<"Contraseña:"<<endl
        <<"->";cin>>matrizLogin[0][1];
       
            break;
        case 2:
        cout<<"\n\n\n------------ La Biblioteca ------------"<<endl
        <<"\tRegister"<<endl
        <<"Usuario:"<<endl
        <<"->";
      
        cout<<"\n\n\n------------ La Biblioteca ------------"<<endl
        <<"\tRegister"<<endl
        <<"Contraseña:"<<endl
        <<"->";
    

            break;
         case 3:
            cout<<"Hasta luego...";
            break;
        default:
            cout<<"Valor incorrecto..., Revise.";
            break;
        }

    }while(!opcionInicioSesion==1||!opcionInicioSesion==2||!opcionInicioSesion==3);


 return 0;
}

//-------------------------------------------------------------------------------------

//Funciones Definidas

void crearFichero(string nombreArchivo){
    ofstream archivo;
    archivo.open(nombreArchivo,ios::out);

    if(archivo.fail()){cout<<"No se pudo abrir el archivo";exit(1);}
}

void escribirEnFichero(string nombreArchivo,string texto){
    ofstream archivo;

    archivo.open(nombreArchivo,ios::out);
    
    if(archivo.fail()){cout<<"No se pudo abrir el archivo";exit(1);}

      archivo.close();
}

void leerficheroLogin(string nombreArchivo){
    ifstream archivo(nombreArchivo);
    string fichero[contarfilas(nombreArchivo)][contarcolumnas(nombreArchivo)];
     if(archivo.fail()){cout<<"No se pudo leer el archivo";exit(1);}
    int i=0;
    string fila;
    string array_fila[contarcolumnas(nombreArchivo)];
    char c [30];
    while(archivo.getline(c,' ')){
        fila = archivo.get(c);
    }
   
}

int contarfilas(string nombreArchivo){
    ifstream archivo(nombreArchivo);
    int contador_lineas=0;
    char c [30];
    if(archivo.fail()){cout<<"No se ha podido contar las filas del archivo";exit(1);}
    while(archivo.getline(c,' ')){
            contador_lineas++;
    }
    archivo.close();
    return contador_lineas;
}

int contarcolumnas(string nombreArchivo)
{
    ifstream archivo(nombreArchivo);
    int contador_colunmas=0;
    char linea [30];
    archivo.getline(linea,' ');
    if(archivo.fail()){cout<<"No se ha podido contar las columnas del archivo";exit(1);}
     vector<char> v(begin(linea),end(linea));
    contador_colunmas=count(v.begin(),v.end(),';');
    contador_colunmas++;
    return contador_colunmas;

}