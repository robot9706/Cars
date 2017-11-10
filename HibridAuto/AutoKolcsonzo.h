#pragma once

#include "BenzinesAuto.h"

#include <ostream>
using namespace std;

class AutoKolcsonzo
{
private:
	int _helyek;
	BenzinesAuto** _autok;

public:
	AutoKolcsonzo(int kapacitas);
	AutoKolcsonzo* operator+=(BenzinesAuto& a);
	BenzinesAuto* operator[](int index);
	friend ostream& operator<<(ostream& os, AutoKolcsonzo& t);

	AutoKolcsonzo(AutoKolcsonzo& k);
	~AutoKolcsonzo();
};