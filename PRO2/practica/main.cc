#include <iostream>
#include "tabla_de_frecuencias.hh"
#include "TreeCode.hh"
#include "idioma.hh"
#include "cjt_idiomas.hh"

using namespace std;

int main (){
    int n;
    cin >> n;
    Cjt_Idiomas c; //(n) tamañano n ? en la creadora ?

    for (int i = 0; i < n; ++i){
        Idioma l;
        l.leer_nombre();
        l.crear_idioma();
        c.anadir_idioma(l); //Si el idioma ya existía sustituye la tabla de frecuencias
    }
    string op; //nombre de la opción
    string s; //nombre del idioma
    while (cin >> op and op != "fin"){
        cin >> s; //leemos el nombre del idioma
        if (c.existe_idioma(s)){
            if (op == "tabla_frec"){
                //Mostrar la tabla de frecuencia del idioma s
                cout << "Tabla de frecuencias de " << s << ":" << endl;
                c.consultar_idioma(s).escribir_tabla_frecuencias(); //(l)?
                cout << endl;
            } else if (op == "treecode"){
                cout << "Treecode de " << s << ":" << endl;
                cout << "recorrido en preorden:" << endl;
                c.consultar_idioma(s).escribir_TreeCode_preorden();
                cout << "recorrido en inorden:" << endl;
                c.consultar_idioma(s).escribir_TreeCode_inorden();
                cout << endl;
            } else if (op == "codigos"){
                //Escribir códigos
            }
        } else {
            if (op == "tabla_frec"){
                cout << "Tabla de frecuencias de " << s << ':' << endl;
                cout << "El idioma no existe" << endl;
                cout << endl;
            } else if (op == "treecode"){
                cout << "Treecode de " << s << ':' << endl;
                cout << "El idioma no existe" << endl;
                cout << endl;
            } else if (op == "codigos"){
                cout << "Codigos de " << s << ':' << endl;
                cout << "El idioma no existe" << endl;
                cout << endl;
            }
        }
    }
}
