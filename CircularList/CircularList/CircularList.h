#pragma once

template <class T>
class CNode {
public:
	T dato;
	CNode<T>* next;
	CNode<T>* prev;
	CNode(T _dato) { dato = _dato; next = prev = NULL; }
};
template <class T>
class CircularList {
private:
	CNode<T>* head;
	int elements;
public:
	CircularList() { head = NULL; elements = 0; }
	bool find(CNode<T>** &p, T dato);
	bool add(T dato);
	bool remove(T dato);
	void print();
	void print_reverb();
	void count_elements();
	void JosePhus(int jumps, int survivors);
};

template <class T>
inline bool CircularList<T>::find(CNode<T>**& p, T dato) {
	for (p = &head; (*p)->next != head && dato > (*p)->dato; p = &((*p)->next));
	if ((*p)->next == head && dato > (*p)->dato)	p = &((*p)->next);
	return (*p)->dato == dato;
}
template <class T>
inline bool CircularList<T>::add(T dato) {
	if (!head) {
		CNode<T>* t = new CNode<T>(dato);
		head = t;
		t->next = t->prev = t;
		return true;
	}

	CNode<T>** p;
	if (find(p, dato)) return false;
	CNode<T>* t = new CNode<T>(dato);

	t->prev = (*p)->prev;
	t->next = (*p);
	if (&(*p) == &head)	(*p)->prev->next = t;
	(*p)->prev = t;
	(*p) = t;
	return true;
}
template <class T>
inline bool CircularList<T>::remove(T dato) {
	if (!head) return false;
	CNode<T>** p;
	if (!find(p, dato)) return false;
	CNode<T>* t = (*p);
	if (head->next != head) {
		(*p)->next->prev = (*p)->prev;
		(*p)->prev->next = (*p)->next;
		if (&(*p) == &head)	(*p) = (*p)->next;
	}
	else head = NULL;
	delete t;
	return true;
}
template <class T>
inline void CircularList<T>::print() {
	if (!head)	return;
	CNode<T>** p;
	for (p = &head; (*p)->next != head; p = &((*p)->next))
		std::cout << (*p)->dato << " ";
	std::cout << (*p)->dato << std::endl;
}
template <class T>
inline void CircularList<T>::print_reverb() {
	if (!head)	return;
	CNode<T>** p;
	for (p = &head->prev; (*p)->prev != head->prev; p = &((*p)->prev))
		std::cout << (*p)->dato << " ";
	std::cout << (*p)->dato << std::endl;

}
template <class T>
inline void CircularList<T>::count_elements() {
	if (!head)	return;
	CNode<T>** p;
	for (p = &head; (*p)->next != head; p = &((*p)->next))
		elements++;
	elements++;
}
template <class T>
inline void CircularList<T>::JosePhus(int jumps, int survivors) {
	if (!head)	return;
	count_elements();
	for (CNode<T>** p = &head; elements > survivors; elements--) {
		for (int count = 1; count < jumps; p = &((*p)->next), count++);
		CNode<T>* t = (*p);
		if (head->next != head) {
			if ((*p) == head) p = &head;
			(*p)->next->prev = (*p)->prev;
			(*p)->prev->next = (*p)->next;
			if (&(*p) == &head)	(*p) = (*p)->next;
		}
		else head = NULL;
		delete t;
	}
}