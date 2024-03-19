#include "PoljeRuza.h"


PoljeRuza::PoljeRuza(bool trojanska) {
	this->trojanska = trojanska;
	this->otkriveno = true;
}

char PoljeRuza::VratiSimbol() {
	if(trojanska)
		return '!';
	return '#';
}
