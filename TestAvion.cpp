#include "TestAvion.h"

void TestAvion::testAll() {
	this->testConstructori();
	this->testSetteriSiGetteri();
	this->testOperatorEgal();
	this->testOperatorEgalitate();
	this->testClone();
	this->testEquals();
	this->testToString();
}

//Desc: testeaza constructorii clasei Avion
void TestAvion::testConstructori() {
	Avion a1;
	assert(a1.getCod() == "" && a1.getPlecare() == "" && a1.getDestinatie() == "" &&
		a1.getData() == "" && a1.getEscala() == "" && a1.getnrTotLoc() == 0 &&
		a1.getnrLocRez() == 0);
	Avion a2("5", "cluj", "ferentari", "19", "da", 120, 120);
	assert(a2.getCod() == "5" && a2.getPlecare() == "cluj" && a2.getDestinatie() == "ferentari" &&
		a2.getData() == "19" && a2.getEscala() == "da" && a2.getnrTotLoc() == 120 &&
		a2.getnrLocRez() == 120);
	Avion a3(a2);
	assert(a3.getCod() == "5" && a3.getPlecare() == "cluj" && a3.getDestinatie() == "ferentari" &&
		a3.getData() == "19" && a3.getEscala() == "da" && a3.getnrTotLoc() == 120 &&
		a3.getnrLocRez() == 120);

	Avion* pa1 = new Avion();
	assert(pa1->getCod() == "" && pa1->getPlecare() == "" && pa1->getDestinatie() == "" &&
		pa1->getData() == "" && pa1->getEscala() == "" && pa1->getnrTotLoc() == 0 &&
		pa1->getnrLocRez() == 0);
	Avion* pa2 = new Avion("7", "mangalia", "timisoara", "23", "nu", 45, 36);
	assert(pa2->getCod() == "7" && pa2->getPlecare() == "mangalia" && pa2->getDestinatie() == "timisoara" &&
		pa2->getData() == "23" && pa2->getEscala() == "nu" && pa2->getnrTotLoc() == 45 &&
		pa2->getnrLocRez() == 36);
	Avion* pa3 = new Avion(*pa2);
	assert(pa3->getCod() == "7" && pa3->getPlecare() == "mangalia" && pa3->getDestinatie() == "timisoara" &&
		pa3->getData() == "23" && pa3->getEscala() == "nu" && pa3->getnrTotLoc() == 45 &&
		pa3->getnrLocRez() == 36);
}

//Desc: testeaza setterii si getteri clasei Avion
void TestAvion::testSetteriSiGetteri() {
	Avion a("5", "cluj", "ferentari", "19", "da", 120, 120);
	assert(a.getCod() == "5" && a.getPlecare() == "cluj" && a.getDestinatie() == "ferentari" &&
		a.getData() == "19" && a.getEscala() == "da" && a.getnrTotLoc() == 120 &&
		a.getnrLocRez() == 120);

	a.setCod("10");
	a.setPlecare("mangalia");
	a.setDestinatie("timisoara");
	a.setData("23");
	a.setEscala("nu");
	a.setnrTotLoc(45);
	a.setnrLocRez(36);

	assert(a.getCod() == "10" && a.getPlecare() == "mangalia" && a.getDestinatie() == "timisoara" &&
		a.getData() == "23" && a.getEscala() == "nu" && a.getnrTotLoc() == 45 &&
		a.getnrLocRez() == 36);
}

//Desc: testeaza operatorul egal pentru clasa Avion
void TestAvion::testOperatorEgal() {
	Avion a;
	Avion a2("5", "cluj", "ferentari", "19", "da", 120, 120);
	assert(a.getCod() == "" && a.getPlecare() == "" && a.getDestinatie() == "" &&
		a.getData() == "" && a.getEscala() == "" && a.getnrTotLoc() == 0 &&
		a.getnrLocRez() == 0);

	a = a2;
	assert(a.getCod() == "5" && a.getPlecare() == "cluj" && a.getDestinatie() == "ferentari" &&
		a.getData() == "19" && a.getEscala() == "da" && a.getnrTotLoc() == 120 &&
		a.getnrLocRez() == 120);
}

//Desc: testeaza operatorul de egalitate pentru clasa Avion
void TestAvion::testOperatorEgalitate() {
	Avion a1("5", "cluj", "ferentari", "19", "da", 120, 120);
	Avion a2("7", "mangalia", "timisoara", "23", "nu", 45, 36);

	assert((a1 == a2) == false);
}

//Desc: testeaza functia clone a clasei Avion
void TestAvion::testClone() {
	Avion a("5", "cluj", "ferentari", "19", "da", 120, 120);
	Avion* e = (Avion*)a.clone();

	assert(e->getCod() == "5" && e->getPlecare() == "cluj" && e->getDestinatie() == "ferentari" &&
		e->getData() == "19" && e->getEscala() == "da" && e->getnrTotLoc() == 120 &&
		e->getnrLocRez() == 120);
}

//Desc: testeaza functia equals a clasei Avion
void TestAvion::testEquals() {
	Avion* pa1 = new Avion("5", "cluj", "ferentari", "19", "da", 120, 120);
	Avion* pa2 = new Avion("5", "cluj", "ferentari", "19", "da", 120, 120);

	assert(pa1->equals(pa2) == true);
}

//Desc: testeaza functia toString a clasei Avion
void TestAvion::testToString() {
	Avion a("5", "cluj", "ferentari", "19", "da", 120, 120);
	string s = a.toString(",");

	assert(s == "AV,5,cluj,ferentari,19,da,120,120");
}