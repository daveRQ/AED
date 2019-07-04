#pragma once
#include <vector>

template <class G>
class CNode {
public:
	typedef	typename	G::Edge		Edge;
	typedef	typename	G::N		N;
	typedef typename	G::E		E;
	N data;

	// Para El Dixtra
	E acumulado;	// Etiquetado
	bool data_end;
	CNode* procede;		// Etiquetado
						// End

	std::vector<Edge*> edges;
	CNode(N _data) { data = _data; }
};
template <class G>
class CEdge {
public:
	typedef	typename	G::Node		Node;
	typedef	typename	G::N		N;
	typedef	typename	G::E		E;
	Node* nodes[2];		//0 es la salida .. 1 es llegada
	bool dir;			//0 un lado .. 1 ambos lados
	E data;
	CEdge(E _data, Node* a, Node* b, bool _dir) {
		data = _data;
		nodes[0] = a;
		nodes[1] = b;
		dir = _dir;
	}
};
template <class N, class E>
class CGrafo {
public:
	typedef	typename	CGrafo<N, E>	self;
	typedef	typename	CNode<self>		Node;
	typedef typename	CEdge<self>		Edge;
	typedef typename	N		N;
	typedef	typename	E		E;
	std::vector<Node*> nodes;

	CGrafo() { ; }
	bool find_Node(int &posicion, N data);
	bool insert_Node(N n);
	bool find_Edge(int &posicion, E e, Node* a, Node* b);
	bool insert_Edge(E e, Node* a, Node* b, bool dir);
	bool remove_Edge(E e, Node* a, Node* b, bool dir);
	bool remove_Node(N n);
	void print();
	Node* n(N n) {
		int p;
		if (find_Node(p, n)) return nodes[p];
		return NULL;
	}
	bool seguir(int &p);
	bool menor_element(int &p_menor);
	void dixtra(N a, N b);
};

template<class N, class E>
inline bool CGrafo<N, E>::find_Node(int &posicion, N data) {
	int tam_nodes = nodes.size();
	for (posicion = 0; posicion < tam_nodes; posicion++) {
		if (data == nodes[posicion]->data)
			return 1;
	}
	return 0;
}
template<class N, class E>
inline bool CGrafo<N, E>::insert_Node(N n) {
	int p;
	if (find_Node(p, n))	return 0;
	nodes.push_back(new Node(n));
	return 1;
}
template<class N, class E>
inline bool CGrafo<N, E>::find_Edge(int &posicion, E data, Node* a, Node* b) {
	int tam_edges_a = a->edges.size();
	for (posicion = 0; posicion < tam_edges_a; posicion++) {
		bool p = (a->edges[posicion]->nodes[0] == a);
		if (data == a->edges[posicion]->data && a->edges[posicion]->nodes[p] == b)
			return true;
	}
	return false;
}
template<class N, class E>
inline bool CGrafo<N, E>::insert_Edge(E e, Node* a, Node* b, bool dir) {
	if (!a || !b) return 0;
	int posicion;
	if (find_Edge(posicion, e, a, b)) {
		if (a->edges[posicion]->dir == dir || a->edges[posicion]->dir == 1)	// Si no hay nada q agregar
			return false;
		a->edges[posicion]->dir = 1;			// Agrega para el otro lado mas
		b->edges.push_back(a->edges[posicion]);
		return true;
	}
	int pos;
	if (find_Edge(pos, e, b, a)) {
		bool p = (b->edges[pos]->nodes[0] == b);
		if (b->edges[pos]->nodes[p] == a) {
			b->edges[pos]->dir = 1;
			a->edges.push_back(b->edges[pos]);
			return true;
		}
	}
	Edge* temp = new Edge(e, a, b, dir);
	a->edges.push_back(temp);	// Agrego arista al nodo "a"
	if (dir == 1 && a != b)				// Si debo agregar a ambos lados
		b->edges.push_back(temp);
	return true;
}
template<class N, class E>
inline bool CGrafo<N, E>::remove_Edge(E e, Node* a, Node* b, bool dir) {
	if (!a || !b) return 0;
	int posicion_a;
	if (!find_Edge(posicion_a, e, a, b)) return false;
	if (a->edges[posicion_a]->dir == 1 && dir == 0) {		// Elimino solo media arista
		a->edges[posicion_a]->dir = 0;
		a->edges.erase(a->edges.begin() + posicion_a);
		return 1;
	}
	int posicion_b;
	if (find_Edge(posicion_b, e, b, a) && a != b) 			// Elimino arista si sale del nodo b
		b->edges.erase(b->edges.begin() + posicion_b);
	Edge* t = a->edges[posicion_a];
	a->edges.erase(a->edges.begin() + posicion_a);		// Elimino arista del nodo a
	delete t;
	return true;
}
template<class N, class E>
inline bool CGrafo<N, E>::remove_Node(N n) {
	int a;
	if (!find_Node(a, n)) return false;
	while (nodes[a]->edges.size() > 0) {
		Node* e_a = nodes[a]->edges[0]->nodes[0];
		Node* e_b = nodes[a]->edges[0]->nodes[1];
		remove_Edge(nodes[a]->edges[0]->data, e_a, e_b, 1);
	}
	nodes.erase(nodes.begin() + a);
	return true;
}
template<class N, class E>
inline void CGrafo<N, E>::print() {
	int tam_nodes = nodes.size();
	for (int i = 0; i < tam_nodes; i++) {
		int tam_edges = nodes[i]->edges.size();
		cout << nodes[i]->data << " ->> ";
		for (int j = 0; j < tam_edges; j++) {
			bool p = nodes[i]->edges[j]->nodes[0] == nodes[i];
			cout << " -> " << nodes[i]->edges[j]->data << " -> " << nodes[i]->edges[j]->nodes[p]->data << " || ";
		}
		cout << endl;
	}
}


