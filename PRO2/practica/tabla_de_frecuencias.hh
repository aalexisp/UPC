//Build 2.0
/** @file tabla_de_frecuencias.hh
    @brief Especificación de la clase tabla_de_frecuencias
*/
#ifndef TABLA_DE_FRECUENCIAS_HH
#define TABLA_DE_FRECUENCIAS_HH

#include <iostream>
#include <map>
#include <string>
using namespace std;

/** @class tabla_de_frecuencias
    @brief Representa la tabla de frecuencias de un idioma

    Caracterizado por crear el árbol binario
*/
class Tabla_de_frecuencias {
public:
    //Constructoras--------------------------------------------

    /** @brief Creadora por defecto.

        Se ejecuta automáticamente al declarar un idioma.
        \pre <em>cierto</em>
        \post El resultado es una tabla de frecuencias vacía
    */

    Tabla_de_frecuencias();

    /** @brief Creadora copiadora.

        Permite declarar una tabla de frecuencias que ya existía
        \pre <em>cierto</em>
        \post El resultado es una tabla de frecuencias igual que otra ya existente
    */

    Tabla_de_frecuencias(const Tabla_de_frecuencias& t);

    //Modificadoras--------------------------------------------

//Por determinar

    //Consultoras--------------------------------------------

    /** @brief Consulta el carácter del idioma según su frecuencia
        \pre El primer elemento del p.i no está vacío
        \post El resultado es el carácter (lo retorna)
     */

    void consultar_caracter(string s) const; //Para consultar el carácter

    /** @brief Consulta el par de carácter, frecuencia (string, int)
        \pre El diccionario del parámetro implícito no estña vacío
        \post El resultado es el par de carácter, frecuencia
     */

    map<string, int> consultar_tabla_frecuencias() const; //Para consultar el par carácter, frecuencia

    //Lectura y escritura--------------------------------------------


     /** @brief Llena la tabla de frecuencias con los valores correspondientes
        \pre La tabla de frecuencias ha sido declarada y está vacía
        \post El parámetro implícito (?) pasa a contener los valores correspondientes
    */

    void leer_tabla_frecuencias();

    /** @brief Operación de escritura

        \pre <em>cierto</em>
        \post Escribe la tabla de frecuencias a partir de sus carácteres y sus frecuencias, el del parámetro implícito por el canal estándar de salida
     */

    void escribir_tabla_frecuencias() const; //Frecuencias y carácteres


private:
    //Atributos--------------------------------------------
    map <string, int> m; //Valores que van dentro del árbol

    //Métodos privados--------------------------------------------

    /** @brief Ordena la tabla de frecuencias el el orden pedido para el árbol
        \pre La tabla de frecuencias no está vacía y tiene valores válidos
        \post El parámetro implícito pasa a estar ordenado según la ordenación pedida
     */

    //Necesiario ? es un map
    bool ordena_tabla_frecuencias(string a, string b); //Menor si string a < string b
};
#endif
