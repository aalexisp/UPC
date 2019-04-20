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

map<string, int> Tabla_de_frecuencias::consultar_tabla_frecuencias() const{
    return m; //get freq table
}

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

bool ordena_tabla_frecuencias(string a, string b){
    return a < b;
}
