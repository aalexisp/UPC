//Build 6.0
/** @file Tabla_de_frecuencias.hh
    @brief Especificación de la clase Tabla_de_frecuencias
*/
#ifndef TABLA_DE_FRECUENCIAS_HH
#define TABLA_DE_FRECUENCIAS_HH

#ifndef NO_DIAGRAM
#include <iostream>
#include <map>
#include <string>
#endif

using namespace std;

/*
 * Clase Tabla_de_frecuencias
 */

/** @class Tabla_de_frecuencias
    @brief Representa la tabla de frecuencias de un idioma.

    Caracterizado por crear el árbol binario o TreeCode.
    Una Tabla_de_frecuencias está constituido por un caracter y
    un entero que indica el número de veces que aparece ese carácter en el Idioma.
*/
class Tabla_de_frecuencias {

private:

    /* Para una construcción eficiente de la Tabla_de_frecuencias se ha implementado esta tabla
       como un diccionario de pares string, int. De esta forma dado que cada Idioma tiene
       su propia Tabla_de_frecuencias en este diccionario guardamos los carácteres y frecuencias
       que nos van entrado. Además se usará un iterador aux para pasar pares string, int
       al TreeCode dado que los necesitamos para crear este.*/

    //--------------------------------------------Atributos--------------------------------------------

    /** @brief Es un diccionario clave, valor. Sirve para crear la Tabla_de_frecuencias.

        A partir de un carácter como string y su correspondiente frecuencia como un entero*/
    map <string, int> m; //Valores que van dentro del árbol
    /** @brief Un simple iterador para recorrer la tabla y que sea más fácil retornar pares al TreeCode.  */
    map<string, int>::const_iterator aux; //Iterador para el map

public:

    //--------------------------------------------Constructoras--------------------------------------------

    /** @brief Creadora por defecto.

        Se ejecuta automáticamente al declarar un Idioma.
        @pre <em>cierto</em>.
        @post El resultado es una Tabla_de_frecuencias vacía.
    */
    Tabla_de_frecuencias();

    //--------------------------------------------Modificadoras--------------------------------------------

    /** @brief Inicializa el iterador del p.i al principio de la tabla.
        \pre m no es vacía.
        \post El iterador apunta a m.begin().
    */
    void inicializa_recorrido();

    //--------------------------------------------Consultoras--------------------------------------------

    /** @brief Consulta el tamaño de la Tabla_de_frecuencias.
        \pre La Tabla_de_frecuencias existe.
        \post Retorna el tamaño de la Tabla_de_frecuencias.
    */
    int tamano() const;

    /** @brief Consulta el par string, int (caràcter, frecuencia).
        \pre El diccionario del p.i no está vacío, si 0 <= i <= m.size().
        \post El resultado es el par caracter, frecuencia.
     */
    pair<string, int> consultar_proximo();

    /** @brief Consulta si el carácter s está en la Tabla_de_frecuencias.
        \pre <em>cierto</em>.
        \post Retorna cierto si se ha encontrado el carácter, falso en caso contrario.
    */
    bool esta (string s) const;

    //--------------------------------------------Lectura y escritura--------------------------------------------

     /** @brief Llena la Tabla_de_frecuencias con pares string, int (carácter, frecuencia).
        \pre La Tabla_de_frecuencias ha sido declarada y está vacía.
        \post El parámetro implícito pasa a contener los pares string, int.
    */
    void leer_tabla_frecuencias();

    /** @brief Operación de escritura.

        \pre <em>cierto</em>.
        \post Escribe la Tabla_de_frecuencias por el canal estándar de salida.
     */
    void escribir_tabla_frecuencias() const;

private:

    //--------------------------------------------Métodos privados-------------------------------------------

    /** @brief Modifica la frecuencia de un carácter.
        @pre El carácter existe y tiene frecuencia.
        @post La frecuencia del carácter ha sido modificada.
    */
    void modificar_frecuencias(const pair<string, int>& p);

};
#endif
