#pragma once
#include <vector>
#include <iomanip>

template <class T>
class Node {
public:
	T dato;
	Node<T>* b_nodes[2];
	int height;
	int balance;
	Node(T _dato) { dato = _dato; b_nodes[0] = b_nodes[1] = NULL; height = 0; }
};

template <class T>
class Avl {
private:
	Node<T>* root;
	std::vector<Node<T>*> elements;

	void OH(Node<T> *p);
	void add_heights();
	bool v_b(Node<T>* &p);
	void InOrder(Node<T> *p);
	void Alola(Node<T>* a, int n);
	void balancear();
public:
	Avl() { root = NULL; }
	bool find(T dato, Node<T> **&p);
	bool add(T dato);
	bool remove(T dato);
	void print();

};

template<class T>
bool Avl<T>::find(T dato, Node<T>**& p) {
	for (p = &root; *p && (*p)->dato != dato; p = &(*p)->b_nodes[(*p)->dato < dato]);
	return !!*p;
}

template<class T>
inline bool Avl<T>::add(T dato) {
	Node<T> **p;
	if (find(dato, p)) return 0;
	Node<T>* temp = new Node<T>(dato);
	(*p) = temp;
	balancear();
	return 1;
}

template<class T>
inline bool Avl<T>::remove(T dato) {
	Node<T> ** p, ** q;
	if (!find(dato, p)) return 0;
	if ((*p)->b_nodes[0] && (*p)->b_nodes[1]) {
		for (q = &(*p)->b_nodes[0]; (*q)->b_nodes[1]; q = &(*q)->b_nodes[1]);
		(*p)->dato = (*q)->dato;
		p = q;
	}
	Node<T> *t = *p;
	(*p) = (*p)->b_nodes[(*p)->b_nodes[1] != 0];
	balancear();
	delete t;
	return 1;
}

template<class T>
inline void Avl<T>::OH(Node<T>* p) {
	if (!p)	return;
	OH(p->b_nodes[0]);
	elements.push_back(p);
	OH(p->b_nodes[1]);
}

template<class T>
inline void Avl<T>::add_heights() {
	OH(root);
	int tam_elements = elements.size();
	for (int i = 0; i < tam_elements; i++)
		elements[i]->height = 0;
	while (tam_elements > 0) {
		tam_elements = elements.size();
		for (int i = tam_elements - 1; i > -1; i--) {

			if (!elements[i]->b_nodes[0] && !elements[i]->b_nodes[1]) {
				elements[i]->height = 1;
				elements[i]->balance = 0;
			}
			else if (!elements[i]->b_nodes[0] && elements[i]->b_nodes[1] && elements[i]->b_nodes[1]->height) {
				elements[i]->height = elements[i]->b_nodes[1]->height + 1;
				elements[i]->balance = 0 - elements[i]->b_nodes[1]->height;
			}
			else if (!elements[i]->b_nodes[1] && elements[i]->b_nodes[0] && elements[i]->b_nodes[0]->height) {
				elements[i]->height = elements[i]->b_nodes[0]->height + 1;
				elements[i]->balance = elements[i]->b_nodes[0]->height;
			}
			else if (elements[i]->b_nodes[0] && elements[i]->b_nodes
				[1] && elements[i]->b_nodes[0]->height && elements[i]->b_nodes[1]->height) {
				if (elements[i]->b_nodes[0]->height > elements[i]->b_nodes[1]->height)
					elements[i]->height = elements[i]->b_nodes[0]->height + 1;
				else
					elements[i]->height = elements[i]->b_nodes[1]->height + 1;
				elements[i]->balance = elements[i]->b_nodes[0]->height - elements[i]->b_nodes[1]->height;
			}
			if (elements[i]->height != 0) elements.erase(elements.begin() + i);
		}
	}
	OH(root);
}

template<class T>
inline bool Avl<T>::v_b(Node<T>* &p) {
	int tam_elements = elements.size();
	vector<Node<T>*> menores;
	for (int i = tam_elements - 1; i > -1; i--) {
		if (elements[i]->balance > 1 || elements[i]->balance < -1)  menores.push_back(elements[i]);
	}
	if (menores.size() == 0)	return false;
	int tam_menores = menores.size();
	p = menores[0];
	for (int i = 0; i < tam_menores; i++) {
		if (p->height > menores[i]->height)
			p = menores[i];
	}
	return true;
}

