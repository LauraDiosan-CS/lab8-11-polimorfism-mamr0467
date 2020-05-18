#include "UI.h"

UI::UI()
{
}


UI::~UI()
{
}

void UI::afisareCalatorii(vector<Calatorie*> calatorii) {

	for (Calatorie* ca : calatorii) {
		if (ca->getnrTotLoc() == ca->getnrLocRez())
			changeColor(12);
		cout << ca->toString(" ").erase(0, 3) << '\n';

		changeColor(7);
	}

	for (size_t i = 0; i < calatorii.size(); i++) {
		delete calatorii[i];
		calatorii[i] = NULL;
	}
}

bool UI::login() {
	string answer = "";
	cout << "\nIntroduceti \"x\" pentru a renunta la logare sau altceva pentru a continua: ";
	getline(cin, answer);
	if (answer == "x")
		return false;
	string numar = "";
	while (numar != "1" && numar != "2") {
		cout << "Introduceti numarul de ordine al tipului de fisier in care doriti sa salvati datele:\n";
		cout << "\t1. Fisier TXT\n";
		cout << "\t2. Fisier CSV\n";
		cout << "Numarul ales: ";
		getline(cin, numar);
	}

	if (numar == "1") {
		this->serv.SetRepo(new RepoTXT("Calatorii.txt"));
		this->servUser.setRepo(RepoUser("User.txt"));
	}
	else {
		this->serv.SetRepo(new RepoCSV("Calatorii.csv"));
		this->servUser.setRepo(RepoUser("User.csv"));
	}

	string user = "";
	string password = "";
	while (true) {
		cout << "----------------------------\n";
		cout << "User: ";
		getline(cin, user);
		cout << "Password: ";
		getline(cin, password);

		if (this->servUser.verificaUser(user, password) == false)
			cout << "----------------------------\n Wrong data!\n";
		else
			return true;
	}
}

void UI::adaugareCalatorieAvion() {
	string cod, plecare, destinatie, data, escala;
	int locTot, locRez;
	cout << "Codul calatoriei: ";
	getline(cin, cod);
	cout << "Locul de plecare: ";
	getline(cin, plecare);
	cout << "Destinatia: ";
	getline(cin, destinatie);
	cout << "Data calatoriei: ";
	getline(cin, data);
	cout << "Face escala?(da/nu): ";
	getline(cin, escala);
	cout << "Numarul total de locuri: ";
	cin >> locTot;
	cin.get();
	cout << "Numarul de locuri rezervate: ";
	cin >> locRez;
	cin.get();
	try {
		this->serv.addElem(cod, plecare, destinatie, data, escala, locTot, locRez);
	}
	catch (ValidationException& vexc) {
		cout << vexc.what() << '\n';
	}
	catch (MyException& exc) {
		cout << exc.what();
	}
}

void UI::adaugareCalatorieAutobuz() {
	string cod, plecare, destinatie, data;
	int durata, locTot, locRez;
	cout << "Codul calatoriei: ";
	getline(cin, cod);
	cout << "Locul de plecare: ";
	getline(cin, plecare);
	cout << "Destinatia: ";
	getline(cin, destinatie);
	cout << "Data calatoriei: ";
	getline(cin, data);
	cout << "Durata calatoriei: ";
	cin >> durata;
	cin.get();
	cout << "Numarul total de locuri: ";
	cin >> locTot;
	cin.get();
	cout << "Numarul de locuri rezervate: ";
	cin >> locRez;
	cin.get();
	try {
		this->serv.addElem(cod, plecare, destinatie, data, durata, locTot, locRez);
	}
	catch (ValidationException& vexc) {
		cout << vexc.what() << '\n';
	}
	catch (MyException& exc) {
		cout << exc.what() << '\n';
	}
}

