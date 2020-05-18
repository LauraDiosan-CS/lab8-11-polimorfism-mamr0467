#pragma once
#include <fstream>
#include <vector>
#include "User.h"
#include "MyException.h"

using namespace std;

class RepoUser {
private:
	vector<User> v;
	string fileName;
public:
	RepoUser();
	RepoUser(string);
	RepoUser(const RepoUser&);
	~RepoUser();
	
	void loadFromFile();
	void saveToFile();

	RepoUser& operator=(const RepoUser&);
	void setFileName(string);
	string getFileName();
	void add(User&);
	void remove(string);
	void update(User&, User&);
	User getByPos(int);
	
	int getSize();
	vector<User> getAll();

	void empty();
};