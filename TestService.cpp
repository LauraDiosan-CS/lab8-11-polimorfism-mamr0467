#include "TestService.h"

//Desc: gestioneaza functiile de test pentru clasa Service
void TestService::testAll() {
	this->testSetteriSiGetteri();
	this->testAdd();
	this->testDelete();
	this->testUpdate();
	this->testRezervaLocuri();
	this->testCalatoriiAnumitaData();
}

//Desc: testeaza setterii si getterii clasei Service
void TestService::testSetteriSiGetteri() {
	RepoFile* repo = new RepoCSV();
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

//Desc: testeaza functia de adaugare a clasei Service
void TestService::testAdd() {
	RepoFile* repo = new RepoCSV();
	Service s(repo);
	try {
		assert(s.getSize() == 0);
		s.addElem("5", "cluj", "ferentari", "22.11.2020", "da", 134, 122);
		s.addElem("4", "cluj", "ferentari", "22.11.2020", "da", 134, 122);
		assert(s.getSize() == 2);
	}
	catch (MyException& exc) {
		cout << exc.getMessage() << '\n';
	}
}

//Desc: testeaza functia de stergere a clasei Service
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

//Desc: testeaza functia de update a clasei Service
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

//Desc: testeaza functionalitatea de a rezerva locuri
void TestService::testRezervaLocuri() {
	RepoFile* repo = new RepoCSV();
	Service s(repo);

	s.addElem("5", "cluj", "ferentari", "22.11.2020", "da", 134, 122);
	s.addElem("1x", "brasov", "mangalia", "10.05.2032", "nu", 123, 34);
	s.addElem("4b", "italia", "romania", "06.06.2020", 10, 40, 13);

	try {
		s.rezervaLocuri("5", 5);
		s.rezervaLocuri("1x", 40);

		assert(s.getElemByPos(0)->getnrLocRez() == 127);
		assert(s.getElemByPos(1)->getnrLocRez() == 74);
	}
	catch (MyException& exc) {
		cout << exc.what() << '\n';
	}
}

//Desc: testeaza functionalitatea de a afisa calatoriile dintr-o anumita data din Service
void TestService::testCalatoriiAnumitaData() {
	RepoFile* repo = new RepoCSV();
	Service s(repo);

	s.addElem("5", "cluj", "ferentari", "22.11.2020", "da", 134, 122);
	s.addElem("1x", "brasov", "mangalia", "22.11.2020", "nu", 123, 34);
	s.addElem("4b", "italia", "romania", "06.06.2020", 10, 40, 13);

	try {
		s.calatoriiAnumitaData("22.11.2020").size() == 2;
	}
	catch (MyException& exc) {
		cout << exc.what() << '\n';
	}
}