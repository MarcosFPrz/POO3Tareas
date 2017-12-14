#include "Dijsktra.h"

void Dijsktra::init()
{
	for (int i = 0; i <= V; ++i) {
		distancia[i] = INF;  
		visitado[i] = false; 
		previo[i] = -1;
	}

	Q.push(Node(inicial, 0));
	distancia[inicial] = 0;

	while (!Q.empty())
	{
		actual = Q.top().first;
		Q.pop();
	}

	if (visitado[actual]) continue;

	visitado[actual] = true;

	for (int i = 0; i < ady[actual].size(); ++i)
	{
		adyacente = ady[actual][i].first;
		peso = ady[actual][i].second;

		if (!visitado[adyacente])
		{
			relajacion(actual, adyacente, peso);
		}
	}

}

void Dijsktra::relajacion(int actual, int adyacente, int peso)
{
	if (distancia[actual] + peso < distancia[adyacente]) 
	{
		distancia[adyacente] = distancia[actual] + peso;  
		previo[adyacente] = actual;                       
		Q.push(Node(adyacente, distancia[adyacente])); 
	}
}

void Dijsktra::print(int destino) 
{
	if (previo[destino] != -1)
		print(previo[destino]);
	printf("%d ", destino);
}

Dijsktra::Dijsktra()
{
}


Dijsktra::~Dijsktra()
{
}
