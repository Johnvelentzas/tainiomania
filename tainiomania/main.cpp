#include "graphics.h"

// The custom callback function that the library calls 
// to check for and set the current application state.
void update(float ms)
{

}

// The window content drawing function.
void draw()
{

}

int main()
{
    graphics::createWindow(1200, 600, "Hello World");

    graphics::setDrawFunction(draw);
    graphics::setUpdateFunction(update);

    graphics::setCanvasSize(1000, 500);
    graphics::setCanvasScaleMode(graphics::CANVAS_SCALE_FIT);

    graphics::startMessageLoop();

    return 0;
}