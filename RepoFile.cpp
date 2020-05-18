#include "RepoFile.h"

//Desc: creeaza un obiect nou de tip RepoFile
//In: -
//Out: un obiect nou de tip RepoFile cu valori implicte
RepoFile::RepoFile() {
	this->fileName = "";
	this->loadFromFile();
}

//Desc: creeaza un obiect nou de tip RepoFile
//In: fileName, string - numele fisierului pentru noul obiect
//Out: un obiect nou de tip RepoFile cu numele fisiserului dat ca parametru
RepoFile::RepoFile(string fileName) {
	this->fileName = fileName;
	this->loadFromFile();
}

//Desc: distruge un obiect de tip RepoFile
//In: -
//Out: -
RepoFile::~RepoFile() {
	for (size_t i = 0; i < this->v.size(); i++)
		if (this->v[i]) {
			delete this->v[i];
			this->v[i] = NULL;
		}
}

//Desc: schimba numele fisierului unui RepoFile
//In: fileName, string - n oul nume pentru fisier
//Out: -
void RepoFile::setFileName(string fileName) {
	this->fileName = fileName;
}

//Desc: acceseaza numele fisierului unui RepoFile
//In: -
//Out: numele fisierului
string RepoFile::getFileName() {
	return this->fileName;
}

//Desc: preia datele din fisierul al carui nume exista ca atribut
//In: -
//Out: -
void RepoFile::loadFromFile() {
	if (this->fileName != "") {
		char del = ' ';
		if (this->fileName.find(".txt"))
			del = ' ';
		else
			del = ',';

		ifstream f(this->fileName);
		string line;

		while (getline(f, line)) {
			if (line.substr(0, 2) == "AU") {
				Autobuz au(line, del);
				this->v.push_back(au.clone());
			}
			else {
				Avion av(line, del);
				this->v.push_back(av.clone());
			}
		}
	}
}

//Desc: salveaza  datele in fisierul al carui nume este retinut ca atribut
//In: -
//Out: datele din arr
void RepoFile::saveToFile() {
	if (this->fileName != "") {
		ofstream g(this->fileName);
		string del = "";

		if (this->fileName.find(".txt") != string::npos)
			del = " ";
		else
			del = ",";

		for (size_t i = 0; i < v.size(); i++)
			g << this->v[i]->toString(del);
	}
}

//Desc: adauga un nou element in RepoFile
//In: c, Calatorie*, noul element
//Out: -
void RepoFile::addElem(Calatorie* c) throw(ValidationException, MyException) {
	if (typeid(*c) == typeid(Avion)) {
		vAvion.validate(c);
	}
	else if (typeid(*c) == typeid(Autobuz)) {
		vAuto.validate(c);
	}

	//for (int i = 0; i < this->v.size(); i++)
		//if (this->v[i]->getCod() == c->getCod())
			//throw MyException("Codul trebuie sa fie unic!");

	this->v.push_back(c->clone());
	this->saveToFile();
}

//Desc: sterge un element din RepoFile
//In: e, Calatorie*, element de sters
//Out: true, daca elementul a fost sters, false altfel
void RepoFile::delElem(string cod) throw(MyException) {

	size_t i = 0;
	while (i < this->v.size() && this->v[i]->getCod() != cod)
		i++;

	if (i < this->v.size()) {
		delete this->v[i];
		this->v[i] = NULL;
		this->v.erase(this->v.begin() + i);
		this->saveToFile();

	}
	else
	{
		throw MyException("Nu a putut fi gasit calatoria cu codul respectiv.");
	}

}
//Desc: sterge un element din RepoFile
//In: e, Calatorie*, element de sters
//Out: true, daca elementul a fost sters, false altfel
void RepoFile::delElem(string cod, string destinatie) {
	bool rez = false;

	size_t i = 0;
	while (i < this->v.size() && this->v[i]->getCod() != cod)
		i++;
	if (i < this->v.size()) {
		if (v[i]->getDestinatie() == destinatie) {
			delete this->v[i];
			this->v[i] = NULL;
			this->v.erase(this->v.begin() + i);
			this->saveToFile();
		}
		else
			throw DeleteException1("");
	}
	else
	{
		throw DeleteException2("");
	}

	/*
	for (size_t i = 0; i < v.size(); i++) {
		if (this->v[i]->getCod() == cod) {
			if (this->v[i]->getDestinatie() == destinatie) {
				delete this->v[i];
				this->v[i] = NULL;
				this->v.erase(this->v.begin() + i);

				rez = true;
				this->saveToFile();
			}
			else {
				throw DeleteException1("");
			}
		}
		if (this->v[i]->getDestinatie() == destinatie)
			rez = true;
	}

	if(rez == false)
		throw DeleteException2("");*/
}

