#include "cjt_idiomas.hh"

int main (){
    int n;
    cin >> n;
    Cjt_Idiomas c; //(n) tamañano n ? en la creadora ?

    for (int i = 0; i < n; ++i){
        c.anadir_modificar(); //Si el idioma ya existía se modifica la tabla
    }

    string op; //nombre de la opción
    string s; //nombre del idioma
    string st; //para los codigos
    bool primer = true;
    while (cin >> op and op != "fin"){
        cin >> s; //leemos el nombre del idioma
        if (primer){
            primer = false;
        } else cout << endl;
        if (c.existe_idioma(s)){
            if (op == "tabla_frec"){
                //Mostrar la tabla de frecuencia del idioma s
                cout << "Tabla de frecuencias de " << s << ':' << endl;
                c.consultar_idioma(s).escribir_tabla_frecuencias();
            } else if (op == "treecode"){
                //Mostrar el treecode del idioma s
                cout << "Treecode de " << s << ':' << endl;
                c.consultar_idioma(s).escribir_treecode();
            } else if (op == "codigos"){
                //Mostrar los códigos del idioma s
                cin >> st;
                if (st == "todos") cout << "Codigos de " << s << ':' << endl;
                else cout << "Codigo de " << st << " en " << s << ":" << endl;
                c.consultar_idioma(s).escribir_codigos(st);
            }
        } else {
            if (op == "tabla_frec"){
                cout << "Tabla de frecuencias de " << s << ':' << endl;
                cout << "El idioma no existe" << endl;
            } else if (op == "treecode"){
                cout << "Treecode de " << s << ':' << endl;
                cout << "El idioma no existe" << endl;
            } else if (op == "codigos"){
                cin >> st;
                if (st == "todos"){
                    cout << "Codigos de " << s << ':' << endl;
                    cout << "El idioma no existe" << endl;
                } else {
                    cout << "Codigo de " << st << " en " << s << ":" << endl;
                    cout << "El idioma no existe o el caracter no esta en el idioma" << endl;
                }
            }
        }
    }
}
