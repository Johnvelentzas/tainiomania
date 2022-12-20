#pragma once
#include "being.h"
#include <string>

class human : public being {
public:
	std::string name;
	human(int age, std::string name) : being(age) {
		std::cout << "human constructor" << std::endl;
		this->name = name;
	}
	~human() {
		std::cout << "human destructor." << std::endl;
	}
};