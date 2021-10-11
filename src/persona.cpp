#include <iostream>

using namespace std;

class persona
{
private:
    string dni;
    string nombre;
    string apellidos;
    string email;
    string contraseña;
public:
    persona(string,string,string,string,string);
    ~persona();
};

persona::persona(string _dni, string _nombre, string _apellidos, string _email, string _contraseña)
{
    dni=_dni;
    nombre=_nombre;
    apellidos=_apellidos;
    email=_email;
    contraseña=_contraseña;
}

persona::~persona()
{
}
