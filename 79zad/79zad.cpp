#include <iostream>
#include <string>
#include <stdlib.h>

#define N 10

using namespace std;

void Merge(int* A, int first, int last)
{
	int middle, start, final, j;
	int* mas = new int[100];
	middle = (first + last) / 2;
	start = first;
	final = middle + 1;

	for (j = first; j <= last; j++)
		if ((start <= middle) && ((final > last) || (A[start] < A[final])))
		{
			mas[j] = A[start];
			start++;
		}
		else
		{
			mas[j] = A[final];
			final++;
		}

	for (j = first; j <= last; j++) A[j] = mas[j];
	delete[]mas;
}

void MergeSort(int* A, int first, int last)
{

	if (first < last)
	{
		MergeSort(A, first, (first + last) / 2);
		MergeSort(A, (first + last) / 2 + 1, last);
		Merge(A, first, last);
	}
}


int main()
{
	setlocale(LC_CTYPE, "ukr");
	cout << "++++++++++++++++++++++++++++++++++++\n";
	cout << "            Iнформацiя:           \n";
	cout << "Група: IПЗ-I 18к                  \n";
	cout << "ПІБ: Соляной Александр Олегович\n";
	cout << "Номер теми: 1.1.2 \n";
	cout << "Номер завдання: 79 " << "\n";
	cout << "+++++++++++++++++++++++++++++++++++\n\n";

	{
		int* arr = new int[N];

		for (int i = 0; i < N; i++)
		{
			arr[i] = rand() % 100;
			cout << "Arr " << arr[i] << "\n";
		}

		MergeSort(arr, 0, N);

		cout << "Sorting array: \n";

		for (int i = 0; i < N; i++)
			cout << "Arr " << arr[i] << "\n";

		delete[]arr;
	}
}