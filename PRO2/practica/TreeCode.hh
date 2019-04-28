//Build 5.0
/** @file TreeCode.hh
    @brief Especificación de la clase TreeCode
*/
#ifndef TREECODE_HH
#define TREECODE_HH

#include "tabla_de_frecuencias.hh"

#ifndef NO_DIAGRAM
#include "BinTree.hh"
#include <vector>
#include <algorithm>
#endif

/** @class TreeCode
    @brief Representa los caracteres y frecuencias de un Idioma.

    Caracterizado por ser un árbol binario.
    Se forma apartir de la Tabla_de_frecuencias de forma recursiva.
*/
class TreeCode {
public:
    //Constructoras--------------------------------------------

    /** @brief Creadora por defecto sin parámetros.

        Se ejecuta automáticamente al declarar un TreeCode.
        \pre <em>cierto</em>.
        \post El resultado es un TreeCode vacío, un árbol binario.
    */

    TreeCode();

    /** @brief Creadora por defecto con parámetros.

        Se ejecuta automáticamente al declarar un TreeCode.
        \pre <em>cierto</em>.
        \post El resultado es un TreeCode vacío, un árbol binario.
    */

    TreeCode(const Tabla_de_frecuencias& tf);

    /** @brief Creadora copiadora.

        Permite declarar un TreeCode que ya existía.
        \pre <em>cierto</em>.
        \post El resultado es un TreeCode igual que otro ya existente.
    */

    TreeCode(const TreeCode& tree);

    //Modificadoras--------------------------------------------

//MODIFICADORAS NO NECESARIAS POR EL MOMENTO

    //Consultoras--------------------------------------------

    /** @brief Función para codificar los carácteres.
        \pre El carácter existe y es codificable.
        \post Se retorna el caráter codificado en 0's y 1's.
    */

    string codifica(string s);

    /** @brief Función para decodificar los carácteres.
        \pre El carácter existe y es decodificable.
        \post Se retorna el carácter decodificado como un string.
    */

    string decodifica(string s);

    //Lectura y escritura--------------------------------------------

    /** @brief Operación de escritura del treecode.

        \pre <em>cierto</em>.
        \post Se escribe el treecode en preorden e inorden por el canal estándar de salida.
    */
    void escribir_treecode() const;

    /** @brief Operación de escritura de la tabla de codigos.

        \pre <em>cierto</em>.
        \post Se escribe el treecode en preorden e inorden por el canal estándar de salida.
    */
    void escribir_codigos(string s) const;

private:
    //Atributos--------------------------------------------

    BinTree<pair<string, int> > t; //Árbol binario por defecto
    //Para construir el treecode
    vector<BinTree<pair<string, int> > > v; //Vector de árboles binarios

    map<string, string> tm; //Tabla de los códigos

    //Métodos privados--------------------------------------------

    /** @brief Función para escribir el treecode en preorden.
        \pre El treecode está lleno y tiene valores correctos.
        \post Se ha escrito el treecode en preorden por el canal estándar de salida.
    */

    void escribir_preorden(const BinTree<pair<string, int> >& b) const; //Función para escribir el treecode en preorden


    /** @brief Función para escribir el treecode en inorden.
        \pre El treecode está lleno y tiene valores correctos.
        \post Se ha escrito el treecode en inorden por el canal estándar de salida.
    */

    void escribir_inorden(const BinTree<pair<string, int> >& b) const; //Función para escribir el treecode en inorden

    /** @brief Función para sumar las frecuencias de diversas tablas.
        \pre La tabla de frecuencias del p.i tiene valores.
        \post Las frecuencias de la tabla del p.i pasa a tener nuevos valores.
    */

    pair<string, int> suma(const pair<string,int>& a, const pair<string, int>& b); //Función para crear el par que van el el nodo de la raiz de a y b

    /** @brief Llena el vector de árboles (nodos base).
        \pre El vector de bintrees ha sido declarado y está vacío.
        \post El parámetro implícito pasa a contener los valores de la tabla de frecuencias.
    */

    void crear_nodos_base(const Tabla_de_frecuencias& tf);

    /** @brief Función para insertar un bintree en el vector de bintree's
        \pre <em>cierto</em>
        \post El bintree "tree" queda incluído en el vector del p.i
    */

    void insertar(BinTree<pair<string, int> >& tree);

    /** @brief Llena el TreeCode con los valores correspondientes.
        \pre El TreeCode ha sido declarado y está vacío.
        \post El parámetro implícito pasa a contener los valores correspondientes.
    */

    void crear_TreeCode();

    /** @brief Crea la tabla de códigos de cada carácter.
        \pre El treecode y la tabla de frecuencias existen y tienen valores.
        \post La tabla de códigos pasa a contener sus valores correspondientes.
    */

    void crear_tabla_codigos(const BinTree<pair<string, int> >& tc, const pair<string, string>& p, const Tabla_de_frecuencias& tf);

};
#endif
