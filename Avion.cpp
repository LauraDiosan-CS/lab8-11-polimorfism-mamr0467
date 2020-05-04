#include "Avion.h"

//Desc: creeza un obiect nou de tip Avion
//In: -
//Out: o instanta a clasei Avion cu atribute implicte
Avion::Avion() {
	this->cod = "";
	this->plecare = "";
	this->destinatie = "";
	this->data = "";
	this->escala = "";
	this->nrTotLoc = 0;
	this->nrLocRez = 0;
}

//Desc: creeza un obiect nou de tip Avion
//In: cod, int - codul pentru noul obiect
//    plecare, string - plecarea pentru noul obiect
//    destinatie, string - destinatia pentru noul obiect
//    data, string - data pentru noul obiect
//    escala, string - proprietatea de a avea escala pentru noul obiect
//	  nrTotLoc, int - numar total de locuri pentru noul obiect
//	  nrLocRez, int - numarul de locuri rezervate pentru noul obiect
//Out: o instanta a clasei Avion cu atributele date de parametri
Avion::Avion(string cod, string plecare, string destinatie, string data, string escala, int nrTotLoc, int nrLocRez) {
	this->cod = cod;
	this->plecare = plecare;
	this->destinatie = destinatie;
	this->data = data;
	this->escala = escala;
	this->nrTotLoc = nrTotLoc;
	this->nrLocRez = nrLocRez;
}

//Desc: creeza un obiect nou de tip Avion
//In: a, Avion - un obiect de tip Avion
//Out: o instanta a clasei Avion cu atributele date de avionul transmis ca parametru
Avion::Avion(const Avion& a) {
	this->cod = a.cod;
	this->plecare = a.plecare;
	this->destinatie = a.destinatie;
	this->data = a.data;
	this->escala = a.escala;
	this->nrTotLoc = a.nrTotLoc;
	this->nrLocRez = a.nrLocRez;
}

//Desc: distruge un obiect de tip avion
//In: -
//Out: -
Avion::~Avion() {}

//Desc: schimba codul unui avion
//In: cod, int - noul cod
//Out:
void Avion::setCod(string cod) {
	this->cod = cod;
}

//Desc: schimba locul de plecare al unui avion
//In: plecare, string - noul loc de plecare
//Out:
void Avion::setPlecare(string plecare) {
	this->plecare = plecare;
}

//Desc: schimba destinatia al unui avion
//In: destinatie, string - noua destinatie
//Out:
void Avion::setDestinatie(string destinatie) {
	this->destinatie = destinatie;
}

//Desc: schimba data al unui avion
//In: data, string - noua data
//Out:
void Avion::setData(string data) {
	this->data = data;
}

//Desc: schimba proprietatea de a avea escala a unui avion
//In: escala, string - noua proprietate de a avea escala
//Out:
void Avion::setEscala(string escala) {
	this->escala = escala;
}

//Desc: schimba numarul de locuri totale ale unui avion
//In: nrTotLoc, int - noul numar de locuri totale
//Out:
void Avion::setnrLocuriTotale(int nrTotLoc) {
	this->nrTotLoc = nrTotLoc;
}

//Desc: schimba numarul de locuri rezervate ale unui avion
//In: nrLocRez, int - noul numar de locuri rezervate
//Out:
void Avion::setnrLocuriRez(int nrLocRez) {
	this->nrLocRez = nrLocRez;
}

//Desc: acceseaza codul unui avion
//In: -
//Out: codul avionului
string Avion::getCod() {
	return this->cod;
}

//Desc: acceseaza locul de plecare al unui avion
//In: -
//Out: locul de plecare al avionului
string Avion::getPlecare() {
	return this->plecare;
}

//Desc: acceseaza destinatia unui avion
//In: -
//Out: destinatia avionului
string Avion::getDestinatie() {
	return this->destinatie;
}

//Desc: acceseaza data de plecare a unui avion
//In: -
//Out: data de plecare a avionului
string Avion::getData() {
	return this->data;
}

//Desc: acceseaza proprietatea de a avea escala a unui avion
//In: -
//Out: proprietatea de a avea escala a avionului
string Avion::getEscala() {
	return this->escala;
}

//Desc: acceseaza numarul de locuri totale ale unui avion
//In: -
//Out: numarul de locuri totale ale avionului
int Avion::getnrLocuriTotale() {
	return this->nrTotLoc;
}

//Desc: acceseaza numarul de locuri rezervate ale unui avion
//In: -
//Out: numarul de locuri rezervate ale avionului
int Avion::getnrLocuriRez() {
	return this->nrLocRez;
}

//Desc: creeaza o clona a unui avion cu aceleasi atribute ca si instanta curenta
//In: -
//Out: clona
IEntity* Avion::clone() {
	Avion* a = new Avion(this->cod, this->plecare, this->destinatie, this->data,
		this->escala, this->nrTotLoc, this->nrLocRez);

	return a;
}


//Desc: verifica daca doua obiecte au aceleasi atribute
//In: e, IEntity* - pointer catre un obiect de tip IEntity
//Out: true/false
bool Avion::equals(IEntity* e) {
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

//Desc: verifica daca doua obiecte au aceleasi atribute
//In: avion, Avion& - o referinta catre un avion
//Out: true/false
bool Avion::operator==(const Avion& avion) {
	return ((this->cod == avion.cod) && (this->plecare == avion.plecare) &&
		(this->destinatie == avion.destinatie) && (this->data == avion.data) &&
		(this->escala == avion.escala) && (this->nrTotLoc == avion.nrTotLoc) &&
		(this->nrLocRez == avion.nrLocRez));
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