#pragma once

#include "moviePoster.h"
#include "appObject.h"

class movie : public appObject {

public:

	std::string posterPath;
	std::string title;
	int year = 0;
	std::string director;
	std::string* leads = nullptr;
	std::string* category = nullptr;

	void update() {

	}

	void init() {

	}

	movie() {

	}

	movie(std::string posterPath, std::string title, int year, std::string director, std::string leads[3], std::string category[3]) {
		this->posterPath = posterPath;
		this->title = title;
		this->year = year;
		this->director = director;
		this->leads = leads;
		this->category = category;
	}

	~movie() {

	}

	moviePoster getPoster(float pos_x, float pos_y) {
		return moviePoster(pos_x, pos_y, this->posterPath, this->title, this->year, this->director, this->leads, this->category);
	}
};

class data {
private:
	std::string avatarleads[3] = { "Sam Worthington", "Zoe Saladana", "Sigourney Weaver" };
	std::string avatarcategory[3] = { "action", "adventure", "fantasy" };
	std::string pulpleads[3] = { "John Travolta", "Uma Thurman", "Samuel L. Jackson" };
	std::string pulpcategory[3] = { "crime", "drama", "" };
	std::string rockyleads[3] = { "Tim Curry", "Susan Sarandon", "Barry Bostwick" };
	std::string rockycategory[3] = { "comedy", "horror", "musical" };
	std::string nightleads[3] = { "Ruth Cracknell", "John Frawley", "Kerry Walker" };
	std::string nightcategory[3] = { "drama", "comedy", "" };
	std::string hunger1leads[3] = { "Jennifer Lawrence", "Josh Hutcherson", "Liam Hemsworth" };
	std::string hunger1category[3] = { "action", "adventure", "sci-fi" };

public:

	movie movieList[7];

	data() {
		movieList[0] = movie((std::string)("avatarTheWayOfWater.png"), (std::string)("Avatar:The Way Of Water"), 2022, (std::string)("James Cameron"), avatarleads, avatarcategory);
		movieList[1] = movie((std::string)("avatar.png"), (std::string)("Avatar"), 2009, (std::string)("James Cameron"), avatarleads, avatarcategory);
		movieList[2] = movie((std::string)("pulpFiction.png"), (std::string)("Pulp Fiction"), 1994, (std::string)("Quentin Tarantino"), pulpleads, pulpcategory);
		movieList[3] = movie((std::string)("rockyHorror.png"), (std::string)("The Rocky Horror Picture Show"), 1975, (std::string)("Jim Sharman"), rockyleads, rockycategory);
		movieList[4] = movie((std::string)("theNight.png"), (std::string)("The Night, the Prowler"), 1978, (std::string)("Jim Sharman"), nightleads, nightcategory);
		movieList[5] = movie((std::string)("hungerGames1.png"), (std::string)("The Hunger Games"), 2012, (std::string)("Gary Ross"), hunger1leads, hunger1category);
		movieList[6] = movie((std::string)("hungerGames2.png"), (std::string)("The Hunger Games: Catching Fire"), 2013, (std::string)("Francis Lawrence"), hunger1leads, hunger1category);
	}

	~data() {}
};