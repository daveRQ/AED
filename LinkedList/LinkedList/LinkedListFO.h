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
class NodeFO {
private:
	T dato;
public:
	NodeFO<T> *next;
	NodeFO(T _dato) { dato = _dato; next = NULL; }
	T get_dato() { return dato; }
};
template <class T, class C>
class LinkedListFO {
private:
	NodeFO<T> *m_head;
	C m_c;
public:
	LinkedListFO() { m_head = NULL; }
	~LinkedListFO() { while (m_head)	remove(m_head->get_dato()); }
	bool find(T dato, NodeFO<T> **&p);
	bool add(T dato);
	bool remove(T dato);
	void print();
};

template <class T, class C>
bool LinkedListFO<T, C>::find(T dato, NodeFO<T> **&p) {
	for (p = &m_head; *p && m_c.cmp((*p)->get_dato(), dato); p = &((*p)->next));
	return (*p) && (*p)->get_dato() == dato;
}
template <class T, class C>
bool LinkedListFO<T, C>::add(T dato) {
	NodeFO<T> **p;
	if (find(dato, p)) return 0;
	NodeFO<T> *temp = new NodeFO<T>(dato);
	temp->next = *p;
	*p = temp;
	return 1;
}
template <class T, class C>
bool LinkedListFO<T, C>::remove(T dato) {
	NodeFO<T> **p;
	if (!find(dato, p)) return 0;
	NodeFO<T> *temp = (*p);
	*p = (*p)->next;
	delete temp;
	return 1;
}
template <class T, class C>
void LinkedListFO<T, C>::print() {
	for (NodeFO<T> **p = &m_head; *p; p = &((*p)->next))
		std::cout << (*p)->get_dato() << "  ";
	std::cout << std::endl;
}
