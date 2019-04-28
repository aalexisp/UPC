/** @file TreeCode.cc
    @brief Código de la clase TreeCode
*/
#include "TreeCode.hh"

//Constructoras--------------------------------------------

TreeCode::TreeCode(){}

TreeCode::TreeCode(const Tabla_de_frecuencias& tf){
    crear_nodos_base(tf);
    crear_TreeCode();
    pair<string, string> p;
    crear_tabla_codigos(t, p, tf);
}

TreeCode::TreeCode(const TreeCode& tree){
    t = tree.t;
    v = tree.v;
}

//Modificadoras--------------------------------------------

//No necesarias

//Consultoras--------------------------------------------

//string TreeCode::codifica(string s);
//string TreeCode::decodifica(string s);

//Lectura y escritura--------------------------------------------

void TreeCode::escribir_treecode() const{
    cout << "recorrido en preorden:" << endl;
    escribir_preorden(t);
    cout << "recorrido en inorden:" << endl;
    escribir_inorden(t);
}

void TreeCode::escribir_codigos(string s) const{
    map<string, string>::const_iterator it;
    if (s != "todos" and tm.find(s) != tm.end()){
        it = tm.find(s);
        cout << it->first << " " << it->second << endl;
    } else if (s == "todos") {
        it = tm.begin();
        while (it != tm.end()){
            cout << it->first << " " << it->second << endl;
            ++it;
        }
    } else {
        cout << "El idioma no existe o el caracter no esta en el idioma" << endl;
    }
}

//Métodos privados--------------------------------------------

void TreeCode::escribir_preorden(const BinTree<pair<string, int> >& b) const{
    if (not b.empty()){
        cout << b.value().first << ' ' << b.value().second << endl;
        escribir_preorden(b.left());
        escribir_preorden(b.right());
    }
}

void TreeCode::escribir_inorden(const BinTree<pair<string, int> >& b) const{
    if (not b.empty()){
        escribir_inorden(b.left());
        cout << b.value().first << ' ' << b.value().second << endl;
        escribir_inorden(b.right());
    }
}

bool comp(const BinTree<pair<string,int> >& a, const BinTree<pair<string,int> >& b){
	if (a.value().second < b.value().second) return true;
	else if (a.value().second == b.value().second){
		if (a.value().first < b.value().first) return true;
    }
	return false;
} //Método no privado pero se usa dentro de uno

pair<string,int> TreeCode::suma(const pair<string,int>& a, const pair<string, int>& b){
	pair<string,int> p;
	p.second = a.second + b.second;
	if (a.first < b.first) p.first = a.first + b.first;
	else p.first = b.first + a.first;
	return p;
}

void TreeCode::crear_nodos_base(const Tabla_de_frecuencias& tf){
    BinTree<pair<string, int> > b;
    pair<string, int> p;
    map<string, int>::const_iterator aux;
    tf.cambio(aux);
    for(int i = 0; i < tf.tamano(); ++i){
        p = tf.consultar_iesimo(i, aux);
        b = BinTree<pair<string, int> > (p);
        v.push_back(b);
    }
    sort(v.begin(),v.end(),comp);
}

void TreeCode::insertar(BinTree<pair<string, int> >& tree){
    v.push_back(tree);
    for (int i = 0; i < v.size()-1; ++i){
        if (comp(tree, v[v.size()-2-i])){
            swap(v[v.size()-1-i], v[v.size()-2-i]);
        }
    }
}


void TreeCode::crear_TreeCode(){
	if(v.size() == 1){
        t = v[0];
	} else {
		pair<string, int> p = suma(v[0].value(),v[1].value());
		BinTree<pair<string,int > > tree (p, v[0], v[1]);
		v.erase(v.begin(),v.begin()+2);
        insertar(tree);
		crear_TreeCode();
    }
}

void TreeCode::crear_tabla_codigos(const BinTree<pair<string, int> >& tc, const pair<string, string>& p, const Tabla_de_frecuencias& tf){
    if (tf.esta(p.first) and tm.size() < tf.tamano()){
        tm.insert(pair<string, string>(p.first, p.second));
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
