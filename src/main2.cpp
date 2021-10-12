#include <iostream>
#include <string>
#include<fstream>

using namespace std;

void escribir();

int main(){
escribir();
}

void escribir(){
    ofstream archivo;       //dato - variable 

    string nombrearchivo;
string usuario, DNI;


cout << "\t\t  ¿QUE NOMBRE QUIERE PARA EL ARCHIVO? " ;
getline(cin, nombrearchivo);

    archivo.open(nombrearchivo.c_str(), ios::out);  //abrinedo archivo, si no existe es creado 
                                            // gracias al punto c_str se copia el nombre del archivo que el usuario quiera       

    if(archivo.fail()){                                 //por si ocurrer un error al crearse el archivo
        cout<<"NO SE PUDO ABRIR EL ARCHIVO";
        exit(1);
    }

    cout << "\t\t --- LOGIN USUARIO --- " << endl;
    cout << "\t\t Nombre y Apellidos: "<< endl;
getline(cin,usuario);
archivo<<usuario;
archivo<<";";
cout << "\t\t Intruduzca el DNI: "<< endl;
getline(cin, DNI);
archivo<<DNI;
    archivo.close()  ;       //cerrar archivo
}