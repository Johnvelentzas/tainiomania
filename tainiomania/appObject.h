#pragma once

class appObject {
private:
	float pos_x;
	float pos_y;
public:
	virtual void draw() = 0;
	virtual void update() = 0;
	virtual void init() = 0;
	virtual ~appObject() {};
};