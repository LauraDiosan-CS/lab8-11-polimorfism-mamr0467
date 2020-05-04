#include "Array.h"

//Desc: dubleaza capacaitatea unui Array
//In: -
//Out: -
void Array::resize() {
	IEntity** aux = new IEntity * [2 * this->capacity];
	for (int i = 0; i < this->capacity; i++)
		aux[i] = this->elements[i]->clone();
	for (int i = 0; i < this->capacity; i++)
		delete this->elements[i];
	delete[] this->elements;
	this->elements = aux;
	this->capacity *= 2;
}

//Desc: creeaza un obiect nou de tip Array
//In: -
//Out: un nou obiect de tip Array cu valori implicite
Array::Array() {
	this->size = 0;
	this->capacity = 100;
	this->elements = new IEntity * [100];
}

//Desc: creeaza un obiect nou de tip Array
//In: cap, in - capacitatea pentru Array
//Out: un obiect nou de tip Array cu capacitatea cap
Array::Array(int cap) {
	this->size = 0;
	this->capacity = cap;
	this->elements = new IEntity * [cap];
}

//Desc: creeaza un obiect nou de tip Array
//In: arr, Array& - un obiect de tip Array
//Out: un nou obiect de tip Array cu valorile celui dat ca parametru
Array::Array(const Array& arr) {
	this->size = arr.size;
	this->capacity = arr.capacity;
	this->elements = new IEntity * [arr.capacity];
	for (int i = 0; i < arr.size; i++)
		this->elements[i] = arr.elements[i]->clone();
}

//Desc: distruge un obiect de tip Array
//In: -
//Out: -
Array::~Array() {
	if (this->elements) {
		for (int i = 0; i < this->size; i++)
			if (this->elements[i]) {
				delete this->elements[i];
				this->elements[i] = NULL;
			}
		delete[] this->elements;
		this->elements = NULL;
	}
}

//Desc: schimba atributele unui Array cu atributele altui Array
//In: arr, Array& - un obiect de tip Array
//Out: o referinta catre instanta curenta
Array& Array::operator=(const Array& arr) {
	if (this != &arr) {
		if (this->elements) {
			for (int i = 0; i < this->size; i++)
				if (this->elements[i]) {
					delete this->elements[i];
					this->elements[i] = NULL;
				}
			delete[] this->elements;
		}
		this->size = arr.size;
		this->capacity = arr.capacity;
		this->elements = new IEntity * [arr.capacity];
		for (int i = 0; i < arr.size; i++)
			this->elements[i] = arr.elements[i]->clone();
	}

	return *this;
}

//Desc: adauga un element in Array
//In: elem, *IEntity - elementul de adaugat
//Out: -
void Array::addElem(IEntity* elem) {
	if (this->size >= this->capacity)
		this->resize();
	this->elements[this->size++] = elem->clone();
}

//Desc: sterge un element din Array
//In: elem, IEntity* - elementul de sters
//Out: -
void Array::removeElem(IEntity* elem) {
	int i = 0;
	while (i < this->size) {
		if (elem->equals(this->elements[i])) {
			delete[] this->elements[i];
			for (int j = i; j < this->size - 1; j++)
				this->elements[j] = this->elements[j + 1];

			this->size--;
		}
		else
			i++;
	}
}

//Desc: acceseaza lungimea unui Array
//In: -
//Out: lungimea Array-ului
int Array::getSize() {
	return this->size;
}

//Desc: verifica daca Array-ul contine un anumit element
//In: elem, IEntity* - elementul pentru a  verifica daca exista
//Out: true/false
bool Array::contains(IEntity* elem) {
	for (int i = 0; i < this->size; i++)
		if (elem->equals(this->elements[i]))
			return true;
	return false;
}

//Desc: acceseaza elementul de pe o anumita pozitie
//In: pos, int - pozitia de pe care se cere elementul
//Out: elementul de pe pozitia pos
IEntity* Array::getElemPos(int pos) {
	return this->elements[pos]->clone();
}

//Desc: creeaza un iterator pentru Array
//In: -
//Out: iteratorul creat
IIterator* Array::getIterator() {
	IIterator* arrI = new ArrayIterator(this);

	return arrI;
}

//Desc: sterge toate elementele din Array
//In: -
//Out: -
void Array::empty() {
	for(int i = 0; i < this->size; i++)
		if (this->elements[i]) {
			delete this->elements[i];
			this->elements[i] = NULL;
		}
	this->size = 0;
}