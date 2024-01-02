#include "Camera.h"
#include "WindowSingleton.h"

int toPixelValue(double position, int canvasSize) {
    // move origin [-1, 1] -> [0, 2]
    double translated_position = position + 1;
    // scale [0, 2] -> [0, canvasSize]
    return translated_position * canvasSize / 2.0;
}

int Camera::toPixelX(double position) {
    auto window = WindowSingleton::getInstance().getWindow();
    int canvasWidth = window->getSize().x;
    return toPixelValue(position, canvasWidth);
}

int Camera::toPixelY(double position) {
    auto window = WindowSingleton::getInstance().getWindow();
    int canvasHeight = window->getSize().x * 11 / 20; // same aspect ratio for a 20 by 11 grid
    return toPixelValue(position, canvasHeight);
}
