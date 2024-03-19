#pragma once
class Polje
{
protected:
	bool otkriveno;
public:
	Polje() { this->otkriveno = false; };
	virtual char VratiSimbol();
	virtual char Prskaj(int jacina);
	virtual bool JelOtkriveno() { return true; };
	virtual bool JelTrava() { return false; };
	virtual bool JelRuza() { return false; };
	void OtvoriPolje() { this->otkriveno = true; };
};

