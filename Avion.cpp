#include "Avion.h"

//Desc: creeza un obiect nou de tip Avion
//In: -
//Out: o instanta a clasei Avion cu atribute implicte
Avion::Avion() :  Calatorie() {
	this->escala = "";
}

//Desc: creeza un obiect nou de tip Avion
//In: cod, string - codul pentru noul obiect
//    plecare, string - plecarea pentru noul obiect
//    destinatie, string - destinatia pentru noul obiect
//    data, string - data pentru noul obiect
//    escala, string - proprietatea de a avea escala pentru noul obiect
//	  nrTotLoc, int - numar total de locuri pentru noul obiect
//	  nrLocRez, int - numarul de locuri rezervate pentru noul obiect
//Out: o instanta a clasei Avion cu atributele date de parametri
Avion::Avion(string cod, string plecare, string destinatie, string data, string escala, int nrTotLoc, int nrLocRez) : 
	Calatorie(cod, plecare, destinatie, data, nrTotLoc, nrLocRez) {
	this->escala = escala;
}

//Desc: creeza un obiect nou de tip Avion
//In: a, Avion - un obiect de tip Avion
//Out: o instanta a clasei Avion cu atributele date de avionul transmis ca parametru
Avion::Avion(const Avion& a) : Calatorie(a) {
	this->escala = a.escala;
}

//Desc: distruge un obiect de tip avion
//In: -
//Out: -
Avion::~Avion() {}

//Desc: schimba proprietatea de a avea escala a unui avion
//In: escala, string - noua proprietate de a avea escala
//Out:
void Avion::setEscala(string escala) {
	this->escala = escala;
}

//Desc: acceseaza proprietatea de a avea escala a unui avion
//In: -
//Out: proprietatea de a avea escala a avionului
string Avion::getEscala() {
	return this->escala;
}

//Desc: creeaza o clona a unui avion cu aceleasi atribute ca si instanta curenta
//In: -
//Out: clona
Calatorie* Avion::clone() {
	Avion* a = new Avion(this->cod, this->plecare, this->destinatie, this->data,
		this->escala, this->nrTotLoc, this->nrLocRez);

	return a;
}


//Desc: verifica daca doua obiecte au aceleasi atribute
//In: e, Calatorie* - pointer catre un obiect de tip IEntity
//Out: true/false
bool Avion::equals(Calatorie* e) {
	return ((this->cod == ((Avion*)e)->cod) && (this->plecare == ((Avion*)e)->plecare) &&
		(this->destinatie == ((Avion*)e)->destinatie) && (this->data == ((Avion*)e)->data) &&
		(this->escala == ((Avion*)e)->escala) && (this->nrTotLoc == ((Avion*)e)->nrTotLoc) &&
		(this->nrLocRez == ((Avion*)e)->nrLocRez));
}

//Desc: creeaza un string format din atrubutele avionului separate printr-un delimitator
//In: del, string - delimitatorul
//Out: string-ul cu atributele avionului
string Avion::toString(string del) {
	string s = "";
	s = s + "AV" + del + this->cod + del + this->plecare + del + this->destinatie + del +
		this->data + del + this->escala + del + to_string(this->nrTotLoc) + del +
		to_string(this->nrLocRez);

	return s;
}

//Desc: citeste atributele unui avion folosind un stream standard de intrare
//In: is, istream& - o referinta catre un stream standard de intrare
//	  avion, Avion& - o referinta catre un avion
//Out: referinta catre stremul de intrare dat ca parametru
istream& operator>>(istream& is, Avion& avion) {
	is >> avion.cod;
	is >> avion.plecare;
	is >> avion.destinatie;
	is >> avion.data;
	is >> avion.escala;
	is >> avion.nrTotLoc;
	is >> avion.nrLocRez;

	return is;
}

//Desc: citeste atributele unui avion folosind un stream standard de intrare
//In: is, istream& - o referinta catre un stream standard de intrare
//	  avion, Avion& - o referinta catre un avion
//Out: referinta catre stremul de intrare dat ca parametru
ostream& operator<<(ostream& os, Avion& avion) {
	os << avion.cod << ' ';
	os << avion.plecare << ' ';
	os << avion.destinatie << ' ';
	os << avion.data << ' ';
	os << avion.escala << ' ';
	os << avion.nrTotLoc << ' ';
	os << avion.nrLocRez << ' ';

	return os;
}

//Desc: verifica daca doua obiecte au aceleasi atribute
//In: avion, Calatorie& - o referinta catre un avion
//Out: true/false
bool Avion::operator==(const Calatorie& avion) {
	return ((this->cod == ((Avion&)avion).cod) && (this->plecare == ((Avion&)avion).plecare) &&
		(this->destinatie == ((Avion&)avion).destinatie) && (this->data == ((Avion&)avion).data) &&
		(this->escala == ((Avion&)avion).escala) && (this->nrTotLoc == ((Avion&)avion).nrTotLoc) &&
		(this->nrLocRez == ((Avion&)avion).nrLocRez));
}

//Desc: verifica daca doua obiecte au atribute diferite
//In: avion, Calatorie& - o referinta catre o calatorie
//Out: true/false
bool Avion::operator!=(const Calatorie& avion) {
	return ((this->cod != ((Avion&)avion).cod) || (this->plecare != ((Avion&)avion).plecare) ||
		(this->destinatie != ((Avion&)avion).destinatie) || (this->data != ((Avion&)avion).data) ||
		(this->escala != ((Avion&)avion).escala) || (this->nrTotLoc != ((Avion&)avion).nrTotLoc) ||
		(this->nrLocRez != ((Avion&)avion).nrLocRez));
}

//Desc: schimba atributele unui avion cu atributele altui avion
//In: a, Avion& - o referinta catre un avion
//Out: referinta catre instanta curenta
Avion& Avion::operator=(const Avion& a) {
	this->cod = a.cod;
	this->plecare = a.plecare;
	this->destinatie = a.destinatie;
	this->data = a.data;
	this->escala = a.escala;
	this->nrTotLoc = a.nrTotLoc;
	this->nrLocRez = a.nrLocRez;

	return *this;
}