#pragma once

#include <string>
#include <list>
#include "data.h"

class filter
{
public:

	std::string search = "";
	int year_from = 1900;
	int year_to = 2023;
	std::string title = "";
	std::string director = "";
	std::string lead = "";
	std::list<std::string> categories;


	filter();
	~filter();
	void addCategory(std::string cat);
	void removeCategory(std::string cat);
	void setLead(std::string lead);
	void removeLead();
	void setDirector(std::string director);
	void removeDirector();
	void setTitle(std::string title);
	void removeTitle();
	void setYearFrom(int year);
	void removeYearFrom();
	void setYearTo(int year);
	void removeYearTo();
	void setSearch(std::string search);
	void removeAllFilters();

	bool filterMovie(movie movie);

};