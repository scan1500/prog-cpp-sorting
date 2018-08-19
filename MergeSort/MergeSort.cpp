#include <iostream>
using namespace std;

void MergeSort(int *_intarray, int _arraysize);
int help, key, j;

void main()
{




	cin.peek();
}

void MergeSort(int *_intarray, int _arraysize)
{
	//Alle 2 Nachbarn sortieren
	for (int i = 0; i < _arraysize; i+=2)
	{
		if (_intarray[i] > _intarray[i + 1])
		{
			help = _intarray[i];
			_intarray[i] = _intarray[i + 1];
			_intarray[i + 1] = _intarray[i];
		}
	}

	for (int i = 1; i < _arraysize; i++)
	{
		for (j = i, key = _intarray[j]; j > 0 && _intarray[j - 1] > key; j--)
			_intarray[j] = _intarray[j - 1];

		_intarray[j] = key;
	}
}






}