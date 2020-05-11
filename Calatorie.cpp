#include "Calatorie.h"

Calatorie::Calatorie() {
	this->cod = "";
	this->plecare = "";
	this->destinatie = "";
	this->data = "";
	this->nrTotLoc = 0;
	this->nrLocRez = 0;
}

Calatorie::Calatorie(string cod, string plecare, string dest, string data, int nrLocTot, int nrLocRez) {
	this->cod = cod;
	this->plecare = plecare;
	this->destinatie = dest;
	this->data = data;
	this->nrTotLoc = nrLocTot;
	this->nrLocRez = nrLocRez;
}

Calatorie::Calatorie(const Calatorie& c) {
	this->cod = c.cod;
	this->plecare = c.plecare;
	this->destinatie = c.destinatie;
	this->data = c.data;
	this->nrTotLoc = c.nrTotLoc;
	this->nrLocRez = c.nrLocRez;
}

Calatorie::~Calatorie()
{
}

//Desc: acceseaza codul unei calatorii
//In: -
//Out: codul calatoriei
string Calatorie::getCod() {
	return this->cod;
}

//Desc: acceseaza destinatia unei calatorii
//In: -
//Out: destinatia calatoriei
string Calatorie::getDestinatie() {
	return this->destinatie;
}

//Desc: acceseaza locul de plecare al unei calatorii
//In: -
//Out: locul de plecare al unei calatoriei
string Calatorie::getPlecare() {
	return this->plecare;
}

//Desc: acceseaza data unei calatorii
//In: -
//Out: data calatoriei
string Calatorie::getData() {
	return this->data;
}

//Desc: acceseaza numarul de locuri rezervate ale unei calatorii
//In: -
//Out: numarul de locuri rezervate ale calatoriei
int Calatorie::getnrLocRez() {
	return this->nrLocRez;
}

//Desc: acceseaza numarul de locuri totale ale unei calatorii
//In: -
//Out: numarul de locuri totale ale calatoriei
int Calatorie::getnrTotLoc() {
	return this->nrTotLoc;
}

//Desc: schimba codul unei calatorii
//In: cod, string - noul cod
//Out:
void Calatorie::setCod(string cod) {
	this->cod = cod;
}

//Desc: schimba locul de plecare al unei calatorii
//In: plecare, string - noul loc de plecare
//Out:
void Calatorie::setPlecare(string plecare) {
	this->plecare = plecare;
}

//Desc: schimba destinatia al unei calatorii
//In: destinatie, string - noua destinatie
//Out:
void Calatorie::setDestinatie(string destinatie) {
	this->destinatie = destinatie;
}

//Desc: schimba numarul de locuri rezervate ale unei calatorii
//In: nrLocRez, int - noul numar de locuri rezervate
//Out:
void Calatorie::setnrLocRez(int nrLocRez) {
	this->nrLocRez = nrLocRez;
}

//Desc: schimba numarul de locuri totale ale unei calatorii
//In: nrTotLoc, int - noul numar de locuri totale
//Out:
void Calatorie::setnrTotLoc(int nrTotLoc) {
	this->nrTotLoc = nrTotLoc;
}

//Desc: schimba data al unei calatorii
//In: data, string - noua data
//Out:
void Calatorie::setData(string data) {
	this->data = data;
}

string Calatorie::toString(string delim) {
	string s = "";
	s = "CA" + delim + this->cod + delim + this->plecare + delim + this->destinatie
		+ delim + this->data + delim + to_string(this->nrTotLoc) + " " + to_string(this->nrLocRez) + "\n";
	return s;
}

Calatorie* Calatorie::clone()
{
	Calatorie* calatorie1 = new Calatorie();
	calatorie1->cod = this->cod;
	calatorie1->plecare = this->plecare;
	calatorie1->destinatie = this->destinatie;
	calatorie1->data = this->data;
	calatorie1->nrTotLoc = this->nrTotLoc;
	calatorie1->nrLocRez = this->nrLocRez;
	return calatorie1;
}

bool Calatorie::equals(Calatorie* e) {
	return ((this->cod == e->cod) && (this->plecare == e->plecare) &&
		(this->destinatie == e->destinatie) && (this->data == e->data) && 
		(this->nrTotLoc == e->nrTotLoc) && (this->nrLocRez == e->nrLocRez));
}

istream& operator>>(istream& is, Calatorie& c) {
	is >> c.cod;
	is >> c.plecare;

	is >> c.destinatie;
	is >> c.data;
	is >> c.nrTotLoc;

	is >> c.nrLocRez;
	return is;
}

ostream& operator<<(ostream& os, const Calatorie& c) {
	os << c.cod << " " << c.plecare << " " << c.destinatie << " " << 
		c.data << " " << c.nrTotLoc << " " << c.nrLocRez;

	return os;
}


bool Calatorie::operator==(const Calatorie& c) {
	return (this->cod == c.cod && this->data == c.data && 
		this->destinatie == c.destinatie && this->plecare == c.plecare && 
		this->nrLocRez == c.nrLocRez && this->nrTotLoc == c.nrTotLoc);
}

bool Calatorie::operator!=(const Calatorie& c) {
	return (this->cod != c.cod || this->data != c.data ||
		this->destinatie != c.destinatie || this->plecare != c.plecare ||
		this->nrLocRez != c.nrLocRez || this->nrTotLoc != c.nrTotLoc);
}