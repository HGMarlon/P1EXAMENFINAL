#include "ClsmenuMantenimientos.h"

#include<conio.h>
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<cstdlib>
#include<cstring>
#include<ctime>

#include<ClsEntrenador.h>
#include<ClsEquipo.h>
#include<ClsPais.h>
#include<ClsTipoJugador.h>
#include<ClsTipoPuesto.h>
#include<ClsmenuMantenimientos.h>

using namespace std;

ClsmenuMantenimientos::ClsmenuMantenimientos()
{
    //ctor
}

ClsmenuMantenimientos::mmenuMantimientos()
{
    int found=0;
    int choice2;
    do
    {
        system("cls");
        //Menu segundo nivel
        cout<<"-------------------------------"<<endl;
        cout<<" |   SISTEMA DE MANTENIMIENTO |"<<endl;
        cout<<"-------------------------------"<<endl;
        cout<<"1. CRUD entrenadores"<<endl;
        cout<<"2. CRUD equipo"<<endl;
        cout<<"3. CRUD pais"<<endl;
        cout<<"4. CRUD tipo jugador"<<endl;
        cout<<"5. CRUD tipo puesto"<<endl;
        cout<<"0. Volver al menu principal"<<endl;
        cout<<"-------------------------------"<<endl;
        cout<<"Opcion a escoger:[1/2/3/4/5/0]"<<endl;
        cout<<"-------------------------------"<<endl;
        cout<<"Ingresa tu Opcion: ";
        cin>>choice2;
        switch(choice2)
        {
        case 1:
            {

                ClsEntrenador entrenador;
                entrenador.mmenuEntrenador();

            }
            break;
        case 2:
            {
                ClsEquipo equipo;
                equipo.mmenuEquipo();

            }
            break;
        case 3:
            {
                 ClsPais pais;
                pais.mmenuPais();
            }
            break;
        case 4:
            {

            }
            break;
        case 5:
            {

            }
            break;
        case 6:
            {

            }
            break;
        case 7:
            {

            }
            break;
        case 0:
            {

            }
            break;
        default:
            cout<<"numero ingresado no válido, intente de nuevo.";
            getch();
            break;
        }
    }while(choice2!=0);
}

ClsmenuMantenimientos::~ClsmenuMantenimientos()
{
    //dtor
}
