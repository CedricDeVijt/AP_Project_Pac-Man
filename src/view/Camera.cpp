#include "Camera.h"
#include "../util/Singleton.h"
#include "Window.h"

const double CANVAS_RATIO = 20.0 / 11.0;

bool isHeigthLimited() {
    const auto windowSize = Singleton<Window>::getInstance().getWindow()->getSize();
    return windowSize.x * 720 > windowSize.y * 1200;
}

int toPixelValue(double position, int canvasSize) {
    // move origin [-1, 1] -> [0, 2]
    const double translated_position = position + 1;
    // scale [0, 2] -> [0, canvasSize]
    return translated_position * canvasSize / 2.0;
}

int Camera::getMazeWidth() {
    const auto windowSize = Singleton<Window>::getInstance().getWindow()->getSize();
    const int windowSizeX = windowSize.x;
    const int windowSizeY = windowSize.y;

    if (isHeigthLimited()) {
        // height limited
        return (windowSizeY -80) * CANVAS_RATIO;
    } else {
        // width limited
        return windowSizeX;
    }
}


int Camera::getMazeHeight() {
    const auto windowSize = Singleton<Window>::getInstance().getWindow()->getSize();
    const int windowSizeX = windowSize.x;
    const int windowSizeY = windowSize.y;

    if (isHeigthLimited()) {
        // height limited
        return windowSizeY - 80;
    } else {
        // width limited
        return windowSizeX / CANVAS_RATIO;
    }

}


int Camera::getMazeOffsetX() {
    const auto windowSize = Singleton<Window>::getInstance().getWindow()->getSize();
    const int windowSizeX = windowSize.x;

    if (isHeigthLimited()) {
        // height limited
        return (windowSizeX - getMazeWidth())/2;
    } else {
        // width limited
        return 0;
    }

}


int Camera::getMazeOffsetY() {
    const auto windowSize = Singleton<Window>::getInstance().getWindow()->getSize();
    const int windowSizeY = windowSize.y;

    if (isHeigthLimited()) {
        // height limited
        return 0;
    } else {
        // width limited
        return (int(windowSizeY) - (getMazeHeight() + 80))/2;
    }

}


int Camera::toPixelX(double position) {
    return toPixelValue(position, getMazeWidth()) + getMazeOffsetX();
}

int Camera::toPixelY(double position) {
    return toPixelValue(position, getMazeHeight()) + getMazeOffsetY();
}

std::tuple<int, int, int, int> Camera::toPixelCoordinates(const std::tuple<double, double, double, double>& position) {
    double x, y, sx, sy;
    std::tie(x, y, sx, sy) = position;
    int posX = toPixelX(x);
    int posY = toPixelY(y);

    // TODO
    int size = getMazeWidth() /20;
    return {posX, posY, size, size};
}

//
//int Camera::getGridSize(double position) {
//    return getMazeWidth() / 20
//}

