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
#include <stdio.h>

using namespace std;

//Funciones Declaradas

void crearFichero(string);
void escribirEnFichero(string,string);
int contarfilas(string);
int contarcolumnas(string);
char menuMain();
void casos(int);
void gestionLibros(string[20],string[20],string[20],string[20]);
void buscar();
void mostrarLibros() ;



//------------------------------------------------------------------------------------

int biblio[40] ;

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
        string matrizLogin[2];
        string linea;
        size_t posicion;
        int contador=0;
        string matrizLibros[20]={
        {"Luces_De_Bohemia"},
        {"Cien_Años_De_Soledad"},
        {"Don_Quijote_De_La_Mancha"},
        {"Historia_De_Dos_Ciudades"},
        {"El_Señor_De_Los_Anillos"},
        {"El_Principito"},
        {"El_Hobbit"},
        {"Sueño_En_El_Pabellon_Rojo"},
        {"Triple_Representativa"},
        {"Ella"},
        {"El_Codigo_De_Vinci"},
        {"El_Alquimista"},
        {"El_Guardian_Entre_El_Centeno"},
        {"El_Camino_A_Cristo"},
        {"Heidi"},
        {"Ana_De_Las_Tejas_Verdes"},
        {"Azabache"},
        {"El_Nombre_De_La_Rosa"},
        {"La_Orquidia_Azul"},
        {"Las_Polillas_Y_La_Luz"}};

        string matrizISBN[20]={
        {"8423913074"},
        {"8425536001871"},
        {"8415171803"},
        {"8416827095"},
        {"8845292614"},
        {"9788683737475"},
        {"9780044403371"},
        {"9781616120351"},
        {"9788497593120"},
        {"8495618605"},
        {"9786074716863"},
        {"0062511408"},
        {"7543321726"},
        {"9798629671299"},
        {"1603400311"},
        {"8427211902"},
        {"9788417512491"},
        {"9788490628942"},
        {"9788494315961"},
        {"9781543329704"}};

        bool matrizDisponibilidad[20]={
        {false},
        {true},
        {false},
        {false},
        {false},
        {false},
        {false},
        {true},
        {false},
        {false},
        {false},
        {false},
        {false},
        {false},
        {true},
        {true},
        {false},
        {false},
        {false},
        {false}
        };

        string matrizNombres[20]={
            {"Carlos Mendoza"},
            {""},
            {""},
            {""},
            {""},
            {""},
            {""},
            {""},
            {""},
            {""},
            {""},
            {""},
            {""},
            {""},
            {""},
            {""},
            {""},
            {""},
            {""},
            {""},

        };
        
    do{
        do{
          cout<<"\n------------ La Biblioteca ------------"<<endl
            <<"\t-> Login <-"<<endl
            <<"DNI:"<<endl
            <<"->";cin>>dni;
         cout<<"\n------------ La Biblioteca ------------"<<endl
            <<"\t-> Login <-"<<endl
            <<"Contraseña:"<<endl
            <<"->";cin>>contraseña;
        fstream archivo("login.txt");                       //hay que crear archivo
        while(getline(archivo,linea)){
         while((posicion=linea.find(";"))!=string::npos){         //caracter separador
            matrizLogin[contador]=linea.substr(0,posicion);                //para guaradar el usuario, desde el primer caracter hasta la ultima (del usuario) 
         linea.erase(0,posicion+1);   //+1 para eliminar la coma tambien 
         contador++;                  //incrementa contador
         }  
         contador=0;                 //ponemos contador a 0 porque si no empezaria desde 1 (por ejemplo)
             if(matrizLogin[contador]==dni){
               break;      //salir bucle
             }
        }
        if(matrizLogin[0]!=dni&&matrizLogin[1]!=contraseña){cout<<"Datos incorrectos";}
        
        }while(matrizLogin[0]!=dni&&matrizLogin[1]!=contraseña);

          opcionInicioSesion= menuMain();
          casos(opcionInicioSesion);
        
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
    char linea [40];
    archivo.getline(linea,' ');
    if(archivo.fail()){cout<<"No se ha podido contar las columnas del archivo";exit(1);}
     vector<char> v(begin(linea),end(linea));
    contador_colunmas=count(v.begin(),v.end(),';');
    contador_colunmas++;
    return contador_colunmas;

}

char menuMain()
{  char opcion = '  ';
cout<<"\n------------ La Biblioteca ------------\n";
cout<<"\tBienvenido!"<<endl;
cout<<"\nDepartamento de biblioteca\n";
cout<<"\n***************\n";
   cout<<"\n A) Gestion de libros\n";
   cout<<"\n B) Buscar un libro\n";
   cout<<"\n C) Muestra el inventario \n";
   cout<<"\n D) Muestra los usuarios \n";
   cout<<"\n E) Salir";
   cout<<"\n Opcion :";  
   cin>> opcion;
   opcion = toupper(opcion);
   return opcion;
     }
 
 
void casos(int opcion,string matrizISBN[20], string matrizNombres[20], string matrizDisponibilidad[20], string matrizLibros[20])
{
  switch (opcion){
        case 'A' :
             gestionLibros(matrizISBN[20],matrizNombres[20],matrizDisponibilidad[20],matrizLibros[20]); 
            break ; 
        case 'B' :
             buscar(); 
            break ; 
        case 'C' :
             mostrarLibros(); 
            break ;
        case 'D' :
            break;
        case 'E' :
            cout << "\n Hasta luego! \n Gracias por usar nuestro programa!\n";  
            break ; 
        default :
                  cout << "\n Valor invalido. Porfavor revise... \n";
            break ;    
 
}
return;
}
 
 
void gestionLibros(string matrizISBN[20][1],string matrizNombres[20][0],string matrizDisponibilidad[20][0], string matrizLibros[20][0]){
     int P,Q; 
    string ISBN_A_Buscar;
    bool encontrado=false;
     
     cout<<"\n------------ La Biblioteca ------------\n";
     cout<<"\n Estas en la seccion de gestion de libros \n";
     cout<<"\n **************** \n\n";
 
      do{
         cout << "Inserta ISBN\n " ;
         cin >> ISBN_A_Buscar;
        for(int i=0;matrizISBN[i][0].length();i++){
            while(matrizISBN[i][0]!=ISBN_A_Buscar){
                encontrado=true;
                if(matrizNombres){

                }
                
            }
            if(encontrado=false){cout<<"ISBN no encontrado en nuestra libreria.";}
            i++;
        }
       fflush( stdin );
 
         cout<<"Quieres seguir buscando?...\n Si=1/No=0\n";
         cin>>P;

          }while(P != 0) ;
  system("cls");

  return ; 
}  
 
void mostrarLibros() 
 {
     cout<<"\n Estas en la sección de muestra de captura de libros \n";
 
     cout<<"\n **************** \n";
     for (int x = 0 ; x < 40 ; x++)
        {
          cout << "\nLo capturado : " <<  biblio[x];
         }
   cout<<endl;
   system("pause");
   system("cls");
   return ;  
 
     }