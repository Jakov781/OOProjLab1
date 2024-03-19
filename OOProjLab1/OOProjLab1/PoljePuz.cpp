#include "PoljePuz.h"


PoljePuz::PoljePuz(bool trojanski) {
	this->trojanskiPuz = trojanski;
	this->otkriveno = true;
}
char PoljePuz::VratiSimbol() {
	if (trojanskiPuz)
		return '$';
	return '%';
}
