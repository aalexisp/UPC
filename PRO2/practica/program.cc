/** @mainpage

    El programa principal se encuentra en el módulo program.cc.
    Dados los tipos de datos aportados por el enunciado, necesitaremos un módulo
    para representar un Conjunto de Idiomas (cjt_idiomas) en el cual incluiremos otro
    módulo que será utilizado para representar un Idioma. Además será
    preciso requerir de otro más para representar una tabla_de_frecuencias
    junto con un último módulo usado para dejar constancia de un TreeCode
    necesarios para la creación de nuestro idioma.

    Comentarios:

    - En un primer vistazo, comenzaríamos por considerar las operaciones que
    vamos a necesitar para el programa principal y utilizaremos una serie
    de condiciones en las cuales utilizaremos un módulo diferente para cada
    una de estas.

    - Cabe remarcar que no todas las operaciones de escritura, es decir, la
    operación "cout" aparecen en el main, pues era necesario usarlas
    dentro de algún módulo dada la disposición que se ha realizado de las clases.

    - Nótese que en comparación con la especificación entregada incialmente
    se han borrado o añadido nuevas funciones, pues ha sido necesario
    dado que a partir de modificaciones de eficiencia se ha debido cambiar
    estas funciones.

    - Con el fin de realizar el grafo de dependencias de clases se ha usado
    la funcionalidad #ifndef NO_DIAGRAM ... #endif. Así las librerias y clases
    que no queiero que aparezcan en la construcción serán omitidas por el
    "graphviz" (que es lo que crea los grafos).

    - El TreeCode se ha implementado con un vector, cosa que en primera instancia aparece
    ineficiente en comparación de la implementación con conjuntos. Pero dado que en principio
    no hay demasiada diferencia según el modelo de implementación que he planteado para dejar
    más claro y presentable la práctica he optado por implementar con vectores.
    
*/

/** @file program.cc

    @brief Programa principal

    Este es el programa principal. Cabe destacar que en principio las entradas
    que nos llegan son correctas y se ajustan a lo pedido dentro del ámbito
    de la práctica. Por esa razón se obviarán algunas comprobaciones.
    Con el fin de mejorar la presentación de la práctica, he optado por utilizar
    nombres relativamente claros para las variables. Además se aportan comentarios para reforzarlo.
    Las operaciones son del tipo string, pues es como se dan en la entrada.

*/

#include "Cjt_idiomas.hh"

int main (){
    int n; //Número de idiomas que nos entran.
    cin >> n; //Leemos el número de idiomas que nos va a entrar.
    Cjt_Idiomas c; //Declaramos un conjunto de idioma inicial.

    for (int i = 0; i < n; ++i){
        string nombre; //Nombre del idioma que leemos.
        cin >> nombre; //Leemos el idioma.
        c.anadir_modificar(nombre); //Si el idioma ya existía se modifica la tabla
    }

    string op; //nombre de la opción
    string s; //nombre del idioma
    string st; //para los codigos
    string code; //para codificar o decodificar

    while (cin >> op and op != "fin"){
        cin >> s; //leemos el nombre del idioma
        if (op == "anadir/modificar"){ //Operación para añadir o modificar un idioma en el conjunto.
            if (c.existe_idioma(s)) cout << "Modificado " << s << endl << endl;
            else cout << "Anadido " << s << endl << endl;
            c.anadir_modificar(s);
        }
        if (c.existe_idioma(s)){ //Primero comprobamos que el idioma exista.
            //Porque si no debemos imprimir otras cosas.
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
            } else if (op == "codifica"){
                //Codificar un texto a binario (0's, 1's).
                cin >> code;
                cout << "Codifica en " << s << " el texto:" << endl;
                cout << code << endl;
                c.codifica(s, code);
                cout << endl;
            } else if (op == "decodifica"){
                //Decodificar un texto en binario (0's, 1's).
                cin >> code;
                cout << "Decodifica en " << s << " el texto:" << endl;
                cout << code << endl;
                c.decodifica(s, code);
                cout << endl;
            }
        } else { //En todos estos casos, el idioma que se utiliza para cada operación no existe
            //y por lo tanto debemos imprimir que no existe.
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
            } else if (op == "codifica"){
                cin >> code;
                cout << "Codifica en " << s << " el texto:" << endl;
                cout << code << endl;
                cout << "El idioma no existe" << endl;
                cout << endl;
            } else if (op == "decodifica"){
                cin >> code;
                cout << "Decodifica en " << s << " el texto:" << endl;
                cout << code << endl;
                cout << "El idioma no existe" << endl;
                cout << endl;
            }
        }
    }
}
