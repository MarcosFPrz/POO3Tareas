#include <iostream>
#include <time.h>

int Divide(int *array, int start, int end)
{
	int left;
	int right;
	int pivot;
	int temp;

	pivot = array[start];
	left = start;
	right = end;


	while (left < right) {
		while (array[right] > pivot) {
			right--;
		}

		while ((left < right) && (array[left] <= pivot)) {
			left++;
		}


		if (left < right) {
			temp = array[left];
			array[left] = array[right];
			array[right] = temp;
		}
	}


	temp = array[right];
	array[right] = array[start];
	array[start] = temp;


	return right;

}

void BubbleSort(int a[])
{
	int n = sizeof(a);

	for (int i = 0; i< n; ++i)
		std::cin >> a[i];

	for (int i = 1; i<n; ++i)
	{
		for (int j = 0; j<(n - i); ++j)
			if (a[j]>a[j + 1])
			{
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
	}
}

static void QuickSort(int *array, int start, int end)
{
	int pivot;

	if (start < end) {
		pivot = Divide(array, start, end);


		QuickSort(array, start, pivot - 1);


		QuickSort(array, pivot + 1, end);
	}

}

static void Merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;


	int *L = new int[n1], *R = new int[n2];




	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];


	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}


	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}
	
static void MergeSort(int arr[], int l, int r)
{
	if (l < r)
	{

		int m = l + (r - l) / 2;


		MergeSort(arr, l, m);
		MergeSort(arr, m + 1, r);

		Merge(arr, l, m, r);
	}
}

int main()
{
	int a[10000];

	for (int i = 0; i < 10000; ++i)
		a[i] = (rand() % 400);


	clock_t startT, endT;

	startT = clock();

	QuickSort(a, 0, 100 - 1);
	BubbleSort(a);

	endT = clock();

	float dif = (float)endT - (float)startT;

	std::cout << dif << std::endl;

	system("Pause");

	return 0;

}
