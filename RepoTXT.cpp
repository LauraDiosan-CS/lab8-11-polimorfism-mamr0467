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
	if (this->fileName!= "") {
		string del = " ";

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
void RepoTXT::saveToFile() {
	if (this->fileName != "") {
		ofstream g(this->fileName);
		string del = " ";

		for (size_t i = 0; i < this->v.size(); i++)
			g << this->v[i]->toString(del);
	}
}