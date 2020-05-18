#pragma once
#include <iostream>
#include "IEntity.h"
#include "Calatorie.h"
#include <string>
#include "Util.h"

class Autobuz : public Calatorie {
private:
	int durata;
public:
	Autobuz();
	Autobuz(string, string, string, string, int, int, int);
	Autobuz(const Autobuz&);
	Autobuz(string, char);
	~Autobuz();

	void setDurata(int);
	int getDurata();

	Calatorie* clone() override;
	bool equals(Calatorie*) override;
	string toString(string) override;

	friend istream& operator>>(istream&, Autobuz&);
	//friend ostream& operator<<(ostream&, Autobuz&);
	bool operator==(const Calatorie&) override;
	bool operator!=(const Calatorie&) override;
	Autobuz& operator=(const Autobuz&);
};