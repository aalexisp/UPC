#include "cjt_idiomas.hh"

//Constructoras--------------------------------------------

Cjt_Idiomas::Cjt_Idiomas(){
    map<string, Idioma> m;
}

Cjt_Idiomas::Cjt_Idiomas(const Cjt_Idiomas& c){
    m = c.m;
}

//Modificadoras--------------------------------------------

void Cjt_Idiomas::anadir_idioma(const Idioma& l){
    pair<string, Idioma> p;
    if (not existe_idioma(l.consultar_nombre())){
        p.first = l.consultar_nombre();
        p.second = l;
        m.insert(p);
    } else {
        modificar_idioma(l);
    }
}

void Cjt_Idiomas::modificar_idioma(const Idioma& l){
    m[l.consultar_nombre()] = l;
}

void Cjt_Idiomas::eliminar_idioma(string s){
    map<string, Idioma>::iterator it = m.find(s);
    if (it != m.end()) m.erase(it);
}

//Consultoras--------------------------------------------

int Cjt_Idiomas::tamano() const{
    return m.size();
}

bool Cjt_Idiomas::existe_idioma(string s) const {
    return m.find(s) != m.end(); //retorna cierto si está
}

Idioma Cjt_Idiomas::consultar_idioma(string s) const{
    map<string, Idioma>::const_iterator it = m.find(s);
    return it->second;
}

//Escritura y lectura--------------------------------------------

void Cjt_Idiomas::escribir_tabla_frec_idioma(string s) const{
    map<string, Idioma>::const_iterator it = m.find(s);
    it->second.escribir_tabla_frecuencias();
    //*it.second
}
