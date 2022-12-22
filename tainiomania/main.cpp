#include "graphics.h"
#include "tainiomania.h"
#include "Comfig.h"

// The custom callback function that the library calls 
// to check for and set the current application state.
void update(float ms)
{
    tainiomania* app = reinterpret_cast<tainiomania*>(graphics::getUserData());
    app->update();
}

// The window content drawing function.
void draw()
{
    tainiomania* app = reinterpret_cast<tainiomania*>(graphics::getUserData());
    app->draw();
}

int main()
{
    tainiomania app;

    graphics::createWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Tainiomania");

    graphics::setUserData(&app);

    graphics::setDrawFunction(draw);
    graphics::setUpdateFunction(update);

    graphics::setCanvasSize(100, 500);
    graphics::setCanvasScaleMode(graphics::CANVAS_SCALE_FIT);

    graphics::startMessageLoop();

    return 0;
}