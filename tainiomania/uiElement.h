#pragma once

#include "appObject.h"

/**
* A basic virtual ui element with no functions
*/
class uiElement : public appObject {
protected:
	float pos_x;
	float pos_y;
	float width;
	float height;
public:
	virtual void draw() = 0;
};