//Build 3.0
/** @file TreeCode.hh
    @brief Especificación de la clase TreeCode
*/
#ifndef TREECODE_HH
#define TREECODE_HH

#include "tabla_de_frecuencias.hh"

#ifndef NO_DIAGRAM
#include "BinTree.hh"
#include <vector>
#endif

/** @class TreeCode
    @brief Representa los caracteres y frecuencias de un Idioma.

    Caracterizado por ser un árbol binario.
*/
class TreeCode {
public:
    //Constructoras--------------------------------------------

    /** @brief Creadora por defecto.

        Se ejecuta automáticamente al declarar un TreeCode.
        \pre <em>cierto</em>.
        \post El resultado es un TreeCode vacío, un árbol binario.
    */

    TreeCode();

    /** @brief Creadora copiadora.

        Permite declarar un TreeCode que ya existía.
        \pre <em>cierto</em>.
        \post El resultado es un TreeCode igual que otro ya existente.
    */

    TreeCode(const TreeCode& tree);

    //Modificadoras--------------------------------------------

    /** @brief Llena el vector de árboles (nodos base).
        \pre El vector de bintrees ha sido declarado y está vacío.
        \post El parámetro implícito pasa a contener los valores de la tabla de frecuencias.
    */

    void crear_nodos_base(Tabla_de_frecuencias tbl);

    /** @brief Llena el TreeCode con los valores correspondientes.
        \pre El TreeCode ha sido declarado y está vacío.
        \post El parámetro implícito pasa a contener los valores correspondientes.
    */

    void crear_TreeCode(); //A partir de la tabla de frecuencias

    //Consultoras--------------------------------------------

    /** @brief Función para codificar los carácteres
        \pre El carácter existe y es codificable
        \post Se retorna el caráter codificado en 0's y 1's
    */

//    string codifica(string s);

    /** @brief Función para decodificar los carácteres
        \pre El carácter existe y es decodificable
        \post Se retorna el carácter decodificado como un string
    */

    //string decodifica(string s);

    //Lectura y escritura--------------------------------------------

    /** @brief Operación de escritura.

        \pre <em>cierto</em>.
        \post Se escribe el treecode en preorden e inorden por el canal estándar de salida.
    */
    void escribir_treecode();

private:
    //Atributos--------------------------------------------

    BinTree<pair<string, int> > t; //Árbol binario por defecto
    //Para construir el treecode
    vector<BinTree<pair<string, int> > > v; //Vector de árboles binarios

    map<string, string> m; //caracter - caracter codificado

    //Métodos privados--------------------------------------------

    /** @brief Función para escribir el treecode en preorden.
        \pre El treecode está lleno y tiene valores correctos.
        \post Se ha escrito el treecode en preorden por el canal estándar de salida.
    */

    void escribir_preorden(const BinTree<pair<string, int> >& b); //Función para escribir el treecode en preorden


    /** @brief Función para escribir el treecode en inorden.
        \pre El treecode está lleno y tiene valores correctos.
        \post Se ha escrito el treecode en inorden por el canal estándar de salida.
    */

    void escribir_inorden(const BinTree<pair<string, int> >& b); //Función para escribir el treecode en inorden


    /** @brief Función para ordenar el vector de árboles.
        \pre El treecode existe y no está vacío.
        \post El vector de bintree's pasa a estar ordenado.
    */

    void ordenar_vector_treecode(); //Función para ordenar el vector de árboles para formar el árbol


    /** @brief Función para sumar las frecuencias de diversas tablas.
        \pre La tabla de frecuencias del p.i tiene valores.
        \post Las frecuencias de la tabla del p.i pasa a tener nuevos valores.
    */

    pair<string, int> suma(pair<string,int> a, pair<string, int> b); //Función para crear el par que van el el nodo de la raiz de a y b


    /** @brief Función para vacíar los nodos base.
        \pre El vector de nodos base no está vacío.
        \post El vector de nodos base pasa a estar vacío.
    */

    void vaciar_nodos_base(); //Función para vaciar los nodos base del TreeCode

};
#endif
