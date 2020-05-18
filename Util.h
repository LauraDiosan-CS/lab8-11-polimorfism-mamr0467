#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include <Windows.h>
#include <cwchar>

using namespace std;

vector<string> inline split(const string& s, char delim) {
	vector<string> words;
	stringstream ss(s);
	string item;

	while (getline(ss, item, delim))
		words.push_back(item);

	return words;
}

void inline changeColor(int desiredColor) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), desiredColor);
}
