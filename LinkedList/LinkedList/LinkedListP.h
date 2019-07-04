#pragma once

template <class T>
class compare {
public:
	virtual bool cmp(T, T) = 0;
};
template <class T>
class Less1 :public compare<T> {
public:
	bool cmp(T a, T b) { return a < b; }
};
template <class T>
class Greater1 :public compare<T> {
public:
	bool cmp(T a, T b) { return a > b; }
};

template <class T>
class NodeP {
private:
	T dato;
public:
	NodeP<T> *next;
	NodeP(T _dato) { dato = _dato; next = NULL; }
	T get_dato() { return dato; }
};
template <class T>
class LinkedListP {
private:
	NodeP<T> *m_head;
	compare<T> *m_c;
public:
	LinkedListP(compare<T> *p) { m_head = NULL;	m_c = p; }
	~LinkedListP() { while (m_head)	remove(m_head->get_dato()); }
	bool find(T dato, NodeP<T> **&p);
	bool add(T dato);
	bool remove(T dato);
	void print();
};

template <class T>
bool LinkedListP<T>::find(T dato, NodeP<T> **&p) {
	for (p = &m_head; *p && (m_c->cmp((*p)->get_dato(), dato)); p = &((*p)->next));
	return (*p) && (*p)->get_dato() == dato;
}
template <class T>
bool LinkedListP<T>::add(T dato) {
	NodeP<T> **p;
	if (find(dato, p)) return 0;
	NodeP<T> *temp = new NodeP<T>(dato);
	temp->next = *p;
	*p = temp;
	return 1;
}
template <class T>
bool LinkedListP<T>::remove(T dato) {
	NodeP<T> **p;
	if (!find(dato, p)) return 0;
	NodeP<T> *temp = (*p);
	*p = (*p)->next;
	delete temp;
	return 1;
}
template<class T>
void LinkedListP<T>::print() {
	for (NodeP<T> **p = &m_head; *p; p = &((*p)->next))
		std::cout << (*p)->get_dato() << "  ";
	std::cout << std::endl;
}