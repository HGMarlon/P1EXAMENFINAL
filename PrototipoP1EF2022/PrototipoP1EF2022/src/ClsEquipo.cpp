#include "ClsEquipo.h"

#include<conio.h>
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<cstdlib>
#include<ctime>
#include<string.h>

#include "ClsmenuMantenimientos.h"

using namespace std;

ClsEquipo::ClsEquipo(string snombreEquipo, int iclaveEquipo)
{
    //ctor
    mestablecerNombreEquipo(snombreEquipo);
    mestablecerClaveEquipo(iclaveEquipo);
}

int ClsEquipo::mobtenerClaveEquipo() const
{
    return m_iID_Equipo;
}

void ClsEquipo::mestablecerClaveEquipo (int ienteroClaveEquipo)
{
    m_iID_Equipo = ienteroClaveEquipo;
}

string ClsEquipo::mobtenerNombreEquipo() const
{
    return m_sNombre;
}

void ClsEquipo::mestablecerNombreEquipo( string scadenaNombreEquipo )
{
   // copiar a lo más 20 caracteres de la cadena en nombree
   const char *svalorNombreEquipo = scadenaNombreEquipo.data();
   int ilongitudEquipo = strlen( svalorNombreEquipo );
   ilongitudEquipo = ( ilongitudEquipo < 20 ? ilongitudEquipo : 19 );
   strncpy( m_sNombre, svalorNombreEquipo, ilongitudEquipo );

   // anexar caracter nulo al final del nombre
   m_sNombre[ ilongitudEquipo ] = '\0';

}


ClsEquipo::mcrearEquipo()
{
    ofstream archivoEquipo("registrosequipo.dat", ios::out | ios::binary);
    if(!archivoEquipo)
    {
        cerr<<"No se abrio el archivo"<<endl;
        exit(1);
    }
    ClsEquipo equipoEnBlanco;
    for(int i=0; i<100; i++)
    {
        archivoEquipo.write(reinterpret_cast<const char * > (&equipoEnBlanco), sizeof(ClsEquipo));
    }
}

int ClsEquipo::mobtenerIndicadorEquipo(const char * const iindicadorEquipo)
{
    int m_iID_Equipo;

   // obtener el valor del número de cuenta
   do {
      cout << iindicadorEquipo << " (1 - 100): ";
      cin >> m_iID_Equipo;

   } while ( m_iID_Equipo < 1 || m_iID_Equipo > 100 );

   return m_iID_Equipo;
}


void ClsEquipo::mnuevoEquipo(fstream &archivoEquipo)
{
   ClsEquipo equipo;
   int m_iID_Equipo = mobtenerIndicadorEquipo( "Escriba el numero de equipo" );

   // desplazar el apuntador de posición del archivo hasta el registro correcto en el archivo
   archivoEquipo.seekg(
      ( m_iID_Equipo - 1 ) * sizeof( ClsEquipo ) );

   // leer el registro del archivo
   archivoEquipo.read( reinterpret_cast< char * >( &equipo ),
      sizeof( ClsEquipo ) );

   // crear el registro, si éste no existe ya
   if ( equipo.mobtenerClaveEquipo() == 0 ) {

      char m_sNombre[20];

      // el usuario introduce el nombre
      cout << "Escriba el nombre del Equipo: " << endl;
      cin >> setw( 20 ) >> m_sNombre;

      // usar valores para llenar los valores de la clave
      equipo.mestablecerNombreEquipo( m_sNombre );

      // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
      archivoEquipo.seekp( ( m_iID_Equipo - 1 ) *
         sizeof( ClsEquipo ) );

      // insertar el registro en el archivo
      archivoEquipo.write(
         reinterpret_cast< const char * >( &equipo ),
         sizeof( ClsEquipo ) );

        cout << "Equipo agregado con exito.";

   }

   // mostrar error si la cuenta ya existe
   else
   {
       cerr << "El equipo #" << m_iID_Equipo << " ya contiene informacion." << endl;
       getch();
   }
}

void ClsEquipo::mostrarLineaEquipo( const ClsEquipo &registro )
{
       cout << left << setw( 10 ) << registro.mobtenerClaveEquipo()
          << setw( 20 ) << registro.mobtenerNombreEquipo().data()
          << endl;
}


void ClsEquipo::mconsultarRegistroEquipo(fstream &archivoEquipo)
{
   cout << left << setw( 20 ) << "Nombre del equipo" << setw( 10 )
   << "Numero de equipo" << endl;

   // colocar el apuntador de posición de archivo al principio del archivo de registros
   archivoEquipo.seekg( 0 );

   // leer el primer registro del archivo de registros
   ClsEquipo equipo;
   archivoEquipo.read( reinterpret_cast< char * >( &equipo ),
      sizeof( ClsEquipo ) );

   // copiar todos los registros del archivo de registros en el archivo de texto
   while ( !archivoEquipo.eof() ) {

      // escribir un registro individual en el archivo de texto
      if ( equipo.mobtenerClaveEquipo() != 0 )
         mostrarLineaEquipo(equipo);

      // leer siguiente registro del archivo de registros
      archivoEquipo.read( reinterpret_cast< char * >( &equipo ),
         sizeof( ClsEquipo ) );

   }
}

