// Grafo.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include "Grafo.h"
#include <iostream>

using namespace std;



int main() {
	CGrafo<char, int> G;
	/*G.insert_Node('A');
	G.insert_Node('B');
	G.insert_Node('C');
	G.insert_Node('D');
	G.insert_Node('E');
	G.insert_Node('F');
	G.insert_Node('G');
	G.insert_Node('H');
	G.insert_Node('I');
	G.insert_Node('J');
	G.insert_Node('K');

	G.insert_Edge(1, G.n('A'), G.n('B'), 0);
	G.insert_Edge(6, G.n('B'), G.n('C'), 0);
	G.insert_Edge(5, G.n('A'), G.n('C'), 1);
	G.insert_Edge(7, G.n('C'), G.n('D'), 0);
	G.insert_Edge(2, G.n('D'), G.n('E'), 1);

	G.insert_Edge(4, G.n('C'), G.n('F'), 1);
	G.insert_Edge(3, G.n('E'), G.n('F'), 1);
	G.insert_Edge(2, G.n('F'), G.n('K'), 0);
	G.insert_Edge(8, G.n('F'), G.n('G'), 0);
	G.insert_Edge(5, G.n('G'), G.n('H'), 1);

	G.insert_Edge(2, G.n('H'), G.n('A'), 1);
	G.insert_Edge(7, G.n('G'), G.n('J'), 1);
	G.insert_Edge(4, G.n('J'), G.n('F'), 1);
	G.insert_Edge(4, G.n('H'), G.n('I'), 1);
	G.insert_Edge(2, G.n('I'), G.n('J'), 0);*/

	/*G.insert_Node('A');
	G.insert_Node('B');
	G.insert_Node('C');
	G.insert_Node('D');
	G.insert_Node('E');
	G.insert_Node('F');

	G.insert_Edge(2, G.n('A'), G.n('B'), 1);
	G.insert_Edge(3, G.n('A'), G.n('D'), 1);
	G.insert_Edge(1, G.n('A'), G.n('C'), 0);
	G.insert_Edge(3, G.n('C'), G.n('D'), 1);
	G.insert_Edge(2, G.n('C'), G.n('E'), 0);
	G.insert_Edge(4, G.n('E'), G.n('F'), 0);
	G.insert_Edge(6, G.n('D'), G.n('F'), 0);
	*/

	/*G.insert_Node('A');
	G.insert_Node('B');
	G.insert_Node('C');
	G.insert_Node('D');
	G.insert_Node('E');
	G.insert_Node('F');
	G.insert_Node('G');
	G.insert_Node('H');
	G.insert_Node('I');
	G.insert_Node('J');
	G.insert_Node('K');
	G.insert_Node('L');
	G.insert_Node('M');
	G.insert_Node('N');
	G.insert_Node('P');

	G.insert_Edge(8, G.n('A'), G.n('B'), 1);
	G.insert_Edge(4, G.n('A'), G.n('E'), 1);
	G.insert_Edge(5, G.n('A'), G.n('D'), 1);
	G.insert_Edge(3, G.n('B'), G.n('C'), 1);
	G.insert_Edge(4, G.n('B'), G.n('F'), 1);
	G.insert_Edge(12, G.n('B'), G.n('E'), 1);
	G.insert_Edge(11, G.n('C'), G.n('G'), 1);

	G.insert_Edge(9, G.n('C'), G.n('F'), 1);
	G.insert_Edge(9, G.n('D'), G.n('E'), 1);
	G.insert_Edge(6, G.n('D'), G.n('H'), 1);
	G.insert_Edge(3, G.n('E'), G.n('F'), 1);
	G.insert_Edge(5, G.n('E'), G.n('J'), 1);
	G.insert_Edge(8, G.n('E'), G.n('I'), 1);
	G.insert_Edge(1, G.n('F'), G.n('G'), 1);

	G.insert_Edge(8, G.n('F'), G.n('K'), 1);
	G.insert_Edge(7, G.n('G'), G.n('L'), 1);
	G.insert_Edge(8, G.n('G'), G.n('K'), 1);
	G.insert_Edge(2, G.n('H'), G.n('I'), 1);
	G.insert_Edge(7, G.n('H'), G.n('M'), 1);
	G.insert_Edge(10, G.n('I'), G.n('J'), 1);
	G.insert_Edge(6, G.n('I'), G.n('M'), 1);

	G.insert_Edge(6, G.n('J'), G.n('K'), 1);
	G.insert_Edge(9, G.n('J'), G.n('N'), 1);
	G.insert_Edge(5, G.n('K'), G.n('L'), 1);
	G.insert_Edge(7, G.n('K'), G.n('P'), 1);
	G.insert_Edge(6, G.n('L'), G.n('P'), 1);
	G.insert_Edge(2, G.n('M'), G.n('N'), 1);
	G.insert_Edge(12, G.n('N'), G.n('P'), 1);*/

	G.insert_Node('A');
	G.insert_Node('B');
	G.insert_Node('C');
	G.insert_Node('D');
	G.insert_Node('E');
	G.insert_Node('F');
	G.insert_Edge(7, G.n('A'), G.n('B'), 1);
	G.insert_Edge(9, G.n('A'), G.n('C'), 1);
	G.insert_Edge(14, G.n('A'), G.n('F'), 1);
	G.insert_Edge(10, G.n('B'), G.n('C'), 1);
	G.insert_Edge(15, G.n('B'), G.n('D'), 1);
	G.insert_Edge(11, G.n('C'), G.n('D'), 1);
	G.insert_Edge(2, G.n('C'), G.n('F'), 1);
	G.insert_Edge(6, G.n('D'), G.n('E'), 1);
	G.insert_Edge(9, G.n('E'), G.n('F'), 1);

	G.print();

	cout << endl;

	G.dixtra('A', 'E');

	system("PAUSE");
	return 0;
}

