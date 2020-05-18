#include <iostream>
#include <fstream>
#include "TestAvion.h"
#include "TestAutobuz.h"
#include "TestRepoFile.h"
#include "TestService.h"
#include "TestServiceUser.h"
#include "UI.h"
#include "Util.h"

using namespace std;

void resetElements(Service& serv, vector<Calatorie*> defaultTrips) {
	serv.empty();
	for (Calatorie* ca : defaultTrips)
		serv.add(ca);
}

void testResetElements() {
	Calatorie* c1 = new Avion("156", "Cluj - Napoca", "Dubai", "14.06.2020", "false", 100, 80);
	Calatorie* c2 = new Autobuz("873", "Constanta", "Cluj - Napoca", "15.07.2020", 1, 40, 20);
	Calatorie* c3 = new Autobuz("118", "Vienna", "Bucuresti", "14.06.2020", 3, 80, 50);
	Calatorie* c4 = new Avion("122", "Bucuresti", "Cluj - Napoca", "14.06.2020", "false", 100, 80);
	Calatorie* c5 = new Avion("122", "Cluj - Napoca", "Bucuresti", "14.06.2020", "false", 100, 80);

	RepoFile* repo = new RepoCSV();
	Service service(repo);
	vector<Calatorie*> defaultTrips;
	defaultTrips.push_back(c1);
	defaultTrips.push_back(c2);
	defaultTrips.push_back(c3);
	defaultTrips.push_back(c4);
	defaultTrips.push_back(c5);
	
	resetElements(service, defaultTrips);

	service.deletee(c1);

	
	assert(service.getSize() == 3);
	assert(*(service.getElemByPos(0)) == *c2);
	assert(*(service.getElemByPos(1)) == *c3);
	assert(*(service.getElemByPos(2)) == *c5);

	resetElements(service, defaultTrips);

	service.deletee(c2);
	assert(service.getSize() == 4);
	assert(*(service.getElemByPos(0)) == *c1);
	assert(*(service.getElemByPos(1)) == *c3);
	assert(*(service.getElemByPos(2)) == *c4);
	assert(*(service.getElemByPos(3)) == *c5);

	resetElements(service, defaultTrips);

	service.deletee(c3);
	assert(service.getSize() == 3);
	assert(*(service.getElemByPos(0)) == *c1);
	assert(*(service.getElemByPos(1)) == *c2);
	assert(*(service.getElemByPos(2)) == *c5);

	resetElements(service, defaultTrips);
	service.deletee(c4);
	assert(service.getSize() == 1);
	assert(*(service.getElemByPos(0)) == *c2);


	resetElements(service, defaultTrips);
	service.deletee(c5);
	assert(service.getSize() == 3);
	assert(*(service.getElemByPos(0)) == *c1);
	assert(*(service.getElemByPos(1)) == *c2);
	assert(*(service.getElemByPos(2)) == *c3);

	for (size_t i = 0; i < defaultTrips.size(); i++) {
		delete defaultTrips[i];
		defaultTrips[i] = NULL;
	}
}

int main()
{
	TestAvion testAv;
	testAv.testAll();
	TestAutobuz testAu;
	testAu.testAll();
	TestRepoFile testRepo;
	testRepo.testAll();
	TestService testServ;
	testServ.testAll();
	TestServiceUser testServUser;
	testServUser.testAll();
	testResetElements();

	UI ui;
	ui.runUI();

	return 0;
}
