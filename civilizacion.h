#ifndef CIVILIZACION_H
#define CIVILIZACION_H
#include<iostream>
using namespace std;
#include<algorithm>
#include<iomanip>

#include "aldeano.h"
#include<list>
class Civilizacion
{
list<Aldeano> list;
string nombre;
int ubx,uby;
float point;
public:
        Civilizacion();
        Civilizacion(const string& nombre, int ubx, int uby, float point);

        //Nombre
        void setNombre(const string& d);
        string getNombre();

        //Ubicacion en x
        void setUbx(int d);
        int getUbx();

        //Ubicacion en y
        void setUby(int d);
        int getUby();

        //Puntuacion
        void setPoint(float d);
        float getPoint();

        //Sobrecarga
        friend ostream& operator<<(ostream& out, const Civilizacion& c)
        {
            out << left;
            out << setw(8) << c.nombre;
            out << setw(6) << c.ubx;
            out << setw(6) << c.uby;
            out << setw(7) << c.point;
            out << endl;
            return out;
        }
        friend istream& operator>>(istream& in, Civilizacion& c)
        {
            cout<<"Nombre: ";
            fflush(stdin);
            cin>>c.nombre;

            cout<<"Ubicacion en x: ";
            fflush(stdin);
            cin>>c.ubx;

            cout<<"Ubicacion en y: ";
            fflush(stdin);
            cin>>c.uby;

            cout<<"Puntaje: ";
            fflush(stdin);
            cin>>c.point;

            return in;
        }

        //Aldeanos
        void agregar_inicio(const Aldeano& a);
        void agregar_final(const Aldeano& a);
        void eliminarByNombre(const string& nombre);
        void eliminarBySalud(int x);
        void eliminarByEdad();
        void ordenaraNombre();
        void ordenarByEdad();
        void ordenarBySalud();
        Aldeano* buscar_ald(const string& name);
        void printald();

        Aldeano* front()
        {
            return &list.front();
        }

        Aldeano* back()
        {
            return &list.back();
        }
};
Civilizacion::Civilizacion()
{
    
}
Civilizacion::Civilizacion(const string& nombre, int ubx, int uby, float point)
{
 this-> nombre = nombre;
 this-> ubx = ubx;
 this-> uby = uby;
 this-> point = point;
}
void Civilizacion::setNombre(const string& d){
    nombre = d;
}
string Civilizacion::getNombre()
{
    return nombre;
}
void Civilizacion::setUbx(int d)
{
    ubx = d;
}
int Civilizacion::getUbx()
{
    return ubx;
}
void Civilizacion::setUby(int d)
{
    uby = d;
}
int Civilizacion::getUby()
{
    return uby;
}
void Civilizacion::setPoint(float d)
{
    point = d;
}
float Civilizacion::getPoint()
{
    return point;
}
void Civilizacion::agregar_inicio(const Aldeano& a)
{
    list.push_front(a);
}

void Civilizacion::agregar_final(const Aldeano& a)
{
    list.push_back(a); 
}

void Civilizacion::eliminarByNombre(const string& nombre)
{
    for(auto it = list.begin(); it!= list.end(); it++){
        Aldeano& a = *it;
        if(nombre == a.getNombre()){
            list.erase(it);
            break;
        }
    }
}

void Civilizacion::eliminarBySalud(int x)
{
    list.remove_if([x](Aldeano a){return a.getSalud() < x;});
}

void Civilizacion::eliminarByEdad()
{
    list.remove_if([](Aldeano a){return a.getEdad() >= 60;});
}

void Civilizacion::ordenaraNombre()
{
    list.sort([](Aldeano c, Aldeano k){return c.getNombre() < k.getNombre();});
}

void Civilizacion::ordenarByEdad()
{
    list.sort([](Aldeano c, Aldeano k){return c.getEdad() > k.getEdad();});
}

void Civilizacion::ordenarBySalud()
{
    list.sort([](Aldeano c, Aldeano k){return c.getSalud() > k.getSalud();});
}

Aldeano* Civilizacion::buscar_ald(const string& name)
{
    for(auto it = list.begin(); it != list.end(); it++){
        Aldeano& a = *it;
        if(name == a.getNombre()){
            return &a;
        }
    }  
    return nullptr;
}

void Civilizacion::printald()
{
    if(list.empty()){
        cout<<"Sin aldeanos"<<endl;
    } else {
    cout << left;
    cout << setw(8) << "Nombre";
    cout << setw(6) << "Genero";
    cout << setw(6) << "Edad";
    cout << setw(7) << "Salud";
    cout << endl;
    for(auto it = list.begin(); it != list.end(); it++){

        Aldeano& a = *it;

        cout<<a;
    }  
    }
}
#endif