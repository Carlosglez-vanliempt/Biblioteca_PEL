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

using namespace std;

//Funciones Declaradas

void crearFichero(string);
void escribirEnFichero(string,string);
void leerFicheroLogin();
int contarfilas(string);
int contarcolumnas(string);



//------------------------------------------------------------------------------------

int main(){

    int opcionInicioSesion;
    std::ifstream archivo ("login.txt");
        string dni;
        string nombre;
        string apellido;
        string contraseña;
        string matrizLogin[0][1];
    do{
        cout<<"\n\n\n------------ La Biblioteca ------------"<<endl
                <<"-Bienvenido!" <<endl
                <<"1 - Iniciar sesión"<<endl
                <<"2 - Registrase"<<endl
                <<"3 - Salir"<<endl
                <<"-->";
               // contarfilas("login.txt");
            cin >> opcionInicioSesion;

        switch (opcionInicioSesion)
        {
        case 1:
        if(!archivo.is_open()){
             escribirEnFichero("login","DNI;contraseña");
        }  
             cout<<"\n\n\n------------ La Biblioteca ------------"<<endl
        <<"\tLogin"<<endl
        <<"DNI:"<<endl
        <<"->;";
        cin>>matrizLogin[1][1];
        leerFicheroLogin();
        cout<<"\n\n\n------------ La Biblioteca ------------"<<endl
        <<"\tLogin"<<endl
        <<"Contraseña:"<<endl
        <<"->";
       // cin>>contraseña;
            break;
        case 2:
        cout<<"\n\n\n------------ La Biblioteca ------------"<<endl
        <<"\tRegister"<<endl
        <<"Usuario:"<<endl
        <<"->";
       // cin>>usuario;
        cout<<"\n\n\n------------ La Biblioteca ------------"<<endl
        <<"\tRegister"<<endl
        <<"Contraseña:"<<endl
        <<"->";
       // cin>>contraseña;

            break;
         case 3:
            cout<<"Hasta luego...";
            break;
        default:
            cout<<"Valor incorrecto..., Revise.";
            break;
        }

    }while(!opcionInicioSesion==3);


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
    ifstream archivo;
    string fichero[2][1];

    archivo.open(nombreArchivo,ios::in);
    if(archivo.fail()){cout<<"No se pudo leer el archivo";exit(1);}

}

int contarfilas(string nombreArchivo){
    ifstream archivo;
    int contador=0;
    archivo.open(nombreArchivo,ios::in);
    if(archivo.fail()){cout<<"No se ha podido contar las filas del archivo";exit(1);}
    while(archivo.eof()){
        contador++;
    }
    cout<<contador;
    return contador;
}