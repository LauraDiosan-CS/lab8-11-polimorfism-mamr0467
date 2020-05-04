#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "Avion.h"
#include "Autobuz.h"
#include "Array.h"
#include "RepoFile.h"

class RepoTXT: public RepoFile{
private:
	//Array arr;
	//string fileName;
public:
	RepoTXT();
	RepoTXT(string);
	~RepoTXT();

	//void setFileName(string);
	//string getFileName();

	void loadFromFile() override;
	void saveToFile() override;
	//void addElem(IEntity*);
	//bool delElem(IEntity*);
	//bool updateElem(IEntity*, IEntity*);
	//IEntity* getElemPos(int);
	//IEntity** getAll();
	//int getSize();
	//void empty();
};