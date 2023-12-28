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
    std::cout << "CoinView::update() Coinview was updated\n";
    // TODO do this properly using camera
    double x, y, size_x, size_y;
    std::tie(x, y, size_x, size_y) = position;
    std::cout << "Creating coin at " << x <<", " << y <<"\n";
    std::cout << "New position at " << 30*20 *(x+1) <<", " << 30*11 * (y+1) <<"\n";

//    sf::RectangleShape rectangle(sf::Vector2f(64, 64));
    sf::RectangleShape rectangle(sf::Vector2f(60, 60));
    // Set the position of the rectangle
//    rectangle.setPosition(600*(x+1), 400*(y+1));
    rectangle.setPosition(30*20*(x+1), 30*11*(y+1));
    // Set the color of the rectangle (optional)
    rectangle.setFillColor(sf::Color::Yellow);
    window->draw(rectangle);
}

FruitView::FruitView(std::tuple<double, double, double, double> position) : position(position){
}

void FruitView::update() {
    std::cout << "FruitView::update() Fruitview was updated\n";
    // TODO do this properly using camera
    double x, y, size_x, size_y;
    std::tie(x, y, size_x, size_y) = position;
    std::cout << "Creating fruit at " << x <<", " << y <<"\n";
    std::cout << "New position at " << 30*20 *(x+1) <<", " << 30*11 * (y+1) <<"\n";

//    sf::RectangleShape rectangle(sf::Vector2f(64, 64));
    sf::RectangleShape rectangle(sf::Vector2f(60, 60));
    // Set the position of the rectangle
//    rectangle.setPosition(600*(x+1), 400*(y+1));
    rectangle.setPosition(30*20*(x+1), 30*11*(y+1));
    // Set the color of the rectangle (optional)
    rectangle.setFillColor(sf::Color::Red);
    window->draw(rectangle);
}