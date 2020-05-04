#include "RepoFile.h"

//Desc: creeaza un obiect nou de tip RepoFile
//In: -
//Out: un obiect nou de tip RepoFile cu valori implicte
RepoFile::RepoFile() {
	this->fileName = "";
}

//Desc: creeaza un obiect nou de tip RepoFile
//In: fileName, string - numele fisierului pentru noul obiect
//Out: un obiect nou de tip RepoFile cu numele fisiserului dat ca parametru
RepoFile::RepoFile(string fileName) {
	this->fileName = fileName;
}

//Desc: distruge un obiect de tip RepoFile
//In: -
//Out: -
RepoFile::~RepoFile()
{
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
				arr.addElem(a);
				delete a;
			}
			else {
				Autobuz* ab = new Autobuz(cod, plecare, destinatie, data, durata, locTot, locRez);
				arr.addElem(ab);
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

		for (int i = 0; i < this->arr.getSize(); i++)
			g << this->arr.getElemPos(i)->toString(del);
	}
}

//Desc: adauga un nou element in RepoFile
//In: e, IEntity*, noul element
//Out: -
void RepoFile::addElem(IEntity* e) {
	this->arr.addElem(e);
	this->saveToFile();
}

//Desc: sterge un element din RepoFile
//In: e, IEntity*, element de sters
//Out: true, daca elementul a fost sters, false altfel
bool RepoFile::delElem(IEntity* e) {
	int size = this->arr.getSize();
	this->arr.removeElem(e);
	if (size != this->arr.getSize()) {
		this->saveToFile();
		return true;
	}

	return false;
}

//Desc: modifica un element din RepoFile
//In: eVechi, IEntity* - elementul de modificat
//	  eNou, IEntity* - elementul cu care este modificat elementul vechi
//Out: true, daca elementul a fost modificat, false altfel
bool RepoFile::updateElem(IEntity* eVechi, IEntity* eNou) {
	int i = 0;
	while (i < this->arr.getSize()) {
		if (eVechi->equals(arr.getElemPos(i)) == true) {
			//IIterator* it = this->arr.getIterator();
			//while (it->getCrtElem()->equals(eVechi) == false)
				//it->moveNext();
			//IEntity* e = it->getCrtElem();
			//e = eNou;
			this->arr.removeElem(eVechi);
			this->arr.addElem(eNou);
			this->saveToFile();
			return true;
		}
		else
			i++;
	}

	return false;
}

//Desc: acceseaza elementul de pe o anumita pozitie din repoFile
//In: pos, int - pozitia elementului
//Out: eleementul de pe positia pos
IEntity* RepoFile::getElemPos(int pos) {
	return this->arr.getElemPos(pos);
}

//Desc: acceseaza lista de elemente din RepoFile
//In: -
//Out: lista de elemente
IEntity** RepoFile::getAll() {
	IEntity** lista = new IEntity * [this->arr.getSize()];
	for (int i = 0; i < this->arr.getSize(); i++)
		lista[i] = this->arr.getElemPos(i);

	return lista;
}

//Desc: sterge toate elementele din RepoFile
//In: -
//Out: -
void RepoFile::empty() {
	this->arr.empty();
	this->saveToFile();
}

//Desc: acceseaza lungimea listei de eleemnte din RepoFile
//In: -
//Out: lungimea listei de elemente
int RepoFile::getSize() {
	return this->arr.getSize();
}