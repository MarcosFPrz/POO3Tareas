#include "Grafo.h"



Grafo::Grafo(bool hacia)
{
	indice = 0;
	mandar = hacia;
}


Grafo::~Grafo()
{
}

void Grafo::AgregarNodo(std::string nombre)
{
	Nodo* N = new Nodo(indice, nombre);
	Nodos.push_back(*N);

	std::cout << "Nodo Agregado " << N->nom << std::endl;

	//std::cout << indice << std::endl;
	indice++;
	//std::cout << indice << std::endl;

	aristas.push_back(ListaAristas());
}

void Grafo::AgregarArista(int origen, int destino, float peso)
{
	for (ListaAristas::iterator i = aristas[origen].begin(); i != aristas[origen].end(); i++)
	{
		if (i->fin == destino)
		{
			std::cout << "Ya habia arista del nodo " << origen << " al nodo " << destino << "\n";
			return;
		}

	}
	
	std::cout << "Se ha agredado una arista del nodo " << origen << " al nodo " << destino << " con un peso de " << peso << std::endl;

	Arista* Ar = new Arista(origen, destino, peso);
	aristas[origen].push_back(*Ar);

	if (!mandar)
	{
		Arista* Ar2 = new Arista(origen, destino, peso);
		aristas[origen].push_back(*Ar2);
	}

}

void Grafo::MuestraMatriz()
{
	std::cout << "Matriz del grafo: \n\t";
	for (int i = 0; i < aristas.size(); ++i)
	{
		std::cout << "\t" << i << "\n";
	}

	for (std::vector<Nodo>::iterator nodo = Nodos.begin(); nodo != Nodos.end(); ++nodo)
	{
		std::cout << nodo->n << " - " << nodo->nom << std::endl;
	}
}
