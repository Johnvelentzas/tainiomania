#include "tainiomania.h"
#include "Comfig.h"
#include "avatar.h"

avatar av1(100.f, 150.f);
avatar av2(300.f, 150.f);

void tainiomania::update()
{
}

void tainiomania::draw()
{
	av1.draw();
	av2.draw();
}

tainiomania::tainiomania()
{
}

tainiomania::~tainiomania()
{
}
