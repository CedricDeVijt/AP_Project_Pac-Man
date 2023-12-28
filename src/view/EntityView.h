#ifndef AP_PROJECT_PAC_MAN_ENTITYVIEW_H
#define AP_PROJECT_PAC_MAN_ENTITYVIEW_H


#include "../model/PacMan.h"
#include "WindowSingleton.h"
#include <SFML/Graphics.hpp>
#include <memory>

using std::shared_ptr;

class EntityView : public Observer {
protected:
    shared_ptr<sf::RenderWindow> window = WindowSingleton::getInstance().getWindow();
};

//class PacManView : public EntityView {
//public:
//    PacManView(shared_ptr<PacMan> pacMan);
//
//private:
//    shared_ptr <PacMan> pacMan;
//};
//
//class GhostView : public EntityView {
//
//};
//
//class CoinView : public EntityView {
//
//};

class WallView : public EntityView {
public:
    WallView(std::tuple<double, double, double, double> position);

    void update() override;

private:
    // TODO pull up to EntityView
    std::tuple<double, double, double, double> position;
};

//class FruitView : public EntityView {
//
//};

#endif //AP_PROJECT_PAC_MAN_ENTITYVIEW_H
