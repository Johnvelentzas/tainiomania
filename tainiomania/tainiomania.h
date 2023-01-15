#pragma once

#include "filter.h"
/** tainiomania
* The app's main class that manages all the ui and logic elements.
*/
class tainiomania {
public:
	static filter* getFilter();
	void update();
	void draw();
	static float getScroll();
	tainiomania();
	~tainiomania();
};