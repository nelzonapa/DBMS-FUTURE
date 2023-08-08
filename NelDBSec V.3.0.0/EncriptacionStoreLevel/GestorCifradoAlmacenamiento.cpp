#include "GestorCifradoAlmacenamiento.h"

GestorCifradoAlmacenamiento::GestorCifradoAlmacenamiento() {
    // Constructor: inicialización de instancias
}

byte[] GestorCifradoAlmacenamiento::cifrarDatos(byte[] datos) {
    ClaveCifrado clave = gestorClavesCifrado.obtenerClaveActual();
    byte[] datosCifrados = algoritmoCifrado.cifrar(datos, clave);
    almacenamientoDatos.almacenarDatos(datosCifrados);
    gestorMetadatos.registrarUsoClave(clave, obtenerFechaActual());
    return datosCifrados;
}

byte[] GestorCifradoAlmacenamiento::descifrarDatos(byte[] datosCifrados) {
    ClaveCifrado clave = gestorClavesCifrado.obtenerClaveActual();
    byte[] datosDescifrados = algoritmoCifrado.descifrar(datosCifrados, clave);
    return datosDescifrados;
}

void GestorCifradoAlmacenamiento::rotarClaveCifrado() {
    gestorClavesCifrado.rotarClave();
}

Fecha GestorCifradoAlmacenamiento::obtenerFechaActual() {
    // Implementación para obtener la fecha actual
}
