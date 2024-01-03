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

std::tuple<int, int> Camera::toPixelCoordinates(std::tuple<double, double, double, double> position) {
    double x, y;
    std::tie(x, y, std::ignore, std::ignore) = position;
    int posX = toPixelX(x);
    int posY = toPixelY(y);

    return {posX, posY};
}
