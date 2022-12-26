#pragma once
#include "graphics.h"
#include "uiElement.h"
#include "Comfig.h"
#include <string.h>
#include <iostream>

class avatar : public uiElement {
private:
	const graphics::Brush brush = {
		WHITE,
		BLACK,
		0.f,
		0.f,
		WHITE,
		1.f,
		1.f,
		std::string(ASSETS_PATH) + "avatarTheWayOfWater.png",
		false,
		0.f,
		1.f
	};
public:
	void draw() {
		graphics::drawRect(this->pos_x, this->pos_y, this->width, this->height, this->brush);
	}
	void update(){}
	void init() {}
	avatar(float pos_x, float pos_y) {
		this->width = 100.f;
		this->height = 200.f;
		this->pos_x = pos_x;
		this->pos_y = pos_y;
		std::cout << std::string(ASSETS_PATH) + "avatarTheWayOfWater.png" << std::endl;
	}
};