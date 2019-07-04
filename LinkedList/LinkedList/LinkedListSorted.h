#pragma once
// Lista simple ordenada
template <class T>
class Node {
private:
	T dato;
public:
	Node<T> *next;
	Node(T _dato) { dato = _dato; next = NULL; }
	T get_dato() { return dato; }
};
template <class T>
class LinkedList {
private:
	Node<T> *m_head;
public:
	LinkedList() { m_head = NULL; }
	~LinkedList() { while (m_head)	remove(m_head->get_dato()); }
	bool find(T dato, Node<T> **&p);
	bool add(T dato);
	bool remove(T dato);
	void print();
};

template <class T>
bool LinkedList<T>::find(T dato, Node<T> **&p) {
	for (p = &m_head; *p && (*p)->get_dato() < dato; p = &((*p)->next));
	return (*p) && (*p)->get_dato() == dato;
}
template <class T>
bool LinkedList<T>::add(T dato) {
	NodeS<T> **p;
	if (find(dato, p)) return 0;
	Node<T> *temp = new Node<T>(dato);
	temp->next = *p;
	*p = temp;
	return 1;
}
template <class T>
bool LinkedList<T>::remove(T dato) {
	Node<T> **p;
	if (!find(dato, p)) return 0;
	Node<T> *temp = (*p);
	*p = (*p)->next;
	delete temp;
	return 1;
}
template<class T>
void LinkedList<T>::print() {
	for (Node<T> **p = &m_head; *p; p = &((*p)->next))
		std::cout << (*p)->get_dato() << "  ";
	std::cout << std::endl;
}

//con Polimorfismo			Pregunta a todos, y siempre es el mismo, 
// clases relativas cmp; less ; greater;


/*
Punteros a Funciones
bool less(int a, int b)	return a < b;
bool greater(inte a, int b) return a > b;
Decalracion de Puntero a Funcion	bool (*p)(int, int)
p = &greater;
(*p)(3,4);
*/




