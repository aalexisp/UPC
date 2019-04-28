/** @file idioma.cc
    @brief Código de la clase Idioma.
*/
#include "idioma.hh"
#include "TreeCode.hh"

//Constructoras--------------------------------------------

Idioma::Idioma(string nom, const Tabla_de_frecuencias& tf){
    nombre = nom;
    t = tf; //Tabla de frecuencias
    tree = TreeCode(tf); //TreeCode
    //TreeCode auxt(tf);
    //tree = auxt;
    //m = tree.obtener_tabla_codificacion() //Texto sin codificar y decodificado
}

Idioma::Idioma(const Idioma& l){
    m = l.m;
    t = l.t;
    tree = l.tree;
    nombre = l.nombre;
}

//Modificadoras--------------------------------------------

//Sin modificadoras

//Consultoras--------------------------------------------

string Idioma::consultar_nombre() const{
    return nombre;
}

bool Idioma::existe_caracter(string s) const{
    return t.esta(s);
}

//Escritura y lectura--------------------------------------------

void Idioma::leer_tabla_frecuencias() {
    t.leer_tabla_frecuencias();
}

void Idioma::escribir_tabla_frecuencias() const{
    t.escribir_tabla_frecuencias();
}

void Idioma::escribir_treecode(){
    tree.escribir_treecode();
}

void Idioma::escribir_codigos(string st){
    tree.escribir_codigos (st);
}
