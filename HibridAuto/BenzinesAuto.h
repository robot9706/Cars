#pragma once

#include <string>

using namespace std;

class BenzinesAuto 
{
private:
	string tipus;
	int tankMeret;
	double fogyasztas; //l/100km

public:
	BenzinesAuto(string tipus, int tank, double fogyasztas);
	BenzinesAuto();
	BenzinesAuto(string fileNev);

	virtual double hatotav();
	void kiir();
	void ment(string fileNEv);
};