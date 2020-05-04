#include "Autobuz.h"

//Desc: creeza un obiect nou de tip Autobuz
//In: -
//Out: o instanta a clasei Autobuz cu atribute implicte
Autobuz::Autobuz() {
	this->cod = "";
	this->plecare = "";
	this->destinatie = "";
	this->data = "";
	this->durata = 0;
	this->nrTotLoc = 0;
	this->nrLocRez = 0;
}

//Desc: creeza un obiect nou de tip Autobuz
//In: cod, string - codul pentru noul obiect
//    plecare, string - plecarea pentru noul obiect
//    destinatie, string - destinatia pentru noul obiect
//    data, string - data pentru noul obiect
//    durata, int - durata pentru noul obiect
//	  nrTotLoc, int - numar total de locuri pentru noul obiect
//	  nrLocRez, int - numarul de locuri rezervate pentru noul obiect
//Out: o instanta a clasei Autobuz cu atributele date de parametri
Autobuz::Autobuz(string cod, string plecare, string destinatie, string data, int durata, int nrTotLoc, int nrLocRez) {
	this->cod = cod;
	this->plecare = plecare;
	this->destinatie = destinatie;
	this->data = data;
	this->durata = durata;
	this->nrTotLoc = nrTotLoc;
	this->nrLocRez = nrLocRez;
}

//Desc: creeza un obiect nou de tip Autobuz
//In: a, Autobuz - un obiect de tip Autobuz
//Out: o instanta a clasei Autobuz cu atributele date de Autobuzul transmis ca parametru
Autobuz::Autobuz(const Autobuz& a) {
	this->cod = a.cod;
	this->plecare = a.plecare;
	this->destinatie = a.destinatie;
	this->data = a.data;
	this->durata = a.durata;
	this->nrTotLoc = a.nrTotLoc;
	this->nrLocRez = a.nrLocRez;
}

//Desc: distruge un obiect de tip Autobuz
//In: -
//Out: -
Autobuz::~Autobuz() {}

//Desc: schimba codul unui Autobuz
//In: cod, int - noul cod
//Out:
void Autobuz::setCod(string cod) {
	this->cod = cod;
}

//Desc: schimba locul de plecare al unui Autobuz
//In: plecare, string - noul loc de plecare
//Out:
void Autobuz::setPlecare(string plecare) {
	this->plecare = plecare;
}

//Desc: schimba destinatia al unui Autobuz
//In: destinatie, string - noua destinatie
//Out:
void Autobuz::setDestinatie(string destinatie) {
	this->destinatie = destinatie;
}

//Desc: schimba data al unui Autobuz
//In: data, string - noua data
//Out:
void Autobuz::setData(string data) {
	this->data = data;
}

//Desc: schimba durata calatoriei unui Autobuz
//In: durata, int - noua durata a calatoriei 
//Out:
void Autobuz::setDurata(int durata) {
	this->durata = durata;
}

//Desc: schimba numarul de locuri totale ale unui Autobuz
//In: nrTotLoc, int - noul numar de locuri totale
//Out:
void Autobuz::setnrLocuriTotale(int nrTotLoc) {
	this->nrTotLoc = nrTotLoc;
}

//Desc: schimba numarul de locuri rezervate ale unui Autobuz
//In: nrLocRez, int - noul numar de locuri rezervate
//Out:
void Autobuz::setnrLocuriRez(int nrLocRez) {
	this->nrLocRez = nrLocRez;
}

//Desc: acceseaza codul unui Autobuz
//In: -
//Out: codul Autobuzului
string Autobuz::getCod() {
	return this->cod;
}

//Desc: acceseaza locul de plecare al unui Autobuz
//In: -
//Out: locul de plecare al Autobuzului
string Autobuz::getPlecare() {
	return this->plecare;
}

//Desc: acceseaza destinatia unui Autobuz
//In: -
//Out: destinatia Autobuzului
string Autobuz::getDestinatie() {
	return this->destinatie;
}

