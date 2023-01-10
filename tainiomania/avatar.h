#pragma once
#include "graphics.h"
#include "uiElement.h"
#include "Comfig.h"
#include <string.h>
#include <iostream>

class avatar : public uiElement {
public:
	void draw() {
		graphics::Brush brush;
		brush.texture = (std::string)ASSETS_PATH + "avatarTheWayOfWater.png";
		graphics::drawRect(this->pos_x, this->pos_y, this->width, this->height, brush);
	}
	void update(){}
	void init() {}
	avatar(float pos_x, float pos_y) {
		this->width = 100.f;
		this->height = 200.f;
		this->pos_x = pos_x;
		this->pos_y = pos_y;
	}
};