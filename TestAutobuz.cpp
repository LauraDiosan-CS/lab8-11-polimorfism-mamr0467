#include "TestAutobuz.h"

void TestAutobuz::testAll() {
	this->testConstructori();
	this->testSetteriSiGetteri();
	this->testOperatorEgal();
	this->testOperatorEgalitate();
	this->testClone();
	this->testEquals();
	this->testToString();
}

//Desc: testeaza constructorii clasei Autobuz
void TestAutobuz::testConstructori() {
	Autobuz a1;
	assert(a1.getCod() == "" && a1.getPlecare() == "" && a1.getDestinatie() == "" &&
		a1.getData() == "" && a1.getDurata() == 0 && a1.getnrTotLoc() == 0 &&
		a1.getnrLocRez() == 0);
	Autobuz a2("5", "cluj", "ferentari", "19", 15, 120, 120);
	assert(a2.getCod() == "5" && a2.getPlecare() == "cluj" && a2.getDestinatie() == "ferentari" &&
		a2.getData() == "19" && a2.getDurata() == 15 && a2.getnrTotLoc() == 120 &&
		a2.getnrLocRez() == 120);
	Autobuz a3(a2);
	assert(a3.getCod() == "5" && a3.getPlecare() == "cluj" && a3.getDestinatie() == "ferentari" &&
		a3.getData() == "19" && a3.getDurata() == 15 && a3.getnrTotLoc() == 120 &&
		a3.getnrLocRez() == 120);

	Autobuz* pa1 = new Autobuz();
	assert(pa1->getCod() == "" && pa1->getPlecare() == "" && pa1->getDestinatie() == "" &&
		pa1->getData() == "" && pa1->getDurata() == 0 && pa1->getnrTotLoc() == 0 &&
		pa1->getnrLocRez() == 0);
	Autobuz* pa2 = new Autobuz("7", "mangalia", "timisoara", "23", 111, 45, 36);
	assert(pa2->getCod() == "7" && pa2->getPlecare() == "mangalia" && pa2->getDestinatie() == "timisoara" &&
		pa2->getData() == "23" && pa2->getDurata() == 111 && pa2->getnrTotLoc() == 45 &&
		pa2->getnrLocRez() == 36);
	Autobuz* pa3 = new Autobuz(*pa2);
	assert(pa3->getCod() == "7" && pa3->getPlecare() == "mangalia" && pa3->getDestinatie() == "timisoara" &&
		pa3->getData() == "23" && pa3->getDurata() == 111 && pa3->getnrTotLoc() == 45 &&
		pa3->getnrLocRez() == 36);
}

//Desc: testeaza setterii si getteri clasei Autobuz
void TestAutobuz::testSetteriSiGetteri() {
	Autobuz a("5", "cluj", "ferentari", "19", 8, 120, 120);
	assert(a.getCod() == "5" && a.getPlecare() == "cluj" && a.getDestinatie() == "ferentari" &&
		a.getData() == "19" && a.getDurata() == 8 && a.getnrTotLoc() == 120 &&
		a.getnrLocRez() == 120);

	a.setCod("10");
	a.setPlecare("mangalia");
	a.setDestinatie("timisoara");
	a.setData("23");
	a.setDurata(18);
	a.setnrTotLoc(45);
	a.setnrLocRez(36);

	assert(a.getCod() == "10" && a.getPlecare() == "mangalia" && a.getDestinatie() == "timisoara" &&
		a.getData() == "23" && a.getDurata() == 18 && a.getnrTotLoc() == 45 &&
		a.getnrLocRez() == 36);
}

//Desc: testeaza operatorul egal pentru clasa Autobuz
void TestAutobuz::testOperatorEgal() {
	Autobuz a;
	Autobuz a2("5", "cluj", "ferentari", "19", 31, 120, 120);
	assert(a.getCod() == "" && a.getPlecare() == "" && a.getDestinatie() == "" &&
		a.getData() == "" && a.getDurata() == 0 && a.getnrTotLoc() == 0 &&
		a.getnrLocRez() == 0);

	a = a2;
	assert(a.getCod() == "5" && a.getPlecare() == "cluj" && a.getDestinatie() == "ferentari" &&
		a.getData() == "19" && a.getDurata() == 31 && a.getnrTotLoc() == 120 &&
		a.getnrLocRez() == 120);
}

//Desc: testeaza operatorul de egalitate pentru clasa Autobuz
void TestAutobuz::testOperatorEgalitate() {
	Autobuz a1("5", "cluj", "ferentari", "19", 42, 120, 120);
	Autobuz a2("7", "mangalia", "timisoara", "23", 42, 45, 36);

	assert((a1 == a2) == false);
}

//Desc: testeaza functia clone a clasei Autobuz
void TestAutobuz::testClone() {
	Autobuz a("5", "cluj", "ferentari", "19", 6, 120, 120);
	Autobuz* e = (Autobuz*)a.clone();

	assert(e->getCod() == "5" && e->getPlecare() == "cluj" && e->getDestinatie() == "ferentari" &&
		e->getData() == "19" && e->getDurata() == 6 && e->getnrTotLoc() == 120 &&
		e->getnrLocRez() == 120);
}

//Desc: testeaza functia equals a clasei Autobuz
void TestAutobuz::testEquals() {
	Autobuz* pa1 = new Autobuz("5", "cluj", "ferentari", "19", 75, 120, 120);
	Autobuz* pa2 = new Autobuz("5", "cluj", "ferentari", "19", 75, 120, 120);

	assert(pa1->equals(pa2) == true);
}

//Desc: testeaza functia toString a clasei Autobuz
void TestAutobuz::testToString() {
	Autobuz a("5", "cluj", "ferentari", "19", 23, 120, 120);
	string s = a.toString(",");

	assert(s == "AU,5,cluj,ferentari,19,23,120,120");
}