#pragma once
#include "RepoFile.h"
#include <assert.h>
#include "RepoTXT.h"
#include "RepoCSV.h"
#include "Avion.h"
#include "Autobuz.h"
#include "DeleteException1.h"
#include "DeleteException2.h"

class TestRepoFile {
private:
	void testAdd();
	void testDel();
	void testUpdate();
	void testGet();
	void testCerinta();
	void cerintaExceptii();
public:
	void testAll();
};
