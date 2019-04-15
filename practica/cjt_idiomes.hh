//Build 1.0
/** @file cjt_idiomes.hh
    @brief Especificación de la clase cjt_idiomes
*/
#ifndef CJT_IDIOMES_HH
#define CJT_IDIOMES_HH

#include "idioma.hh"

/** @class Cjt_Idiomas
    @brief Representa un conjuto de idiomas

    Se caracteríza por definirse como un vector de idiomas
*/

class Cjt_Idiomas{

    //Constructora--------------------------------------------

    /** @brief Creadora por defecto.

        Se ejecuta automáticamente al declarar un conjunto de idiomas.
        \pre <em>cierto</em>
        \post El resultado es un conjunto de idioma vacío sin idiomas.
        \coste Constante
    */

    Cjt_Idiomas();

    /** @brief Creadora copiadora.

        Permite declarar un idioma como copia de otro que ya existía
        \pre <em>cierto</em>
        \post El resultado es un idioma igual que i
        \coste Lineal ????
    */

    Cjt_Idiomas(const Cjt_Idiomas& c;)

    //Modificadoras--------------------------------------------

    /** @brief Añade el idioma l al conjunto
        \pre El idioma es válido y no está repetido (si lo está cambio tabla?)
        \post El idioma l ha sido añadido al conjunto
        \coste ??
     */

    void añadir_idioma(const Idioma& l);

    /** @brief Se modifica el idioma del conjunto por el nuevo, l
        \pre El idioma que hay en el conjunto existe
        \post El idioma del conjunto ha sido modificado por el nuevo l
        \coste ??
     */

    void modificar_idioma(string s, const Tabla_Frecuencia& l);

    void eliminar_idioma(); //en cjt

    //Consultoras--------------------------------------------

    /** @brief Consulta el tamaño del conjunto
        \pre <em>cierto</em>
        \post Retorna el tamaño del conjunto
        \coste
     */

    int tamaño() const; //????

    /** @brief Consulta si el idioma está en el conjunto
        \pre <em>cierto</em>
        \post Retorna cierto si el idioma está en el conjunto, falso en caso contrario
        \coste ??
     */

    bool existe_idioma();

    /** @brief Consulta el idioma según su nombre ?
        \pre El idioma existe
        \post Retorna el idioma con nombre s
        \coste ??
     */

    void consultar_idioma(string s);

    //Escritura y lectura--------------------------------------------

    /** @brief Operación de escritura de la tabla de frecuencia de un idioma
        \pre El idioma existe y su tabla no es vacía (si lo fuese se notificaría?)
        \post Se ha escrito por el canal estándar de salida la tabla de frecuencia (se llama a escribir del Idioma y luego a Frecuencias)
        \coste ??
     */
    void escribir_tabla_freq_idioma();

        /** @brief Operación de escritura del código codificado
        \pre <em>cierto</em>
        \post Se ha escrito el texto codificado por en canal estándar de salida
        \coste ??
     */

    void codifica() const;

    /** @brief Operación de escritura del código decodificado
        \pre <em>cierto</em>
        \post Se ha escrito el texto decodificado por el canal estándar de salida
        \coste ??
     */
    void decodifica() const;

private:
    //Atributos--------------------------------------------
    map<string, Idioma> m; //nombre del idioma y el idioma
    static const int MAX_TAM; //Si fuese necesario
};
#endif
