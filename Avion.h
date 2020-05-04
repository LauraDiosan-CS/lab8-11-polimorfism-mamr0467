#pragma once
#include <iostream>
#include <string>
#include "IEntity.h"

using namespace std;
class Avion : public IEntity {
private:
	string cod;
	string plecare;
	string destinatie;
	string data;
	string escala;
	int nrTotLoc;
	int nrLocRez;
public:
	Avion();
	Avion(string, string, string, string, string, int, int);
	Avion(const Avion& a);
	~Avion();

	void setCod(string);
	void setPlecare(string);
	void setDestinatie(string);
	void setData(string);
	void setEscala(string);
	void setnrLocuriTotale(int);
	void setnrLocuriRez(int);
	string getCod();
	string getPlecare();
	string getDestinatie();
	string getData();
	string getEscala();
	int getnrLocuriTotale();
	int getnrLocuriRez();

	IEntity* clone();
	bool equals(IEntity*);
	string toString(string);

	friend istream& operator>>(istream&, Avion&);
	//friend ostream& operator<<(ostream&, Avion&);
	bool operator==(const Avion&);
	Avion& operator=(const Avion&);
};