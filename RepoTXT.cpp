#include "RepoTXT.h"

//Desc: creeaza un obiect nou de tip RepoTXT
//In: -
//Out: un obiect nou de tip RepoTXT cu valori implicte
RepoTXT::RepoTXT() {
	this->setFileName("");
	this->loadFromFile();
}

//Desc: creeaza un obiect nou de tip RepoTXT
//In: fileName, string - numele fisierului pentru noul obiect
//Out: un obiect nou de tip RepoTXT cu numele fisiserului dat ca parametru
RepoTXT::RepoTXT(string fileName) {
	this->setFileName(fileName);
	this->loadFromFile();
}

//Desc: distruge un obiect de tip RepoTXT
//In: -
//Out: -
RepoTXT::~RepoTXT()
{
}

//Desc: preia datele din fisierul al carui nume exista ca atribut
//In: -
//Out: -
void RepoTXT::loadFromFile() {
	if (this->fileName != "") {
		char del = ' ';

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
void RepoTXT::saveToFile() {
	if (this->fileName != "") {
		ofstream g(this->fileName);
		string del = " ";

		for (size_t i = 0; i < this->v.size(); i++)
			g << this->v[i]->toString(del) << '\n';
	}
}