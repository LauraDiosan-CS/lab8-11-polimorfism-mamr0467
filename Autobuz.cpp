#include "Autobuz.h"

//Desc: creeza un obiect nou de tip Autobuz
//In: -
//Out: o instanta a clasei Autobuz cu atribute implicte
Autobuz::Autobuz() : Calatorie() {
	this->durata = 0;
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
Autobuz::Autobuz(string cod, string plecare, string destinatie, string data, int durata, int nrTotLoc, int nrLocRez) :
	Calatorie(cod, plecare, destinatie, data, nrTotLoc, nrLocRez) {
	this->durata = durata;
}

//Desc: creeza un obiect nou de tip Autobuz
//In: a, Autobuz - un obiect de tip Autobuz
//Out: o instanta a clasei Autobuz cu atributele date de Autobuzul transmis ca parametru
Autobuz::Autobuz(const Autobuz& a) : Calatorie(a) {
	this->durata = a.durata;
}

Autobuz::Autobuz(string line, char delim) {
	vector<string> words = split(line, delim);
	this->cod = words[1];
	this->plecare = words[2];
	this->destinatie = words[3];
	this->data = words[4];
	this->durata = stoi(words[5]);
	this->nrTotLoc = stoi(words[6]);
	this->nrLocRez = stoi(words[7]);
}

//Desc: distruge un obiect de tip Autobuz
//In: -
//Out: -
Autobuz::~Autobuz() {}

//Desc: schimba durata calatoriei unui Autobuz
//In: durata, int - noua durata a calatoriei 
//Out:
void Autobuz::setDurata(int durata) {
	this->durata = durata;
}

//Desc: acceseaza duarata calatoriei unui Autobuz
//In: -
//Out: durata calatoriei Autobuzului
int Autobuz::getDurata() {
	return this->durata;
}

//Desc: creeaza o clona a unui Autobuz cu aceleasi atribute ca si instanta curenta
//In: -
//Out: clona
Calatorie* Autobuz::clone() {
	Autobuz* a = new Autobuz(this->cod, this->plecare, this->destinatie, this->data,
		this->durata, this->nrTotLoc, this->nrLocRez);

	return a;
}


//Desc: verifica daca doua obiecte au aceleasi atribute
//In: e, Calatorie* - pointer catre un obiect de tip calatorie
//Out: true/false
bool Autobuz::equals(Calatorie* e) {
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
//In: Autobuz, Calatorie& - o referinta catre un Autobuz
//Out: true/false
bool Autobuz::operator==(const Calatorie& a) {
	return ((this->cod == ((Autobuz&)a).cod) && (this->plecare == ((Autobuz&)a).plecare) &&
		(this->destinatie == ((Autobuz&)a).destinatie) && (this->data == ((Autobuz&)a).data) &&
		(this->durata == ((Autobuz&)a).durata) && (this->nrTotLoc == ((Autobuz&)a).nrTotLoc) &&
		(this->nrLocRez == ((Autobuz&)a).nrLocRez));
}

//Desc: verifica daca doua obiecte au aceleasi atribute
//In: Autobuz, Calatorie& - o referinta catre o Calatorie
//Out: true/false
bool Autobuz::operator!=(const Calatorie& a) {
	return ((this->cod != ((Autobuz&)a).cod) && (this->plecare != ((Autobuz&)a).plecare) &&
		(this->destinatie != ((Autobuz&)a).destinatie) && (this->data != ((Autobuz&)a).data) &&
		(this->durata != ((Autobuz&)a).durata) && (this->nrTotLoc != ((Autobuz&)a).nrTotLoc) &&
		(this->nrLocRez != ((Autobuz&)a).nrLocRez));
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