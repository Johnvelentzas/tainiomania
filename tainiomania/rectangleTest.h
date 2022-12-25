#pragma once

#include "appObject.h"
#include "graphics.h"

class rectangleTest : public appObject {
private:
	const graphics::Brush brush;
public:
	void draw() {
		graphics::drawRect(100.0f, 100.0f, 100.0f, 100.0f, this->brush);
	};
	void update() {};
	void init() {};
	rectangleTest() {};
	~rectangleTest() {};
};