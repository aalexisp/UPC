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
    //crear nodos base
    tree.crear_nodos_base(t); //llenamos el vector de árboles con los de la tabla
    tree.crear_TreeCode(); //acabamos el árbol
}

//Consultoras--------------------------------------------

string Idioma::consultar_nombre() const{
    return nombre;
}

//Escritura y lectura--------------------------------------------

void Idioma::leer_nombre(){
    cin >> nombre;
}

void Idioma::leer_tabla_frecuencias() {
    t.leer_tabla_frecuencias();
}

void Idioma::escribir_tabla_frecuencias() const{
    t.escribir_tabla_frecuencias();
}

void Idioma::escribir_treecode(){
    tree.escribir_treecode();
}
