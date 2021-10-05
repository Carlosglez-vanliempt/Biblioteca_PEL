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

int main(){
    escribirEnFichero();
 cout<<"Hola Mundo\n";
 cout<<"Esto si funciona";
 return 0;
};