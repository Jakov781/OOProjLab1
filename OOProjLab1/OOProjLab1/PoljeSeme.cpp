#include "PoljeSeme.h"


PoljeSeme::PoljeSeme(bool otk, int br){
	this->otkriveno = otk;
	this->brojSemena = br;
}

char PoljeSeme::VratiSimbol() {
	if (otkriveno)
		return '*';
	return '-';
}
char PoljeSeme::Prskaj(int jacina) {
	if (jacina + this->brojSemena == 2)
		return '1';
	if (jacina + this->brojSemena == 3)
		return '2';
	if (jacina + this->brojSemena == 4)
		return '3';
	throw "Nemoguc potez";
}
