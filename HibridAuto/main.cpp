#include "BenzinesAuto.h"
#include "HibridAuto.h"
#include "AutoKolcsonzo.h"

#include <iostream>
#include <locale>

using namespace std;

void main_f1()
{
	BenzinesAuto* a;

	//Benzines ctor
	{
		a = new BenzinesAuto("Random", 60, 6);

		cout << "Ctor alapján:" << endl;

		a->kiir();

		delete a;
	}

	//Benzines stdin
	{
		cout << "Bement alapján:" << endl;

		a = new BenzinesAuto();

		a->kiir();
		a->ment("random.car");

		delete a;
	}

	//Benzines file
	{
		cout << "Fájlból:" << endl;

		a = new BenzinesAuto("random.car");

		a->kiir();

		delete a;
	}

	//Hibrid ctor
	{
		a = new HibridAuto("Hibrid", 50, 6, 50, false);

		cout << "Hibrid:" << endl;
		a->kiir();

		delete a;
	}
}

void main_f2()
{
	AutoKolcsonzo k(5);

	BenzinesAuto b1("Benzines #1", 30, 1);
	k += b1;

	HibridAuto h1("Hibrid #1", 30, 1, 50, false);
	k += h1;

	HibridAuto h2("Hibrid #2", 100, 2, 20, false);
	k += h2;

	BenzinesAuto* kolcson = k[1];
	cout << "1. indexû autó kölcsönzése: " << (kolcson == NULL ? "nem" : "") << " sikeres" << endl;

	BenzinesAuto* kolcson2 = k[4];
	cout << "4. indexû autó kölcsönzése: " << (kolcson2 == NULL ? "nem" : "") << " sikeres" << endl;

	cout << k;
}

int main()
{
	setlocale(LC_ALL, "");

	//main_f1();
	main_f2();

	system("pause");

	return 0;
}