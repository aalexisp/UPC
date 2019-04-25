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

void Cjt_Idiomas::anadir_modificar(){
    string nombre;
    cin >> nombre;
    if (m.find(nombre) == m.end()){ //si el idioma no está
        Tabla_de_frecuencias tf;
        tf.leer_tabla_frecuencias();
        Idioma l(nombre, tf);
        m.insert(make_pair(nombre, l));
    }else{
        map<string, Idioma>::iterator it;
        it = m.find(nombre);
        it->second.leer_tabla_frecuencias();
    }
}

void Cjt_Idiomas::eliminar_idioma(string s){
    map<string, Idioma>::iterator it = m.find(s);
    if (it != m.end()) m.erase(it);
} //NO USADO 

//Consultoras--------------------------------------------

int Cjt_Idiomas::tamano() const{
    return m.size();
}

bool Cjt_Idiomas::existe_idioma(string s) const {
    return m.find(s) != m.end(); //retorna cierto si está
}

//Escritura y lectura--------------------------------------------

void Cjt_Idiomas::escribir_treecode(string s)const{
    consultar_idioma(s).escribir_treecode();
}

void Cjt_Idiomas::escribir_tabla_frecuencias(string s)const{
    consultar_idioma(s).escribir_tabla_frecuencias();
}

void Cjt_Idiomas::escribir_codigos(string s, string st)const{
    consultar_idioma(s).escribir_codigos(st);
}
//void Cjt_Idiomas::codifica(string s) const;

//void Cjt_Idiomas::decodifica(string s) const;

//Métodos privados--------------------------------------------

Idioma Cjt_Idiomas::consultar_idioma(string s) const{
    map<string, Idioma>::const_iterator it = m.find(s);
    return it->second;
}
