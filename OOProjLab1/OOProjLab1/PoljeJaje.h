#pragma once
#include "Polje.h"
class PoljeJaje : public Polje
{
private:
	const int brojJaja = 1;
public:
	char VratiSimbol();
	char Prskaj(int jacina);
	bool JelOtkriveno() { return false; };
};

