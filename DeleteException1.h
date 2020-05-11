#pragma once
#include <stdexcept>

using namespace std;

class DeleteException1 : public runtime_error {
private:
	const char* message;
public:
	DeleteException1(const char* m) : runtime_error(m), message(m) {
	}
	const char* what() {
		return message;
	}
	const char* getMessage() {
		return message;
	}
};