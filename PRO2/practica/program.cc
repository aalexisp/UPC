/** @mainpage

    El programa principal se encuentra en el módulo main.cc
    Dados los tipos de datos aportados por el enunciado, necesitaremos un módulo
    para representar un Conjunto de Idiomas en el cual incluiremos otro
    módulo que será utilizado para representar un Idioma. Además será
    preciso requerir de otro módulo para representar una Tabla de frecuencias
    junto con un último módulo usado para dejar constancia de un TreeCode
    necesarios para la creación de nuestro idioma.

    Comentarios:

    - En un primer vistazo, comenzaríamos por considerar las operaciones que
    vamos a necesitar para el programa principal y utilizaremos una serie
    de condiciones en las cuales utilizaremos un módulo diferente para cada
    operación.

    - Cabe remarcar que no todas las operaciones de escritura, es decir, la
    operación "cout" no aparecen en el main, pues era necesario usarlas
    dentro de algún módulo según la disposición que se ha realizado de las clases.

    - Nótese que en comparación con la especificación entregada incialmente
    se han borrado o añadido nuevas funciones, pues ha sido necesario
    dado que a partir de modificaciones de eficiencia se ha debido cambiar
    estas funciones.
*/

/** @file program.cc

    @brief Programa principal



*/

#include "cjt_idiomas.hh"

int main (){
    int n;
    cin >> n;
    Cjt_Idiomas c;
    
    for (int i = 0; i < n; ++i){
        c.anadir_modificar(); //Si el idioma ya existía se modifica la tabla
    }

    string op; //nombre de la opción
    string s; //nombre del idioma
    string st; //para los codigos
    //bool primer = true;
    while (cin >> op and op != "fin"){
        cin >> s; //leemos el nombre del idioma
        /*if (primer){
            primer = false;
        } else cout << endl;*/
        if (c.existe_idioma(s)){
            if (op == "tabla_frec"){
                //Mostrar la tabla de frecuencia del idioma s
                cout << "Tabla de frecuencias de " << s << ':' << endl;
                c.escribir_tabla_frecuencias(s);
                cout << endl;
            } else if (op == "treecode"){
                //Mostrar el treecode del idioma s
                cout << "Treecode de " << s << ':' << endl;
                c.escribir_treecode(s);
                cout << endl;
            } else if (op == "codigos"){
                //Mostrar los códigos del idioma s
                cin >> st;
                if (st == "todos") cout << "Codigos de " << s << ':' << endl;
                else cout << "Codigo de " << st << " en " << s << ":" << endl;
                c.escribir_codigos(s, st);
                cout << endl;
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
                cin >> st;
                if (st == "todos"){
                    cout << "Codigos de " << s << ':' << endl;
                    cout << "El idioma no existe" << endl;
                    cout << endl;
                } else {
                    cout << "Codigo de " << st << " en " << s << ":" << endl;
                    cout << "El idioma no existe o el caracter no esta en el idioma" << endl;
                    cout << endl;
                }
            }
        }
    }
}
