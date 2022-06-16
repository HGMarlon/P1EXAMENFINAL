#include "ClsEntrenador.h"

#include<conio.h>
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<cstdlib>
#include<ctime>
#include<string.h>

#include "ClsmenuMantenimientos.h"

ClsEntrenador::ClsEntrenador(int iclaveEntrenador, string snombre1Entrenador, string snombre2Entrenador, string sapellido1Entrenador, string sapellido2Entrenador, string sfechaEntrenador,  string susuarioEntrenador)
{
    //ctor
    mestablecerClaveEntrenador(iclaveEntrenador);
    mestablecerNombre1Entrenador(snombre1Entrenador);
    mestablecerNombre2Entrenador(snombre2Entrenador);
    mestablecerApellido1Entrenador(sapellido1Entrenador);
    mestablecerApellido2Entrenador(sapellido2Entrenador);
    mestablecerFechaNacimientoEntrenador(sfechaEntrenador);
    mestablecerUsuarioEntrenador(susuarioEntrenador);

}
int ClsEntrenador:: mobtenerClaveEntrenador() const
{
    return m_iID_Entrenador;
}

void ClsEntrenador::mestablecerClaveEntrenador (int ienteroClaveEntrenador)
{
    m_iID_Entrenador = ienteroClaveEntrenador;
}

string ClsEntrenador::mobtenerNombre1Entrenador() const
{
    return m_sNombre1;
}

void ClsEntrenador::mestablecerNombre1Entrenador( string scadenaNombreEntrenador )
{
   // copiar a lo más 20 caracteres de la cadena en nombree
   const char *svalorNombreEntrenador = scadenaNombreEntrenador.data();
   int ilongitudEntrenador = strlen( svalorNombreEntrenador );
   ilongitudEntrenador = ( ilongitudEntrenador < 20 ? ilongitudEntrenador : 19 );
   strncpy( m_sNombre1, svalorNombreEntrenador, ilongitudEntrenador );

   // anexar caracter nulo al final del nombre
   m_sNombre1[ ilongitudEntrenador ] = '\0';

}

string ClsEntrenador::mobtenerNombre2Entrenador() const
{
    return m_sNombre2;
}

void ClsEntrenador::mestablecerNombre2Entrenador( string scadenaNombre2Entrenador )
{
   // copiar a lo más 20 caracteres de la cadena en nombree
   const char *svalorNombre2Entrenador = scadenaNombre2Entrenador.data();
   int ilongitudEntrenador = strlen( svalorNombre2Entrenador );
   ilongitudEntrenador = ( ilongitudEntrenador < 20 ? ilongitudEntrenador : 19 );
   strncpy( m_sNombre2, svalorNombre2Entrenador, ilongitudEntrenador );

   // anexar caracter nulo al final del nombre
   m_sNombre2[ ilongitudEntrenador ] = '\0';

}

string ClsEntrenador::mobtenerApellido1Entrenador() const
{
    return m_sApellido1;
}

void ClsEntrenador::mestablecerApellido1Entrenador( string scadenaApellido1Entrenador )
{
   // copiar a lo más 20 caracteres de la cadena en nombree
   const char *svalorApellido1Entrenador = scadenaApellido1Entrenador.data();
   int ilongitudEntrenador = strlen( svalorApellido1Entrenador );
   ilongitudEntrenador = ( ilongitudEntrenador < 20 ? ilongitudEntrenador : 19 );
   strncpy( m_sApellido1, svalorApellido1Entrenador, ilongitudEntrenador );

   // anexar caracter nulo al final del nombre
   m_sApellido1[ ilongitudEntrenador ] = '\0';

}

string ClsEntrenador::mobtenerApellido2Entrenador() const
{
    return m_sApellido2;
}

void ClsEntrenador::mestablecerApellido2Entrenador( string scadenaApellido2Entrenador )
{
   // copiar a lo más 20 caracteres de la cadena en nombree
   const char *svalorApellido2Entrenador = scadenaApellido2Entrenador.data();
   int ilongitudEntrenador = strlen( svalorApellido2Entrenador );
   ilongitudEntrenador = ( ilongitudEntrenador < 20 ? ilongitudEntrenador : 19 );
   strncpy( m_sApellido2, svalorApellido2Entrenador, ilongitudEntrenador );

   // anexar caracter nulo al final del nombre
   m_sApellido2[ ilongitudEntrenador ] = '\0';

}

string ClsEntrenador::mobtenerFechaNacimientoEntrenador() const
{
    return m_sFechaNacimiento;
}

