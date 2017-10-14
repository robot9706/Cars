#include "HibridAuto.h"

HibridAuto::HibridAuto(string tipus, int tank, double fogyasztas, int elektromosTav, bool onvezeto)
	: BenzinesAuto(tipus, tank, fogyasztas)
{
	this->elektromosHatotav = elektromosTav;
	this->onvezeto = onvezeto;
}

double HibridAuto::hatotav()
{
	return BenzinesAuto::hatotav() + elektromosHatotav;
}
