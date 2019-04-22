//Build 3.0
/** @file cjt_idiomas.hh
    @brief Especificación de la clase cjt_idiomas
*/
#ifndef CJT_IDIOMAS_HH
#define CJT_IDIOMAS_HH

#include "idioma.hh"

/** @class Cjt_Idiomas
    @brief Representa un conjuto de Idioma.

    Caracterizado por un diccionario de Idioma.
*/

class Cjt_Idiomas{
public:
    //Constructoras--------------------------------------------

    /** @brief Creadora por defecto.

        Se ejecuta automáticamente al declarar un conjunto de idiomas.
        \pre <em>cierto</em>.
        \post El resultado es un conjunto de idioma vacío sin idiomas.
    */

    Cjt_Idiomas();

    /** @brief Creadora copiadora.

        Permite declarar un idioma como copia de otro que ya existía.
        \pre <em>cierto</em>.
        \post El resultado es un idioma igual que i.
    */

    Cjt_Idiomas(const Cjt_Idiomas& c);

    //Modificadoras--------------------------------------------

    /** @brief Añade el idioma l al conjunto.
        \pre El idioma es válido y no está repetido (si lo está cambio la tabla de frecuencias y treecode).
        \post El idioma l ha sido añadido al conjunto.
     */

    void anadir_modificar();

    /** @brief Se elimina un idioma del conjunto a partir de su nombre.
        \pre El idioma existiía en el conjunto.
        \post El idioma ha sido eliminado del conjunto.
    */

    void eliminar_idioma(string s); //en cjt

    //Consultoras--------------------------------------------

    /** @brief Consulta el tamaño del conjunto.
        \pre <em>cierto</em>.
        \post Retorna el tamaño del conjunto.
     */

    int tamano() const;

    /** @brief Consulta si el idioma está en el conjunto
        \pre <em>cierto</em>
        \post Retorna cierto si el idioma está en el conjunto, falso en caso contrario
     */

    bool existe_idioma(string s) const;

    /** @brief Consulta el idioma a partir un nombre.
        \pre El idioma existe.
        \post Retorna el idioma con nombre s.
     */

    Idioma consultar_idioma(string s) const;

    //Escritura y lectura--------------------------------------------

        /** @brief Operación de escritura del código codificado.
        \pre <em>cierto</em>.
        \post Se ha escrito el texto codificado por en canal estándar de salida.
     */

    void codifica(string s) const;

    /** @brief Operación de escritura del código decodificado.
        \pre <em>cierto</em>.
        \post Se ha escrito el texto decodificado por el canal estándar de salida.
     */
    void decodifica(string s) const;

private:
    //Atributos--------------------------------------------

    map<string, Idioma> m; //nombre del idioma y el idioma
};
#endif
