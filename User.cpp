#include "User.h"

User::User() {
	this->cod = "";
	this->nume = "";
	this->email = "";
	this->parola = "";
}

User::User(string cod, string nume, string email, string parola) {
	this->cod = cod;
	this-> nume = nume;
	this->email = email;
	this->parola = parola;
}

User::User(const User& user) {
	this->cod = user.cod;
	this->nume = user.nume;
	this->email = user.email;
	this->parola = user.parola;
}

User::User(string line, char delim) {
	vector<string> words = split(line, delim);
	this->cod = words[0];
	this->nume = words[1];
	this->email = words[2];
	this->parola = words[3];
}

User::~User()
{
}

void User::setCod(string cod) {
	this->cod = cod;
}

void User::setNume(string nume) {
	this->nume = nume;
}

void User::setEmail(string email) {
	this->email = email;
}

void User::setParola(string parola) {
	this->parola = parola;
}

string User::getCod() {
	return this->cod;
}

string User::getNume() {
	return this->nume;
}

string User::getEmail() {
	return this->email;
}

string User::getParola() {
	return this->parola;
}

string User::toString(string delim) {
	string obj = "";
	obj = obj + this->cod + delim + this->nume + delim +
		this->email + delim + this->parola;

	return obj;
}

User& User::operator=(const User& user) {
	if (this != &user) {
		this->cod = user.cod;
		this->nume = user.nume;
		this->email = user.email;
		this->parola = user.parola;
	}

	return *this;
}

bool User::operator==(const User& user) {
	return (this->cod == user.cod && this->nume == user.nume && 
		this->email == user.email && this->parola == user.parola);
}

bool User::operator!=(const User& user) {
	return (this->cod != user.cod || this->nume != user.nume ||
		this->email != user.email || this->parola != user.parola);
}

istream& operator>>(istream& is, User& user) {
	is >> user.cod;
	is >> user.nume;
	is >> user.email;
	is >> user.parola;

	return is;
}

ostream& operator<<(ostream& os, User& user) {
	os << user.cod << " " << user.nume <<
		" " << user.email << " " << user.parola;

	return os;
}