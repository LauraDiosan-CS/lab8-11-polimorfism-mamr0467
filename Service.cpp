#include "Service.h"

//Desc: creeaza un nou obiect de tip Service
//In: -
//Out: un nou obiect de tip Service cu repo NULL
Service::Service() {
	this->repo = NULL;
}

//Desc: creeaza un nou obiect de tip Service
//In: repo, RepoFile* - un obiect de tip RepoFile
//Out: un nou obiect de tip Service cu Repo-ul dat de cel din parametru
Service::Service(RepoFile* repo) {
	this->repo = repo;
}

//Desc: distruge un obiect de tip Service
//In: -
//Out: -
Service::~Service() {
	if (this->repo) {
		delete this->repo;
		this->repo = NULL;
	}
}

void Service::setFile(string fileName) {
	this->repo->setFileName(fileName);
}

void Service::SetRepo(RepoFile* repo) {
	this->repo = repo;
	this->repo->loadFromFile();
}

//Desc: adauga o calatorie in Service:
//In:
//Out:
void Service::addElem(string cod, string plecare, string destinatie, string data, string escala, int locTot, int locRez) {

	Calatorie* calatorie = new Avion(cod, plecare, destinatie, data, escala, locTot, locRez);

	try {
		this->repo->addElem(calatorie);
	}
	catch (MyException& exc) {
		throw exc;
	}
	if (calatorie)
		delete calatorie;
}

//Desc: adauga o calatorie in Service
//In:
//Out:
void Service::addElem(string cod, string plecare, string destinatie, string data, int durata, int locTot, int locRez) {

	Calatorie* calatorie = new Autobuz(cod, plecare, destinatie, data, durata, locTot, locRez);

	try {
		this->repo->addElem(calatorie);
	}
	catch (MyException& exc) {
		throw exc;
	}
	if (calatorie)
		delete calatorie;
}

//Desc: sterge o calatorie din Service
//In: cod, string- codul calatoriei
//Out: true daca eleemntul a fost sters, false altfel
bool Service::delElem(string cod) {
	bool rez = false;
	try {
		rez = this->repo->delElem(cod);

		return rez;
	}
	catch (MyException& exc) {
		throw exc;
	}
}

//Desc: modifica o calatorie din Service
//In: -
//Out: true daca calatoria a fost modificata, false altfel
bool Service::updateElem(string codVechi, string plecare, string dest, string data, string escala, int locTot, int locRez) {
	Calatorie* ca = new Avion(codVechi, plecare, dest, data, escala, locTot, locRez);
	Calatorie* cVechi = this->repo->getByCode(codVechi);

	try {
		bool rez = this->repo->updateElem(cVechi, ca);
		delete ca;
		delete cVechi;

		return rez;
	}
	catch (MyException& exc) {
		throw exc;
	}
}

//Desc: modifica o calatorie din Service
//In: -
//Out: true daca calatoria a fost modificata, false altfel
bool Service::updateElem(string codVechi, string plecare, string dest, string data, int durata, int locTot, int locRez) {
	Calatorie* ca = new Autobuz(codVechi, plecare, dest, data, durata, locTot, locRez);
	Calatorie* cVechi = this->repo->getByCode(codVechi);

	try {
		bool rez = this->repo->updateElem(cVechi, ca);
		delete ca;
		delete cVechi;

		return rez;
	}
	catch (MyException& exc) {
		throw exc;
	}
}

//Desc: acceseaza lungimea listei de calatorii
//In: -
//Out: lungimea listei
int Service::getSize() {
	return this->repo->getSize();
}

//Desc: acceseaza lista de calatorii
//In: -
//Out: lista de calatorii
vector<Calatorie*> Service::getAll() {
	return this->repo->getAll();
}

//Desc: sterge toate calatoriile
//In: -
//Out: -
void Service::empty() {
	this->repo->empty();
}

//Desc: acceseaza o calatorie dupa pozitia din lista
//In: pos, int - pozitia calatoriei
//Out: -
Calatorie* Service::getElemByPos(int pos) {
	try {
		return this->repo->getElemPos(pos);
	}
	catch (MyException& exc) {
		throw exc;
	}
}