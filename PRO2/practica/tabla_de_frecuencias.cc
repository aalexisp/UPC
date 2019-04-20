#include "tabla_de_frecuencias.hh"

//Constructoras--------------------------------------------

Tabla_de_frecuencias::Tabla_de_frecuencias(){
    map <string, int> m;
}

Tabla_de_frecuencias::Tabla_de_frecuencias(const Tabla_de_frecuencias& t){
    m = t.m;
}

//Modificadoras--------------------------------------------

//Por determinar

//Consultoras--------------------------------------------

int Tabla_de_frecuencias::tamano(){
    return m.size();
}

pair<string, int> Tabla_de_frecuencias::consultar_iesimo(int i){
    it = m.begin();
    while (i != 0 and it != m.end()){
        ++it;
        --i;
    }
    return (*it);
}

/*
string Tabla_de_frecuencias::consultar_iesimo_string(int i){
    it = m.begin();
    while (i != 0){
        ++it;
        --i;
    }
    return it->first;
}

int Tabla_de_frecuencias::consultar_iesimo_int(int i){
    it = m.begin();
    while (i != 0){
        ++it;
        --i;
    }
    return it->second;
}
*/

//Lectura y escritura--------------------------------------------

void Tabla_de_frecuencias::leer_tabla_frecuencias(){
    int n;
    cin >> n;
    pair<string, int> p;
    for (int i = 0; i < n; ++i){
        cin >> p.first >> p.second;
        m.insert(p);
    }
}

void Tabla_de_frecuencias::escribir_tabla_frecuencias() const{
    for(map<string, int>::const_iterator it = m.begin(); it != m.end(); ++it){
        cout << it->first << ' ' << it->second << endl;
    }
}

//Métodos privados--------------------------------------------
//Por definir
