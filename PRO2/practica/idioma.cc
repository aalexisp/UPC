#include "idioma.hh"
#include "TreeCode.hh"

//Constructoras--------------------------------------------

Idioma::Idioma(){
    string nombre;
    map <string, string> m; //Texto sin codificar y decodificado
    Tabla_de_frecuencias t; //Tabla de frecuencias
    TreeCode tree; //TreeCode
}

Idioma::Idioma(const Idioma& l){
    m = l.m;
    t = l.t;
    tree = l.tree;
    nombre = l.nombre;
}

//Modificadoras--------------------------------------------

void Idioma::crear_idioma(){
    Tabla_de_frecuencias aux;
    aux.leer_tabla_frecuencias(); //Creamos la tabla de frecencias
    t = aux;
    //crear nodos base
    tree.crear_nodos_base(aux); //llenamos el vector de árboles con los de la tabla
    tree.crear_TreeCode(); //acabamos el árbol
}

void Idioma::modificar_tabla_frecuencias(const Tabla_de_frecuencias& tb){
    t = tb;
}

//Consultoras--------------------------------------------

Tabla_de_frecuencias Idioma::consultar_tabla_frecuencias() const{
    return t;
}

string Idioma::consultar_nombre() const{
    return nombre;
}

//Escritura y lectura--------------------------------------------

void Idioma::leer_nombre(){
    cin >> nombre;
}

void Idioma::escribir_tabla_frecuencias() const{
    t.escribir_tabla_frecuencias();
}

void Idioma::escribir_TreeCode_preorden(){
    tree.escribir_preorden(tree.consultar_treecode());
}

void Idioma::escribir_TreeCode_inorden(){
    tree.escribir_inorden(tree.consultar_treecode());
}