//Desc: acceseaza data de plecare a unui Autobuz
//In: -
//Out: data de plecare a Autobuzului
string Autobuz::getData() {
	return this->data;
}

//Desc: acceseaza duarata calatoriei unui Autobuz
//In: -
//Out: durata calatoriei Autobuzului
int Autobuz::getDurata() {
	return this->durata;
}

//Desc: acceseaza numarul de locuri totale ale unui Autobuz
//In: -
//Out: numarul de locuri totale ale Autobuzului
int Autobuz::getnrLocuriTotale() {
	return this->nrTotLoc;
}

//Desc: acceseaza numarul de locuri rezervate ale unui Autobuz
//In: -
//Out: numarul de locuri rezervate ale Autobuzului
int Autobuz::getnrLocuriRez() {
	return this->nrLocRez;
}

//Desc: creeaza o clona a unui Autobuz cu aceleasi atribute ca si instanta curenta
//In: -
//Out: clona
IEntity* Autobuz::clone() {
	Autobuz* a = new Autobuz(this->cod, this->plecare, this->destinatie, this->data,
		this->durata, this->nrTotLoc, this->nrLocRez);

	return a;
}


//Desc: verifica daca doua obiecte au aceleasi atribute
//In: e, IEntity* - pointer catre un obiect de tip IEntity
//Out: true/false
bool Autobuz::equals(IEntity* e) {
	return ((this->cod == ((Autobuz*)e)->cod) && (this->plecare == ((Autobuz*)e)->plecare) &&
		(this->destinatie == ((Autobuz*)e)->destinatie) && (this->data == ((Autobuz*)e)->data) &&
		(this->durata == ((Autobuz*)e)->durata) && (this->nrTotLoc == ((Autobuz*)e)->nrTotLoc) &&
		(this->nrLocRez == ((Autobuz*)e)->nrLocRez));
}

//Desc: creeaza un string format din atrubutele Autobuzului separate printr-un delimitator
//In: del, string - delimitatorul
//Out: string-ul cu atributele Autobuzului
string Autobuz::toString(string del) {
	string s = "";
	s = s + "AU" + del + this->cod + del + this->plecare + del + this->destinatie + del +
		this->data + del + to_string(this->durata) + del + to_string(this->nrTotLoc) + del +
		to_string(this->nrLocRez);

	return s;
}

//Desc: citeste atributele unui Autobuz folosind un stream standard de intrare
//In: is, istream& - o referinta catre un stream standard de intrare
//	  Autobuz, Autobuz& - o referinta catre un Autobuz
//Out: referinta catre stremul de intrare dat ca parametru
istream& operator>>(istream& is, Autobuz& Autobuz) {
	is >> Autobuz.cod;
	is >> Autobuz.plecare;
	is >> Autobuz.destinatie;
	is >> Autobuz.data;
	is >> Autobuz.durata;
	is >> Autobuz.nrTotLoc;
	is >> Autobuz.nrLocRez;

	return is;
}

//Desc: verifica daca doua obiecte au aceleasi atribute
//In: Autobuz, Autobuz& - o referinta catre un Autobuz
//Out: true/false
bool Autobuz::operator==(const Autobuz& Autobuz) {
	return ((this->cod == Autobuz.cod) && (this->plecare == Autobuz.plecare) &&
		(this->destinatie == Autobuz.destinatie) && (this->data == Autobuz.data) &&
		(this->durata == Autobuz.durata) && (this->nrTotLoc == Autobuz.nrTotLoc) &&
		(this->nrLocRez == Autobuz.nrLocRez));
}

//Desc: schimba atributele unui Autobuz cu atributele altui Autobuz
//In: a, Autobuz& - o referinta catre un Autobuz
//Out: referinta catre instanta curenta
Autobuz& Autobuz::operator=(const Autobuz& a) {
	this->cod = a.cod;
	this->plecare = a.plecare;
	this->destinatie = a.destinatie;
	this->data = a.data;
	this->durata = a.durata;
	this->nrTotLoc = a.nrTotLoc;
	this->nrLocRez = a.nrLocRez;

	return *this;
}