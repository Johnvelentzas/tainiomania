#pragma once

#include "appObject.h"

class clickable : public appObject {
private:
	void(*function);
public:
	void addClickFunction(void(*fun)) {
		this->function = &fun;
	}
	void clickFunction() {
		
	}
};