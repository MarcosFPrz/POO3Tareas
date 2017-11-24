#include <iostream>
#include <fstream>

std::ofstream Matriz;

int main() {

	int i, j, f, c;

	std::cout << "Introduce el numero de filas" << std::endl;
	std::cin >> f;
	std::cout << "Introduce el numero de columnas" << std::endl;
	std::cin >> c;

	//Creamos la Matriz
	int **M = new int*[f];
	for (i = 0; i < f; i++)
		M[i] = new int[c];

	//Abrimos el archivo Matriz.txt
	Matriz.open("Matriz.txt", std::ios::app);

	std::cout << "Introduzca los elementos" << std::endl;
	for (i = 0; i < f; i++)
	{
		for (j = 0; j < c; j++)
		{
			std::cin >> M[i][j];
			//Guardamos la matrix en el archivo
			Matriz << M[i][j];
		}

		Matriz << "\n";
	}

	//Mostramos la matriz en consola
	std::cout << "Mostrar la matriz" << std::endl;
	for (i = 0; i < f; i++) 
	{
		for (j = 0; j < c; j++)
		{
			std::cout << M[i][j] << " ";
		}
		std::cout << std::endl;
	}


	
	Matriz.close();



	delete[] M;

	system("Pause");
	return 0;
}

