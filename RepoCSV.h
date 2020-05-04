#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Avion.h"
#include "Autobuz.h"
#include "Array.h"
#include "RepoFile.h"

class RepoCSV : public RepoFile {
private:
	//Array arr;
	//string fileName;
public:
	RepoCSV();
	RepoCSV(string);
	~RepoCSV();

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
