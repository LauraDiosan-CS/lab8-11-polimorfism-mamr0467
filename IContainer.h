#pragma once
#include "IEntity.h"
#include "IIterator.h"

class IContainer {
public:
	virtual void addElem(IEntity*) = 0;
	virtual void removeElem(IEntity*) = 0;
	virtual int getSize() = 0;
	virtual bool contains(IEntity*) = 0;
	virtual IEntity* getElemPos(int) = 0;

	friend class IIterator;
	virtual IIterator* getIterator() = 0;

	virtual ~IContainer() {};
};
