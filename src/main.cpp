/* 
    CARLOS GONZÁLEZ VAN LIEMPT - JUAN CARLOS JIMÉNEZ  --  | La Biblioteca |   --   

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

using namespace std;

//Funciones Declaradas

void escribirEnFichero();



//------------------------------------------------------------------------------------

int main(){
    int opcionInicioSesion;
    do{
        cout<<"\n\n\n------------ La Biblioteca ------------"<<endl
                <<"-Bienvenido!" <<endl
                <<"1 - Iniciar sesión"<<endl
                <<"2 - Registrase"<<endl
                <<"3 - Salir"<<endl
                <<"-->";
            cin >> opcionInicioSesion;

        switch (opcionInicioSesion)
        {
        case 1:
            
            break;
        case 2:
            
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

void escribirEnFichero(){
    ofstream archivo;

    archivo.open("libros.txt",ios::out);

    if(archivo.fail()){
        cout<<"No se pudo abrir el archivo";
        exit(1);
    }
    archivo<<"El Quijote de la mancha";

    archivo.close();
}