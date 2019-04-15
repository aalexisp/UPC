//Build 1.0
/** @file Frecuencias.hh
    @brief Especificación de la clase Frecuencias
*/
#ifndef FRECUENCIAS_HH
#define FRECUENCIAS_HH

#include <iostream>
// #include "BinTree.hh"
#include <map>
#include <string>
using namespace std;

/** @class Frecuencias
    @brief Representa la tabla de frecuencias de un idioma

    Caracterizado por crear el árbol binario
*/
class Tabla_Frecuencias {
    
    //Constructoras--------------------------------------------

    /** @brief Creadora por defecto.

        Se ejecuta automáticamente al declarar un idioma.
        \pre <em>cierto</em>
        \post El resultado es una tabla de frecuencias vacía
        \coste Constante
    */
    
    Tabla_Frecuencias();

    /** @brief Creadora copiadora.

        Permite declarar una tabla de frecuencias que ya existía
        \pre <em>cierto</em>
        \post El resultado es una tabla de frecuencias igual que otra ya existente
        \coste Lineal ????
    */
    
    Tabla_Frecuencias(const Tabla_Frecuencias& t);

    //Modificadoras--------------------------------------------
    
    /** @brief Modifica la tabla de frecuencias con los valores correspondientes
        \pre La tabla de frecuencias no está vacía y tiene valores válidos
        \post El parámetro implícito para a estar modificado con los nuevos valores que le hemos dado
        \coste lineal ?
     */ 
        
    void modificar_frecuencia(); //Modifica la frecuencia, número
    
//     void borrar_tabla_frecuencias(); ???

    
    //Consultoras--------------------------------------------
    
    /** @brief Consulta el carácter del idioma según su frecuencia
        \pre El primer elemento del p.i no está vacío
        \post El resultado es el carácter (lo retorna)
        \coste ???
     */
    
    void consultar_caracter(string s) const; //Para consultar el carácter
    
    /** @brief Consulta la frecuencia del carácter correspondiente
        \pre El segundo elemento del p.i no está vacío
        \post El resultado es el numéro, la frecuencia del carácter (lo retorna)
        \coste ???
     */
    
    void consultar_frecuencia() const; //Para consultar la frecuencia del carácter
    
    //Lectura y escritura--------------------------------------------
    
    
     /** @brief Llena la tabla de frecuencias con los valores correspondientes
        \pre La tabla de frecuencias ha sido declarada y está vacía
        \post El parámetro implícito (?) pasa a contener los valores correspondientes
        \coste lineal ?
    */
    
    void leer_tabla_frecuencias();
    
    /** @brief Operación de escritura
     
        \pre <em>cierto</em>
        \post Escribe la tabla de frecuencias a partir de sus carácteres y sus frecuencias, el del parámetro implícito por el canal estándar de salida
        \coste ??? respecto los valores del map
     */
    
    void escribir_tabla_frecuencias() const; //Frecuencia y carácter

    
private:
    //Atributos--------------------------------------------
    map <string, int> m; //Valores que van dentro del árbol
    //...
    
    /** @brief Ordena la tabla de frecuencias el el orden pedido para el árbol
        \pre La tabla de frecuencias no está vacía y tiene valores válidos
        \post El parámetro implícito pasa a estar ordenado según la ordenación pedida
        \coste logarítmico ?
     */
    
    void ordena_tabla_frecuencias(); //Necesaria ?
};
#endif
