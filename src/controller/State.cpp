#include "State.h"
#include "../util/Singleton.h"
#include "../view/Window.h"

State::State(shared_ptr<StateManager> stateManager) : stateManager(stateManager) {}

void State::centerHorizontally(sf::Text& title, int posY) {
    const auto window = Singleton<Window>::getInstance().getWindow();
    const int titleWidth = title.getGlobalBounds().width;
    title.setPosition((window->getSize().x - titleWidth) / 2, posY);
}
