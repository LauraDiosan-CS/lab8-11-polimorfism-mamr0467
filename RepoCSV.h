#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Avion.h"
#include "Autobuz.h"
#include "Array.h"
#include "RepoFile.h"

class RepoCSV : public RepoFile {
public:
	RepoCSV();
	RepoCSV(string);
	~RepoCSV();

	void loadFromFile() override;
	void saveToFile() override;
};
