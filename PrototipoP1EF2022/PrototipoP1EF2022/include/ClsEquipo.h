#ifndef CLSEQUIPO_H
#define CLSEQUIPO_H

#include<conio.h>
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<cstdlib>

using namespace std;

class ClsEquipo
{
    public:
        ClsEquipo(string = "", int = 0);

        mmenuEquipo();
        mcrearEquipo();

        int mobtenerIndicadorEquipo( const char * const );

        void mnuevoEquipo(fstream &archivoEquipo);

        void mconsultarRegistroEquipo(fstream &archivoEquipo);

        void mostrarLineaEquipo( const ClsEquipo &registro );

        void mmodificarRegistroEquipo( fstream &archivoEquipo );

        void mmostrarLineaRegistroEquipo( ostream &salida, const ClsEquipo &registro );

        void mimprimirRegistroEquipo(fstream &archivoEquipo);

        void meliminarRegistroEquipo(fstream &archivoEquipo);

        void mbuscarEquipo(fstream &archivoEquipo);

        void mestablecerClaveEquipo( int ) ;
        int mobtenerClaveEquipo() const;

        void mestablecerNombreEquipo( string );
        string mobtenerNombreEquipo() const;

        virtual ~ClsEquipo();

    protected:

    private:
        int m_iID_Equipo;
        char m_sNombre[20];
};

#endif // CLSEQUIPO_H
