#include "TestServiceUser.h"

//Desc: gestioneaza functiile de test pentru clas ServiceUser
void TestServiceUser::testAll() {
	this->testSetteriSiGetteri();
	this->testAdd();
	this->testDelete();
	this->testUpdate();
	this->testVerificaUser();
}

//Desc: testeaza setterii si getterii clasei ServiceUser
void TestServiceUser::testSetteriSiGetteri() {
	ServiceUser s;
	User user("1", "petrica", "petrica@utcn.ro", "shaorma");

	assert(s.getSize() == 0);
	s.add("1", "petrica", "petrica@utcn.ro", "shaorma");
	assert(s.getElemByPos(0) == user);
}

//Desc: testeaza functia de adaugare a clasei ServiceUser
void TestServiceUser::testAdd() {
	RepoUser repo;
	ServiceUser s(repo);

	assert(s.getSize() == 0);
	s.add("1", "petrica", "petrica@utcn.ro", "shaorma");
	s.add("2", "vasile", "vasile@ubb.ro", "sapa");
	assert(s.getSize() == 2);
}

//Desc: testeaza functia de stergere pentru clasa ServiceUser
void TestServiceUser::testDelete() {
	ServiceUser s;
	assert(s.getSize() == 0);
	s.add("1", "petrica", "petrica@utcn.ro", "shaorma");
	s.add("2", "vasile", "vasile@ubb.ro", "sapa");
	assert(s.getSize() == 2);

	s.del("1");
	assert(s.getSize() == 1);
}

//Desc: testeaza functia de update a clasei ServiceUser
void TestServiceUser::testUpdate() {
	ServiceUser s;
	User user("1", "gicu", "gicu@gmail.com", "parola");

	s.add("1", "petrica", "petrica@utcn.ro", "shaorma");
	s.add("2", "vasile", "vasile@ubb.ro", "sapa");

	s.update("1", "gicu", "gicu@gmail.com", "parola");
	assert(s.getElemByPos(1) == user);
}

void TestServiceUser::testVerificaUser() {
	ServiceUser s;
	User user("1", "gicu", "gicu@gmail.com", "parola");

	s.add("1", "petrica", "petrica@utcn.ro", "shaorma");
	s.add("2", "vasile", "vasile@ubb.ro", "sapa");

	assert(s.verificaUser("petrica@utcn.ro", "shaorma") == true);
	assert(s.verificaUser("septimiu@ubb.ro", "iubescpoo") == false);
}