#pragma once
#include <cstdlib>
#include "Polje.h"
#include "PoljeTrava.h"
#include "PoljeSeme.h"
#include "PoljeRuza.h"
#include "PoljeJaje.h"
#include "PoljePuz.h"
#include <iostream>
#include <fstream>

using namespace std;

class Livada
{
private:
	Polje*** Polja;
	int n;
public:
	Livada(const char* fajl);
	~Livada();
	int VratiN() { return n; };
	void PrikaziLivadu();
	void PrskajPolje(int jacina, int i, int j);
	bool JelSveOtkriveno();
	bool PrskajSeme();
	void OtvoriSvaPolja();
	int BrojBodova();
private:
	void ZameniRuzom(int i, int j);
	void RasejiSeme(int i, int j);
	void ZameniSemenom(int i, int j);
	void ZameniTrojanskomRuzom(int i, int j);
	void ZameniPuzem(int i, int j);
	void ZameniTravom(int i, int j);
	void ZameniTrojanskimPuzem(int i, int j);
	void UnistiOkolneRuze(int i, int j);
};

