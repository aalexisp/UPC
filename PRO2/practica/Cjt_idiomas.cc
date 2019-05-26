/** @file Cjt_idiomas.cc
    @brief Código de la clase Cjt_Idiomas
*/

#include "Cjt_idiomas.hh"

    //--------------------------------------------Constructoras--------------------------------------------

//Constructora por defecto.
Cjt_Idiomas::Cjt_Idiomas(){}

    //--------------------------------------------Modificadoras--------------------------------------------

void Cjt_Idiomas::anadir_modificar(string nombre){
    //La función añade o modifica un idioma según el nombre que tenga. Esta constructora hace llamadas
    //a métodos públicos de otras funciones que son las que leen de la entrada
    //los datos correspondientes para formar el idioma.
    //Aqui simplemente se crean variables necesarias para la llamda y se añade al diccionario de Idiomas.
    if (m.find(nombre) == m.end()){ //Si el idioma no está:
        Tabla_de_frecuencias tf; //Declaramos una Tabla_de_frecuencias.
        tf.leer_tabla_frecuencias(); //Y la leemos.
        Idioma l(nombre, tf);
        m.insert(make_pair(nombre, l));
    }else{
        map<string, Idioma>::iterator it = m.find(nombre); //Se declara un iterador para ir mirando el idioma que hay que modificar.
        it->second.leer_tabla_frecuencias(); //Se modifican las frecuencias dado que está función lo hace así a parte de leer las frecuencias para añadir.
        it->second.modificar_treecode();
    }
}

    //--------------------------------------------Consultoras--------------------------------------------

bool Cjt_Idiomas::existe_idioma(string s) const {
    //Retorna cierto si está.
    return m.find(s) != m.end();
}

    //--------------------------------------------Escritura y lectura--------------------------------------------

void Cjt_Idiomas::codifica(const string& s, const string& code){
    //Función para codificar un texto s. Hace una llamada a otro método público de Idioma que realiza la tarea.
    (m.find(s)->second).escribir_codificado(code);
}

void Cjt_Idiomas::decodifica(const string& s, const string& code){
        //Función para decodificar un texto s. Hace una llamada a otro método público de Idioma que realiza la tarea.
    (m.find(s)->second).escribir_decodificado(code);
}

void Cjt_Idiomas::escribir_treecode(string s)const{
    //Función para escribir el TreeCode en función de su nombre s. Hace una llamada a otro método público de Idioma que realiza la tarea.
    (m.find(s)->second).escribir_treecode();
}

void Cjt_Idiomas::escribir_tabla_frecuencias(string s)const{
    //Función para escribir el la Tabla_De_frecuencias en función de su nombre s. Hace una llamada a otro método público de idioma que realiza la tarea.
    (m.find(s)->second).escribir_tabla_frecuencias();
}

void Cjt_Idiomas::escribir_codigos(string s, string st)const{
    //Función para escribir los códigos de una Idioma según su nombre s.
    (m.find(s)->second).escribir_codigos(st);
}

    //--------------------------------------------Métodos privados--------------------------------------------

    //                                          Sin métodos privados
