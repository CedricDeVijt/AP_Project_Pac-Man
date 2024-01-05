#include "State.h"
#include "../view/Window.h"
#include "../util/Singleton.h"

State::State(StateManager* stateManager) : stateManager(stateManager) {}

void State::centerHorizontally(sf::Text &title, int posY) {
    const auto window = Singleton<Window>::getInstance().getWindow();
    const int titleWidth = title.getGlobalBounds().width;
    title.setPosition((window->getSize().x - titleWidth) / 2, posY);
}

