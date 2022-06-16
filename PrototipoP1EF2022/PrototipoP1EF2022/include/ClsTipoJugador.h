#ifndef CLSTIPOJUGADOR_H
#define CLSTIPOJUGADOR_H


class ClsTipoJugador
{
    public:
        ClsTipoJugador();
        virtual ~ClsTipoJugador();

    protected:

    private:
         int m_iID_TipoJugador;
        char m_sPosicion[20];
};

#endif // CLSTIPOJUGADOR_H
