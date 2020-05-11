#include "TestService.h"

void TestService::testAll() {
	this->testSetteriSiGetteri();
	this->testAdd();
	this->testDelete();
	this->testUpdate();
}

void TestService::testSetteriSiGetteri() {
	RepoFile *repo = new RepoCSV();
	Service s(repo);
	
	try {
		assert(s.getSize() == 0);
		s.addElem("5", "cluj", "ferentari", "22.11.2020", "da", 134, 122);
		assert(s.getSize() == 1);
		Calatorie* c = s.getElemByPos(0);
		assert(c->getCod() == "5");

		delete c;
	}
	catch (MyException& exc) {
		cout << exc.getMessage() << '\n';
	}
}

void TestService::testAdd() {
	RepoFile* repo = new RepoCSV();
	Service s(repo);
	try{
		assert(s.getSize() == 0);
		s.addElem("5", "cluj", "ferentari", "22.11.2020", "da", 134, 122);
		s.addElem("4", "cluj", "ferentari", "22.11.2020", "da", 134, 122);
		assert(s.getSize() == 2);
	}
	catch (MyException& exc){
		cout << exc.getMessage() << '\n';
	}
}

void TestService::testDelete() {
	RepoFile* repo = new RepoCSV();
	Service s(repo);
	try {
		s.addElem("5", "cluj", "ferentari", "22.11.2020", "da", 134, 122);
		assert(s.getSize() == 1);
		s.delElem("5");
		assert(s.getSize() == 0);
	}
	catch (MyException& exc) {
		cout << exc.getMessage() << '\n';
	}
}

void TestService::testUpdate() {
	RepoFile* repo = new RepoCSV();
	Service s(repo);
	try {
		assert(s.getSize() == 0);
		s.addElem("5", "cluj", "ferentari", "22.11.2020", "da", 134, 122);
		assert(s.getSize() == 1);
		s.updateElem("5", "mangalia", "ferentari", "22.11.2020", "da", 134, 122);

		Calatorie* c = s.getElemByPos(0);
		assert(c->getPlecare() == "mangalia");

		delete c;
	}
	catch (MyException& exc) {
		cout << exc.getMessage() << '\n';
	}
}