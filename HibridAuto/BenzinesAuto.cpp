#include "BenzinesAuto.h"

#include <fstream>
#include <iostream>

using namespace std;

BenzinesAuto::BenzinesAuto(string type, int tank, double fogyasztas)
{
	this->tipus = type;
	this->tankMeret = tank;
	this->fogyasztas = fogyasztas;
}

BenzinesAuto::BenzinesAuto()
{
	cout << "Aut� t�pusa? ";
	cin >> tipus;

	cout << "Tank m�rete? ";
	cin >> tankMeret;

	cout << "Fogyaszt�sa?";
	cin >> fogyasztas;
}

BenzinesAuto::BenzinesAuto(string fileName)
{
	ifstream file(fileName);

	file >> tipus;
	file >> tankMeret;
	file >> fogyasztas;

	file.close();
}

double BenzinesAuto::hatotav()
{
	return (tankMeret / fogyasztas) * 100;
}

void BenzinesAuto::kiir()
{
	cout << "Az aut� t�pusa: " << tipus << ", hat�t�vols�ga: " << hatotav() << endl;
}

void BenzinesAuto::ment(string fileName)
{
	ofstream file(fileName);

	file << tipus << endl;
	file << tankMeret << endl;
	file << fogyasztas << endl;

	file.close();
}
