#include <iostream>
#include <time.h>
using namespace std;

void Ausgabe(int *_intarray, int _arraysize);
void SelectionSort(int *_intarray, int _arraysize);
void RandomIntArray(int* _intarray, int _arraysize, int _randsize);

int j, min_pos, help;
long countMovement, countComparison;
double time1 = 0.0, tstart;

void main()
{
	int a[10000];
	//int test[] = { 2, 4, 1, 3 };
	int test[] = { 4, 3, 2, 1 };

	
	RandomIntArray(a, sizeof(a) / sizeof(int), 1000);
	Ausgabe(a, sizeof(a) / sizeof(int));

	SelectionSort(a, sizeof(a) / sizeof(int));
	Ausgabe(a, sizeof(a) / sizeof(int));
	
/*
	SelectionSort(test, sizeof(test) / sizeof(int));
	Ausgabe(test, sizeof(test) / sizeof(int));
*/
	cin.peek();
}

void SelectionSort(int *_intarray, int _arraysize)
{
	countMovement = 0, countComparison = 0;

	tstart = clock();
	for (int i = 0; i < _arraysize - 1; i++)
	{
		for (j = i + 1, min_pos = i, countMovement++; j < _arraysize; j++, countComparison++)
			if (_intarray[j] < _intarray[min_pos])
			{
				min_pos = j;
				countMovement++;
			}

		if (_intarray[i] != _intarray[min_pos])
		{
			help = _intarray[min_pos];
			_intarray[min_pos] = _intarray[i];
			_intarray[i] = help;
			countMovement += 3;
		}
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
