#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;

fstream f("duration.txt", ios::app);
void Ausgabe(int *_intarray, int _arraysize);
void ShellSort(int *_intarray, int _arraysize);
void RandomIntArray(int* _intarray, int _arraysize, int _randsize);

int help, j, key, duration;
long countMovement, countComparison;
double time1 = 0.0, tstart;
int gaps[3][6] = { { 209, 109, 41, 19, 5, 1 }, { 32, 16, 8, 4, 2, 1 }, { 281, 77, 23, 8, 1 } };

int *gap_pointer;

void main()
{
	int a[10000];

	for (int i = 0; i < 3; i++)
	{
		duration = 0;
		gap_pointer = gaps[i];
		f << "Gaparray[" << i << "]" << endl;
		for (int i = 0; i < 5; i++)
		{
			RandomIntArray(a, sizeof(a) / sizeof(int), 1000);
			Ausgabe(a, sizeof(a) / sizeof(int));

			ShellSort(a, sizeof(a) / sizeof(int));
			Ausgabe(a, sizeof(a) / sizeof(int));
		}
		f << "Average: " << duration << endl;
	}

	f.close();
	cin.peek();
}

void ShellSort(int *_intarray, int _arraysize)
{
	countMovement = 0, countComparison = 0;

	tstart = clock();
	//Vorsortieren für InsertionSort
	for (int sort_distance = *gap_pointer; sort_distance > 1; sort_distance = *(gap_pointer++))
		for (int i = 0; (i + sort_distance) < _arraysize; i++, countComparison++)
			if (_intarray[i] > _intarray[i + sort_distance])
			{
				help = _intarray[i];
				_intarray[i] = _intarray[i + sort_distance];
				_intarray[i + sort_distance] = help;
				countMovement += 3;
			}
	//SortDistance == 1 -> InsertionSort
	for (int i = 1; i < _arraysize; i++)
	{
		for (j = i, key = _intarray[j], countMovement++, countComparison++; j > 0 && _intarray[j - 1] > key; j--)
		{
			_intarray[j] = _intarray[j - 1];
			countMovement++;

			if (j - 1 != 0)
				countComparison++;
		}
		_intarray[j] = key;
		countMovement++;
	}
	time1 += clock() - tstart;
	for(int i = 0 ; i < time1; i++)
		f << "|";
	f  << endl;

	duration += time1;
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