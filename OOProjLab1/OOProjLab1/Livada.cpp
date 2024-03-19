#include "Livada.h"

Livada::Livada(const char* fajl) {
	ifstream f(fajl);
	f >> this->n;
	this->Polja = new Polje * *[n];
	for (int i = 0; i < n; i++) {
		this->Polja[i] = new Polje * [n];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char c;
			f >> c;
			switch (c)
			{
			case '-': 
				this->Polja[i][j] = new PoljeTrava(false); 
				break;
			case '*': 
				int br;
				f >> br;
				this->Polja[i][j] = new PoljeSeme(false, br); 
				break;
			case '^': 
				this->Polja[i][j] = new PoljeJaje(); 
				break;
			default:
				throw "Pogresan unos u fajlu";
				break;
			}
		}
	}
}
Livada::~Livada() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			delete Polja[i][j];
		}
		delete[] Polja[i];
	}
	delete[] Polja;
}

void Livada::PrikaziLivadu() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << Polja[i][j]->VratiSimbol() << "    ";
		}
		cout << endl;
	}
}
void Livada::PrskajPolje(int jacina, int i, int j) {
	char event = Polja[i][j]->Prskaj(jacina);

	switch (event)
	{
	case '1':
		ZameniRuzom(i, j);
		break;
	case '2':
		RasejiSeme(i, j);
		break;
	case '3':
		ZameniTrojanskomRuzom(i, j);
		break;
	case '4':
		ZameniPuzem(i, j);
		break;
	case '5':
		ZameniTrojanskimPuzem(i, j);
		break;
	default:
		break;
	}
}
void Livada::ZameniRuzom(int i, int j) {
	delete this->Polja[i][j];
	this->Polja[i][j] = new PoljeRuza(false);
}
void Livada::ZameniSemenom(int i, int j) {
	delete this->Polja[i][j];
	this->Polja[i][j] = new PoljeSeme(true, 1);
}
void Livada::RasejiSeme(int i, int j) {
	int br = 0;
	for (int ii = -1; ii <= 1; ii++) {
		for (int jj = -1; jj <= 1; jj++) {
			if (i + ii < n && j + jj < n && i + ii >= 0 && j + jj >= 0) {
				if (Polja[i + ii][j + jj]->JelTrava()) {
					ZameniSemenom(i + ii, j + jj);
					br++;
					if (br >= 2)
						break;
				}
			}
		}
		if (br >= 2)
			break;
	}
	delete this->Polja[i][j];
	this->Polja[i][j] = new PoljeTrava(true);

}
void Livada::ZameniTrojanskomRuzom(int i, int j) {
	delete this->Polja[i][j];
	this->Polja[i][j] = new PoljeRuza(true);

	for (int j = 0; j < 3; j++) {
		int ii = rand() % n;
		int jj = rand() % n;
		if (ii == i && jj == j)
			j--;
		else
			ZameniRuzom(ii, jj);
	}
}
void Livada::ZameniPuzem(int i, int j) {
	delete this->Polja[i][j];
	this->Polja[i][j] = new PoljePuz(false);
	UnistiOkolneRuze(i, j);
}
void Livada::UnistiOkolneRuze(int i, int j) {
	for (int ii = -1; ii <= 1; ii++) {
		for (int jj = -1; jj <= 1; jj++) {
			if (i + ii < n && j + jj < n && i + ii >= 0 && j + jj >= 0) {
				if (Polja[i + ii][j + jj]->JelRuza()) {
					ZameniTravom(i + ii, j + jj);
				}
			}
		}
	}
}
void Livada::ZameniTravom(int i, int j) {
	delete this->Polja[i][j];
	this->Polja[i][j] = new PoljeTrava(true);
}
void Livada::ZameniTrojanskimPuzem(int i, int j) {
	delete this->Polja[i][j];
	this->Polja[i][j] = new PoljePuz(true);
	UnistiOkolneRuze(i, j);

	for (int j = 0; j < 3; j++) {
		int ii = rand() % n;
		int jj = rand() % n;
		if (ii == i && jj == j)
			j--;
		else
			ZameniPuzem(ii, jj);
	}
}
bool Livada::JelSveOtkriveno() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!Polja[i][j]->JelOtkriveno())
				return false;
		}
	}
	return true;
}
bool Livada::PrskajSeme() {
	bool sem = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (Polja[i][j]->VratiSimbol() == '*'){
				int jacina = (rand() % 2) + 1;
				PrskajPolje(jacina, i, j);
				sem = true;
			}
		}
	}
	return sem;
}
void Livada::OtvoriSvaPolja() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			Polja[i][j]->OtvoriPolje();
		}
	}
}
int Livada::BrojBodova() {
	int br = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (Polja[i][j]->JelRuza())
				br += 10;
		}
	}
	return br;
}
