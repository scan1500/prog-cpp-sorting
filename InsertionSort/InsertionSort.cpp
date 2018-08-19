#include <iostream>
#include <time.h>
using namespace std;

void Ausgabe(int *_intarray, int _arraysize);
void InsertionSort(int *_intarray, int _arraysize);
void RandomIntArray(int* _intarray, int _arraysize, int _randsize);

int j, help, key;
long countMovement, countComparison;
double time1 = 0.0, tstart;

void main()
{
	int a[10000];
	int test[] = { 4, 3, 2, 1 };

	RandomIntArray(a, sizeof(a) / sizeof(int), 1000);
	Ausgabe(a, sizeof(a) / sizeof(int));

	InsertionSort(a, sizeof(a)/sizeof(int));
	Ausgabe(a, sizeof(a) / sizeof(int));

	/*
	InsertionSort(test, sizeof(test) / sizeof(int));
	Ausgabe(test, sizeof(test) / sizeof(int));
	*/
	cin.peek();
}
void InsertionSort(int *_intarray, int _arraysize)
{
	countComparison = 0, countMovement = 0;

	tstart = clock();
	for (int i = 1; i < _arraysize; i++)
	{
		//countComparison für ersten Durchlauf inkrementieren
		for (j = i, key = _intarray[j], countMovement++, countComparison++; j > 0 && _intarray[j - 1] > key; j--)
		{
			_intarray[j] = _intarray[j - 1];
			countMovement++;

			if(j-1 != 0)
			countComparison++; //countComparison für nächsten Durchlauf inkrementieren
		}
		_intarray[j] = key;
		countMovement++;
	}
	time1 += clock() - tstart;
}

void Ausgabe(int *_intarray, int _arraysize)
{
	for (int i = 0; i < _arraysize; i++)
		cout << _intarray[i] << " ";

	time1 = time1 / CLOCKS_PER_SEC;
	cout << endl << endl << "Time = " << time1 << " sec." << endl;
	cout << "Comparisons: " << countComparison << endl;
	cout << "Movements: " << countMovement << endl << endl;

}

void RandomIntArray(int *_intarray, int _arraysize, int _randsize)
{
	for (int i = 0, srand(time(0)); i < _arraysize; i++)
		_intarray[i] = (int)(_randsize*rand() / (RAND_MAX + 1.0));
}