#pragma once
#include <iostream>
#include <string>
using namespace std;

class Calatorie {
protected:
	string cod;
	string plecare;
	string destinatie;
	string data;
	int nrTotLoc;
	int nrLocRez;
public:
	Calatorie();
	Calatorie(string, string, string, string, int, int);
	Calatorie(const Calatorie&);
	~Calatorie();

	void setCod(string);
	void setPlecare(string);
	void setDestinatie(string);
	void setData(string);
	void setnrTotLoc(int);
	void setnrLocRez(int);

	string getCod();
	string getPlecare();
	string getDestinatie();
	string getData();
	int getnrTotLoc();
	int getnrLocRez();

	virtual string toString(string);
	virtual Calatorie* clone();
	virtual bool equals(Calatorie*);
	friend istream& operator>>(istream&, Calatorie&);
	friend ostream& operator<<(ostream&, const Calatorie&);
	virtual bool operator==(const Calatorie&);
	virtual bool operator!=(const Calatorie&);
};