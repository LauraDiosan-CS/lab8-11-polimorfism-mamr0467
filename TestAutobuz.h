#pragma once
#include "Autobuz.h"
#include <assert.h>

class TestAutobuz {
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