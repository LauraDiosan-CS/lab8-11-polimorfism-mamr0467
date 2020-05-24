#pragma once
#include <iostream>
#include <string>
#include "Util.h"

using namespace std;

class User {
private:
	string cod;
	string nume;
	string email;
	string parola;
public:
	User();
	User(string, string, string, string);
	User(const User&);
	User(string, char);
	~User();

	void setCod(string);
	void setNume(string);
	void setEmail(string);
	void setParola(string);

	string getCod();
	string getNume();
	string getEmail();
	string getParola();

	string toString(string);

	User& operator=(const User&);
	bool operator==(const User&);
	bool operator!=(const User&);

	friend istream& operator>>(istream&, User&);
	friend ostream& operator<<(ostream&, User&);
};