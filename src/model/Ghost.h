#ifndef AP_PROJECT_PAC_MAN_GHOST_H
#define AP_PROJECT_PAC_MAN_GHOST_H


#include "EntityModel.h"
#include "Direction.h"
#include <tuple>

enum class GhostType {
    Blinky, Pinky, Inky, Clyde, Fear
};


class Ghost : public EntityModel {
public:
    Ghost(GhostType type, std::tuple<double, double, double, double> homePosition);
    GhostType getType() const;
    void eaten();
    void toFearMode();
    void setTargetPosition(std::tuple<double, double, double, double> position);
    bool isFearMode() const;
    bool isChaseMode() const;
    bool isWaitMode() const;

private:
    GhostType type;
    bool fearMode;
    bool chaseMode;
    bool waitMode;
    bool hasLeftStartingPoint;
    std::tuple<double, double, double, double> homePosition;
    std::tuple<double, double, double, double> pacManPosition;
    Direction direction;

    //double manhattanDistance(std::tuple<double, double, double, double> a, std::tuple<double, double, double, double> b);

};


#endif //AP_PROJECT_PAC_MAN_GHOST_H
