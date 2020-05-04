#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Avion.h"
#include "Autobuz.h"
#include "Array.h"

class RepoFile {
protected:
	Array arr;
	string fileName;
public:
	RepoFile();
	RepoFile(string);
	virtual ~RepoFile();

	virtual void setFileName(string);
	virtual string getFileName();

	virtual void loadFromFile();
	virtual void saveToFile();
	virtual void addElem(IEntity*);
	virtual bool delElem(IEntity*);
	virtual bool updateElem(IEntity*, IEntity*);
	virtual IEntity* getElemPos(int);
	virtual IEntity** getAll();
	virtual int getSize();
	virtual void empty();
};