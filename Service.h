#pragma once
#include "RepoTXT.h"
#include "RepoCSV.h"
#include <typeinfo>
#include <string.h>
#include <string>

using namespace std;

class Service {
private:
	RepoFile* repo;
public:
	Service();
	Service(RepoFile*);
	~Service();

	void setFile(string);
	void SetRepo(RepoFile*);
	void addElem(string, string, string, string, string, int, int);
	void addElem(string, string, string, string, int, int, int);
	void add(Calatorie*);
	void delElem(string);
	void updateElem(string, string, string, string, string, int, int);
	void updateElem(string, string, string, string, int, int, int);
	void deletee(Calatorie*);
	int getSize();
	Calatorie* getElemByPos(int);
	vector<Calatorie*> getAll();

	void empty();

	vector<Calatorie*> calatoriiAnumitaData(string);
	void rezervaLocuri(string, int);
};