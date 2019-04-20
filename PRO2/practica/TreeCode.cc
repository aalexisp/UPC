#include "TreeCode.hh"

//Constructoras--------------------------------------------

TreeCode::TreeCode(){
    BinTree<pair<string, int> > t;
    vector<BinTree<pair<string, int> > > v;
}

TreeCode::TreeCode(const TreeCode& tree){
    t = tree.t;
    v = tree.v;
}

//Modificadoras--------------------------------------------

void TreeCode::crear_nodos_base(Tabla_de_frecuencias tbl){
    BinTree<pair<string, int> > b;
    pair<string, int> p;
    for(int i = 0; i < tbl.tamano(); ++i){
        p = tbl.consultar_iesimo(i);
        b = BinTree<pair<string, int> > (p);
        v.push_back(b);
    }
}

void TreeCode::crear_TreeCode(){
	if(v.size() == 1){
        t = v[0];
	} else {
        ordenar_vector_treecode();
		pair<string, int> p = suma(v[0].value(),v[1].value());
		BinTree<pair<string,int > > a (p, v[0], v[1]);
		v.erase(v.begin(),v.begin()+2);
		v.push_back(a);
		crear_TreeCode();
    }
}

//Consultoras--------------------------------------------

//Por determinar

//Lectura y escritura--------------------------------------------

void TreeCode::escribir_treecode(){
    cout << "recorrido en preorden:" << endl;
    escribir_preorden(t);
    cout << "recorrido en inorden:" << endl;
    escribir_inorden(t);
}


//Métodos privados--------------------------------------------

void TreeCode::escribir_preorden(const BinTree<pair<string, int> >& b){
    if (not b.empty()){
        cout << b.value().first << ' ' << b.value().second << endl;
        escribir_preorden(b.left());
        escribir_preorden(b.right());
    }
}

void TreeCode::escribir_inorden(const BinTree<pair<string, int> >& b){
    if (not b.empty()){
        escribir_inorden(b.left());
        cout << b.value().first << ' ' << b.value().second << endl;
        escribir_inorden(b.right());
    }
}

bool comp(BinTree<pair<string,int> > a, BinTree<pair<string,int> > b){
	if (a.value().second < b.value().second) return true;
	else if (a.value().second == b.value().second){
		if (a.value().first < b.value().first) return true;
    }
	return false;
} //Método no privado pero se usa dentro de uno

void TreeCode::ordenar_vector_treecode(){
    sort(v.begin(),v.end(),comp);
}

pair<string,int> TreeCode::suma(pair<string,int> a, pair<string, int> b){
	pair<string,int> p;
	p.second = a.second + b.second;
	if (a.first < b.first) p.first = a.first + b.first;
	else p.first = b.first + a.first;
	return p;
}
