#pragma once
#include <iostream>
#include <string>
#include "IEntity.h"
#include "Calatorie.h"
#include "Util.h"

using namespace std;
class Avion : public Calatorie {
private:
	string escala;
public:
	Avion();
	Avion(string, string, string, string, string, int, int);
	Avion(const Avion& a);
	Avion(string, char);
	~Avion();

	void setEscala(string);
	string getEscala();

	Calatorie* clone() override;
	bool equals(Calatorie*) override;
	string toString(string) override;

	friend istream& operator>>(istream&, Avion&);
	friend ostream& operator<<(ostream&, Avion&);
	bool operator==(const Calatorie&) override;
	bool operator!=(const Calatorie&) override;
	Avion& operator=(const Avion&);
};