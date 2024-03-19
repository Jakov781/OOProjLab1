#include "PoljeTrava.h"


PoljeTrava::PoljeTrava(bool otk) {
	this->otkriveno = otk;
}
char PoljeTrava::VratiSimbol() {
	if (otkriveno)
		return '@';
	return '-';
}
char PoljeTrava::Prskaj(int jacina) {
	this->otkriveno = true;
	return '0';
}
