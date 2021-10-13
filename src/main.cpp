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
        string matrizFichero[contarfilas("login.txt")][contarcolumnas("login.txt")];
    do{
        do{
          cout<<"\n\n\n------------ La Biblioteca ------------"<<endl
            <<"\t-> Login <-"<<endl
            <<"DNI:"<<endl
            <<"->";cin>>dni;
         cout<<"\n\n\n------------ La Biblioteca ------------"<<endl
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

        cout<<"\n\n\n------------ La Biblioteca ------------"<<endl
                <<"-Bienvenido!" <<endl
                <<"1 - Iniciar sesion"<<endl
                <<"2 - Registrase"<<endl
                <<"3 - Salir"<<endl
                <<"-->"<<endl;
            cin >> opcionInicioSesion;

        switch (opcionInicioSesion)
        {
            
        case 1:
            
            break;
        case 2:
            break;
         case 3:
          // leerFicheroLogin("login.txt");
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
   // string fichero[contarfilas(nombreArchivo)][contarcolumnas(nombreArchivo)];
     if(archivo.fail()){cout<<"No se pudo leer el archivo";exit(1);}
    char linea [128];
        while(!archivo.eof()){
            archivo >> linea;
            cout<<linea<<endl;
        }
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

char menu()
{  char opcion = '  ';
cout <<"\nDepartamento de biblioteca\n";
cout <<"\n***************\n";
   cout << "\n A) captura de libros\n";
   cout << "\n B) Buscar un libro\n";
   cout << "\n C) Muestra el inventario \n";
   cout << "\n D) Ordena los libros capturados \n";
   cout << "\n E) Salir";
   cout << "\n Dame la opcion :";  
   cin >> opcion;
   opcion = toupper(opcion);
   return opcion;
     }
 
 
void casos(int opcion)
{
  switch (opcion)
  {
     case 'A' :
          {
             captura(); 
             break ; 
          }
 
 
       case 'B' :
          {
             buscar(); 
             break ; 
          }
 
 
        case 'C' :
          {
             muestra(); 
             break ; 
          }   
 
        case 'D' :
          {
               ordena();  
 
             break ; 
          }  
          case 'E':
               {
          cout << "\n Gracias por usar nuestro programa\n"; 
              break;
              }
        default :
                {
                  cout << "\n Error en opcion \n";
                  break ;    
                 }
 
}
return;
}
 
 
void captura(){
     int P,Q; 
    int q[40];
 
     cout <<"\n Estas en la sección de captura de libros \n";
     cout <<"\n **************** \n\n";
 
      do{
         cout << "Inserta ISBN\n " ;
         cin >> biblio[40];
     if(int len = ( sizeof(40)/sizeof(biblio[0]) )){
 
            cout<<"error numero de ISBN REPETIDO!!!\n";
            }
            else{
            cout<<"hola";}
       fflush( stdin );
 
         cout<<"Quieres seguir buscando?...\n Si=1/No=0\n";
         cin>>P;
 
 
 
          }while(P != 0) ;
 
 
  system("cls");
 
  return ; 
}  
 
 
 
void buscar()
 {
     float ISBN_a_buscar = 0.0;
     int alumnos = 0 ; 
     cout <<"\n  --- Estas en la sección de busqueda de libros ---\n";
    
     cout <<"\n Inserta ISBN del libro que estas buscando: \n";
     cin >> ISBN_a_buscar; 
 
     for (int x = 0 ; x < 40 ; x++)
        {
          if ( ISBN_a_buscar == biblio[x])
             {
               ++alumnos;
             }
        }
 
 
 
   return  ; 
 
 
 
 
     }
void muestra() 
 {
     cout <<"\n Estas en la sección de muestra de captura de libros \n";
 
     cout <<"\n **************** \n";
     for (int x = 0 ; x < 40 ; x++)
        {
          cout << "\nLo capturado : " <<  biblio[x];
         }
   cout <<endl;
   system("pause");
   system("cls");
   return ;  
 
 
     }
void ordena()
{
     cout <<"\n Ordena de la forma que mas te agrade los libros capturados \n";
     cout <<"\n **************** \n";
     int aux=0;
for(int x=0; x <40 ; x++)
{
        for(int y=0;y<40-1;y++)
        {
                if (biblio[y]>biblio[y+1])
                {
                                    aux=biblio[y];
                                    biblio[y]=biblio[y+1];
                                    biblio[y+1]=aux;
                                    }
                                    }
                                    }
                                    cout <<"\nSe han ordenado en forma Ascendente\n";
for(int x=0; x >4000 ; x++)
{
        for(int y=0;y>4000-1;y++)
        {
                if (biblio[y]>biblio[y+1])
                {
                                    aux=biblio[y];
                                    biblio[y]=biblio[y+1];
                                    biblio[y+1]=aux;
                                    }
                                    }
                                    }
                                    cout <<"\nSe han ordenado en forma Descendente\n";
 
 
 
                                    return;
                                    }