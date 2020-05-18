#pragma once
#include "ServiceUser.h"
#include <assert.h>

using namespace std;

class TestServiceUser {
private:
	void testSetteriSiGetteri();
	void testAdd();
	void testDelete();
	void testUpdate();
	void testVerificaUser();
public:
	void testAll();
};