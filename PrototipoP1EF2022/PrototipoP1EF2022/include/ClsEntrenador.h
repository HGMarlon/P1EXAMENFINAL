#ifndef CLSENTRENADOR_H
#define CLSENTRENADOR_H

#include<conio.h>
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<cstdlib>

using namespace std;

class ClsEntrenador
{
    public:
        ClsEntrenador(int = 0, string = "", string = "", string = "", string = "", string = "", string = "");

        mmenuEntrenador();
        mcrearEntrenador();

        int mobtenerIndicadorEntrenador( const char * const );

        void mnuevoEntrenador(fstream &archivoEntrenador);

        void mconsultarRegistroEntrenador(fstream &archivoEntrenador);

        void mostrarLineaEntrenador( const ClsEntrenador &registro );

        void mmodificarRegistroEntrenador( fstream &archivoEntrenador );

        void mmostrarLineaRegistroEntrenador( ostream &salida, const ClsEntrenador &registro );

        void mimprimirRegistroEntrenador(fstream &archivoEntrenador);

        void meliminarRegistroEntrenador(fstream &archivoEntrenador);

        void mbuscarEntrenador(fstream &archivoEntrenador);

        void mestablecerClaveEntrenador( int ) ;
        int mobtenerClaveEntrenador() const;

        void mestablecerNombre1Entrenador( string );
        string mobtenerNombre1Entrenador() const;

        void mestablecerNombre2Entrenador( string );
        string mobtenerNombre2Entrenador() const;

        void mestablecerApellido1Entrenador( string );
        string mobtenerApellido1Entrenador() const;

        void mestablecerApellido2Entrenador( string );
        string mobtenerApellido2Entrenador() const;

        void mestablecerFechaNacimientoEntrenador( string );
        string mobtenerFechaNacimientoEntrenador() const;

        void mestablecerUsuarioEntrenador( string );
        string mobtenerUsuarioEntrenador() const;


        virtual ~ClsEntrenador();

    protected:

    private:
        int m_iID_Entrenador;
        char m_sNombre1[20];
        char m_sNombre2[20];
        char m_sApellido1[20];
        char m_sApellido2[20];
        char m_sFechaNacimiento[20];
        char m_sUsuario[20];

};

#endif // CLSENTRENADOR_H
