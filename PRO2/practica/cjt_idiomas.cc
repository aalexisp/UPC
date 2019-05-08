/** @file cjt_idiomas.cc
    @brief Código de la lase Cjt_Idiomas
*/
#include "cjt_idiomas.hh"

//Constructoras--------------------------------------------

Cjt_Idiomas::Cjt_Idiomas(){}

Cjt_Idiomas::Cjt_Idiomas(const Cjt_Idiomas& c){
    m = c.m;
}

//Modificadoras--------------------------------------------

void Cjt_Idiomas::anadir_modificar(string nombre){
    if (m.find(nombre) == m.end()){ //si el idioma no está
        Tabla_de_frecuencias tf;
        tf.leer_tabla_frecuencias();
        Idioma l(nombre, tf);
        m.insert(make_pair(nombre, l));
    }else{
        map<string, Idioma>::iterator it = m.find(nombre);
        it->second.leer_tabla_frecuencias(); //se modifican las frec.
        it->second.modificar_treecode();
    }
}

//Consultoras--------------------------------------------

int Cjt_Idiomas::tamano() const{
    return m.size();
}

bool Cjt_Idiomas::existe_idioma(string s) const {
    return m.find(s) != m.end(); //retorna cierto si está
}

//Escritura y lectura--------------------------------------------

void Cjt_Idiomas::codifica(string s, string code){
    (m.find(s)->second).codifica(code);
}

void Cjt_Idiomas::escribir_treecode(string s)const{
    (m.find(s)->second).escribir_treecode();
}

void Cjt_Idiomas::escribir_tabla_frecuencias(string s)const{
    (m.find(s)->second).escribir_tabla_frecuencias();
}

void Cjt_Idiomas::escribir_codigos(string s, string st)const{
    (m.find(s)->second).escribir_codigos(st);
}
//void Cjt_Idiomas::codifica(string s) const;

//void Cjt_Idiomas::decodifica(string s) const;

//Métodos privados--------------------------------------------