//Desc: modifica un element din RepoFile
//In: eVechi, Calatorie* - elementul de modificat
//	  eNou, Calatorie* - elementul cu care este modificat elementul vechi
//Out: true, daca elementul a fost modificat, false altfel
void RepoFile::updateElem(Calatorie* eVechi, Calatorie* eNou) throw(ValidationException, MyException) {
	if (typeid(*eNou) == typeid(Avion)) {
		vAvion.validate(eNou);
	}
	else if (typeid(*eNou) == typeid(Autobuz)) {
		vAuto.validate(eNou);
	}

	size_t i = 0;
	while (i < this->v.size() && *(this->v[i]) != *eVechi)
		i++;
	if (i < this->v.size()) {
		if (this->v[i]) {
			delete this->v[i];
			this->v[i] = NULL;
		}

		this->v.erase(this->v.begin() + i);
		this->v.push_back(eNou->clone());
		this->saveToFile();
	}
	else
	{
		throw MyException("Nu a putut fi gasita calatoria pentru update.");
	}
}

void RepoFile::update(Calatorie* eVechi, Calatorie* eNou) throw(ValidationException, MyException) {
	if (typeid(*eNou) == typeid(Avion)) {
		vAvion.validate(eNou);
	}
	else if (typeid(*eNou) == typeid(Autobuz)) {
		vAuto.validate(eNou);
	}

	size_t i = 0;
	while (i < this->v.size() && *(this->v[i]) != *eVechi)
		i++;
	if (i < this->v.size()) {
		if (this->v[i]) {
			delete this->v[i];
			this->v[i] = NULL;
		}

		this->v[i] = eNou->clone();
		this->saveToFile();
	}
	else
	{
		throw MyException("Nu a putut fi gasita calatoria pentru update.");
	}
}

//Desc: acceseaza elementul de pe o anumita pozitie din repoFile
//In: pos, int - pozitia elementului
//Out: elementul de pe positia pos
Calatorie* RepoFile::getElemPos(int pos) throw(MyException) {
	if (pos < 0 || pos >= this->v.size())
		throw MyException("Pozitia este in afara indecsilor admisi!");

	return this->v[pos]->clone();
}

//Desc: acceseaza lista de elemente din RepoFile
//In: -
//Out: lista de elemente
vector<Calatorie*> RepoFile::getAll() {
	vector<Calatorie*> vNou;
	for (size_t i = 0; i < this->v.size(); i++)
		vNou.push_back(this->v[i]->clone());

	return vNou;
}

//Desc: sterge toate elementele din RepoFile
//In: -
//Out: -
void RepoFile::empty() {
	for (size_t i = 0; i < this->v.size(); i++)
		if (this->v[i]) {
			delete this->v[i];
			this->v[i] = NULL;
		}
	v.clear();
	this->saveToFile();
}

//Desc: acceseaza o calatorie dupa codul sau
//In: cod, string - codul calatoriei
//Out: calatorie cu codul dat
Calatorie* RepoFile::getByCode(string cod) {
	for (int i = 0; i < this->v.size(); i++)
		if (v[i]->getCod() == cod)
			return v[i]->clone();

	return new Calatorie();
}

//Desc: acceseaza lungimea listei de eleemnte din RepoFile
//In: -
//Out: lungimea listei de elemente
int RepoFile::getSize() {
	return this->v.size();
}

RepoFile& RepoFile::operator=(const RepoFile& repo) {
	this->fileName = repo.fileName;

	return *this;
}

void RepoFile::deletee(Calatorie* ca) {
	for(size_t i = 0; i < this->v.size(); i++)
		if (this->v[i]->equals(ca)) {
			delete this->v[i];
			this->v[i] = NULL;
			this->v.erase(this->v.begin() + i);

			return;
		}
}