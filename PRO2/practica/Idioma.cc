/** @file Idioma.cc
    @brief Código de la clase Idioma.
*/
#include "Idioma.hh"
#include "TreeCode.hh"

    //--------------------------------------------Constructoras--------------------------------------------

Idioma::Idioma(string nom, Tabla_de_frecuencias& tf){
    //En la Constructora creamos el Idioma a partir de la constructura de TreeCode.
    //Además le pasamos una Tabla_de_frecuencias para crear este árbol.
    nombre = nom;
    tbl = tf; //Tabla_de_frecuencias
    tree = TreeCode(tf); //TreeCode
}

    //--------------------------------------------Modificadoras--------------------------------------------

void Idioma::modificar_treecode(){
    //Función para modificar el TreeCode.
    //Básicamente como en la constructora de TreeCode se crea un nuevo árbol. Hacemos el nuevo
    //y lo asignamos al tree del parametro implícito.
    tree = TreeCode(tbl);
}

    //--------------------------------------------Escritura y lectura--------------------------------------------

void Idioma::leer_tabla_frecuencias() {
    //Función para leer una Tabla_de_frecuencias. (Se llama a un método de Tabla_de_frecuencias).
    tbl.leer_tabla_frecuencias();
}

void Idioma::escribir_tabla_frecuencias() const{
    //Función para escribir la Tabla_de_frecuencias. (Se llama a un método público de Tabla_de_frecuencias).
    tbl.escribir_tabla_frecuencias();
}

void Idioma::escribir_treecode()const{
    //Función para escribir el TreeCode. (Se llama a un método público de TreeCode).
    tree.escribir_treecode();
}

void Idioma::escribir_codigos(string st)const{
    //Función para escribir los códigos de un Idioma. (Se llama a un método público de TreeCode).
    tree.escribir_codigos (st);
}

void Idioma::escribir_codificado(const string& s){
    //Función para escribir un texto s en 0's y 1's. (Se llama a un método público de TreeCode).
    tree.escribir_codificado(s);
}

void Idioma::escribir_decodificado(const string& s){
    //Función para escribir un código en 0's y 1's a carácteres. (Se llama a un método público de TreeCode).
    tree.escribir_decodificado(s);
}
