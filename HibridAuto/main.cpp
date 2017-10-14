#include "BenzinesAuto.h"
#include "HibridAuto.h"

#include <iostream>
#include <locale>

using namespace std;

int main()
{
	setlocale(LC_ALL, "");

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

	system("pause");

	return 0;
}