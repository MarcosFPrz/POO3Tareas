#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

struct nodo
{
	char paciente;
	int prioridad;
	struct nodo *next;
};

struct cola
{
	nodo *adelante;
	nodo *atras;
};

//Crear Nodo
struct nodo *crearNodo(char x, int pr)
{
	struct nodo *nuevoNodo = new(struct nodo);
	nuevoNodo->paciente = x;
	nuevoNodo->prioridad = pr;
	return nuevoNodo;
};

//Poner en Cola
void queue(struct cola &q, char valor, int priori)
{

	struct nodo *aux = crearNodo(valor, priori);
	aux->next = NULL;

	if (q.adelante == NULL)
		q.adelante = aux;   // encola el primero elemento
	else
		(q.atras)->next = aux;

	q.atras = aux;        // puntero que siempre apunta al ultimo elemento 
}

void muestraCola(struct cola q)
{
	struct nodo *aux;

	aux = q.adelante;

	cout << " Caracter  Prioridad " << endl;

	while (aux != NULL)
	{
		cout << "    " << aux->paciente << "     |   " << aux->prioridad << endl;
		aux = aux->next;
	}
}


void ordenarPrioridad(struct cola &q)
{
	struct nodo *aux1, *aux2;
	int p_aux;
	char c_aux;

	aux1 = q.adelante;

	while (aux1->next != NULL)
	{
		aux2 = aux1->next;

		while (aux2 != NULL)
		{
			if (aux1->prioridad > aux2->prioridad)
			{
				p_aux = aux1->prioridad;
				c_aux = aux1->paciente;

				aux1->prioridad = aux2->prioridad;
				aux1->paciente = aux2->paciente;

				aux2->prioridad = p_aux;
				aux2->paciente = c_aux;
			}

			aux2 = aux2->next;
		}

		aux1 = aux1->next;
	}
}

void insertar(struct cola &q, char c, int pr)
{
	queue(q, c, pr);
	ordenarPrioridad(q);
}

int main()
{
	struct cola q;

	q.adelante = NULL;
	q.atras = NULL;

	char paciente;     
	int prioridad; 

	//Paciente Random
	int i;
	srand(time(NULL));
	for (i = 0; i < 100; i++)
	{
		paciente = 'A' + rand() % 27;
		//cout << e << endl;
	}

	//Prioridad Random
	srand(time(NULL));
	for (i = 0; i < 100; i++)
	{
		prioridad = 1 + rand() % 100;
		//cout << prioridad << endl;
	}
	
	insertar(q, paciente, prioridad);
	insertar(q, paciente, prioridad);
	insertar(q, paciente, prioridad);

	//cout << "Caracter " << e << " en cola\n";

	if (q.adelante != NULL)
	{
		muestraCola(q);
	}
	else
		cout << "Cola vacia\n";



	system("Pause");

	return 0;
}