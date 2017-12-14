#pragma once
#include <vector>
#define MAX 10005
#define Node pair< int , int >
#define INF 1<<30

class Dijsktra
{
public:

	std::vector< Node > ady[MAX]; 
	int distancia[MAX];      
	bool visitado[MAX];      
	int previo[MAX];
	void priority_queue< Node, vector<Node>, cmp > Q;
	int V;

	void init();
	void relajacion(int, int, int);
	void print(int);


	Dijsktra();
	~Dijsktra();
};

