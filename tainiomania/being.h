#pragma once
#include<iostream>

class being {
private:
	int age;
	bool alive;

public:
	int getAge() {
		return this->age;
	}

	being() {
		std::cout << "being constructor." << std::endl;
		this->age = 0;
		this->alive = true;
	}

	being(int age) {
		std::cout << "being constructor." << std::endl;
		this->age = age;
		this->alive = true;
	}
	virtual ~being() {
		std::cout << "being destructor." << std::endl;
	}
};