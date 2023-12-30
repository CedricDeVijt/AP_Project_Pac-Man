#ifndef AP_PROJECT_PAC_MAN_ENTITYVIEW_H
#define AP_PROJECT_PAC_MAN_ENTITYVIEW_H

#include <memory>
#include <SFML/Graphics.hpp>

#include "../model/Collectable.h"
#include "../model/PacMan.h"
#include "../model/Ghost.h"
#include "../model/Wall.h"
#include "WindowSingleton.h"
#include "SpriteFactory.h"

using std::shared_ptr;

class EntityView : public Observer {
protected:
    shared_ptr<sf::RenderWindow> window = WindowSingleton::getInstance().getWindow();
    SpriteFactory &spriteFactory = SpriteFactory::getInstance();
    int toPixelX(double position);
    int toPixelY(double position);
    int getGridSize() const;
};

class PacManView : public EntityView {
public:
    PacManView(shared_ptr<PacMan> pacMan);
    void update() override ;
private:
    shared_ptr<PacMan> pacMan;
};


class GhostView : public EntityView {
public:
    GhostView(shared_ptr<Ghost> ghost);
    void update() override ;
private:
    shared_ptr<Ghost> ghost;

};

class CoinView : public EntityView {
public:
    CoinView(shared_ptr<Coin> coin);
    void update() override ;
private:
    shared_ptr<Coin> coin;
};

class WallView : public EntityView {
public:
    WallView(shared_ptr <Wall> wall);
    void update() override;

private:
    shared_ptr<Wall> wall;
};

class FruitView : public EntityView {
public:
    FruitView(shared_ptr<Fruit> fruit);
    void update() override;
private:
    shared_ptr<Fruit> fruit;
};

#endif //AP_PROJECT_PAC_MAN_ENTITYVIEW_H
