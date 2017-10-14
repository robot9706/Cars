#pragma once

#include "BenzinesAuto.h"

class HibridAuto : public BenzinesAuto
{
private:
	int elektromosHatotav;
	bool onvezeto;

public:
	HibridAuto(string tipus, int tank, double fogyasztas, int elektromosTav, bool onvezeto);

	virtual double hatotav();
};