#include "RepoUser.h"

RepoUser::RepoUser() {
	this->fileName = "";
}

RepoUser::RepoUser(string fileName) {
	this->fileName = fileName;
	this->loadFromFile();
}

RepoUser::RepoUser(const RepoUser& repo) {
	this->v = repo.v;
	this->fileName = repo.fileName;
}
RepoUser::~RepoUser()
{
}

RepoUser& RepoUser::operator=(const RepoUser& repo) {
	if (this != &repo) {
		this->v = repo.v;
		this->fileName = repo.fileName;
	}

	return *this;
}

void RepoUser::loadFromFile() {
	if (this->fileName != "") {
		char delim = ' ';
		string line = "";
		if (this->fileName.find(".txt") != string::npos)
			delim = ' ';
		else
			delim = ',';

		ifstream f(this->fileName);

		while (getline(f, line)) {
			User user(line, delim);
			v.push_back(user);
		}
	}
}

void RepoUser::saveToFile() {
	if (this->fileName != "") {
		string delim = "";
		if (this->fileName.find(".txt") != string::npos)
			delim = " ";
		else
			delim = ",";

		ofstream g(this->fileName);

		for (size_t i = 0; i < this->v.size(); i++)
			g << v[i].toString(delim) << '\n';
	}
}

void RepoUser::setFileName(string fileName) {
	this->fileName = fileName;
}

string RepoUser::getFileName() {
	return this->fileName;
}

int RepoUser::getSize() {
	return this->v.size();
}

vector<User> RepoUser::getAll() {
	return this->v;
}

void RepoUser::add(User& user) {
	for (int i = 0; i < this->v.size(); i++)
		if (this->v[i].getCod() == user.getCod())
			throw MyException("Codul trebuie sa fie unic!");

	this->v.push_back(user);
	this->saveToFile();
}

void RepoUser::remove(string cod) {
	size_t i = 0;
	while (i < this->v.size() && this->v[i].getCod() != cod)
		i++;

	if (i < this->v.size()) {
		this->v.erase(this->v.begin() + i);
		this->saveToFile();

	}
	else
	{
		throw MyException("Nu a putut fi gasit userul cu codul respectiv.");
	}
}

void RepoUser::update(User& user1, User& user2) {
	size_t i = 0;
	while (i < this->v.size() && user1 != v[i])
		i++;
	if (i < this->v.size()) {
		this->v.erase(this->v.begin() + i);
		this->v.push_back(user2);
		this->saveToFile();
	}
	else
	{
		throw MyException("Nu a putut fi gasita userul pentru update.");
	}
}

User RepoUser::getByPos(int pos) {
	if (pos < 0 || pos >= this->v.size())
		throw MyException("Pozitia este in afara indecsilor admisi!");

	return this->v[pos];
}

void RepoUser::empty() {
	this->v.clear();
	this->saveToFile();
}