void ClsEntrenador::mestablecerFechaNacimientoEntrenador( string scadenaFechaEntrenador )
{
   // copiar a lo más 20 caracteres de la cadena en nombree
   const char *svalorFechaEntrenador = scadenaFechaEntrenador.data();
   int ilongitudEntrenador = strlen( svalorFechaEntrenador );
   ilongitudEntrenador = ( ilongitudEntrenador < 20 ? ilongitudEntrenador : 19 );
   strncpy( m_sFechaNacimiento, svalorFechaEntrenador, ilongitudEntrenador );

   // anexar caracter nulo al final del nombre
   m_sFechaNacimiento[ ilongitudEntrenador ] = '\0';

}

string ClsEntrenador::mobtenerUsuarioEntrenador() const
{
    return m_sUsuario;
}

void ClsEntrenador::mestablecerUsuarioEntrenador( string scadenaUsuarioEntrenador )
{
   // copiar a lo más 20 caracteres de la cadena en nombree
   const char *svalorUsuarioEntrenador = scadenaUsuarioEntrenador.data();
   int ilongitudEntrenador = strlen( svalorUsuarioEntrenador );
   ilongitudEntrenador = ( ilongitudEntrenador < 20 ? ilongitudEntrenador : 19 );
   strncpy( m_sUsuario, svalorUsuarioEntrenador, ilongitudEntrenador );

   // anexar caracter nulo al final del nombre
   m_sUsuario[ ilongitudEntrenador ] = '\0';

}

ClsEntrenador::mcrearEntrenador()
{
    ofstream archivoEntrenador("registrosentrenador.dat", ios::out | ios::binary);
    if(!archivoEntrenador)
    {
        cerr<<"No se abrio el archivo"<<endl;
        exit(1);
    }
    ClsEntrenador entrenadorEnBlanco;
    for(int i=0; i<100; i++)
    {
        archivoEntrenador.write(reinterpret_cast<const char * > (&entrenadorEnBlanco), sizeof(ClsEntrenador));
    }
}

int ClsEntrenador::mobtenerIndicadorEntrenador(const char * const iindicadorEntrenador)
{
    int m_iID_Entrenador;

   // obtener el valor del número de cuenta
   do {
      cout << iindicadorEntrenador << " (1 - 100): ";
      cin >> m_iID_Entrenador;

   } while ( m_iID_Entrenador < 1 || m_iID_Entrenador > 100 );

   return m_iID_Entrenador;
}

void ClsEntrenador::mnuevoEntrenador(fstream &archivoEntrenador)
{
   ClsEntrenador entrenador;
   int m_iID_Entrenador = mobtenerIndicadorEntrenador( "Escriba el numero de Entrenador" );

   // desplazar el apuntador de posición del archivo hasta el registro correcto en el archivo
   archivoEntrenador.seekg(
      ( m_iID_Entrenador - 1 ) * sizeof( ClsEntrenador ) );

   // leer el registro del archivo
   archivoEntrenador.read( reinterpret_cast< char * >( &entrenador ),
      sizeof( ClsEntrenador ) );

   // crear el registro, si éste no existe ya
   if ( entrenador.mobtenerClaveEntrenador() == 0 ) {

        char m_sNombre1[20];
        char m_sNombre2[20];
        char m_sApellido1[20];
        char m_sApellido2[20];
        char m_sFechaNacimiento[20];
        char m_sUsuario[20];

      // el usuario introduce el nombre
      cout << "Escriba el nombre 1 del entrenador: " << endl;
      cin >> setw( 20 ) >> m_sNombre1;
      cout << "Escriba el nombre 2 del entrenador: " << endl;
      cin >> setw( 20 ) >> m_sNombre2;
      cout << "Escriba el apellido 1 del entrenador: " << endl;
      cin >> setw( 20 ) >> m_sApellido1;
       cout << "Escriba el apellido 2 del entrenador: " << endl;
      cin >> setw( 20 ) >> m_sApellido2;
      cout << "Escriba la fecha de nacimiento del entrenador: " << endl;
      cin >> setw( 20 ) >> m_sFechaNacimiento;
      cout << "Escriba el nombre de usuario del entrenador: " << endl;
      cin >> setw( 20 ) >> m_sUsuario;

      // usar valores para llenar los valores de la clave
      entrenador.mestablecerNombre1Entrenador( m_sNombre1 );
      entrenador.mestablecerNombre2Entrenador( m_sNombre2 );
      entrenador.mestablecerApellido1Entrenador( m_sApellido1 );
      entrenador.mestablecerApellido2Entrenador( m_sApellido2 );
      entrenador.mestablecerFechaNacimientoEntrenador( m_sFechaNacimiento );
      entrenador.mestablecerUsuarioEntrenador( m_sUsuario );

      // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
      archivoEntrenador.seekp( ( m_iID_Entrenador - 1 ) *
         sizeof( ClsEntrenador ) );

      // insertar el registro en el archivo
      archivoEntrenador.write(
         reinterpret_cast< const char * >( &entrenador ),
         sizeof( ClsEntrenador ) );

        cout << "Entrenador agregado con exito.";

   }

   // mostrar error si la cuenta ya existe
   else
   {
       cerr << "La cuenta #" << m_iID_Entrenador << " ya contiene informacion." << endl;
       getch();
   }
}

