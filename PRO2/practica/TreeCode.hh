//Build 6.0
/** @file TreeCode.hh
    @brief Especificación de la clase TreeCode
*/
#ifndef TREECODE_HH
#define TREECODE_HH

#include "Tabla_de_frecuencias.hh"

#ifndef NO_DIAGRAM
#include "BinTree.hh"
#include <vector>
#include <algorithm>
#endif

/*
 * Clase Tabla_de_frecuencias
 */

/** @class TreeCode
    @brief Representa los caracteres y frecuencias de un Idioma.

    Caracterizado por ser un árbol binario.
    Se forma apartir de la Tabla_de_frecuencias de forma recursiva.
*/
class TreeCode {

private:
    /* Esta clase es la base de toda la práctica. Con el TreeCode se realizan todas las funcionalidades que se precisan
       para la entrega de la práctica. El TreeCode se basa en los BinTree. Así pues se usa uno como atributo para
       la formación de este. En realidad, la formación completa del TreeCode viene dada por el vector de BinTree.
       Cabe destacar que la implementación con vectores puede no ser del todo eficiente al tener que ordenar
       el vector mediante el método de "burbuja reducido" (hacer swaps hasta llegar a la posición que toca). Además
       de usar el Push_back en algunas ocasiones que para casos extremos va mal. En cambio si se hubiese usado un Conjunto (set)
       que se ordena según un convenio que se le da. Pero para realizar una mejor presentación de la practica, dado
       que pienso que la eficiencia no debería influir demasiado en el uso de uno u otro he optado por esta.
       (Lo implementé con conjuntos y pienso que era bastante más complejo de ver a simple vista)*/

    //--------------------------------------------Atributos--------------------------------------------

    /** @brief Árbol binario por defecto. */
    BinTree<pair<string, int> > t;
    /** @brief Vector de BinTree's para crear el TreeCode. */
    vector<BinTree<pair<string, int> > > v;
    /** @brief Tabla de códigos, hecha con un Diccionario, clave, valor, con el carácter y su representación en 0 y 1. */
    map<string, string> tm;

public:

    //--------------------------------------------Constructoras--------------------------------------------

    /** @brief Creadora por defecto sin parámetros.

        Se ejecuta automáticamente al declarar un TreeCode.
        @pre <em>cierto</em>.
        @post El resultado es un TreeCode vacío, un árbol binario.
    */
    TreeCode();

    /** @brief Creadora por defecto con parámetros.

        Se ejecuta automáticamente al declarar un TreeCode.
        @pre <em>cierto</em>.
        @post El resultado es un TreeCode vacío, un árbol binario.
    */
    TreeCode(Tabla_de_frecuencias& tf);

    //--------------------------------------------Lectura y escritura--------------------------------------------

    /** @brief Operación de escritura del treecode.

        \pre <em>cierto</em>.
        \post Se escribe el TreeCode en preorden e inorden por el canal estándar de salida.
    */
    void escribir_treecode() const;

    /** @brief Operación de escritura de la tabla de codigos.

        \pre <em>cierto</em>.
        \post Se escribe el TreeCode en preorden e inorden por el canal estándar de salida.
    */
    void escribir_codigos(string s) const;

    /** @brief Operación de escritura del texto codificado
        \pre El texto s existe y es codificable.
        \post Se retorna el texto codificado en 0's y 1's.
    */
    void escribir_codificado(const string& s);

    /** @brief Función para decodificar los textos.
        \pre El texto s existe y es decodificable.
        \post Se retorna el texto decodificado como un string.
    */
    void escribir_decodificado(const string& s);

private:

    //--------------------------------------------Métodos privados--------------------------------------------

    /** @brief Función para escribir el treecode en preorden.
        @pre El treecode está lleno y tiene valores correctos.
        @post Se ha escrito el treecode en preorden por el canal estándar de salida.
    */
    void escribir_preorden(const BinTree<pair<string, int> >& b) const;

    /** @brief Función para escribir el treecode en inorden.
        @pre El treecode está lleno y tiene valores correctos.
        @post Se ha escrito el treecode en inorden por el canal estándar de salida.
    */
    void escribir_inorden(const BinTree<pair<string, int> >& b) const;

    /** @brief Función para sumar las frecuencias de diversas tablas.
        @pre La tabla de frecuencias del p.i tiene valores.
        @post Las frecuencias de la tabla del p.i pasa a tener nuevos valores.
    */
    pair<string, int> suma(const pair<string,int>& a, const pair<string, int>& b);

    /** @brief Llena el vector de árboles (nodos base).
        @pre El vector de bintrees ha sido declarado y está vacío.
        @post El parámetro implícito pasa a contener los valores de la tabla de frecuencias.
    */
    void crear_nodos_base(Tabla_de_frecuencias& tf);

    /** @brief Función para insertar un bintree en el vector de bintree's.
        @pre <em>cierto</em>
        @post El bintree "tree" queda incluído en el vector del p.i.
    */
    void insertar(BinTree<pair<string, int> >& tree);

    /** @brief Llena el TreeCode con los valores correspondientes.
        @pre El TreeCode ha sido declarado y está vacío.
        @post El parámetro implícito pasa a contener los valores correspondientes.
    */
    void crear_TreeCode();

    /** @brief Crea la tabla de códigos de cada carácter.
        @pre El TreecCode y la Tabla_de_frecuencias existen y tienen valores.
        @post La tabla de códigos pasa a contener sus valores correspondientes.
    */
    void crear_tabla_codigos(const BinTree<pair<string, int> >& tc, const pair<string, string>& p, const Tabla_de_frecuencias& tf);

    /** @brief Función para codificar los textos.
        @pre El texto existe.
        @post Se retorna el texto codificado en 0's y 1's si ha sido posible la codificación.
    */
    bool codifica_immersion(const string& s, string& res, map<string, string>::const_iterator& it, int& i);

    /** @brief Función para decodificar los textos.
        @pre El código existe.
        @post Se retorna el texto decodificado en carácteres que tiene el Idioma si ha sido posible la decodificación.
    */
    bool decodifica_immersion(const string& s, const BinTree<pair<string, int> >& bt, int& i, string& res, int& ult);

};
#endif
