#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class IEntity {
public:
	virtual ~IEntity() {};

	virtual IEntity* clone() = 0;
	virtual bool equals(IEntity*) = 0;
	virtual string toString(string) = 0;

};