void UI::modificareCalatorie() {
	string codVechi, plecare, destinatie, data, escala;
	int durata, locTot, locRez, optiune;

	cout << "Introduceti tipul calatoriei pe care doriti sa o adaugati:\n";
	cout << "1. Avion    2.Autobuz\n";
	cin >> optiune;
	cin.get();

	cout << "Codul vechi al calatoriei pe care vreti sa o modificati: ";
	getline(cin, codVechi);
	cout << "Noul loc de plecare: ";
	getline(cin, plecare);
	cout << "Noua destinatie: ";
	getline(cin, destinatie);
	cout << "Noua data: ";
	getline(cin, data);
	if (optiune == 1) {
		cout << "Face escala?(da/nu): ";
		getline(cin, escala);
	}
	else {
		cout << "Durata caltoriei: ";
		cin >> durata;
		cin.get();
	}
	cout << "Noul numar de locuri totale: ";
	cin >> locTot;
	cin.get();
	cout << "Noul numar de locuri rezervate: ";
	cin >> locRez;
	cin.get();

	if (optiune == 1) {
		try {
			this->serv.updateElem(codVechi, plecare, destinatie, data, escala, locTot, locRez);
		}
		catch (ValidationException& vexc) {
			cout << vexc.what() << '\n';
		}
		catch (MyException& exc) {
			cout << exc.what() << '\n';
		}
	}
	else {
		try {
			this->serv.updateElem(codVechi, plecare, destinatie, data, durata, locTot, locRez);
		}
		catch (ValidationException& vexc) {
			cout << vexc.what() << '\n';
		}
		catch (MyException& exc) {
			cout << exc.what() << '\n';
		}
	}
}

void UI::stergereCalatorie() {
	string cod;
	cout << "Codul calatoriei pe care doriti sa il stergeti: ";
	getline(cin, cod);
	try {
		this->serv.delElem(cod);
	}
	catch (MyException& exc) {
		cout << exc.what() << '\n';
	}
}

void UI::afisareCalatoriiAnumitaData() {
	string data;
	cout << "Data pentru care sa afiseze calatoriile: ";
	getline(cin, data);

	vector<Calatorie*> v = this->serv.calatoriiAnumitaData(data);
	if (v.size() == 0)
		cout << "Nu exista calatorii in data respectiva.\n";
	else {
		this->afisareCalatorii(v);
	}
}

void UI::rezervaLocuri() {
	string cod;
	int rezervari;
	cout << "Codul calatoriei pentru care doriti sa ii faceti rezervari: ";
	getline(cin, cod);
	cout << "Numarul de locuri pe care doriti sa le rezervati: ";
	cin >> rezervari;
	cin.get();
	try {
		this->serv.rezervaLocuri(cod, rezervari);
		this->afisareCalatorii(this->serv.getAll());
	}
	catch (MyException& exc) {
		cout << exc.what() << '\n';
	}
}

void UI::meniu() {
	cout << "Optiunile sunt:\n";
	cout << "\t1. Adaugare calatorie cu avionul\n";
	cout << "\t2. Adaugare calatorie cu autobuzul\n";
	cout << "\t3. Modificare calatorie\n";
	cout << "\t4. Stergere calatorie\n";
	cout << "\t5. Afiseaza calatoriile dintr-o anumita data\n";
	cout << "\t6. Rezerva locuri pentru o anumita calatorie\n";
	cout << "\t7. Afisare calatorii\n";
	cout << "\tx. Inchidere aplicatie\n";
}

void UI::runUI() {

	string comanda = "";
	bool continua = true;
	while (continua) {
		bool result = this->login();
		if (result == false)
			continua = false;
		else {
			this->afisareCalatorii(this->serv.getAll());
			bool inSession = true;
			while (inSession) {
				this->meniu();
				cout << "Introduceti comanda: ";
				getline(cin, comanda);

				if (comanda == "1")
					this->adaugareCalatorieAvion();
				else if (comanda == "2")
					this->adaugareCalatorieAutobuz();
				else if (comanda == "3")
					this->modificareCalatorie();
				else if (comanda == "4")
					this->stergereCalatorie();
				else if (comanda == "5")
					this->afisareCalatoriiAnumitaData();
				else if (comanda == "6")
					this->rezervaLocuri();
				else if (comanda == "7")
					this->afisareCalatorii(this->serv.getAll());
				else if (comanda == "x")
					inSession = false;
				else
					cout << "Comanda invalida!\n";
			}
		}
	}
}