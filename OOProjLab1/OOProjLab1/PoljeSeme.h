#pragma once
#include "Polje.h"

class PoljeSeme : public Polje
{
	int brojSemena;
public:
	int BrojSemena() { return brojSemena; };
	PoljeSeme(bool otk, int br);
	bool JelOtkriveno() { return false; };
	char VratiSimbol();
	char Prskaj(int jacina);
};

