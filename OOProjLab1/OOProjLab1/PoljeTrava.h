#pragma once
#include "Polje.h"

class PoljeTrava : public Polje
{
public:
	PoljeTrava(bool);
	char VratiSimbol();
	char Prskaj(int jacina);
	bool JelTrava() { return true; };
};

