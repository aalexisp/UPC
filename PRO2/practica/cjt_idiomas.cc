#include "cjt_idiomas.hh"

//Constructoras--------------------------------------------

Cjt_Idiomas::Cjt_Idiomas(){
    map<string, Idioma> m;
}

Cjt_Idiomas::Cjt_Idiomas(const Cjt_Idiomas& c){
    m = c.m;
}

//Modificadoras--------------------------------------------

void Cjt_Idiomas::anadir_modificar(){
    Idioma l;
    l.leer_nombre();
    if (m.find(l.consultar_nombre()) == m.end()){ //si el idioma no está
        l.leer_tabla_frecuencias();
    }else{
        map<string, Idioma>::iterator it = m.begin();
        it = m.find(l.consultar_nombre());
        it->second.leer_tabla_frecuencias();
    }
    l.crear_idioma();
    m.insert(make_pair(l.consultar_nombre(), l));
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

//void Cjt_Idiomas::codifica(string s) const;

//void Cjt_Idiomas::decodifica(string s) const;
