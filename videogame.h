#ifndef VIDEOGAME_H
#define VIDEOGAME_H
#include "civilizacion.h"
#include<vector>
#include<algorithm>

class Videogame
{
string user;
vector<Civilizacion> vec;
    public:
    Videogame();
    void setUser(string nom);
    string getUser();

    //metodos Civilizacion
    void agregar(const Civilizacion& c); 
    void insertar(size_t p, const Civilizacion& c);
    void crear(size_t n, const Civilizacion& c);
    void print();

    Civilizacion* primera();
    Civilizacion* ultima();
    size_t total();

    void ordenarByNombre();
    void ordenarByUbx();
    void ordenarByUby();
    void ordenarByPoint();

    void eliminar(const string& nombre);
    Civilizacion* buscar(const string& nombre);

};
Videogame::Videogame()
{
    user = " ";
}

void Videogame::print()
{
    if(total() == 0){
        cout<<"Sin civilizaciones"<<endl;
    } else {
    cout << left;
    cout << setw(8) << "Nombre";
    cout << setw(6) << "UB.X";
    cout << setw(6) << "UB.Y";
    cout << setw(7) << "Puntos";
    cout << endl;
    for(size_t i=0;i<vec.size();i++){
        Civilizacion& c = vec[i];
        cout<<c;
    }   
    }
}
void Videogame::setUser(string nom)
{
    user = nom;
}
string Videogame::getUser()
{
    return user;
}
void Videogame::agregar(const Civilizacion& c)
{
    vec.push_back(c);
}
void Videogame::insertar(size_t p, const Civilizacion& c)
{
    vec.insert(vec.begin()+p, c);
}
void Videogame::crear(size_t n, const Civilizacion& c)
{
    vec = vector<Civilizacion>(n,c);
}
Civilizacion* Videogame::primera()
{
    if(vec.size() == 0){
        return nullptr;
    } else {
        return &vec.front();
    }
}
Civilizacion* Videogame::ultima()
{
    if(vec.size() == 0){
        return nullptr;
    } else {
        return &vec.back();
    }
}
size_t Videogame::total()
{
    return vec.size();
}
void Videogame::ordenarByNombre()
{ 
    sort(vec.begin(),vec.end(),[](Civilizacion c, Civilizacion k)
    {return c.getNombre() < k.getNombre();});
}
void Videogame::ordenarByUbx()
{
    sort(vec.begin(),vec.end(),[](Civilizacion c, Civilizacion k)
    {return c.getUbx() < k.getUbx();});
}
void Videogame::ordenarByUby()
{
    sort(vec.begin(),vec.end(),[](Civilizacion c, Civilizacion k)
    {return c.getUby() < k.getUby();});
}
void Videogame::ordenarByPoint()
{
    sort(vec.begin(),vec.end(),[](Civilizacion c, Civilizacion k)
    {return c.getPoint() > k.getPoint();});
}
void Videogame::eliminar(const string& nombre)
{
    for(size_t i=0;i<vec.size();i++){
        Civilizacion& c = vec[i];
        if(nombre == c.getNombre()){
            vec.erase(vec.begin()+i);
        }
    }   
}
Civilizacion* Videogame::buscar(const string& nombre)
{
    //auto it = find(vec.begin(),vec.end(),nombre);
    for(size_t i=0;i<vec.size();i++){
        Civilizacion& c = vec[i];
        if(nombre == c.getNombre()){
            return &c;
        }
    }
    return nullptr; 
}


#endif