template<class T>
inline void Avl<T>::balancear() {

	add_heights();
	int tam_elements = elements.size();
	Node<T>* t;
	while (v_b(t)) {
		Node<T>** x;
		find(t->dato, x);
		if (!(*x)->b_nodes[0]) {
			if (!(*x)->b_nodes[1]->b_nodes[0]) {
				(*x)->b_nodes[1]->b_nodes[0] = (*x);
				(*x) = (*x)->b_nodes[1];
				(*x)->b_nodes[0]->b_nodes[1] = NULL;
			}
			else {
				(*x)->b_nodes[1]->b_nodes[0]->b_nodes[0] = (*x);
				(*x)->b_nodes[1]->b_nodes[0]->b_nodes[1] = (*x)->b_nodes[1];
				(*x) = (*x)->b_nodes[1]->b_nodes[0];
				(*x)->b_nodes[0]->b_nodes[1] = NULL;
				(*x)->b_nodes[1]->b_nodes[0] = NULL;
			}
		}
		else if (!(*x)->b_nodes[1]) {
			if (!(*x)->b_nodes[0]->b_nodes[1]) {
				(*x)->b_nodes[0]->b_nodes[1] = (*x);
				(*x) = (*x)->b_nodes[0];
				(*x)->b_nodes[1]->b_nodes[0] = NULL;
			}
			else {
				(*x)->b_nodes[0]->b_nodes[1]->b_nodes[1] = (*x);
				(*x)->b_nodes[0]->b_nodes[1]->b_nodes[0] = (*x)->b_nodes[0];
				(*x) = (*x)->b_nodes[0]->b_nodes[1];
				(*x)->b_nodes[1]->b_nodes[0] = NULL;
				(*x)->b_nodes[0]->b_nodes[1] = NULL;
			}
		}
		else if ((*x)->b_nodes[0]->height < (*x)->b_nodes[1]->height) {
			if ((*x)->b_nodes[1]->b_nodes[1]->height >(*x)->b_nodes[1]->b_nodes[0]->height) {
				Node<T>* z = (*x);
				(*x) = (*x)->b_nodes[1];
				z->b_nodes[1] = (*x)->b_nodes[0];
				(*x)->b_nodes[0] = z;
			}
			else {
				Node<T>* z = (*x)->b_nodes[1]->b_nodes[0];
				(*x)->b_nodes[1]->b_nodes[0] = z->b_nodes[1];
				z->b_nodes[1] = (*x)->b_nodes[1];
				(*x)->b_nodes[1] = z->b_nodes[0];
				z->b_nodes[0] = (*x);
				(*x) = z;
			}
		}
		else if ((*x)->b_nodes[0]->height > (*x)->b_nodes[1]->height) {
			if ((*x)->b_nodes[0]->b_nodes[0]->height > (*x)->b_nodes[0]->b_nodes[1]->height) {
				Node<T>* z = (*x);
				(*x) = (*x)->b_nodes[0];
				z->b_nodes[0] = (*x)->b_nodes[1];
				(*x)->b_nodes[1] = z;
			}
			else {
				Node<T>* z = (*x)->b_nodes[0]->b_nodes[1];
				(*x)->b_nodes[0]->b_nodes[1] = z->b_nodes[0];
				z->b_nodes[0] = (*x)->b_nodes[0];
				(*x)->b_nodes[0] = z->b_nodes[1];
				z->b_nodes[1] = (*x);
				(*x) = z;
			}
		}
		add_heights();
	}
}

template<class T>
inline void Avl<T>::Alola(Node<T>* a, int n) {
	if (a != NULL) { // Si el árbol no está vacío
		Alola(a->b_nodes[1], n + 1);
		for (int i = 0; i < n; i++)
			cout << "   ";
		cout << a->dato << endl;
		Alola(a->b_nodes[0], n + 1);
	}
}


template<class T>
void Avl<T>::print() {
	//InOrder(root);
	//std::cout << std::endl;
	int n = 2;
	Alola(root, n);
}

template<class T>
void Avl<T>::InOrder(Node<T>* p) {
	if (!p)	return;
	InOrder(p->b_nodes[0]);
	std::cout << p->dato << " -> ";
	std::cout << p->height << " -> ";
	std::cout << p->balance << "   ";
	InOrder(p->b_nodes[1]);
}
