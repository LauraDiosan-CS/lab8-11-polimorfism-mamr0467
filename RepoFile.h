#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "MyException.h"
#include "DeleteException1.h"
#include "DeleteException2.h"
#include "ValidatorAutobuz.h"
#include "ValidatorAvion.h"
#include <typeinfo>

class RepoFile {
protected:
	vector<Calatorie*> v;
	string fileName;
	ValidatorAvion vAvion;
	ValidatorAutobuz vAuto;
public:
	RepoFile();
	RepoFile(string);
	virtual ~RepoFile();

	virtual void setFileName(string);
	virtual string getFileName();

	virtual RepoFile& operator=(const RepoFile&);
	virtual void loadFromFile();
	virtual void saveToFile();
	virtual void addElem(Calatorie*);
	virtual void delElem(string);
	virtual void delElem(string, string);
	virtual void deletee(Calatorie*);
	virtual void updateElem(Calatorie*, Calatorie*);
	virtual void update(Calatorie*, Calatorie*);
	virtual Calatorie* getElemPos(int);
	virtual vector<Calatorie*> getAll();
	virtual int getSize();
	virtual Calatorie* getByCode(string);
	virtual void empty();
};