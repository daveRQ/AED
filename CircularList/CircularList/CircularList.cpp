// CircularList.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include "CircularList.h"
#include <time.h>
#include <iostream>

using namespace std;



int main()
{
	srand(time(0));
	CircularList<int> A;
	int cant = 180;
	/*for (int i = 0; i < cant; i++)
	A.add(-50 + (rand() % 101));
	*/
	for (int i = 1; i < cant + 1; i++)
		A.add(i);


	A.print();

	A.JosePhus(30, 2);

	cout << endl << endl << endl << endl;
	A.print();

	system("PAUSE");
	return 0;
}


