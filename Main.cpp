#include <iostream>
#include <fstream>
#include "TestAvion.h"
#include "TestAutobuz.h"
#include "TestRepoFile.h"
#include "TestService.h"
#include "Service.h"
#include "UI.h"

using namespace std;

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
	
	//Service s;
	
	//UI ui(s);
	//ui.runUI();

	return 0;
}