void ClsEquipo::mmostrarLineaRegistroEquipo( ostream &salida, const ClsEquipo &registro )
{
       salida << left << setw( 10 ) << registro.mobtenerClaveEquipo()
          << setw( 20 ) << registro.mobtenerNombreEquipo().data()
          << endl;
}

void ClsEquipo::mmodificarRegistroEquipo( fstream &archivoEquipo )
{

   ClsEquipo equipo;
   int m_iID_Equipo = mobtenerIndicadorEquipo("Ingrese el nombre del equipo");

   archivoEquipo.seekg(
      ( m_iID_Equipo - 1 ) * sizeof( ClsEquipo ) );

   // leer el primer registro del archivo
   archivoEquipo.read( reinterpret_cast< char * >( &equipo ),
      sizeof( ClsEquipo ) );

   // actualizar el registro
   if ( equipo.mobtenerClaveEquipo() != 0 ) {
      mmostrarLineaRegistroEquipo( cout, equipo );

      cout << "\nEscriba el Nombre del Banco: ";
      char m_sNombre[20];
      cin >> m_sNombre;

     // actualizar el saldo del registro
      equipo.mestablecerNombreEquipo( m_sNombre );
      mmostrarLineaRegistroEquipo( cout, equipo );

      // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
      archivoEquipo.seekp(
         ( m_iID_Equipo - 1 ) * sizeof( ClsEquipo ) );

      // escribir el registro actualizado sobre el registro anterior en el archivo
      archivoEquipo.write(
         reinterpret_cast< const char * >( &equipo ),
         sizeof( ClsEquipo ) );

        cout << "Equipo modificado con éxito.";

   } // fin de instrucción if

   // mostrar error si la cuenta no existe
   else
      cerr << "El equipo #" << m_iID_Equipo << " no tiene informacion." << endl;
}

void ClsEquipo::meliminarRegistroEquipo(fstream &archivoEquipo)
{
    int iindicadorEquipo= mobtenerIndicadorEquipo( "Escriba el equipo a eliminar" );

   // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
   archivoEquipo.seekg(
      ( iindicadorEquipo - 1 ) * sizeof( ClsEquipo ) );

   // leer el registro del archivo
   ClsEquipo equipo;
   archivoEquipo.read( reinterpret_cast< char * >( &equipo ),
      sizeof( ClsEquipo ) );

   // eliminar el registro, si es que existe en el archivo
   if ( equipo.mobtenerClaveEquipo() != 0 ) {
      ClsEquipo equipoEnBlanco;

      // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
      archivoEquipo.seekp( ( iindicadorEquipo - 1 ) *
         sizeof( ClsEquipo ) );

      // reemplazar el registro existente con un registro en blanco
      archivoEquipo.write(
         reinterpret_cast< const char * >( &equipoEnBlanco ),
         sizeof( ClsEquipo ) );

      cout << "El equipo #" << iindicadorEquipo << " eliminada correctamente.\n";

   }

   // mostrar error si el registro no existe
   else
   {
       cerr << "La Cuenta #" << iindicadorEquipo << " esta vacia.\n";
   }
   getch();
}

ClsEquipo::mmenuEquipo()
{
    string codigo;
    fstream abrir;
    int found=0;


    int iseleccionMenuBancos;
    do
    {
        system("cls");
        // abrir el archivo en modo de lectura y escritura
        fstream archivoEquipo("registrosequipo.dat", ios::in | ios::out | ios::binary);
        // salir del programa si fstream no puede abrir el archivo
        if ( !archivoEquipo )
            {
                cerr << "No se pudo abrir el archivo." << endl;
                mcrearEquipo();
                cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo";
                exit ( 1 );

            }

        cout<<"-------------------------------"<<endl;
        cout<<"|  SISTEMA GESTION EQUIPO |"<<endl;
        cout<<"-------------------------------"<<endl;
        cout<<"1. Ingreso Equipo"<<endl;
        cout<<"2. Despliegue Equipo"<<endl;
        cout<<"3. Modifica Equipo"<<endl;
        cout<<"4. Borrar Equipo"<<endl;
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

                system("cls");
                mnuevoEquipo(archivoEquipo);
                getch();
            }
            break;
        case 2:
            {

                system("cls");
                mconsultarRegistroEquipo(archivoEquipo);
                cout << "Fin del archivo.";
                getch();
            }
            break;
        case 3:
            {

                system("cls");
                mmodificarRegistroEquipo(archivoEquipo);
                getch();
            }
            break;
        case 4:
            {

                system("cls");
                meliminarRegistroEquipo(archivoEquipo);
                getch();
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

ClsEquipo::~ClsEquipo()
{
    //dtor
}
