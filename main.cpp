#include<iostream>
using namespace std;
#include "videogame.h"
int main(){
    Videogame vg;
    char opc;
    while(true){
    system("cls");
    if(vg.getUser() != " "){
    cout<<"Usuario: "<<vg.getUser()<<endl;
    }
    cout<<"Menu: "<<endl;
    cout<<"a) Nombre de usuario"<<endl;
    cout<<"b) Agregar civilizacion"<<endl;
    cout<<"c) Insertar civilizacion"<<endl;
    cout<<"d) Crear civilizacion"<<endl;
    cout<<"e) Primera civilizacion"<<endl; 
    cout<<"f) Ultima civilizacion"<<endl; 
    cout<<"g) Ordenar"<<endl;
    cout<<"h) Eliminar civilizacion"<<endl;
    cout<<"i) Buscar"<<endl;
    cout<<"j) Modificar"<<endl;
    cout<<"k) Resumen"<<endl;
    cout<<"l) Salir"<<endl;
    cin>>opc;
    if(opc == 'a'){ //USER
        string nom;
        cout<<"Ingresa el nombre: ";
        cin>>nom;
        vg.setUser(nom);
    }
    else if(opc == 'b'){ //AGRARAR - PUSH_BACK
        Civilizacion c;
        cin>>c;
        vg.agregar(c);
    }
    else if(opc == 'c'){ //INSERTAR
        size_t p;
        cout<<"Ingresa la posicion: "<<endl;
        cin>>p;
        if(p>=vg.total()){
            cout<<"Posicion invalida"<<endl;
            system("pause");
        } else {
            cout<<"Posicion valida, ingresa la civilizacion:  "<<endl;
            Civilizacion c;
            cin>>c;
            vg.insertar(p,c);
        }
    }
    else if(opc == 'd'){ //CREAR
        Civilizacion c;
        size_t n;
        cin>>c;
        cout<<endl<<"Ingresar n: ";
        cin>>n; cout<<endl;
        vg.crear(n,c);
    }
    else if(opc=='e') { //PRIMERA
        Civilizacion* c = vg.primera();
        if(c == nullptr){
            cout<<"Sin civilizaciones"<<endl;
            system("pause");
        } else {
            cout<<"Direccion de memoria: " << c <<endl;
            cout << left;
            cout << setw(8) << "Nombre";
            cout << setw(6) << "UB.X";
            cout << setw(6) << "UB.Y";
            cout << setw(7) << "Puntos";
            cout << endl;
            cout<<*c<<endl;
            system("pause");
        }
    }
    else if(opc=='f'){ //ULTIMA
    Civilizacion* c = vg.ultima();
    if(c == nullptr){
            cout<<"Sin civilizaciones"<<endl;
            system("pause");
        } else {
            cout<<"Direccion de memoria: " << c <<endl;
            cout << left;
            cout << setw(8) << "Nombre";
            cout << setw(6) << "UB.X";
            cout << setw(6) << "UB.Y";
            cout << setw(7) << "Puntos";
            cout << endl;
            cout<<*c<<endl;
            system("pause");
        }
    }
    else if(opc=='g'){ //ORDENAR
        int opc;
        system("cls");
        cout<<"1) Ordenar Por Nombre"<<endl;
        cout<<"2) Ordenar Por Ubicacion en x"<<endl;
        cout<<"3) Ordenar Por Ubicacion en y"<<endl;
        cout<<"4) Ordenar Por Puntaje"<<endl;
        cout<<"Opcion: "; cin>>opc; 
        switch(opc){
        case 1: vg.ordenarByNombre(); break;
        case 2: vg.ordenarByUbx(); break;
        case 3: vg.ordenarByUby(); break;
        case 4: vg.ordenarByPoint(); break;
        default: cout<<"Opcion invalida "; system("pause"); break;
        }
    }
    else if(opc=='h'){ //ELIMINAR
        string nom;
        cout<<"Ingrese el nombre: "; cin>>nom;
        vg.eliminar(nom);
    }
    else if(opc == 'i'){ //BUSCAR
        int opc;
        string busc;
        cout<<"Buscar: "; cin>>busc;
        Civilizacion* c = vg.buscar(busc);
        if(c == nullptr){
            cout<<"Sin resultados"<<endl;
            system("pause");
        } else {
            cout<<"Direccion de memoria: " << c <<endl;
            cout << left;
            cout << setw(8) << "Nombre";
            cout << setw(6) << "UB.X";
            cout << setw(6) << "UB.Y";
            cout << setw(7) << "Puntos";
            cout << endl;
            cout<<*c<<endl;

            cout<<endl;
            cout<<"Agregar aldenos? (y/1)"<<endl;
            cin>>opc;
        if(opc == 1){
        while(true){
        system("cls");
        cout<<"Menu: "<<endl;
        cout<<"1) Agregar aldeano inicio"<<endl;
        cout<<"2) Agregar aldeano final"<<endl;
        cout<<"3) Eliminar por nombre"<<endl;
        cout<<"4) Eliminar por salud"<<endl;
        cout<<"5) Eliminar por edad de 60"<<endl;
        cout<<"6) Ordenar por Nombre"<<endl;
        cout<<"7) Ordenar por Edad"<<endl;
        cout<<"8) Ordenar por Salud"<<endl;
        cout<<"9) Buscar"<<endl;
        cout<<"10) Modificar"<<endl;
        cout<<"11) Mostar aldeanos"<<endl;
        cout<<"12) Primer alddenao"<<endl;
        cout<<"13) Ultimo aldeano"<<endl;
        cout<<"0) Salir"<<endl;
        cout<<"Opcion: "; cin>>opc;
        if(opc == 1){
            Aldeano a; cin>>a; c->agregar_inicio(a);
            int plus = c->getPoint() + 100;
            c->setPoint(plus);
        }

        else if(opc == 12){
            cout<<"Primer aldeno: "<<endl;
            cout << left;
            cout << setw(8) << "Nombre";
            cout << setw(6) << "Genero";
            cout << setw(6) << "Edad";
            cout << setw(7) << "Salud";
            cout << endl;
            cout<<*c->front()<<endl;
            system("pause");
        }

        else if(opc == 13){
            cout<<"Primer aldeno: "<<endl;
            cout << left;
            cout << setw(8) << "Nombre";
            cout << setw(6) << "Genero";
            cout << setw(6) << "Edad";
            cout << setw(7) << "Salud";
            cout << endl;
            cout<<*c->back()<<endl;
            system("pause");
        }
        
        else if(opc == 2){ 
            Aldeano a; cin>>a; c->agregar_final(a);
            int plus = c->getPoint() + 100;
            c->setPoint(plus);
        }
        
        else if(opc == 3){
            string nombre;
            cout<<"Nombre del aldeano: "; cin>>nombre;
            c->eliminarByNombre(nombre);
        }
        else if(opc == 4){
            int x;
            cout<<"Salud maxima de referencia: "; cin>>x;
            c->eliminarBySalud(x);
        }
        else if(opc == 5){
            c->eliminarByEdad();
        }
        else if(opc == 6){
            c->ordenaraNombre();
        }
        
        else if(opc == 7){
            c->ordenarByEdad();
        }
        else if(opc == 8){
            c->ordenarBySalud();
        }
        else if(opc == 9){
            string name;
            cout<<"Ingresa el nombre del aldeano: "; cin>>name;
            Aldeano* a = c->buscar_ald(name);
        if(a == nullptr){
            cout<<"Sin resultados"<<endl;
            system("pause");
        } else {
            cout<<"Direccion de memoria: " << a <<endl;
            cout << left;
            cout << setw(8) << "Nombre";
            cout << setw(6) << "Genero";
            cout << setw(6) << "Edad";
            cout << setw(7) << "Salud";
            cout << endl;
            cout<<*a<<endl;
            system("pause");
        }
        }
        else if(opc == 10){
            string name;
            cout<<"Nombre del aldeano: "; cin>>name;
            Aldeano* a = c->buscar_ald(name);
            if(a == nullptr){
            cout<<"Sin resultados"<<endl;
            system("pause");
        } else {
            int opc;
            while(opc != 5){
            system("cls");
            cout<<"   Modificar: "<<endl;
            cout<<"1) Modificar Nombre"<<endl;
            cout<<"2) Modificar Genero"<<endl;
            cout<<"3) Modificar Edad"<<endl;
            cout<<"4) Modificar Salud"<<endl;
            cout<<"5) Salir"<<endl;
            cout<<"Opcion: "; 
            cin>>opc; 
                if(opc== 1){
                string temp;
                cout<<"Nuevo nombre: "; cin>>temp;
                a->setNombre(temp);
                }

                else if(opc==2){
                string ubnx;
                cout<<"Nuevo Genero: "; cin>>ubnx;
                a->setGenero(ubnx);
                }

                else if(opc==3){
                int ubny;
                cout<<"Nueva Edad: "; cin>>ubny;
                a->setEdad(ubny);
                }

                else if(opc==4){
                int npoint;
                cout<<"Nueva Salud: "; cin>>npoint;
                a->setSalud(npoint);
                }

                else if(opc==5){
                    break;
                }
                else {
                    cout<<"Opcion no valida"<<endl; system("pause");
                }
            }
        }
        }
        
        else if(opc == 11){
            c->printald();
            system("pause");
        }
        
        else if(opc == 0){break;}
        }
    }
        }
    }
    else if(opc == 'j'){
        string name;
        cout<<"Nombre: "; cin>>name;
        Civilizacion* c = vg.buscar(name);
        if(c == nullptr){
            cout<<"Sin resultados"<<endl;
            system("pause");
        } else {
            int opc;
            while(opc != 5){
            system("cls");
            cout<<"   Modificar: "<<endl;
            cout<<"1) Modificar Nombre"<<endl;
            cout<<"2) Modificar Ubicacion en x"<<endl;
            cout<<"3) Modificar Ubicacion en y"<<endl;
            cout<<"4) Modificar Puntaje"<<endl;
            cout<<"5) Salir"<<endl;
            cout<<"Opcion: "; 
            cin>>opc; 
                if(opc== 1){
                string temp;
                cout<<"Nuevo nombre: "; cin>>temp;
                c->setNombre(temp);
                }

                else if(opc==2){
                int ubnx;
                cout<<"Nueva ubicacion en x: "; cin>>ubnx;
                c->setUbx(ubnx);
                }

                else if(opc==3){
                int ubny;
                cout<<"Nueva ubicacion en y: "; cin>>ubny;
                c->setUby(ubny);
                }

                else if(opc==4){
                float npoint;
                cout<<"Nueva puntuacion: "; cin>>npoint;
                c->setPoint(npoint);
                }

                else if(opc==5){
                    break;
                }
                else {
                    cout<<"Opcion no valida"<<endl; system("pause");
                }
            }
        }
    }
    else if(opc == 'k'){ //PRINT
        vg.print();
        system("pause");
    }
    
    else if(opc == 'l'){
        break;
    }
    }
    return 0;
}