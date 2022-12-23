#pragma once
#include "appObject.h"

class clickable : public appObject{
public:
	virtual void setClickFunction() = 0;
};