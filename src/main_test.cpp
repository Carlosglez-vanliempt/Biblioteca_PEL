#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    ifstream archivo("login.txt");
    string fichero [3][2];
     if(archivo.fail()){cout<<"No se pudo leer el archivo";exit(1);}
    string linea;
    int i=0;;
        while(!archivo.eof()){
            archivo >> linea;
            cout<<linea<<endl;
        }
        linea.replace(linea.begin(),linea.end(),';',' ');
        
        archivo.close();
}