#include "ListaLigadaCircular.h"

void ListaLigadaCircular::InsertaItem(Item * nuevo)
{
	if (!header)
	{
		header = nuevo;
		header->next = nuevo;
		header->prev = nuevo;
	}
	else
	{
		header->next->prev = nuevo;
		nuevo->next = header->next;
		nuevo->prev = header;
		header->next = nuevo;
		header = header->next;
	}
}

void ListaLigadaCircular::InsertaString(std::string str)
{
	Item *it = new Item(str);
	InsertaItem(it);
}

void ListaLigadaCircular::Remove()
{
	header->prev->next = header->next;
	header->next->prev = header->prev;
	Item *temp = header;
	header = header->next;
	delete temp;
}

void ListaLigadaCircular::Print()
{
	Item* it = header;
	do
	{
		char *prefijo = (it == header) ? "String\t" : "\t";
		std::cout << prefijo << it->name.c_str() << std::endl;
		it = it->next;
	} while (it != header);
}


ListaLigadaCircular::ListaLigadaCircular()
{
	header = NULL;
}


ListaLigadaCircular::~ListaLigadaCircular()
{
}
