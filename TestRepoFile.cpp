#include "TestRepoFile.h"

void TestRepoFile::testAll() {
	this->testAdd();
	this->testDel();
	this->testUpdate();
	this->testGet();
	this->testCerinta();
	this->cerintaExceptii();
}

//Desc: testeaza functia de a adauga elemente in RepoFile
void TestRepoFile::testAdd() {
	RepoFile r("Test.csv");
	Avion a("1", "cluj", "ferentari", "23", "da", 13, 11);
	
	assert(r.getSize() == 0);
	try {
		r.addElem(&a);
		assert(r.getSize() == 1);
	}
	catch (MyException &exc) {
		cout << exc.getMessage() << '\n';
	}
	r.empty();
}

//Desc: testeaza functia de a sterge elemente din RepoFile
void TestRepoFile::testDel() {
	RepoFile r("Test.csv");
	Avion a("1", "cluj", "ferentari", "23", "da", 13, 11);
	try {
		r.addElem(&a);
		assert(r.getSize() == 1);
		r.delElem("1", "ferentari");
		assert(r.getSize() == 0);
	}
	catch (MyException& exc) {
		cout << exc.getMessage() << '\n';
	}
	r.empty();
}

//Desc: testeaza functia de a modifica eleemnte din RepoFile
void TestRepoFile::testUpdate() {
	RepoFile r("Test.txt");
	Avion a("1", "cluj", "ferentari", "23", "da", 13, 11);
	Avion a2("2", "mangalia", "cluj", "1", "nu", 133, 75);
	try {
		r.addElem(&a);
		r.updateElem(&a, &a2);
		assert(r.getElemPos(0)->equals(&a2));
	}
	catch (MyException& exc) {
		cout << exc.getMessage() << '\n';
	}
	r.empty();
}

//Desc: testeaza getterii clasei RepoFile
void TestRepoFile::testGet() {
	RepoFile r("Test.txt");
	Avion a("1", "cluj", "ferentari", "23", "da", 13, 11);
	try {
		r.addElem(&a);
		int size = r.getSize();
		Avion* pa = (Avion*)r.getElemPos(0);
		assert(size == 1 && pa->equals(&a));

		delete pa;
	}
	catch (MyException& exc) {
		cout << exc.getMessage() << '\n';
	}

	r.empty();
}

//Desc: testeaza asserturile cerintei din 05.04.2020
void TestRepoFile::testCerinta() {
	RepoFile *repo = new RepoCSV("fisier-111-2.csv");
	Calatorie* c1 = new Avion("1x54", "Cluj-Napoca", "Dubai", "14.06.2020", "false", 100, 80);
	Calatorie* c2 = new Autobuz("39g0", "Constanta", "Brasov", "15.07.2020", 1, 40, 20);
	Calatorie* c3 = new Autobuz("41kl", "Bucuresti", "Vienna", "11.06.2020", 3, 80, 50);


	assert(repo->getSize() == 3);
	assert(*(repo->getElemPos(0)) == *c1);
	assert(*(repo->getElemPos(1)) == *c2);
	assert(*(repo->getElemPos(2)) == *c3);

	Calatorie* c4 = new Avion("h6pd", "Iasi", "Munchen", "20.09.2020", "true", 50, 10);
	repo->updateElem(c2, c4);
	assert(*(repo->getElemPos(0)) == *c1);
	assert(*(repo->getElemPos(1)) == *c3);
	
	repo->empty();

	repo->addElem(c1);
	repo->addElem(c2);
	repo->addElem(c3);

	delete c1;
	delete c2;
	delete c3;
	delete c4;
}
/*
AV,1x54,Cluj-Napoca,Dubai,14.06.2020,false,100,80
AU,39g0,Constanta,Brasov,15.07.2020,1,40,20
AU,41kl,Bucuresti,Vienna,11.06.2020,3,80,50
*/


//Desc: testele din data de 11.05.2020
void TestRepoFile::cerintaExceptii() {
	RepoFile repo;
	Avion c1("156", "Cluj - Napoca", "Dubai", "14.06.2020", "false", 100, 80);
	Autobuz c2("873", "Constanta", "Brasov", "15.07.2020", 1, 40, 20);
	Autobuz c3("118", "Bucuresti", "Vienna", "11.06.2020", 3, 80, 50);

	repo.addElem(&c1);
	repo.addElem(&c2);
	repo.addElem(&c3);

	try {
		repo.delElem("873", "Brasov");
		assert(repo.getSize() == 2);
		assert(repo.getElemPos(0)->equals(&c1));
		assert(repo.getElemPos(1)->equals(&c3));
	}
	catch (DeleteException1& exc1) {
		assert(false);
	}
	catch (DeleteException2& exc2) {
		assert(false);
	}

	try {
		repo.delElem("156", "Paris");
		assert(false);
	}
	catch (DeleteException1& exc1) {
		cout << "DeleteException1 thrown" << '\n';
		assert(repo.getSize() == 2);
		assert(repo.getElemPos(0)->equals(&c1));
		assert(repo.getElemPos(1)->equals(&c3));
	}
	catch (DeleteException2& exc2) {
		assert(false);
	}

	try {
		repo.delElem("667", "Fagaras");
		assert(false);
	}
	catch (DeleteException2& exc2) {
		cout << "DeleteException2 thrown" << '\n';
	}
	catch (DeleteException1& exc1) {
		assert(false);
	}


	
	try {
		repo.delElem("156", "Paris");
		assert(false);
	}
	catch (DeleteException2& exc2) {
		cout << "DeleteException2 thrown" << '\n';
	}
	catch (DeleteException1& exc1) {
		assert(false);
	}



	try {
		repo.delElem("667", "Fagaras");
		assert(false);
	}
	catch (DeleteException2& exc2) {
		cout << "DeleteException2 thrown";
	}
	catch (DeleteException1& exc1) {
		assert(false);
	}

}