#pragma once
#include <iostream>
#include "IEntity.h"
#include <string>

class Autobuz : public IEntity {
private:
	string cod;
	string plecare;
	string destinatie;
	string data;
	int durata;
	int nrTotLoc;
	int nrLocRez;
public:
	Autobuz();
	Autobuz(string, string, string, string, int, int, int);
	Autobuz(const Autobuz&);
	~Autobuz();

	void setCod(string);
	void setPlecare(string);
	void setDestinatie(string);
	void setData(string);
	void setDurata(int);
	void setnrLocuriTotale(int);
	void setnrLocuriRez(int);
	string getCod();
	string getPlecare();
	string getDestinatie();
	string getData();
	int getDurata();
	int getnrLocuriTotale();
	int getnrLocuriRez();

	IEntity* clone();
	bool equals(IEntity*);
	string toString(string);

	friend istream& operator>>(istream&, Autobuz&);
	//friend ostream& operator<<(ostream&, Autobuz&);
	bool operator==(const Autobuz&);
	Autobuz& operator=(const Autobuz&);
};