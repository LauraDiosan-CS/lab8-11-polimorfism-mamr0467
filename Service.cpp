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
}

//Desc: adauga o calatorie in Service:
//In:
//Out:
void Service::addElem(string cod, string plecare, string destinatie, string data, string escala, int locTot, int locRez)
throw (ValidationException, MyException) {

	Avion calatorie(cod, plecare, destinatie, data, escala, locTot, locRez);

	this->repo->addElem(&calatorie);
}

//Desc: adauga o calatorie in Service
//In:
//Out:
void Service::addElem(string cod, string plecare, string destinatie, string data, int durata, int locTot, int locRez)
throw (ValidationException, MyException) {

	Autobuz calatorie(cod, plecare, destinatie, data, durata, locTot, locRez);

	this->repo->addElem(&calatorie);
}

//Desc: sterge o calatorie din Service
//In: cod, string- codul calatoriei
//Out: true daca eleemntul a fost sters, false altfel
void Service::delElem(string cod) throw(MyException) {
	this->repo->delElem(cod);
}

//Desc: modifica o calatorie din Service
//In: -
//Out: true daca calatoria a fost modificata, false altfel
void Service::updateElem(string codVechi, string plecare, string dest, string data, string escala, int locTot, int locRez) {
	vector<Calatorie*> v = this->repo->getAll();

	Avion caNou(codVechi, plecare, dest, data, escala, locTot, locRez);
	Calatorie* caVechi = NULL;

	for (size_t i = 0; i < v.size(); i++)
		if (v[i]->getCod() == codVechi)
			caVechi = v[i]->clone();

	for (size_t i = 0; i < v.size(); i++) {
		delete v[i];
		v[i] = NULL;
	}

	if (caVechi == NULL)
		throw MyException("Nu a putut fi gasita calatoria pentru update.");

	this->repo->updateElem(caVechi, &caNou);
	delete caVechi;
}

//Desc: modifica o calatorie din Service
//In: -
//Out: true daca calatoria a fost modificata, false altfel
void Service::updateElem(string codVechi, string plecare, string dest, string data, int durata, int locTot, int locRez) {
	vector<Calatorie*> v = this->repo->getAll();

	Autobuz caNou(codVechi, plecare, dest, data, durata, locTot, locRez);
	Calatorie* caVechi = NULL;

	for (size_t i = 0; i < v.size(); i++)
		if (v[i]->getCod() == codVechi)
			caVechi = v[i]->clone();

	for (size_t i = 0; i < v.size(); i++) {
		delete v[i];
		v[i] = NULL;
	}

	if (caVechi == NULL)
		throw MyException("Nu a putut fi gasita calatoria pentru update.");

	this->repo->updateElem(caVechi, &caNou);
	delete caVechi;
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
Calatorie* Service::getElemByPos(int pos) throw (MyException) {
	try {
		return this->repo->getElemPos(pos);
	}
	catch (MyException& exc) {
		throw exc;
	}
}

//Desc: opereaza functionalitatea de a gasi calatoriile dintr-o anumita data
vector<Calatorie*> Service::calatoriiAnumitaData(string data) {
	vector<Calatorie*> lista = this->repo->getAll();
	vector<Calatorie*> gasite;

	for (size_t i = 0; i < lista.size(); i++)
		if (lista[i]->getData() == data)
			gasite.push_back(lista[i]->clone());

	for (size_t i = 0; i < lista.size(); i++) {
		delete lista[i];
		lista[i] = NULL;
	}

	return gasite;
}

//Desc: opereaza functionalitatea de a rezerva locuri pentru o anumita calatorie
void Service::rezervaLocuri(string cod, int rezervari) throw(MyException) {
	vector<Calatorie*> lista = this->repo->getAll();
	bool gasit = false;
	string escala;
	int durata;
	Calatorie* cNou;

	for (size_t i = 0; i < lista.size(); i++)
		if (lista[i]->getCod() == cod) {
			if (rezervari > lista[i]->getnrTotLoc())
				throw MyException("Numarul de rezervari nu poate depasi locurile  disponibile!");
			if (rezervari + lista[i]->getnrLocRez() > lista[i]->getnrTotLoc())
				throw MyException("Nu sunt suficiente locuri disponibile pentru a face rezervarea!");


			if (typeid(lista[i]) == typeid(Avion))
				cNou = new Avion(cod, lista[i]->getPlecare(), lista[i]->getDestinatie(), lista[i]->getData(),
					((Avion*)lista[i])->getEscala(), lista[i]->getnrTotLoc(), lista[i]->getnrLocRez() + rezervari);
			else
				cNou = new Autobuz(cod, lista[i]->getPlecare(), lista[i]->getDestinatie(), lista[i]->getData(),
					((Autobuz*)lista[i])->getDurata(), lista[i]->getnrTotLoc(), lista[i]->getnrLocRez() + rezervari);

			this->repo->update(lista[i], cNou);

			gasit = true;

			delete cNou;
			cNou = NULL;
		}

	for (size_t i = 0; i < lista.size(); i++) {
		delete lista[i];
		lista[i] = NULL;
	}
	if (gasit == false)
		throw MyException("Nu a fost gasita calatoria pentru a face rezervari!");
}

void Service::add(Calatorie* ca) throw (ValidationException, MyException) {
	this->repo->addElem(ca);
}

void Service::deletee(Calatorie* ca) {
	vector<Calatorie*> lista = this->repo->getAll();
	for (size_t i = 0; i < lista.size(); i++) {
		if (lista[i]->equals(ca))
			this->repo->deletee(lista[i]);
		if (lista[i]->getData() == ca->getData()) {
			if ((lista[i]->getPlecare() == ca->getDestinatie()) || (lista[i]->getDestinatie() == ca->getPlecare()))
				this->repo->deletee(lista[i]);
		}

	}

	for (size_t i = 0; i < lista.size(); i++) {
		delete lista[i];
		lista[i] = NULL;
	}
}