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
RepoFile::~RepoFile(){
	for(size_t i = 0; i < this->v.size(); i++)
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
		string del = "";
		if (this->fileName.find_first_of(".txt"))
			del = " ";
		else
			del = ",";

		ifstream f(this->fileName);
		string line;

		while (getline(f, line)) {
			string transport = line.substr(0, 2);
			int durata = 0;
			string escala = "";

			size_t pos = line.find(del);
			line.erase(0, pos + 1);

			pos = line.find(del);
			string cod = line.substr(0, pos);
			line.erase(0, pos + 1);

			pos = line.find(del);
			string plecare = line.substr(0, pos);
			line.erase(0, pos + 1);

			pos = line.find(del);
			string destinatie = line.substr(0, pos);
			line.erase(0, pos + 1);

			pos = line.find(del);
			string data = line.substr(0, pos);
			line.erase(0, pos + 1);

			pos = line.find(del);
			if (transport == "AV")
				escala = line.substr(0, pos);
			else
				durata = stoi(line.substr(0, pos));
			line.erase(0, pos + 1);

			pos = line.find(del);
			int locTot = stoi(line.substr(0, pos));
			line.erase(0, pos + 1);

			pos = line.find(del);
			int locRez = stoi(line.substr(0, pos));

			if (transport == "AV") {
				Avion* a = new Avion(cod, plecare, destinatie, data, escala, locTot, locRez);
				this->v.push_back(a->clone());
				delete a;
			}
			else {
				Autobuz* ab = new Autobuz(cod, plecare, destinatie, data, durata, locTot, locRez);
				this->v.push_back(ab->clone());
				delete ab;
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
//In: e, IEntity*, noul element
//Out: -
void RepoFile::addElem(Calatorie* e) {
	for (int i = 0; i < this->v.size(); i++)
		if (this->v[i]->getCod() == e->getCod())
			throw MyException("Codul trebuie sa fie unic!");

	this->v.push_back(e->clone());
	this->saveToFile();
}

//Desc: sterge un element din RepoFile
//In: e, IEntity*, element de sters
//Out: true, daca elementul a fost sters, false altfel
bool RepoFile::delElem(string cod) {

	size_t i = 0;
	while (i < this->v.size() && this->v[i]->getCod() != cod)
		i++;

	if (i < this->v.size()) {
		delete this->v[i];
		this->v[i] = NULL;
		this->v.erase(this->v.begin() + i);
		this->saveToFile();

		return true;
	}

	return false;
}
//Desc: sterge un element din RepoFile
//In: e, IEntity*, element de sters
//Out: true, daca elementul a fost sters, false altfel
bool RepoFile::delElem(string cod, string destinatie) {
	for(size_t i = 0; i < v.size(); i++)
		if (this->v[i]->getCod() == cod) {
			if (this->v[i]->getDestinatie() == destinatie) {
				delete this->v[i];
				this->v[i] = NULL;
				this->v.erase(this->v.begin() + i);
				this->saveToFile();

				return true;
			}
			else {
				throw DeleteException1("");
			}
		}
	throw DeleteException2("");


	/*
	size_t i = 0;
	while (i < this->v.size() && this->v[i]->getCod() != cod)
		i++;
	
	if (i < this->v.size()) {
		delete this->v[i];
		this->v[i] = NULL;
		this->v.erase(this->v.begin() + i);
		this->saveToFile();

		return true;
	}

	return false;*/
}

//Desc: modifica un element din RepoFile
//In: eVechi, IEntity* - elementul de modificat
//	  eNou, IEntity* - elementul cu care este modificat elementul vechi
//Out: true, daca elementul a fost modificat, false altfel
bool RepoFile::updateElem(Calatorie* eVechi, Calatorie* eNou) {
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

		return true;
	}

	return false;
}

//Desc: acceseaza elementul de pe o anumita pozitie din repoFile
//In: pos, int - pozitia elementului
//Out: eleementul de pe positia pos
Calatorie* RepoFile::getElemPos(int pos) {
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