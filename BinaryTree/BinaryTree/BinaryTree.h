#pragma once


template <class T>
class Less {
public:
	inline bool cmp(T a, T b) { return a < b; }
};
template <class T>
class Greater {
public:
	inline bool cmp(T a, T b) { return a > b; }
};

template <class T>
class NodeB {
public:
	T dato;
	NodeB<T>* b_nodes[2];
	NodeB(T _dato) { dato = _dato; b_nodes[0] = b_nodes[1] = NULL; }
};

template <class T, class C>
class TreeB {
private:
	NodeB<T>* root;
	C compare;
public:
	TreeB() { root = NULL; }
	bool find(T dato, NodeB<T> **&p);
	bool add(T dato);
	bool remove(T dato);
	void print();
	void InOrder(NodeB<T> *p);
};

template <class T, class C>
bool TreeB<T, C>::find(T dato, NodeB<T> **&p) {
	for (p = &root; *p && (*p)->dato != dato; p = &(*p)->b_nodes[(*p)->dato < dato]);
	return !!*p;
}
template <class T, class C>
bool TreeB<T, C>::add(T dato) {
	NodeB<T> **p;
	if (find(dato, p)) return 0;
	NodeB<T>* temp = new NodeB<T>(dato);
	(*p) = temp;
	return 1;
}
template <class T, class C>
bool TreeB<T, C>::remove(T data) {
	NodeB<T> ** p, ** q;
	if (!find(data, p)) return 0;
	if ((*p)->b_nodes[0] && (*p)->b_nodes[1]) {
		for (q = &(*p)->b_nodes[0]; (*q)->b_nodes[1]; q = &(*q)->b_nodes[1]);
		(*p)->dato = (*q)->dato;
		p = q;
	}
	NodeB<T> *t = *p;
	(*p) = (*p)->b_nodes[(*p)->b_nodes[1] != 0];
	delete t;
	return 1;
}

template <class T, class C>
void TreeB<T, C>::print() {
	InOrder(root);
	cout << endl;
}
template <class T, class C>
void TreeB<T, C>::InOrder(NodeB<T> *p) {
	if (!p)	return;
	InOrder(p->b_nodes[0]);
	std::cout << p->dato << " ";
	InOrder(p->b_nodes[1]);
}