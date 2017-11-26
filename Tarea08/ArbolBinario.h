#pragma once
#include <iostream>

class ArbolBinario
{
public:
	ArbolBinario * padre;
	ArbolBinario * left;
	ArbolBinario * right;
	int id;
	std::string nombre;
	int nextID = 0;

	ArbolBinario()
	{
		padre = NULL;
		left = NULL;
		right = NULL;
		id = nextID;
		nextID++;
	}
	ArbolBinario(std::string nom)
	{
		padre = NULL;
		left = NULL;
		right = NULL;
		nombre = nom;
		id = nextID;
		nextID++;
	}
	ArbolBinario(std::string nom, int _id)
	{
		padre = NULL;
		left = NULL;
		right = NULL;
		nombre = nom;
		id = _id;
		nextID = id + 1;
	}

	void insertarIzq(ArbolBinario* nodo)
	{
		left = nodo;
		nodo->padre = this;
	}

	void insertarDer(ArbolBinario* nodo)
	{
		right = nodo;
		nodo->padre = this;
	}

	int count()
	{
		int c = 1;
		if (left) c += left->count();
		if (right) c += right->count();
		return c;
	}

	ArbolBinario * getRoot()
	{
		if (this->padre == NULL)
		{
			return this;
		}
		else
		{
			return this->padre->getRoot();
		}
	}

	void printdata(int  lvl = 0)
	{
		for (int i = 0; i < lvl; i++)
		{
			std::cout << "\t";
		}
		std::cout << this->nombre.c_str() <<
			"(" << this->id << ")"
			<< std::endl;
		if (left)
		{
			left->printdata(lvl + 1);
		}
		if (right)
		{
			right->printdata(lvl + 1);
		}
	}

	int compare(ArbolBinario * nodo)
	{
		return this->nombre.compare(nodo->nombre);
	}
	int compare(std::string dato)
	{
		return this->nombre.compare(dato);
	}

	void insert(std::string dato)
	{
		ArbolBinario * it = this;

		while (it != NULL)
		{
			if (it->compare(dato) < 0)
			{
				if (it->left == NULL)
				{
					it->left = new ArbolBinario(dato, nextID);
					nextID++;
					it->left->padre = it;
					it = NULL;
				}
				else
				{
					it = it->left;
				}
			}
			else //meterlo a la derecha
			{
				if (it->right == NULL)
				{
					it->right = new ArbolBinario(dato, nextID);
					nextID++;
					it->right->padre = it;
					it = NULL;
				}
				else
				{
					it = it->right;
				}
			}
		}
	}

	ArbolBinario * find(std::string dato)
	{
		ArbolBinario * it = getRoot();

		while (it != NULL)
		{
			int res = it->compare(dato);
			if (res == 0) //cuando son iguales las strings
			{
				return it;
			}
			else if (res < 0)
			{
				it = it->left;
			}
			else if (res > 0)
			{
				it = it->right;
			}
		}
		//si no se encontró
		return NULL;
	}
};
