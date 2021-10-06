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

void escribirEnFichero();

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

//------------------------------------------------------------------------------------

int main(){
    bool salirMenuMain = false;
    int opcionMenuMain;
    do{
        cout<<"\n\n\n------------ La Biblioteca ------------"<<endl
                <<"0 - Listado de Libros" 
                <<"1 - Listado de Usuarios"
                <<"3 - Historial de Lectura";

    }while(!salirMenuMain==false);

   // escribirEnFichero();
 cout<<"Hola Mundo\n";

 return 0;
}