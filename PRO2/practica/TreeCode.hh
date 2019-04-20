//Build 2.0
/** @file TreeCode.hh
    @brief Especificación de la clase TreeCode
*/
#ifndef TREECODE_HH
#define TREECODE_HH

#include <iostream>
#include "BinTree.hh"
#include <map>
#include <string>
#include <vector>
#include "tabla_de_frecuencias.hh"
using namespace std;

/** @class TreeCode
    @brief Representa los caracteres y frecuencias de un Idioma

    Caracterizado por ser un árbol binario
*/
class TreeCode {
public:
    //Constructoras--------------------------------------------

    /** @brief Creadora por defecto.

        Se ejecuta automáticamente al declarar un TreeCode.
        \pre <em>cierto</em>
        \post El resultado es un TreeCode vacío, un árbol binario
    */

    TreeCode();

    /** @brief Creadora copiadora.

        Permite declarar un TreeCode que ya existía
        \pre <em>cierto</em>
        \post El resultado es un TreeCode igual que otro ya existente
    */

    TreeCode(const TreeCode& tree);

    //Modificadoras--------------------------------------------

    /** @brief Llena el vector de árboles (nodos base)
        \pre El vector de bintrees ha sido declarado y está vacío
        \post El parámetro implícito pasa a contener los valores correspondientes
    */

    void crear_nodos_base(Tabla_de_frecuencias tbl);

    /** @brief Llena el TreeCode con los valores correspondientes
        \pre El TreeCode ha sido declarado y está vacío
        \post El parámetro implícito pasa a contener los valores correspondientes
    */

    void crear_TreeCode(); //A partir de la tabla de frecuencias

    //Consultoras--------------------------------------------

    /** @brief Consulta el valor del árbol del TreeCode
        \pre El bintree del p.i no está vacío y existe
        \post Retorna el árbol del p.i
    */

    BinTree<pair<string,int> > consultar_treecode() const;

    //Lectura y escritura--------------------------------------------

    /** @brief Operación de escritura del TreeCode de un idioma en preorden
        \pre El TreeCode no está vacío y existe
        \post Se ha escrito por el canar estándar de salida el TreeCode en preorden
    */

    void escribir_preorden(const BinTree<pair<string, int> >& b);

    /** @brief Operación de escritura del TreeCode de un idioma en inorden
        \pre El TreeCode no está vacío y existe
        \post Se ha escrito por el canar estándar de salida el TreeCode en inorden
    */

    void escribir_inorden(const BinTree<pair<string, int> >& b);

private:
    //Atributos--------------------------------------------

    BinTree<pair<string, int> > t; //Árbol binario por defecto
    //Para construir el treecode
    vector<BinTree<pair<string, int> > > v; //Vector de árboles binarios

    //Métodos privados--------------------------------------------

    //Función para ordenar el vector de árboles para formar el árbol
    void ordenar_vector_treecode();
    //Función para crear el par que van el el nodo de la raiz de a y b
    pair<string, int> suma(pair<string,int> a, pair<string, int> b);

};
#endif