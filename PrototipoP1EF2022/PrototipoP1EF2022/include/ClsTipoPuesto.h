#ifndef CLSTIPOPUESTO_H
#define CLSTIPOPUESTO_H


class ClsTipoPuesto
{
    public:
        ClsTipoPuesto();
        virtual ~ClsTipoPuesto();

    protected:

    private:
         int m_iID_Puesto;
        char m_sNombrePuesto[20];
        double Salario;
};

#endif // CLSTIPOPUESTO_H
