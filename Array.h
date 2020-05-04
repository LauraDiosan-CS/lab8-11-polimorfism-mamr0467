#pragma once
#include "IContainer.h"
#include "IEntity.h"
#include "IIterator.h"

class Array : public IContainer {
private:
	int size;
	int capacity;
	IEntity** elements;
	void resize();
public:
	Array();
	Array(int);
	Array(const Array&);
	~Array();

	Array& operator=(const Array&);
	void addElem(IEntity*) override;
	void removeElem(IEntity*) override;
	int getSize() override;
	bool contains(IEntity*) override;
	IEntity* getElemPos(int) override;
	void empty();

	friend class ArrayIterator;
	IIterator* getIterator() override;
};

class ArrayIterator : public IIterator {
private:
	Array* arr;
	int crtPos;
public:
	ArrayIterator(Array* arr) {
		this->arr = arr;
		this->crtPos = 0;
	}

	~ArrayIterator()
	{
	}

	void moveNext() override {
		this->crtPos++;
	}

	bool hasNext() override {
		return (this->crtPos < arr->getSize() - 1);
	}

	bool isValid() override {
		return (this->crtPos < arr->getSize());
	}

	IEntity* getCrtElem() override {
		return this->arr->elements[this->crtPos];
	}

	void moveFirst() override {
		this->crtPos = 0;
	}
};
