//Build 6.0
/** @file Idioma.hh
    @brief Especificación de la clase Idioma
*/
#ifndef IDIOMA_HH
#define IDIOMA_HH

#include "TreeCode.hh"
#include "Tabla_de_frecuencias.hh"

/*
 * Clase Idioma
 */

/** @class Idioma
    @brief Representa un alfabeto caracterizaco por un TreeCode y una Tabla_de_frecuencias.

    Se caracteríza por un árbola binario/Treecode y una Tabla_de_frecuencias. Se utiliza esta clase
    con el fin de crear un diseño modular más elaborado dado que en esta clase todas las funciones
    son llamadas a las de otra clase.
*/

class Idioma{
    //Descripción: Un idioma se caracteríza por ser un alfabeto creado a partir de una Tabla_de_frecuencias y un TreeCode.

private:

    //--------------------------------------------Atributos--------------------------------------------

    /** @brief Identificadorde cada Idioma, su nombre. */
    string nombre;
    /** @brief tabla_de_frecuencias del idioma. */
    Tabla_de_frecuencias tbl; //Tabla de frecuencias
    /** @brief TreeCode del idioma. */
    TreeCode tree; //TreeCode

public:

    //--------------------------------------------Constructoras--------------------------------------------

    /** @brief Creadora por defecto.

        Se ejecuta automáticamente al declarar un Idioma.
        Se crea el Idioma a partir de la Tabla_de_frecuencias y su nobmre.
        @pre <em>cierto</em>.
        @post El resultado es un Idioma completo.
    */

    Idioma(string nom, Tabla_de_frecuencias& tf);

    //--------------------------------------------Modificadoras--------------------------------------------

    /** @brief Modifica el TreeCode con una nueva entrada consistente en la Tabla_de_frecuencias.
        \pre El TreeCode existe y la Tabla_de_frecuencias también.
        \post El TreeCode ha quedado modificado a partir de una nueva Tabla_de_frecuencias.
     */
    void modificar_treecode();

    //--------------------------------------------Consultoras--------------------------------------------

    //--------------------------------------------Escritura y lectura--------------------------------------------

    /** @brief Función para leer la Tabla_de_frecuencias.
        /pre <em>cierto</em>.
        /post La Tabla_de_frecuencias pasa a tener valores.
    */
    void leer_tabla_frecuencias();

    /** @brief Operación de escritura de la Tabla_de_frecuencias.
        \pre <em>cierto</em>.
        \post Escribe la Tabla_de_frecuencias del Idioma por el canal estándar de salida.
     */
    void escribir_tabla_frecuencias() const;

    /** @brief Operación de escritura del TreeCode.
        \pre <em>cierto</em>.
        \post Escribe el TreeCode por el canal estándar de salida.
    */
    void escribir_treecode()const;

    /** @brief Operación de escritura de los códigos del Idioma.
        \pre <em>cierto</em>.
        \post Escribe los códigos del Idioma por el canar estándar de salida.
    */
    void escribir_codigos(string st)const;

    /** @brief Función para escribir el texto codificado
        \pre El texto existe y es codificable.
        \post Se retorna el texto codificado en 0's y 1's.
    */
    void escribir_codificado(const string& s);

    /** @brief Operación de escritura del texto decodificado.
        \pre El texto existe y es decodificable.
        \post Se retorna el texto decodificado como un string.
    */
    void escribir_decodificado(const string& s);

};
#endif
