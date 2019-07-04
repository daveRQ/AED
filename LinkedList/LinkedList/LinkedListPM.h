#pragma once


template <class T>
class Compare {
public:
	bool Less(T a, T b) { return a < b; }
	bool Greater(T a, T b) { return a > b; }
};

template <class T>
class NodePM {
private:
	T dato;
public:
	NodePM<T> *next;
	NodePM(T _dato) { dato = _dato; next = NULL; }
	T get_dato() { return dato; }
};
template <class T>
class LinkedListPM {
private:
	NodePM<T> *m_head;
	bool (Compare<int>:: *cmp)(T, T);
public:
	LinkedListPM(bool (Compare<int>:: *_p)(T, T)) { m_head = NULL; cmp = _p; }
	~LinkedListPM() { while (m_head)  remove(m_head->get_dato()); }
	bool find(T dato, NodePM<T> **&p);
	bool add(T dato);
	bool remove(T dato);
	void print();
};

template <class T>
bool LinkedListPM<T>::find(T dato, NodePM<T> **&p) {
	for (p = &m_head; *p && cmp->Less->((*p)->get_dato(), dato); p = &((*p)->next));
	return (*p) && (*p)->get_dato() == dato;
}
template <class T>
bool LinkedListPM<T>::add(T dato) {
	NodePM<T> **p;
	if (find(dato, p)) return 0;
	NodePM<T> *temp = new NodePM<T>(dato);
	temp->next = *p;
	*p = temp;
	return 1;
}
template <class T>
bool LinkedListPM<T>::remove(T dato) {
	NodePM<T> **p;
	if (!find(dato, p)) return 0;
	NodePM<T> *temp = (*p);
	*p = (*p)->next;
	delete temp;
	return 1;
}
template <class T>
void LinkedListPM<T>::print() {
	for (NodePM<T> **p = &m_head; *p; p = &((*p)->next))
		std::cout << (*p)->get_dato() << "  ";
	std::cout << std::endl;
}
