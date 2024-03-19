#include "PoljeJaje.h"

char PoljeJaje::VratiSimbol() {
	if (otkriveno)
		return '^';
	return '-';
}
char PoljeJaje::Prskaj(int jacina) {
	if (jacina + brojJaja == 2)
		return '4';
	if (jacina + brojJaja == 3)
		return '5';
	throw "Nemoguc potez";
}
