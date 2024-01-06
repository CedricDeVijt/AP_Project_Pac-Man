#include "EntityView.h"
#include <SFML/Graphics.hpp>

int EntityView::getGridSize() const{
    return window->getSize().x / 20;
}
