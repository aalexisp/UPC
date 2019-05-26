//Build 6.0
/** @file Cjt_idiomas.hh
    @brief Especificación de la clase Cjt_idiomas
*/
#ifndef CJT_IDIOMAS_HH
#define CJT_IDIOMAS_HH

#include "Idioma.hh"

/*
 * Clase Cjt_Idiomas
 */

/** @class Cjt_Idiomas
    @brief Representa un conjuto de Idioma.

    Caracterizado por ser un conjunto de Idioma.
*/
class Cjt_Idiomas{
    //Descripción: Es un conjunto de idiomas que contiene los idiomas que le añadimos con sus
    //respectivos TreeCode y Tabla_de_frecuencias.

private:

    //--------------------------------------------Atributos--------------------------------------------

    /* Dado que necesitamos almacenar una serie de idiomas y no sabemos cuantos nos entraran inicialmente
       se hace uso de un diccionario clave, valor. Donde la clave será el nombre del Idioma y el valor el idioma
       al que hace referencia. Si se hubiese usado un vector, esto sería ineficiente pues no sabemos el tamaño y
       deberiamos hacer push_backs cosa que es ineficiente para un conjunto muy grande.*/

    /** @brief Diccionario de Idiomas.

    Tiene un nombre como clave y el Idioma como valor */
    map<string, Idioma> m; //nombre del Idioma y el Idioma.

public:

    //--------------------------------------------Constructoras--------------------------------------------

    /** @brief Creadora por defecto.

        Se ejecuta automáticamente al declarar un conjunto de idiomas.
        @pre <em>cierto</em>.
        @post El resultado es un conjunto de idioma vacío sin idiomas.
    */
    Cjt_Idiomas();

    //--------------------------------------------Modificadoras--------------------------------------------

    /** @brief Añade un idioma con nombre "nombre" al conjunto.
        \pre El Idioma es válido y no está repetido (si lo está se modifica la Tabla_de_frecuencias y el TreeCode).
        \post El Idioma con nombre "nombre" ha sido añadido al conjunto si no estaba o modificado en caso contrario.
     */
    void anadir_modificar(string nombre);

    //--------------------------------------------Consultoras--------------------------------------------

    /** @brief Consulta si el Idioma está en el conjunto.
        \pre <em>cierto</em>
        \post Retorna cierto si el Idioma está en el conjunto, falso en caso contrario.
     */
    bool existe_idioma(string s) const;

    //--------------------------------------------Escritura y lectura--------------------------------------------

        /** @brief Operación de escritura del código codificado.
        \pre <em>cierto</em>.
        \post Se ha escrito el texto codificado por en canal estándar de salida.
     */
    void codifica(const string& s, const string& code);

    /** @brief Operación de escritura del código decodificado.
        \pre <em>cierto</em>.
        \post Se ha escrito el texto decodificado por el canal estándar de salida.
     */
    void decodifica(const string& s, const string& code);

    /** @brief Operación de escritura del TreeCode de un Idioma.
        \pre El TreeCode ha sido declarado y tiene valores.
        \post Se ha escrito el TreeCode del Idioma s por el canal estándar de salida.
    */
    void escribir_treecode(string s)const;

    /** @brief Operación de escritura de la Tabla_de_frecuencias de un Idioma.
        \pre  La Tabla_de_frecuencias ha sido declarada y tiene valores.
        \post Se ha escrito la Tabla_de_frecuencias del Idioma s por el canal estándar de salida.
    */
    void escribir_tabla_frecuencias(string s)const;

    /** @brief Operación de escritura de la tabla de códigos de un Idioma.
        \pre  La tabla de códigos ha sido declarada y tiene valores.
        \post Se ha escrito la tabla de códigos del Idioma s por el canal estándar de salida.
    */
    void escribir_codigos(string s, string st)const;

};
#endif
