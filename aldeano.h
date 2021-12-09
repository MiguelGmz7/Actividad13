#ifndef ALDEANO_H
#define ALDEANO_H

#include<iostream>
#include<iomanip>
using namespace std;
#include<list>

class Aldeano
{
string nombre, genero;
int edad, salud;
public:
       Aldeano();

       //Nombre
       void setNombre(const string& a);
       string getNombre();

       //genero
       void setGenero(const string& a);
       string getGenero();

       //edad
       void setEdad(int a);
       int getEdad();

       //salud
       void setSalud(int a);
       int getSalud();

       //Sobrecarga
       friend istream& operator>>(istream& in, Aldeano& a)
        {
            cout<<"Nombre: ";
            fflush(stdin);
            cin>>a.nombre;

            cout<<"Genero: ";
            fflush(stdin);
            cin>>a.genero;

            cout<<"Edad: ";
            fflush(stdin);
            cin>>a.edad;

            cout<<"Salud: ";
            fflush(stdin);
            cin>>a.salud;

            return in;
        }
        friend ostream& operator<<(ostream& out, const Aldeano& a)
        {
            out << left;
            out << setw(8) << a.nombre;
            out << setw(6) << a.genero;
            out << setw(6) << a.edad;
            out << setw(7) << a.salud;
            out << endl;
            return out;
        }
};

Aldeano::Aldeano(){}

void Aldeano::setNombre(const string& a)
{
    nombre = a;
}

string Aldeano::getNombre()
{
    return nombre;
}

void Aldeano::setGenero(const string& a)
{
    genero = a;
}

string Aldeano::getGenero()
{
    return genero;
}

void Aldeano::setEdad(int a)
{
    edad = a;
}

int Aldeano::getEdad()
{
    return edad;
}

void Aldeano::setSalud(int a)
{
    salud = a;
}

int Aldeano::getSalud()
{
    return salud;
}
#endif