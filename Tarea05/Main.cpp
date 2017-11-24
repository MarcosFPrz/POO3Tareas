#include <iostream>
#include "ListaLigadaCircular.h"

int main()
{
	ListaLigadaCircular *lista = new ListaLigadaCircular();
	lista->InsertaString("Esta");
	lista->InsertaString("es");
	lista->InsertaString("una");
	lista->InsertaString("lista");
	lista->InsertaString("ligada");
	lista->InsertaString("circular");
	lista->next();
	lista->Print();

	system("Pause");
	
	return 0;
}