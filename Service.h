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
	bool delElem(string);
	bool updateElem(string, string, string, string, string, int, int);
	bool updateElem(string, string, string, string, int, int, int);
	int getSize();
	Calatorie* getElemByPos(int);
	vector<Calatorie*> getAll();

	void empty();
};