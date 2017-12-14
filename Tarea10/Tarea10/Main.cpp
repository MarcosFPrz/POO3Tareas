#include <iostream>
#include <string>
#include "Grafo.h"

void main()
{
	Grafo* G;
	G = new Grafo(true);

	G->AgregarNodo("Nodo 0");
	G->AgregarNodo("Nodo 1");
	G->AgregarNodo("Nodo 2");
	G->AgregarNodo("Nodo 3");
	G->AgregarNodo("Nodo 4");
	G->AgregarNodo("Nodo 5");

	G->AgregarArista(0, 1, 2);
	G->AgregarArista(1, 2, 4);
	G->AgregarArista(2, 3, 3);
	G->AgregarArista(3, 4, 5);
	G->AgregarArista(4, 5, 3);
	G->AgregarArista(0, 5, 22);
	G->AgregarArista(4, 5, 3);

	system("Pause");
}

