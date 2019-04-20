//Build 2.0
/** @file idioma.hh
    @brief Especificación de la clase Idioma
*/
#ifndef IDIOMA_HH
#define IDIOMA_HH

#include <iostream>
#include "TreeCode.hh"
#include "tabla_de_frecuencias.hh"
using namespace std;

/** @class Idioma
    @brief Representa un alfabeto y tabla de frecuencia

    Se caracteríza por definirse como árbol binario. El idioma puede ser vacío ?????
*/

class Idioma{
public:
    //Constructoras--------------------------------------------

    /** @brief Creadora por defecto.

        Se ejecuta automáticamente al declarar un idioma.
        \pre <em>cierto</em>
        \post El resultado es un idioma vacío sin caracteres.
    */

    Idioma();

    /** @brief Creadora copiadora.

        Permite declarar un idioma como copia de otro que ya existía
        \pre <em>cierto</em>
        \post El resultado es un idioma igual que l
    */

    Idioma(const Idioma& l);

    //Modificadoras--------------------------------------------

    /** @brief Crea el idioma a partir de su tabla de frecuencias
        \pre Idioma está inicializado
        \post Se ha creado un idioma con su tabla de frecuencias y treecode correspondientes
    */

    void crear_idioma();

      /** @brief Se modifica la tabla de frecuencias

        \pre La tabla de frecuencias y el treecode no están vacíos
        \post La tabla de frecuencias se ha sustituido por la nueva tb
    */

    void modificar_tabla_frecuencias(const Tabla_de_frecuencias& tb); //Nuevos valores de las frecuencias

    //Consultoras--------------------------------------------

    /** @brief Consulta el nombre del idioma
        \pre El idioma existe y tiene nombre
        \post Retorna el nombre del idioma
    */

    string consultar_nombre() const;

    //Escritura y lectura--------------------------------------------

    /** @brief Se lee el nombre del idioma que se va a añadir
        /pre <em>cierto</em>
        /post El p.i pasa a tener nombre
    */

    void leer_nombre();

    /** @brief Operación de escritura de la tabla de frecuencias
        \pre <em>cierto</em>
        \post Escribe la tabla de frecuencias del idioma por el canal estándar de salida
     */

    void escribir_tabla_frecuencias() const;

    /** @brief Operación de escritura del TreeCode
        \pre <em>cierto</em>
        \post Escribe el treecode por el canal estándar de salida
    */

    void escribir_treecode();

private:
        //Atributos
        string nombre;
        map <string, string> m; //Texto sin codificar y decodificado
        Tabla_de_frecuencias t; //Tabla de frecuencias
        TreeCode tree; //TreeCode
};
#endif
