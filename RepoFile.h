#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Avion.h"
#include "Autobuz.h"
#include "Array.h"
#include <vector>
#include "Avion.h"
#include "Autobuz.h"
#include "MyException.h"
#include "DeleteException1.h"
#include "DeleteException2.h"

class RepoFile {
protected:
	vector<Calatorie*> v;
	string fileName;
public:
	RepoFile();
	RepoFile(string);
	virtual ~RepoFile();

	virtual void setFileName(string);
	virtual string getFileName();

	virtual void loadFromFile();
	virtual void saveToFile();
	virtual void addElem(Calatorie*);
	virtual bool delElem(string);
	virtual bool delElem(string, string);
	virtual bool updateElem(Calatorie*, Calatorie*);
	virtual Calatorie* getElemPos(int);
	virtual vector<Calatorie*> getAll();
	virtual int getSize();
	virtual Calatorie* getByCode(string);
	virtual void empty();
};