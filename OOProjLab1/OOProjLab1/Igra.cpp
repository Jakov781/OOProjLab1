#include "Igra.h"

Igra::Igra(const char* fajl) : livada(fajl){

}
void Igra::IgrajIgru() {
	srand(time(0));
	while (!livada.JelSveOtkriveno()) {
		livada.PrikaziLivadu();
		if (livada.PrskajSeme())
		{
			cout << "Rasejano seme" << endl;
			continue;
		}
		cout << endl;
		int i, j;
		int jacina;
		jacina = (rand() % 2) + 1;
		i = rand() % livada.VratiN();
		j = rand() % livada.VratiN();
		cout << "jacina: " << jacina << ", x = " << i + 1 << ", y = " << j + 1 << endl;
		livada.PrskajPolje(jacina, i, j);
	}
	cout << endl;
	livada.OtvoriSvaPolja();
	livada.PrikaziLivadu();
	cout << endl << "Broj bodova: " << livada.BrojBodova() << endl;
}