void ClsEntrenador::mostrarLineaEntrenador( const ClsEntrenador &registro )
{
       cout << left << setw( 10 ) << registro.mobtenerClaveEntrenador()
          << setw( 20 ) << registro.mobtenerNombre1Entrenador().data()
          << setw( 20 ) << registro.mobtenerNombre2Entrenador().data()
          << setw( 20 ) << registro.mobtenerApellido1Entrenador().data()
          << setw( 20 ) << registro.mobtenerApellido2Entrenador().data()
          << setw( 20 ) << registro.mobtenerFechaNacimientoEntrenador().data()
          << setw( 20 ) << registro.mobtenerUsuarioEntrenador().data()
          << endl;
}

void ClsEntrenador::mconsultarRegistroEntrenador(fstream &archivoEntrenador)
{
   cout << left << setw( 10 ) << "Numero de Cuenta del entrenador" << setw( 20 )
   << "Nombre 1 del Entrenador" << setw( 20 )
   << "Nombre 2 del Entrenador" << setw( 20 )
   << "Apellido 1 del Entrenador" << setw( 20 )
   << "Apellido 2 del Entrenador" << setw( 20 )
   << "Fecha de nacimiento del Entrenador" << setw( 20 )
   << "Nombre del Usuario del Entrenador " << endl;

   // colocar el apuntador de posición de archivo al principio del archivo de registros
   archivoEntrenador.seekg( 0 );

   // leer el primer registro del archivo de registros
   ClsEntrenador entrenador;
   archivoEntrenador.read( reinterpret_cast< char * >( &entrenador ),
      sizeof( ClsEntrenador ) );

   // copiar todos los registros del archivo de registros en el archivo de texto
   while ( !archivoEntrenador.eof() ) {

      // escribir un registro individual en el archivo de texto
      if ( entrenador.mobtenerClaveEntrenador() != 0 )
         mostrarLineaEntrenador(entrenador);

      // leer siguiente registro del archivo de registros
      archivoEntrenador.read( reinterpret_cast< char * >( &entrenador ),
         sizeof( ClsEntrenador ) );

   }
}


void ClsEntrenador::mmostrarLineaRegistroEntrenador( ostream &salida, const ClsEntrenador &registro )
{
       salida << left << setw( 10 ) << registro.mobtenerClaveEntrenador()
          << setw( 20 ) << registro.mobtenerNombre1Entrenador().data()
          << setw( 20 ) << registro.mobtenerNombre2Entrenador().data()
          << setw( 20 ) << registro.mobtenerApellido1Entrenador().data()
          << setw( 20 ) << registro.mobtenerApellido2Entrenador().data()
          << setw( 20 ) << registro.mobtenerFechaNacimientoEntrenador().data()
          << setw( 20 ) << registro.mobtenerUsuarioEntrenador().data()
          << endl;
}

