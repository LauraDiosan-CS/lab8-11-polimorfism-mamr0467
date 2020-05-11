#pragma once
#include <stdexcept>

using namespace std;

class MyException : public runtime_error {
private:
	const char* message;
public:
	MyException(const char* m) : runtime_error(m), message(m) {
	}
	const char* what() {
		return message;
	}

	const char* getMessage() {
		return message;
	}
};