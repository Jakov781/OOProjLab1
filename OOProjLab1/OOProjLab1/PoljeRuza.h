#pragma once
#include "Polje.h"
class PoljeRuza : public Polje
{
private:
	bool trojanska;
public:
	PoljeRuza(bool);
	char VratiSimbol();
	bool JelRuza() { return true; };
};

