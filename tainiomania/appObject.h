#pragma once
/**
* A virtual class every UI element or logic element must inherit.
*/
class appObject {
public:
	virtual void update() = 0;
	virtual void init() = 0;
	virtual ~appObject() {};
};