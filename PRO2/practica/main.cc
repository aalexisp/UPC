/*
#include "tabla_de_frecuencias.hh"
#include "TreeCode.hh"
#include "idioma.hh"
#include <iostream>
*/
#include "cjt_idiomas.hh"

using namespace std;

int main (){
    int n;
    cin >> n;
    Cjt_Idiomas c; //(n) tamañano n ? en la creadora ?

    for (int i = 0; i < n; ++i){
        c.anadir_modificar(); //Si el idioma ya existía se modifica la tabla
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
                c.consultar_idioma(s).escribir_treecode();
                cout << endl;
            } else if (op == "codigos"){
                /*string x;
                cin >> x;
                c.consultar_idioma(s).codifica(x);*/
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
