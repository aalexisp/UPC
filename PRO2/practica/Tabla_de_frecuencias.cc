/** @file Tabla_de_frecuencias.cc
    @brief Código de la clase Tabla_de_frecuencias
*/

#include "Tabla_de_frecuencias.hh"

    //--------------------------------------------Constructoras--------------------------------------------

//Creadora por defecto
Tabla_de_frecuencias::Tabla_de_frecuencias(){}

    //--------------------------------------------Modificadoras--------------------------------------------

void Tabla_de_frecuencias::inicializa_recorrido() {
    //Inicializa el recorrido del iterador del diccionario del p.i en el inicio m.begin().
    aux = m.begin();
}

    //--------------------------------------------Consultoras--------------------------------------------

int Tabla_de_frecuencias::tamano() const{
    //Retorna el tamaño de la Tabla_de_frecuencias (Diccionario).
    return m.size();
}

pair<string, int> Tabla_de_frecuencias::consultar_proximo() {
    //Esta función se utiliza dentro de un bucle en TreeCode con el fin de hacerle llegar
    //todos los pares sting, int, osea todos los carácteres y frecuencias al TreeCode para crearlo.
    pair<string, int> tmp = *aux;
    ++aux;
    return (tmp);
}

bool Tabla_de_frecuencias::esta(string s) const{
    //Retorna cierto si el carácter s se encuentra en la Tabla_de_frecuencias.
    return m.find(s) != m.end();
}

    //--------------------------------------------Lectura y escritura--------------------------------------------

void Tabla_de_frecuencias::leer_tabla_frecuencias(){
    //Función para leer la Tabla_de_frecuencias. Si el carácter que nos entra ya está en la tabla
    //entonces se modifica. Si no se añade con su respectiva frecuencia.
    int n;
    cin >> n;
    pair<string, int> p;
    //Pre: cierto.
    //Invariante: Lo que nos va entrando son pares string, int, es decir, carácteres y frecuencias.
    for (int i = 0; i < n; ++i){
        cin >> p.first >> p.second;
        if (m.find(p.first) == m.end()) {
            m.insert(p);
        }
        else modificar_frecuencias(p);
    }
    //Post: La Tabla_de_frecuencias pasa a contener los valores correspondientes.
}

void Tabla_de_frecuencias::escribir_tabla_frecuencias() const{
    //Función para escribir la Tabla_de_frecuencias.
    //Pre: La tabla existe y está creada.
    //Invariante: Los valores que imprimimos siempre son pares string, int, es decir, carácteres y frecuencias.
    for(map<string, int>::const_iterator it2 = m.begin(); it2 != m.end(); ++it2){
        cout << it2->first << ' ' << it2->second << endl;
    }
    //Post: La Tabla_de_frecuencias ha sido escrita por el canal estándar de salida.
}

    //--------------------------------------------Métodos privados--------------------------------------------

void Tabla_de_frecuencias::modificar_frecuencias(const pair<string, int>& p){
    //Función para modificar las frecuencias a partir de un carácter y su frecuencia. Estas se suman.
    //Como se tiene que modificar algo del p.i se usa un iterador y no es constante como el que hay como
    //atributo asi que es posible usar ese.
    map<string, int>::iterator it = m.find(p.first);
    it->second += p.second;
}
