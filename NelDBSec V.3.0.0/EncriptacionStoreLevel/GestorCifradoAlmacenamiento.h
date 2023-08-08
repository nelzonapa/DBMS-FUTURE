#ifndef GESTORCIFRADOALMACENAMIENTO_H
#define GESTORCIFRADOALMACENAMIENTO_H


// #include "GestorClavesCifrado.h"
// #include "AlgoritmoCifrado.h"
// #include "AlmacenamientoDatos.h"
// #include "GestorMetadatos.h"

class GestorCifradoAlmacenamiento {
private:
    GestorClavesCifrado gestorClavesCifrado;
    AlgoritmoCifrado algoritmoCifrado;
    AlmacenamientoDatos almacenamientoDatos;
    GestorMetadatos gestorMetadatos;

public:
    GestorCifradoAlmacenamiento();

    byte[] cifrarDatos(byte[] datos);
    byte[] descifrarDatos(byte[] datosCifrados);
    void rotarClaveCifrado();

private:
    Fecha obtenerFechaActual();
};


#endif