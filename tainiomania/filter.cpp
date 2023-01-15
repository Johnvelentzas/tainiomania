#include "filter.h"

#include <iostream>

filter::filter()
{
}

filter::~filter()
{
}

void filter::addCategory(std::string cat)
{
	this->categories.push_front(cat);
}

void filter::removeCategory(std::string cat)
{
	this->categories.remove(cat);
}

void filter::setLead(std::string lead)
{
	this->lead = lead;
}

void filter::removeLead()
{
	this->lead = "";
}

void filter::setDirector(std::string director)
{
	this->director = director;
}

void filter::removeDirector()
{
	this->director = "";
}

void filter::setTitle(std::string title)
{
	this->title = title;
}

void filter::removeTitle()
{
	this->title = "";
}

void filter::setYearFrom(int year)
{
	this->year_from = year;
}

void filter::removeYearFrom()
{
	this->year_from = 1900;
}

void filter::setYearTo(int year)
{
	this->year_to = year;
}

void filter::removeYearTo()
{
	this->year_to = 2023;
}

void filter::setSearch(std::string search)
{
	this->search = search;
}

void filter::removeAllFilters()
{
	this->search = "";
	this->year_from = 1900;
	this->year_to = 2023;
	this->title = "";
	this->director = "";
	this->lead = "";
	this->categories.clear();
}

bool filter::filterMovie(movie mov)
{
	if(this->categories.size() > 0) {
		bool temp = false;
		for (std::list<std::string>::iterator it = this->categories.begin(); it != this->categories.end(); ++it) {
			if (mov.category[0] == *it || mov.category[1] == *it || mov.category[2] == *it) {
				temp = true;
				break;
			}
		}
		if (!temp) { 
			return false;
		}
	}
	if (this->lead != "" && mov.leads[0] != this->lead && mov.leads[1] != this->lead && mov.leads[2] != this->lead) {
		return false;
	}
	if (this->director != "" && this->director != mov.director) {
		return false;
	}
	if (this->title != "" && this->title != mov.title) {
		return false;
	}
	if (this->year_from > mov.year || this->year_to < mov.year) {
		return false;
	}
	return true;
}