void ClsEntrenador::mmodificarRegistroEntrenador( fstream &archivoEntrenador )
{

   ClsEntrenador entrenador;
   int m_iID_Entrenador = mobtenerIndicadorEntrenador("Ingrese ID del entrenador");

   archivoEntrenador.seekg(
      ( m_iID_Entrenador - 1 ) * sizeof( ClsEntrenador ) );

   // leer el primer registro del archivo
   archivoEntrenador.read( reinterpret_cast< char * >( &entrenador ),
      sizeof( ClsEntrenador ) );

   // actualizar el registro
   if ( entrenador.mobtenerClaveEntrenador() != 0 ) {
      mmostrarLineaRegistroEntrenador( cout, entrenador );

      cout << "\nEscriba el nombre 1 del entrenador: ";
      char m_sNombre1[20];
      cin >> m_sNombre1;
      cout << "\nEscriba el nombre 2 del entrenador: ";
      char m_sNombre2[20];
      cin >> m_sNombre2;
      cout << "\nEscriba el apellido 1 del entrenador: ";
      char m_sApellido1[20];
      cin >> m_sApellido1;
      cout << "\nEscriba el apellido 2 del entrenador: ";
      char m_sApellido2[20];
      cin >> m_sApellido2;
      cout << "\nEscriba la fecha de nacimiento del entrenador: ";
      char m_sFechaNacimiento[20];
      cin >> m_sFechaNacimiento;
      cout << "\nEscriba el nombre de usuario del entrenador: ";
      char m_sUsuario[20];
      cin >> m_sUsuario;

      // actualizar el saldo del registro

      entrenador.mestablecerNombre1Entrenador( m_sNombre1 );
      entrenador.mestablecerNombre2Entrenador( m_sNombre2 );
      entrenador.mestablecerApellido1Entrenador( m_sApellido1 );
      entrenador.mestablecerApellido2Entrenador( m_sApellido2 );
      entrenador.mestablecerFechaNacimientoEntrenador( m_sFechaNacimiento );
      entrenador.mestablecerUsuarioEntrenador( m_sUsuario );
      mmostrarLineaRegistroEntrenador( cout, entrenador );

      // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
      archivoEntrenador.seekp(
         ( m_iID_Entrenador - 1 ) * sizeof( ClsEntrenador ) );

      // escribir el registro actualizado sobre el registro anterior en el archivo
      archivoEntrenador.write(
         reinterpret_cast< const char * >( &entrenador ),
         sizeof( ClsEntrenador ) );

        cout << "Entrenador modificado con éxito.";

   } // fin de instrucción if

   // mostrar error si la cuenta no existe
   else
      cerr << "La Cuenta #" << m_iID_Entrenador
         << " no tiene informacion." << endl;
}

void ClsEntrenador::meliminarRegistroEntrenador(fstream &archivoEntrenador)
{
    int iindicadorEntrenador= mobtenerIndicadorEntrenador( "Escriba la ID de entrenador a eliminar" );

   // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
   archivoEntrenador.seekg(
      ( iindicadorEntrenador - 1 ) * sizeof( ClsEntrenador ) );

   // leer el registro del archivo
   ClsEntrenador entrenador;
   archivoEntrenador.read( reinterpret_cast< char * >( &entrenador ),
      sizeof( ClsEntrenador ) );

   // eliminar el registro, si es que existe en el archivo
   if ( entrenador.mobtenerClaveEntrenador() != 0 ) {
      ClsEntrenador entrenadorEnBlanco;

      // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
      archivoEntrenador.seekp( ( iindicadorEntrenador - 1 ) *
         sizeof( ClsEntrenador ) );

      // reemplazar el registro existente con un registro en blanco
      archivoEntrenador.write(
         reinterpret_cast< const char * >( &entrenadorEnBlanco ),
         sizeof( ClsEntrenador ) );

      cout << "El entrenador #" << iindicadorEntrenador << " se elimino correctamente.\n";

   }

   // mostrar error si el registro no existe
   else
   {
       cerr << "El entrenador #" << iindicadorEntrenador << " esta vacia.\n";
   }
   getch();
}

ClsEntrenador::mmenuEntrenador()
{
    string codigo;
    fstream abrir;
    int found=0;


    int iseleccionMenuBancos;
    do
    {
        system("cls");
        // abrir el archivo en modo de lectura y escritura
        fstream archivoEntrenador("registrosentrenador.dat", ios::in | ios::out | ios::binary);
        // salir del programa si fstream no puede abrir el archivo
        if ( !archivoEntrenador )
            {
                cerr << "No se pudo abrir el archivo." << endl;
                mcrearEntrenador();
                cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo";
                exit ( 1 );

            }

        cout<<"-------------------------------"<<endl;
        cout<<"|  SISTEMA GESTION ENTRENADOR |"<<endl;
        cout<<"-------------------------------"<<endl;
        cout<<"1. Ingreso Entrenador"<<endl;
        cout<<"2. Despliegue Entrenador"<<endl;
        cout<<"3. Modifica Entrenador"<<endl;
        cout<<"4. Borrar Entrenador"<<endl;
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
                mnuevoEntrenador(archivoEntrenador);
                getch();
            }
            break;
        case 2:
            {

                system("cls");
                mconsultarRegistroEntrenador(archivoEntrenador);
                cout << "Fin del archivo.";
                getch();
            }
            break;
        case 3:
            {

                system("cls");
                mmodificarRegistroEntrenador(archivoEntrenador);
                getch();
            }
            break;
        case 4:
            {

                system("cls");
                meliminarRegistroEntrenador(archivoEntrenador);
                getch();
            }
            break;

        case 0:
            {

        default:
            cout<<"Opción invalida, intenta de nuevo";
            getch();
            break;
        }
    }
}while(iseleccionMenuBancos!=0);
}

ClsEntrenador::~ClsEntrenador()
{
    //dtor
}
