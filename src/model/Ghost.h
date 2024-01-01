#ifndef AP_PROJECT_PAC_MAN_GHOST_H
#define AP_PROJECT_PAC_MAN_GHOST_H


#include "EntityModel.h"
#include "Direction.h"
#include <tuple>
#include <iostream>

enum class GhostType {
    Blinky, Pinky, Inky, Clyde, Fear
};

std::ostream& operator<<(std::ostream& os, const GhostType& ghostType);

class Ghost : public EntityModel {
public:
    Ghost(GhostType type, std::tuple<double, double, double, double> homePosition);
    GhostType getType() const;
    void capturedByPacMan();
    void toFearMode();
    bool isFearMode() const;
    bool isChaseMode() const;
    bool isWaitMode() const;
    void update(const std::vector<Direction> &directions, std::tuple<double, double, double, double> pacManPosition);

private:
    GhostType type;
    bool fearMode;
    bool chaseMode;
    bool waitMode;
    bool hasLeftStartingPoint;
    std::tuple<double, double, double, double> homePosition;
    Direction direction = Direction::NONE;

    // TODO use stopwatch
    int timer = 0;

    bool atCornerOrIntersection(const std::vector <Direction> &possibleDirections) const;

    Direction getDirectionWithMinmumManhattanDistance(const std::vector <Direction> &possibleDirections,
                                                      const std::tuple<double, double, double, double> &pacManPosition);
    Direction getDirectionWithMaximumManhattanDistance(const std::vector <Direction> &possibleDirections,
                                                      const std::tuple<double, double, double, double> &pacManPosition);
    bool atDeadEnd(const std::vector <Direction> &directions)  const;

    };


#endif //AP_PROJECT_PAC_MAN_GHOST_H
