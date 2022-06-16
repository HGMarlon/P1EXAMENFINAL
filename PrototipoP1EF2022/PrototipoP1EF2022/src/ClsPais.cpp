#include "ClsPais.h"

#include<conio.h>
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<cstdlib>
#include<ctime>
#include<string.h>

#include "ClsmenuMantenimientos.h"

ClsPais::mmenuPais()
{
    string codigo;
    fstream abrir;
    int found=0;


    int iseleccionMenuBancos;
    do
    {
        system("cls");
        // abrir el archivo en modo de lectura y escritura
        fstream archivoEquipo("registrospais.dat", ios::in | ios::out | ios::binary);
        // salir del programa si fstream no puede abrir el archivo
        if ( !archivoEquipo )
            {
                cerr << "No se pudo abrir el archivo." << endl;
                mcrearPais();
                cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo";
                exit ( 1 );

            }

        cout<<"-------------------------------"<<endl;
        cout<<"|  SISTEMA GESTION PAIS |"<<endl;
        cout<<"-------------------------------"<<endl;
        cout<<"1. Ingreso Pais"<<endl;
        cout<<"2. Despliegue Pais"<<endl;
        cout<<"3. Modifica Pais"<<endl;
        cout<<"4. Borrar Pais"<<endl;
        cout<<"0. Volver al menu superior"<<endl;
        cout<<"-------------------------------"<<endl;
        cout<<"Opcion a escoger:[1/2/3/4/0]"<<endl;
        cout<<"------------------------------"<<endl;
        cout<<"Ingresa tu Opcion: ";
        cin>>iseleccionMenuBancos;
        switch(iseleccionMenuBancos)
        {
        case 1:
            {

            }
            break;
        case 2:
            {

            }
            break;
        case 3:
            {


            }
            break;
        case 4:
            {


            }
            break;

        case 0:
            {



        }
          default:
            cout<<"Opcion invalida, intenta de nuevo";
            getch();
    }
}while(iseleccionMenuBancos!=0);
}

ClsPais::~ClsPais()
{
    //dtor
}
