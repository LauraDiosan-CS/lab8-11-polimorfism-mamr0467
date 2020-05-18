#pragma once
#include "RepoUser.h"

using namespace std;

class ServiceUser {
private:
	RepoUser repo;
public:
	ServiceUser();
	ServiceUser(RepoUser&);
	~ServiceUser();

	void setFile(string);
	void setRepo(const RepoUser&);
	void add(string, string, string, string);
	void del(string);
	void update(string, string, string, string);
	int getSize();
	User getElemByPos(int);
	vector<User> getAll();

	void empty();

	bool verificaUser(string, string);
};