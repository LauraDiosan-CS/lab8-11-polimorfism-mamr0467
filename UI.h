#pragma once
#include "Service.h"
#include "ServiceUser.h"
#include "ValidationException.h"
#include "MyException.h"

class UI {
private:
	Service serv;
	ServiceUser servUser;

	bool login();
	void meniu();
	void afisareCalatorii(vector<Calatorie*>);
	void adaugareCalatorieAvion();
	void adaugareCalatorieAutobuz();
	void modificareCalatorie();
	void stergereCalatorie();

	void rezervaLocuri();
	void afisareCalatoriiAnumitaData();
public:
	UI();
	~UI();
	void runUI();
};
