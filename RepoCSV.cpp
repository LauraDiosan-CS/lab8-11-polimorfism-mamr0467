#include "RepoCSV.h"
#include <string>

//Desc: creeaza un obiect nou de tip RepoCSV
//In: -
//Out: un obiect nou de tip RepoFile cu valori implicte
RepoCSV::RepoCSV() {
	this->setFileName("");
	this->loadFromFile();
}

//Desc: creeaza un obiect nou de tip CSV
//In: fileName, string - numele fisierului pentru noul obiect
//Out: un obiect nou de tip RepoCSV cu numele fisiserului dat ca parametru
RepoCSV::RepoCSV(string fileName) {
	this->setFileName(fileName);
	this->loadFromFile();
}

//Desc: distruge un obiect de tip RepoCSV
//In: -
//Out: -
RepoCSV::~RepoCSV()
{
}

//Desc: preia datele din fisierul al carui nume exista ca atribut
//In: -
//Out: -
void RepoCSV::loadFromFile() {
	if (this->fileName != "") {
		char del = ',';

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
void RepoCSV::saveToFile() {
	if (this->fileName != "") {
		ofstream g(this->fileName);
		string del = ",";

		for (size_t i = 0; i < this->v.size(); i++)
			g << this->v[i]->toString(del) << '\n';
	}
}