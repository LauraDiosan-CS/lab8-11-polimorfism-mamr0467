#include "ServiceUser.h"

ServiceUser::ServiceUser()
{
}

ServiceUser::ServiceUser(RepoUser& repo) {
	this->repo = repo;
}

ServiceUser::~ServiceUser()
{
}

void ServiceUser::setFile(string fileName) {
	this->repo.setFileName(fileName);
}

void ServiceUser::setRepo(const RepoUser& repo) {
	this->repo = repo;
}

void ServiceUser::add(string cod, string nume, string email, string parola) {
	User user(cod, nume, email, parola);
	try {
		this->repo.add(user);
	}
	catch (MyException& exc) {
		throw exc;
	}
}

void ServiceUser::del(string cod) {
	try {
		this->repo.remove(cod);
	}
	catch (MyException& exc) {
		throw exc;
	}
}

void ServiceUser::update(string codVechi, string nume, string email, string parola) {
	vector<User> v = this->repo.getAll();
	bool rez = false;
	User  userVechi;

	for (size_t i = 0; i < v.size(); i++)
		if (v[i].getCod() == codVechi) {
			rez = true;
			userVechi = v[i];
		}

	if (rez == false)
		throw MyException("Nu a putut fi gasit userul pentru update!");

	User userNou(codVechi, nume, email, parola);
	this->repo.update(userVechi, userNou);
}

int ServiceUser::getSize() {
	return this->repo.getSize();
}

vector<User> ServiceUser::getAll() {
	return this->repo.getAll();
}

User ServiceUser::getElemByPos(int pos) {
	try {
		return this->repo.getByPos(pos);
	}
	catch (MyException& exc) {
		throw exc;
	}
}

void ServiceUser::empty() {
	this->repo.empty();
}

bool ServiceUser::verificaUser(string email, string parola) {
	bool rez = false;
	vector<User> v = this->repo.getAll();
	for (size_t i = 0; i < v.size(); i++)
		if (v[i].getEmail() == email && v[i].getParola() == parola)
			rez = true;

	return rez;
}