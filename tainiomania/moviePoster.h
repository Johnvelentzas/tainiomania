#pragma once

#include "widget.h"
#include "Comfig.h"


class moviePoster : public widget {
public:
	graphics::Brush brush;
	bool isInFull = false;

	std::string title = "";
	int year = 0;
	std::string yearstr = "0";
	std::string director = "";
	std::string* leads = nullptr;
	std::string* category = nullptr;

	void update();

	void draw();

	void init() {

	}

	void moveToFullScreen();

	std::string leadsToString();

	std::string categoriesToString();

	moviePoster();

	moviePoster(float pos_x, float pos_y, std::string imagePath, std::string title, int year, std::string director, std::string leads[], std::string category[]);

	~moviePoster() {

	}
};