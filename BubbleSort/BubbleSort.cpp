#include <iostream>
#include <time.h>
using namespace std;

void Ausgabe(int *_intarray, int _arraysize);
void BubbleSort(int *_intarray, int _arraysize);
void RandomIntArray(int* _intarray, int _arraysize, int _randsize);

int j, help;
long countMovement, countComparison;
double time1 = 0.0, tstart;

void main()
{
	int a[10000];
	int test[] = { 2, 4, 1, 3 };

	RandomIntArray(a, sizeof(a)/sizeof(int), 1000);
	Ausgabe(a, sizeof(a)/sizeof(int));

	BubbleSort(a, sizeof(a)/sizeof(int)); 	
	Ausgabe(a, sizeof(a) / sizeof(int));
	
	/*
	BubbleSort(test, sizeof(test) / sizeof(int));
	Ausgabe(test, sizeof(test) / sizeof(int));
	*/
	cin.peek();
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

void BubbleSort(int *_intarray, int _arraysize)
{
	countComparison = 0, countMovement = 0;

	tstart = clock();
	for (int i = _arraysize - 1; i > 0; i--)
	{
		for (j = 0; j < i; j++)
		{
			countComparison++;
			if (_intarray[j] > _intarray[j + 1])
			{
				help = _intarray[j];
				_intarray[j] = _intarray[j + 1];
				_intarray[j + 1] = help;
				countMovement++;
			}
		}
	}
	time1 += clock() - tstart;
}

void RandomIntArray(int *_intarray, int _arraysize, int _randsize)
{
	for (int i = 0, srand(time(0)); i < _arraysize; i++)
		_intarray[i] = (int)(_randsize*rand() / (RAND_MAX + 1.0));
}