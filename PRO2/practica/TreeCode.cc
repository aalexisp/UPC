//Copyright (c) 2019 Copyright Holder All Rights Reserved.

/** @file TreeCode.cc
    @brief Código de la clase TreeCode
*/
#include "TreeCode.hh"

    //--------------------------------------------Constructoras--------------------------------------------

TreeCode::TreeCode(){}

TreeCode::TreeCode(Tabla_de_frecuencias& tf){
    //En esta constructora se crea directamente el TreeCode con llamadas a métodos privados.
    //Esto se hace así para dejar constancia de un mejor diseño modular al no dejar como métodos públicos
    //funciones que no se van a usar fuera de esta clase.
    //Se crean los nodos base, osea se meten todos los valores de la Tabla_de_frecuencias en el vector de BinTree.
    //Luego se crea recursivamente y finalmente se crea la tabla de códigos.
    crear_nodos_base(tf);
    crear_TreeCode();
    pair<string, string> p;
    crear_tabla_codigos(t, p, tf);
}

    //--------------------------------------------Lectura y escritura--------------------------------------------

void TreeCode::escribir_treecode() const{
    //Esta función de escritura dado que llama a otras dos funciones de immersión hace uso de cout
    //cosa que es un poco antimodular pero pienso que esta era de las pocas formas de hacerlo.
    cout << "recorrido en preorden:" << endl;
    escribir_preorden(t);
    cout << "recorrido en inorden:" << endl;
    escribir_inorden(t);
}

void TreeCode::escribir_codigos(string s) const{
    //Esta función lo que hace es escribir los códigos que hemos creado anteriormente del TreeCode y
    //están en la tabla de códigos. Consiste en un bucle y unas comparaciones para ver si el iterador
    //apunta al final. Además se mira si el carácter es "todos", en ese caso se imprimen todos los códigos
    //si no se imprime s y su código.
    map<string, string>::const_iterator it;
    if (s != "todos" and tm.find(s) != tm.end()){
        it = tm.find(s);
        cout << it->first << " " << it->second << endl;
    } else if (s == "todos") {
        it = tm.begin();
        //Invariante: it apunta a un elemento de la tabla de códigos, y los valores apuntados son pares string, string.
        while (it != tm.end()){
            cout << it->first << " " << it->second << endl;
            ++it;
        }
    } else {
        cout << "El idioma no existe o el caracter no esta en el idioma" << endl;
    }
}

void TreeCode::escribir_codificado(const string& s){
    //Función para escribir el texto s codificado en 0 y 1.
    //Se hace uso de una función de immersión que es privada.
    map<string, string>::const_iterator it;
    int i = 0;
    string res = "";
    bool b = codifica_immersion(s, res, it, i);
    if (not b) cout << "El texto no pertenece al idioma; primer caracter que falla: " << res << endl;
    else cout << res << endl;
}

void TreeCode::escribir_decodificado(const string& s){
    //Función para escribir un texto decodificado. Se hace uso de una función de immersión.
    string res = "";
    int i = 0;
    bool b = true;
    int ult;
    while (b and i != s.length()){
        b = decodifica_immersion(s, t, i, res, ult);
    }
    if (b) cout << res << endl;
    else {
        cout << "El texto no procede de una codificacion del idioma; ";
        if (s.length() == 1) cout << "ultima posicion del codigo correspondiente al ultimo caracter que se podria decodificar: " << 0 << endl;
        else cout << "ultima posicion del codigo correspondiente al ultimo caracter que se podria decodificar: " << ult << endl;
    }
}

    //--------------------------------------------Métodos privados--------------------------------------------

void TreeCode::escribir_preorden(const BinTree<pair<string, int> >& b) const{
    //Función recursiva que recorre el TreeCode en preorden para escribirlo.
    if (not b.empty()){
        cout << b.value().first << ' ' << b.value().second << endl;
        escribir_preorden(b.left());
        escribir_preorden(b.right());
    }
}

void TreeCode::escribir_inorden(const BinTree<pair<string, int> >& b) const{
    //Función recursiva que recorre el TreeCode en inorden para escribirlo.
    if (not b.empty()){
        escribir_inorden(b.left());
        cout << b.value().first << ' ' << b.value().second << endl;
        escribir_inorden(b.right());
    }
}

bool comp(const BinTree<pair<string,int> >& a, const BinTree<pair<string,int> >& b){
    //Función auxiliar que no es de la clase TreeCode que se usa para la comparación del sort del vector.
	if (a.value().second < b.value().second) return true;
	else if (a.value().second == b.value().second){
		if (a.value().first < b.value().first) return true;
    }
	return false;
}

pair<string,int> TreeCode::suma(const pair<string,int>& a, const pair<string, int>& b){
    //Función para sumar las frecuencias de los nodos "padre" al juntar dos nodos.
	pair<string,int> p;
	p.second = a.second + b.second;
	if (a.first < b.first) p.first = a.first + b.first;
	else p.first = b.first + a.first;
	return p;
}

