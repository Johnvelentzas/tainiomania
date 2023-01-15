#include "tainiomania.h"
#include "moviePoster.h"
#include "graphics.h"

void moviePoster::update(){
	this->pos_y_afterscroll = this->pos_y - tainiomania::getScroll();
	if (this->isCurrInBounds() && !this->isInFull) {
		this->brush.outline_width = 2.f;
		graphics::MouseState mouse;
		graphics::getMouseState(mouse);
		if (mouse.button_right_pressed) {
			filter* filter = tainiomania::getFilter();
			filter->setTitle(this->title);
		}
	}
	else {
		this->brush.outline_width = 0.f;
	}
}

void moviePoster::draw() {
	graphics::drawRect(this->pos_x, this->pos_y_afterscroll, this->width, this->height, this->brush);
	if (this->isInFull) {
		graphics::setFont(std::string("OpenSans-Semibold.ttf"));
		graphics::drawText(FULL_MARGIN_X, FULL_TITLE_POS_Y, FULL_TITLE_SIZE, this->title, this->brush);

		graphics::setFont(std::string("OpenSans-Regular.ttf"));

		graphics::drawText(FULL_MARGIN_X, FULL_LEADS_POS_Y, FULL_LEADS_SIZE, this->leadsToString(), this->brush);
		graphics::drawText(FULL_MARGIN_X, FULL_CAT_POS_Y, FULL_CAT_SIZE, this->categoriesToString(), this->brush);
	}
}

void moviePoster::moveToFullScreen() {
	this->isInFull = true;
	this->pos_x = FULL_POSTER_X;
	this->pos_y = FULL_POSTER_Y;
	this->width = FULL_POSTER_WIDTH;
	this->height = FULL_POSTER_HEIGHT;
}

std::string moviePoster::leadsToString()
{
	return this->leads[0] + ",  " + this->leads[1] + ",  " + this->leads[2];
}

std::string moviePoster::categoriesToString()
{
	return this->category[0] + "    " + this->category[1] + "    " + this->category[2];
}

moviePoster::moviePoster() {
	this->width = float(POSTER_WIDTH);
	this->height = float(POSTER_HEIGHT);
}

moviePoster::moviePoster(float pos_x, float pos_y, std::string imagePath, std::string title, int year, std::string director, std::string leads[], std::string category[]) {
	this->pos_x = pos_x;
	this->pos_y = pos_y;
	this->brush.texture = std::string(ASSETS_PATH) + imagePath;
	this->brush.outline_width = 0.f;
	this->width = float(POSTER_WIDTH);
	this->height = float(POSTER_HEIGHT);
	this->title = title;
	this->year = year;
	this->yearstr = std::to_string(year);
	this->director = director;
	this->leads = leads;
	this->category = category;
}