#include "UI.h"

UI::UI()
{
}


UI::UI(Service& serv) {
	this->serv = serv;
}

UI::~UI()
{
}

void UI::login() {
	// user = "septimiu@ubb"
	// password = septimiu
	string user = "";
	string password = "";
	while (user != "septimiu@ubb" && password != "septimiu") {
		cout << "----------------------------\n";
		cout << "User: ";
		getline(cin, user);
		cout << "Password: ";
		getline(cin, password);

		if (user != "septimiu@ubb" || password != "septimiu")
			cout << "----------------------------\n Wrong data!\n";
	}

	string numar = "";
	while (numar != "1" && numar != "2") {
		cout << "Introduceti numarul de ordine al tipului de fisier in care doriti sa salvati datele:\n";
		cout << "\t1. Fisier TXT\n";
		cout << "\t2. Fisier CSV\n";
		cout << "Numarul ales: ";
		getline(cin, numar);
	}

	RepoFile* repo;

	if (numar == "1")
		repo = new RepoTXT("Calatorii.txt");
	else
		repo = new RepoCSV("Calatorii.csv");

	this->serv.SetRepo(repo);
}

void UI::meniu() {
	cout << "Optiunile sunt:\n";
	cout << "\t1. Adaugare calatorie\n";
	cout << "\t2. Modificare calatorie\n";
	cout << "\t3. Stergere calatorie\n";
	cout << "\t4. Afiseaza caltoriile dintr-o anumita data\n";
	cout << "\t5. Rezerva locuri pentru o anumita calatorie\n";
}

void UI::runUI() {
	this->login();
	string comanda = "";
	bool continua = true;
	while (continua) {
		this->meniu();
		cout << "Introduceti comanda: ";
		getline(cin, comanda);

		if (comanda == "x")
			continua = false;
		else
			cout << "Comanda invalida!\n";
	}
}