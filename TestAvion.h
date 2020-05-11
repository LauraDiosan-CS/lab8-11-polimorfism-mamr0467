#pragma once
#include "Avion.h"
#include <assert.h>

class TestAvion {
private:
	void testConstructori();
	void testSetteriSiGetteri();
	void testOperatorEgal();
	void testOperatorEgalitate();
	void testClone();
	void testEquals();
	void testToString();
public:
	void testAll();
};