#pragma once
#include "Service.h"

class UI {
private:
	Service serv;
	void login();
	void meniu();
public:
	UI();
	UI(Service&);
	~UI();
	void runUI();
};
