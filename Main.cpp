#include <iostream>
#include <fstream>
#include "TestAvion.h"
#include "TestAutobuz.h"
#include "TestRepoFile.h"

using namespace std;

int main()
{
	//TestAvion testAv;
	//testAv.testAll();
	//TestAutobuz testAu;
	//testAu.testAll();
	TestRepoFile testRepo;
	testRepo.testAll();

	return 0;
}