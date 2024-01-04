#include "EntityView.h"
#include "SpriteFactory.h"
#include "Camera.h"
#include <SFML/Graphics.hpp>
#include <iostream>

int EntityView::getGridSize() const { return window->getSize().x / 20; }


