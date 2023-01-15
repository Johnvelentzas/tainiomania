#pragma once

#include "widget.h"
#include <iostream>

class link : public widget
{
public:
	graphics::Brush brush;
	graphics::Brush toggleBrush;
	std::string text;
	float size;
	void (*func)();
	void (*secFunc)();
	bool isHovering = false;
	bool canToggle = false;
	bool toggleState = false;


	link(){}

	link(float pos_x, float pos_y, float letterSize, std::string text, void (*func)()) {
		this->pos_x = pos_x;
		this->pos_y = pos_y;
		this->text = text;
		this->size = letterSize;
		this->func = func;
		this->pos_y_afterscroll = pos_y;
		this->height = letterSize;
		this->width = text.length() * letterSize / 2;
		this->toggleBrush.fill_color[0] = 0.f;
		this->toggleBrush.fill_color[2] = 0.f;
	};

	link(float pos_x, float pos_y, float letterSize, std::string text, void (*func)(), void (*secFunc)()) {
		this->pos_x = pos_x;
		this->pos_y = pos_y;
		this->text = text;
		this->size = letterSize;
		this->func = func;
		this->secFunc = secFunc;
		this->canToggle = true;
		this->pos_y_afterscroll = pos_y;
		this->height = letterSize;
		this->width = text.length() * letterSize / 2;
	};

	void draw() {
		if (this->canToggle)
		{
			graphics::drawDisk(this->pos_y, this->pos_y, 2.f, this->toggleBrush);
		}
		graphics::drawText(this->pos_x, this->pos_y, this->size, this->text, this->brush);
		if (this->isHovering)
		{
			graphics::drawLine(this->pos_x, this->pos_y + (this->height / 2), this->pos_x + this->width, this->pos_y + (this->height / 2), this->brush);
		}
	}

	void update() {
		if (this->isCurrInBoundsText())
		{
			this->isHovering = true;
			graphics::MouseState mouse;
			graphics::getMouseState(mouse);
			if (this->canToggle)
			{
				if (this->toggleState) {
					if (mouse.button_right_pressed) {
						this->toggleBrush.fill_color[0] = 0.f;
						this->toggleBrush.fill_color[2] = 0.f;
						this->secFunc();
					}
				}
				else {
					if (mouse.button_right_pressed) {
						this->toggleBrush.fill_color[0] = 1.f;
						this->toggleBrush.fill_color[2] = 1.f;
						this->func();
					}
				}
			}
			else {
				if (mouse.button_right_pressed) {
					this->func();
				}
			}
		}
		else
		{
			this->isHovering = false;
		}
	}

	~link() {};

	void init(){
	}
};