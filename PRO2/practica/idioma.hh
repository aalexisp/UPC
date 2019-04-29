//Build 5.0
/** @file idioma.hh
    @brief Especificación de la clase Idioma
*/
#ifndef IDIOMA_HH
#define IDIOMA_HH

#include "TreeCode.hh"
#include "tabla_de_frecuencias.hh"

/** @class Idioma
    @brief Representa un alfabeto caracterizaco por un TreeCode y una Tabla_de_frecuencias.

    Se caracteríza por un árbola binario o Treecode y una Tabla_de_frecuencias.
*/

class Idioma{
public:
    //Constructoras--------------------------------------------

    /** @brief Creadora por defecto.

        Se ejecuta automáticamente al declarar un idioma.
        \pre <em>cierto</em>.
        \post El resultado es un idioma vacío sin caracteres.
    */

    Idioma(string nom, const Tabla_de_frecuencias& tf);

    /** @brief Creadora copiadora.

        Permite declarar un idioma como copia de otro que ya existía.
        \pre <em>cierto</em>.
        \post El resultado es un idioma igual que l.
    */

    Idioma(const Idioma& l);

    //Modificadoras--------------------------------------------

//MODIFICADORAS NO NECESARIAS POR EL MOMENTO

    //Consultoras--------------------------------------------

    /** @brief Consulta el nombre del idioma.
        \pre El idioma existe y tiene nombre.
        \post Retorna el nombre del idioma.
    */

    string consultar_nombre() const;

    /** @brief Consulta si el carácter s existe en la Tabla_de_frecuencias.
        \pre <em>cierto</em>.
        \post Retorna true si el carácter existe en la Tabla_de_frecuencias.
    */

    bool existe_caracter(string s) const;

    /** @brief Función para codificar los carácteres.
        \pre El carácter existe y es codificable.
        \post Se retorna el caráter codificado en 0's y 1's.
    */

    string codifica(string s) const;

    /** @brief Función para decodificar los carácteres.
        \pre El carácter existe y es decodificable.
        \post Se retorna el carácter decodificado como un string.
    */

    string decodifica(string s) const;

    //Escritura y lectura--------------------------------------------

    /** @brief Función para leer la tabla de frecuencias.
        /pre <em>cierto</em>.
        /post La tabla de frecuencias pasa a tener valores.
    */

    void leer_tabla_frecuencias();

    /** @brief Operación de escritura de la tabla de frecuencias.
        \pre <em>cierto</em>.
        \post Escribe la tabla de frecuencias del idioma por el canal estándar de salida.
     */

    void escribir_tabla_frecuencias() const;

    /** @brief Operación de escritura del TreeCode.
        \pre <em>cierto</em>.
        \post Escribe el treecode por el canal estándar de salida.
    */

    void escribir_treecode()const;

    /** @brief Operación de escritura de los códigos del Idioma.
        \pre <em>cierto</em>.
        \post Escribe los códigos del idioma por el canar estándar de salida.
    */

    void escribir_codigos(string st)const;

private:
        //Atributos
        string nombre;
        map <string, string> m; //Texto sin codificar y decodificado
        Tabla_de_frecuencias t; //Tabla de frecuencias
        TreeCode tree; //TreeCode
};
#endif
