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

void Idioma::modificar_treecode(){
    tree = TreeCode(t);
}

//Consultoras--------------------------------------------

void Idioma::codifica(string s){
    map<string, string>::const_iterator it;
    int i = 0;
    string res = "";
    string out = tree.codifica(s, res, it, i);
    if (i < s.length() or out == s) cout << "El texto no pertenece al idioma; primer caracter que falla: " << out << endl;
    else cout << res << endl;
}

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

void Idioma::escribir_treecode()const{
    tree.escribir_treecode();
}

void Idioma::escribir_codigos(string st)const{
    tree.escribir_codigos (st);
}
