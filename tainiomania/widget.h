#pragma once

#include "appObject.h"
#include "graphics.h"

/**
* A basic virtual ui element with no functions
*/
class widget : public appObject {
protected:
	float pos_x = 0;
	float pos_y = 0;
	float pos_y_afterscroll = 0;
	float width = 0;
	float height = 0;
public:
	virtual void draw() = 0;
	virtual void update() = 0;

	bool isCurrInBounds() {
		graphics::MouseState mouse;
		graphics::getMouseState(mouse);
		float cur_x = graphics::windowToCanvasX(float(mouse.cur_pos_x));
		float cur_y = graphics::windowToCanvasY(float(mouse.cur_pos_y));
		if (cur_x > this->pos_x - (this->width/2) && cur_x < this->pos_x + (this->width / 2) && cur_y > this->pos_y_afterscroll - (this->height / 2) && cur_y < this->pos_y_afterscroll + (this->height / 2)) {
			return true;
		}
		return false;
	}

	bool isCurrInBoundsText() {
		graphics::MouseState mouse;
		graphics::getMouseState(mouse);
		float cur_x = graphics::windowToCanvasX(float(mouse.cur_pos_x));
		float cur_y = graphics::windowToCanvasY(float(mouse.cur_pos_y));
		if (cur_x > this->pos_x && cur_x < this->pos_x + (this->width) && cur_y > this->pos_y_afterscroll - this->height && cur_y < this->pos_y_afterscroll) {
			return true;
		}
		return false;
	}
};