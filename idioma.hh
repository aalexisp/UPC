//Build 1.0
/** @file idioma.hh
    @brief Especificación de la clase Idioma
*/
#ifndef IDIOMA_HH
#define IDIOMA_HH

#include <iostream>
#include "BinTree.hh"
#include "Frecuencias.hh"
using namespace std;

/** @class Idioma
    @brief Representa un alfabeto y tabla de frecuencia

    Se caracteríza por definirse como árbol binario. El idioma puede ser vacío ?????
*/

class Idioma{

    //Constructoras--------------------------------------------

    /** @brief Creadora por defecto.

        Se ejecuta automáticamente al declarar un idioma.
        \pre <em>cierto</em>
        \post El resultado es un idioma vacío sin caracteres.
        \coste Constante
    */

    Idioma();

    /** @brief Creadora copiadora.

        Permite declarar un idioma como copia de otro que ya existía
        \pre <em>cierto</em>
        \post El resultado es un idioma igual que i
        \coste Lineal ????
    */

    Idioma(const Idioma& i);

    //Modificadoras--------------------------------------------

    /** @brief Crea el idioma a partir de su tabla de frecuencias
        \pre Idioma está inicializado
        \post Se ha creado un idioma con su tabla de frecuencias correspondiente
        \coste ???
    */

    void crear_idioma(Frecuencias());

      /** @brief Modifica la frecuencia del carácter

        \pre La frecuencia del caracter s no está vacía
        \post La frecuencia del carácter s pasa a ser newf como nuevo valor
        \coste lineal, log ??

    */

    void modificar_tabla_frecuencias(string s, int newf); //Nuevos valores de las frecuencias

    void borrar_idioma(); //necesaria?

    //Consultoras--------------------------------------------

    /** @brief Consulta la frecuencia a partir de un carácter
        \pre Existe el carácter
        \post Retorna la frecuencia de un carácter s
        \coste
     */

    void consultar_frecuencia() const;

    //Escritura y lectura--------------------------------------------

    /** @brief Operación de escritura de la tabla de frecuencias

        \pre <em>cierto</em>
        \post Escribe la tabla de frecuencias del idioma por el canal estándar de salida (llama a "Frecuencias")
        \coste ??
     */

    void escribir_tabla_frecuencias(string s) const;

    /** @brief Operación de escritura del "TREECODE"
        \pre <em>cierto</em>
        \post Escribe el "TREECODE" por el canal estándar de salida
        \coste ???
     */

    void escribir_tree_code() const;

private:
        //Atributos
        map <string, string> m;
        Tabla_Frecuencias table; //Tabla de frecuencias
        BinTree tree; //TreeCode (hace clase?)
};
#endif