void TreeCode::crear_nodos_base(Tabla_de_frecuencias& tf){
    //Función para crear los nodos base. Función recursiva que va metiendo en el vector los valores de la Tabla_de_frecuencias.
    //Se ordena solo una vez.
    BinTree<pair<string, int> > b;
    pair<string, int> p;
    tf.inicializa_recorrido();
    for(int i = 0; i < tf.tamano(); ++i){
        p = tf.consultar_proximo();
        b = BinTree<pair<string, int> > (p);
        v.push_back(b);
    }
    sort(v.begin(),v.end(),comp);
}

void TreeCode::insertar(BinTree<pair<string, int> >& tree){
    //Función para insertar el nodo padre que se ha creado de dos nodos hijos. Se deja en la posición que toca según comp.
    v.push_back(tree);
    for (int i = 0; i < v.size()-1; ++i){
        if (comp(tree, v[v.size()-2-i])){
            swap(v[v.size()-1-i], v[v.size()-2-i]);
        }
    }
}

void TreeCode::crear_TreeCode(){
    //Función para crear el TreeCode recursivamente. Se crea en preorden asi pues se visita primero la raíz, luego
    //hijo izquierdo y finalmente derecho. Luego se eliminan los dos primeros hijos dado que el vector está ordenado.
    //Y finalmente se inserta el nodo que se ha creado de los eliminados.
	if(v.size() == 1){
        t = v[0];
	} else {
		pair<string, int> p = suma(v[0].value(),v[1].value());
		BinTree<pair<string,int > > tree (p, v[0], v[1]);
		v.erase(v.begin(),v.begin()+2);
        insertar(tree); //Para insertar en el treecode el bintree resultante
		crear_TreeCode();
    }
}

void TreeCode::crear_tabla_codigos(const BinTree<pair<string, int> >& tc, const pair<string, string>& p, const Tabla_de_frecuencias& tf){
    //Función para crear la tabla de códigos de forma recursiva.
    //Se van recorriendo los hijos y según el convenio comp se van añadiendo 0 o 1 según pertoque.
    if (tf.esta(p.first) and tm.size() < tf.tamano()){
        tm.insert(make_pair(p.first, p.second));
    }

    pair<string,string> aux;

    if (not tc.left().empty()){
        aux.first = tc.left().value().first;
        aux.second = p.second + '0';
        crear_tabla_codigos(tc.left(), aux, tf);
    }
    if (not tc.right().empty()){
        aux.first = tc.right().value().first;
        aux.second = p.second + '1';
        crear_tabla_codigos(tc.right(), aux, tf);
    }
}

bool TreeCode::codifica_immersion(const string& s, string& res, map<string, string>::const_iterator& it, int& i){
    //Función recursiva de immersión para codificar textos. Se hace una función de immersión
    //con fortalecimiento de la pre y debilitamiento de la post dados los parámetros que pasamos.
    //Pasamos un if a expresión para ahorrar líneas y se hace la función recursiva. Básicamente se mira
    //si el carácter que miramos está en la tabla de códigos, en ese caso se añade la codificación del carácter al resultado.
    string aux;
    aux = (s[i]>=0) ? string(1, s[i]) : string(s, i, 2);
    it = tm.find(aux);
    if (i < s.length()){
            if (it == tm.end()){
            res = aux;
            return false;
        } else {
            res += it->second;
            i += (s[i] >= 0) ? 1 : 2;
            return codifica_immersion(s, res, it, i);
        }
    }
    return true;
}

bool TreeCode::decodifica_immersion(const string& s, const BinTree<pair<string, int> >& bt, int& i, string& res, int& ult){
    //Función recursiva de immersion para decodificar textos. Se hace esta función de immersión
    //con un fortalecimiento de la pre y debilitamiento de la post dados los parámetros que pasamos.
    //Básicamente vamos recorriendo el árbol en función de los números que nos llegan, 0 o 1.
    //Si es 0 recorremos el hijo izquierdo, si es 1 el derecho. Esto se hace hasta o bien no hemos quedado
    //sin tamañano en el texto que estamos mirando o bien hemos llegado a un hijo. En el caso de que hayamos acabado
    //de leer el texto y no nos encontremos en un hijo debemos retornar falso.
    if (bt.left().empty() and bt.right().empty()){
        res += (bt.value()).first;
        ult = i;
    } else {
        if (i == s.length()){
            return false;
        } else if (s[i] == '1'){
            ++i;
            return decodifica_immersion(s, bt.right(), i, res, ult);
        } else if (s[i] == '0') { //asegurarse que solo te pueden entrar 0's y 1's
            ++i;
            return decodifica_immersion(s, bt.left(), i, res, ult);
        }
    }
    return true;
}
