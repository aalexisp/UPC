//Build 3.0
/** @file tabla_de_frecuencias.hh
    @brief Especificación de la clase tabla_de_frecuencias
*/
#ifndef TABLA_DE_FRECUENCIAS_HH
#define TABLA_DE_FRECUENCIAS_HH

#ifndef NO_DIAGRAM
#include <iostream>
#include <map>
#include <string>
#endif

using namespace std;

/** @class Tabla_de_frecuencias
    @brief Representa la tabla de frecuencias de un idioma.

    Caracterizado por crear el árbol binario.
*/
class Tabla_de_frecuencias {
public:
    //Constructoras--------------------------------------------

    /** @brief Creadora por defecto.

        Se ejecuta automáticamente al declarar un idioma.
        \pre <em>cierto</em>.
        \post El resultado es una tabla de frecuencias vacía.
    */

    Tabla_de_frecuencias();

    /** @brief Creadora copiadora.

        Permite declarar una tabla de frecuencias que ya existía.
        \pre <em>cierto</em>.
        \post El resultado es una tabla de frecuencias igual que otra ya existente.
    */

    Tabla_de_frecuencias(const Tabla_de_frecuencias& t);

    //Modificadoras--------------------------------------------

    /** @brief Modifica la frecuencia de un carácter.
        \pre El carácter existe y tiene frecuencia.
        \post La frecuencia del carácter ha sido modificada.
    */
    void modificar_frecuencias(const pair<string, int>& p);

    //Consultoras--------------------------------------------

    /** @brief Consulta el tamaño de la tabla de frecuencias.
        \pre La tabla de frecuencia existe.
        \post Retorna el tamaño de la tabla de frecuencias.
    */

    int tamano() const;

    /** @brief Consulta el par string, int (caràcter, frecuencia).
        \pre El diccionario del p.i no está vacío, si 0 <= i <= m.size().
        \post El resultado es el par caracter, frecuencia.
     */

    pair<string, int> consultar_iesimo(int i); //Para consultar el caracter y frecuencia

//  string consultar_iesimo_string(int i); //Para consultar el par carácter, frecuencia
//  int consultar_iesimo_int(int i);

    //Lectura y escritura--------------------------------------------


     /** @brief Llena la tabla de frecuencias con pares string, int (carácter, frecuencia).
        \pre La tabla de frecuencias ha sido declarada y está vacía.
        \post El parámetro implícito pasa a contener los pares string, int.
    */

    void leer_tabla_frecuencias();

    /** @brief Operación de escritura.

        \pre <em>cierto</em>.
        \post Escribe la tabla de frecuencias por el canal estándar de salida.
     */

    void escribir_tabla_frecuencias() const; //Frecuencias y carácteres


private:
    //Atributos--------------------------------------------
    map <string, int> m; //Valores que van dentro del árbol
    map<string, int>::iterator it; //Iterador para el map
    //Métodos privados--------------------------------------------
//por definir
};
#endif
