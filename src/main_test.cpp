#include <cstdlib>
#include <iostream>
#include <cctype>
#include <string>
using namespace std;
char menu();
void casos(int);
void captura();
void buscar();
void muestra() ;
void ordena();
 
int biblio[40] ;
 
int main(int argc, char *argv[])
{
        char opcion = ' ' ; 
    do{
 
    opcion= menu();
    casos(opcion);
}while (opcion!='E');  
 
    system("PAUSE");
    return EXIT_SUCCESS;
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