#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "Avion.h"
#include "Autobuz.h"
#include "Array.h"
#include "RepoFile.h"

class RepoTXT: public RepoFile{
public:
	RepoTXT();
	RepoTXT(string);
	~RepoTXT();

	void loadFromFile() override;
	void saveToFile() override;
};