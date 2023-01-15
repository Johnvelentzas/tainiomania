#include "tainiomania.h"
#include "Comfig.h"
#include "moviePoster.h"
#include "data.h"
#include "link.h"

#include <iostream>

static float scroll = 0.f;
static filter fil;

float endOfPage = 500.f;
bool updateList = true;
data moviedata;
moviePoster posters[100];
link noMoviesFound = link(200.f, CANVAS_HEIGHT / 2, NO_MOVIES_FOUND_SIZE, std::string("NO    MOVIES    FOUND"), []() {fil.removeAllFilters(); updateList = true; });
link year;
link dir;
link exitButton = link(EXIT_X, EXIT_Y, EXIT_SIZE, std::string("CLEAR  FILTERS"), []() {fil.removeAllFilters(); updateList = true; });
link cat1 = link(CATEGORY_MARGIN_X, CATEGORY_Y, CATEGORY_SIZE, std::string("Action"), []() {fil.addCategory(std::string("action")); updateList = true;});
link cat2 = link(CATEGORY_MARGIN_X + 100.f, CATEGORY_Y, CATEGORY_SIZE, std::string("Adventure"), []() {fil.addCategory(std::string("adventure")); updateList = true; });
link cat3 = link(CATEGORY_MARGIN_X + 200.f, CATEGORY_Y, CATEGORY_SIZE, std::string("Fantasy"), []() {fil.addCategory(std::string("fantasy")); updateList = true; });
link cat4 = link(CATEGORY_MARGIN_X + 300.f, CATEGORY_Y, CATEGORY_SIZE, std::string("Crime"), []() {fil.addCategory(std::string("crime")); updateList = true; });
link cat5 = link(CATEGORY_MARGIN_X + 400.f, CATEGORY_Y, CATEGORY_SIZE, std::string("Comedy"), []() {fil.addCategory(std::string("comedy")); updateList = true; });
link cat6 = link(CATEGORY_MARGIN_X + 500.f, CATEGORY_Y, CATEGORY_SIZE, std::string("Horror"), []() {fil.addCategory(std::string("horror")); updateList = true; });
link cat7 = link(CATEGORY_MARGIN_X + 600.f, CATEGORY_Y, CATEGORY_SIZE, std::string("Musical"), []() {fil.addCategory(std::string("musical")); updateList = true; });
int numOfPosters = 0;

void tainiomania::update()
{
	if (graphics::getKeyState(graphics::SCANCODE_UP) && scroll > 0.f) {
		scroll -= SCROLL_SPEED;
	}
	if (graphics::getKeyState(graphics::SCANCODE_DOWN) && scroll < endOfPage - CANVAS_HEIGHT) {
		scroll += SCROLL_SPEED;
	}
	if (updateList) {
		updateList = false;
		float x = float((CANVAS_WIDTH % (POSTER_WIDTH + POSTER_MARGIN)) / 2  + (POSTER_WIDTH/2));
		float y = float(TOP_SPACE);
		numOfPosters = 0;
		for(movie var : moviedata.movieList)
		{
			std::cout << var.title << std::endl;
			if (!fil.filterMovie(var)) {
				continue;
			}
			posters[numOfPosters] = var.getPoster(x, y);
			numOfPosters++;
			x += POSTER_WIDTH + POSTER_MARGIN;
			if (x > CANVAS_WIDTH - ((POSTER_WIDTH + POSTER_MARGIN) / 2)) {
				x = float((CANVAS_WIDTH % (POSTER_WIDTH + POSTER_MARGIN)) / 2 + (POSTER_WIDTH / 2));
				y += float(POSTER_HEIGHT + POSTER_MARGIN);
			}
			endOfPage = float(y + (POSTER_HEIGHT / 2) + POSTER_MARGIN);
		}
		if (numOfPosters == 1)
		{
			posters[0].moveToFullScreen();
			year = link(FULL_MARGIN_X, FULL_YEAR_POS_Y, FULL_YEAR_SIZE, posters[0].yearstr, []() {fil.removeAllFilters(); fil.setYearFrom(posters[0].year); fil.setYearTo(posters[0].year); updateList = true; });
			dir = link(FULL_MARGIN_X, FULL_DIR_POS_Y, FULL_DIR_SIZE, posters[0].director, []() {fil.removeAllFilters(); fil.setDirector(posters[0].director); updateList = true; });
		}

	}	
	for (int i = 0; i < numOfPosters; i++)
	{
		posters[i].update();
	}
	if (numOfPosters == 1)
	{
		year.update();
		dir.update();
	}
	if (numOfPosters == 0) {
		noMoviesFound.update();
	}
	exitButton.update();
	cat1.update();
	cat2.update();	
	cat3.update();	
	cat4.update();	
	cat5.update();	
	cat6.update();	
	cat7.update();
}

void tainiomania::draw()
{
	for (int i = 0; i < numOfPosters; i++)
	{
		posters[i].draw();
	}
	if (numOfPosters == 1)
	{
		year.draw();
		dir.draw();
	}
	if (numOfPosters == 0) {
		noMoviesFound.draw();
	}
	exitButton.draw();
	cat1.draw();
	cat2.draw();
	cat3.draw();
	cat4.draw();
	cat5.draw();
	cat6.draw();
	cat7.draw();
}

float tainiomania::getScroll() {
	return scroll;
}

filter* tainiomania::getFilter()
{
	updateList = true;
	return &fil;
}

tainiomania::tainiomania()
{
}

tainiomania::~tainiomania()
{
}
