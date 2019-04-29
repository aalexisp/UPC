/** @file tabla_de_frecuencias.cc
    @brief Código de la clase Tabla_de_frecuencias
*/

#include "tabla_de_frecuencias.hh"

//Constructoras--------------------------------------------

Tabla_de_frecuencias::Tabla_de_frecuencias(){}

Tabla_de_frecuencias::Tabla_de_frecuencias(const Tabla_de_frecuencias& tf){
    m = tf.m;
}

//Modificadoras--------------------------------------------

void Tabla_de_frecuencias::cambio(map<string, int>::const_iterator& aux)const{
    aux = m.begin();
}

//Consultoras--------------------------------------------

int Tabla_de_frecuencias::tamano() const{
    return m.size();
}

/*
pair<string, int> Tabla_de_frecuencias::consultar_iesimo(int i) const{
    map<string, int>::const_iterator it1 = m.begin();
    while (i != 0 and it1 != m.end()){
        ++it1;
        --i;
    }
    return (*it1);
}*/

pair<string, int> Tabla_de_frecuencias::consultar_iesimo(int i, map<string, int>::const_iterator& aux)const{
    if (i == 0) return (*aux);
    else {
        ++aux;
        return (*aux);
    }
}

bool Tabla_de_frecuencias::esta(string s) const{
    return m.find(s) != m.end();
}

//Lectura y escritura--------------------------------------------

void Tabla_de_frecuencias::leer_tabla_frecuencias(){
    int n;
    cin >> n;
    pair<string, int> p;
    for (int i = 0; i < n; ++i){
        cin >> p.first >> p.second;
        if (m.find(p.first) == m.end()) {
            m.insert(p);
        }
        else modificar_frecuencias(p);
    }
}

void Tabla_de_frecuencias::escribir_tabla_frecuencias() const{
    for(map<string, int>::const_iterator it2 = m.begin(); it2 != m.end(); ++it2){
        cout << it2->first << ' ' << it2->second << endl;
    }
}

//Métodos privados--------------------------------------------

void Tabla_de_frecuencias::modificar_frecuencias(const pair<string, int>& p){
    map<string, int>::iterator it = m.find(p.first);
    it->second += p.second;
}
