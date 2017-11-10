#include "AutoKolcsonzo.h"

#include <memory>
#include <iostream>

using namespace std;

AutoKolcsonzo::AutoKolcsonzo(int kapacitas)
{
	_helyek = kapacitas;

	_autok = new BenzinesAuto*[kapacitas];
	for (int x = 0; x < kapacitas; x++)
		_autok[x] = NULL;
}

AutoKolcsonzo* AutoKolcsonzo::operator+=(BenzinesAuto& a)
{
	for (int x = 0; x < _helyek; x++) 
	{
		if (_autok[x] == NULL) 
		{
			_autok[x] = &a;
			break;
		}
	}

	return this;
}

BenzinesAuto* AutoKolcsonzo::operator[](int index)
{
	if (index < 0 || index >= _helyek || _autok[index] == nullptr)
	{
		cout << "Nincs bent ilyen számú autó." << endl;

		return nullptr;
	}

	BenzinesAuto* a = _autok[index];
	_autok[index] = NULL;

	cout << "Jó utat a következõ " << a->hatotav() << " km-en!" << endl;

	return a;
}

AutoKolcsonzo::AutoKolcsonzo(AutoKolcsonzo& k)
{
	_helyek = k._helyek;

	_autok = new BenzinesAuto*[_helyek];
	for (int x = 0; x < _helyek; x++)
		_autok[x] = k._autok[x];
}

AutoKolcsonzo::~AutoKolcsonzo()
{
	delete[] _autok;
}

ostream& operator<<(ostream& os, AutoKolcsonzo & t)
{
	int count = 0;
	for (int x = 0; x < t._helyek; x++)
	{
		if (t._autok[x] != NULL)
			count++;
	}

	cout << "A kölcsönzõben lévõ autók száma: " << count << endl;

	for (int x = 0; x < t._helyek; x++) 
	{
		if (t._autok[x] != NULL)
		{
			BenzinesAuto* a = t._autok[x];

			cout << "#" << x << ": " << a->tipus << ", táv: " << a->hatotav() << endl;
		}
	}

	return os;
}
