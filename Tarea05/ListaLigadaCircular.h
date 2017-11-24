#pragma once
#include <string>
#include <iostream>

class ListaLigadaCircular
{
public:
	class Item
	{
	public:
		Item *next;
		Item *prev;
		std::string name;
		Item(std::string n)
		{
			name = n;
		}
	};

	Item* getHeader() { return header; }
	void InsertaItem(Item* nuevo);
	void InsertaString(std::string);

	void Remove();
	void prev()
	{
		header = header->prev;
	}
	void next()
	{
		header = header->next;
	}

	void Print();
	ListaLigadaCircular();
	~ListaLigadaCircular();

private:
	Item *header;
};

