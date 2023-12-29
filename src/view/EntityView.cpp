#include "EntityView.h"
#include "SpriteFactory.h"
#include <iostream>
#include <SFML/Graphics.hpp>

//PacManView::PacManView(shared_ptr<PacMan> pacMan) {
//
//}

WallView::WallView(std::tuple<double, double, double, double> position) : position(position){
}

void WallView::update() {
//    std::cout << "WallView::update() Wallview was updated\n";
    // TODO do this properly using camera
    double x, y, size_x, size_y;
    std::tie(x, y, size_x, size_y) = position;
//    std::cout << "Creating wall at " << x <<", " << y <<"\n";
//    std::cout << "New position at " << 30*20 *(x+1) <<", " << 30*11 * (y+1) <<"\n";

//    sf::RectangleShape rectangle(sf::Vector2f(64, 64));
    sf::RectangleShape rectangle(sf::Vector2f(60, 60));
    // Set the position of the rectangle
//    rectangle.setPosition(600*(x+1), 400*(y+1));
    rectangle.setPosition(30*20*(x+1), 30*11*(y+1));
    // Set the color of the rectangle (optional)
    rectangle.setFillColor(sf::Color::Blue);
    window->draw(rectangle);
}

CoinView::CoinView(std::tuple<double, double, double, double> position) : position(position){
}

void CoinView::update() {
//    std::cout << "CoinView::update() Coinview was updated\n";
    // TODO do this properly using camera
    double x, y, size_x, size_y;
    std::tie(x, y, size_x, size_y) = position;
//    std::cout << "Creating coin at " << x <<", " << y <<"\n";
//    std::cout << "New position at " << 30*20 *(x+1) <<", " << 30*11 * (y+1) <<"\n";

    sf::Vector2f scale = sf::Vector2f(1.5, 1.5);
    sf::Sprite sprite = SpriteFactory::getInstance().createCoin(30*20*(x+1), 30*11*(y+1), scale);
    window->draw(sprite);
}

FruitView::FruitView(std::tuple<double, double, double, double> position) : position(position){
}

void FruitView::update() {
//    std::cout << "FruitView::update() Fruitview was updated\n";
    // TODO do this properly using camera
    double x, y, size_x, size_y;
    std::tie(x, y, size_x, size_y) = position;
//    std::cout << "Creating fruit at " << x <<", " << y <<"\n";
//    std::cout << "New position at " << 30*20 *(x+1) <<", " << 30*11 * (y+1) <<"\n";

    sf::Vector2f scale = sf::Vector2f(1.5, 1.5);
    sf::Sprite sprite = SpriteFactory::getInstance().createFruit(0, 30*20*(x+1), 30*11*(y+1), scale);
    window->draw(sprite);
}

GhostView::GhostView(GhostType type, std::tuple<double, double, double, double> homePosition) : type(type), homePosition(homePosition), position(homePosition) {
}

void GhostView::update() {
//    std::cout << "GhostView::update() Ghostview was updated\n";
    // TODO do this properly using camera
    double x, y, size_x, size_y;
    std::tie(x, y, size_x, size_y) = position;
//    std::cout << "Creating ghost at " << x <<", " << y <<"\n";
//    std::cout << "New position at " << 30*20 *(x+1) <<", " << 30*11 * (y+1) <<"\n";

    sf::Vector2f scale = sf::Vector2f(1.5, 1.5);
    sf::Sprite sprite = SpriteFactory::getInstance().createGhost(type, 0, 30*20*(x+1), 30*11*(y+1), scale);
    window->draw(sprite);
}

PacManView::PacManView(shared_ptr<PacMan> pacMan) : pacMan(pacMan) {
}

void PacManView::update() {
//    std::cout << "PacManView::update() PacManview was updated\n";
    // TODO do this properly using camera
    double x, y, size_x, size_y;
    std::tie(x, y, size_x, size_y) = pacMan->getPosition();
//    std::cout << "Creating pacMan at " << x <<", " << y <<"\n";
//    std::cout << "New position at " << 30*20 *(x+1) <<", " << 30*11 * (y+1) <<"\n";

    sf::Vector2f scale = sf::Vector2f(1.5, 1.5);
    sf::Sprite sprite;

    switch (pacMan->getDirection()){
        case Direction::UP:
            sprite = SpriteFactory::getInstance().createPacMan(10, 30*20*(x+1), 30*11*(y+1), scale);
            break;
        case Direction::DOWN:
            sprite = SpriteFactory::getInstance().createPacMan(4, 30*20*(x+1), 30*11*(y+1), scale);
            break;
        case Direction::LEFT:
            sprite = SpriteFactory::getInstance().createPacMan(7, 30*20*(x+1), 30*11*(y+1), scale);
            break;
        case Direction::RIGHT:
//            sprite = SpriteFactory::getInstance().createPacMan(1, 30*20*(x+1), 30*11*(y+1), scale);
////            break;
        case Direction::NONE:
            sprite = SpriteFactory::getInstance().createPacMan(1, 30*20*(x+1), 30*11*(y+1), scale);
            break;
    }


    window->draw(sprite);
}
