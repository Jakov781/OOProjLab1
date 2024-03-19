#pragma once
#include "Polje.h"

class PoljePuz : public Polje
{
private:
	bool trojanskiPuz;
public:
	PoljePuz(bool trojanski);
	char VratiSimbol();
};

