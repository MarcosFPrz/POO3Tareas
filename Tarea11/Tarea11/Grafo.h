#pragma once
#include <list>
#include <vector>
#include "Arista.h"
#include "Nodo.h"

class Grafo
{
public:

	Grafo(bool hacia);
	~Grafo();

	typedef std::list<Arista> ListaAristas;
	typedef std::vector<ListaAristas> VectorDeListaDeAristas;

	std::vector<Nodo> Nodos;
	VectorDeListaDeAristas aristas;

	void AgregarNodo(std::string nombre);
	void AgregarArista(int origen, int destino, float peso);
	void MuestraMatriz();

private:
	int indice;
	bool mandar;
};