template<class N, class E>
inline bool CGrafo<N, E>::seguir(int & p) {
	int tam = nodes.size();
	for (p = 0; p < tam; p++) {
		if (nodes[p]->data_end == false)
			return true;
	}
	return false;
}
template<class N, class E>
inline bool CGrafo<N, E>::menor_element(int & p) {
	if (!seguir(p)) return false;
	int tam = nodes.size();
	if (nodes[p]->acumulado == -1)
		for (int i = p + 1; i < tam && nodes[p]->acumulado == -1; i++) {
			if (!nodes[i]->data_end)	p = i;
		}

	for (int i = p + 1; i < tam; i++) {
		if (!(nodes[i]->data_end) && nodes[i]->acumulado != -1 && nodes[p]->acumulado > nodes[i]->acumulado)
			p = i;
	}
	return true;
}
template<class N, class E>
inline void CGrafo<N, E>::dixtra(N a, N b) {
	int u_a, u_b;
	if (!find_Node(u_a, a))	return;
	if (!find_Node(u_b, b)) return;

	int tam_nodes = nodes.size();

	for (int i = 0; i < tam_nodes; i++) {		// agrego booleanos
		nodes[i]->acumulado = -1;
		nodes[i]->data_end = false;
	}
	//agrego primer elemento
	nodes[u_a]->acumulado = 0;
	nodes[u_a]->procede = nodes[u_a];

	int menor;
	while (menor_element(menor)) {
		nodes[menor]->data_end = true;

		for (int i = 0; i < nodes[menor]->edges.size(); i++) {
			bool cmp = nodes[menor]->edges[i]->nodes[0] != nodes[menor];
			if (nodes[menor]->edges[i]->nodes[cmp]->data_end) {
				int temp = nodes[menor]->acumulado + nodes[menor]->edges[i]->data;
				Node* temp_arista = nodes[menor]->edges[i]->nodes[!cmp];
				if (temp_arista->acumulado > temp || temp_arista->acumulado == -1) {
					temp_arista->acumulado = temp;
					temp_arista->procede = nodes[menor];
				}
			}
		}
	}


	for (int i = 0; i < tam_nodes; i++) {
		if (nodes[i]->acumulado != -1)
			cout << "De " << nodes[u_a]->data << " hacia " << nodes[i]->data << "   " << nodes[i]->acumulado << " << " << nodes[i]->procede->data << endl;
		else
			cout << "De " << nodes[u_a]->data << " hacia " << nodes[i]->data << "  No tiene forma de llegar " << endl;
	}
	cout << endl;

	cout << "El camino de " << nodes[u_a]->data << " hasta " << nodes[u_b]->data << " es: " << endl;
	Node* camino = nodes[u_b];
	cout << camino->data;
	while (camino != nodes[u_a]) {
		camino = camino->procede;
		cout << " << " << camino->data;
	}
	cout << endl << "Con " << nodes[u_b]->acumulado << " de distancia" << endl;
}