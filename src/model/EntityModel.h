#ifndef AP_PROJECT_PAC_MAN_ENTITYMODEL_H
#define AP_PROJECT_PAC_MAN_ENTITYMODEL_H

#include "Subject.h"
#include "Direction.h"
#include <tuple>

static const double SPEED = 2.0 / 4000000; // full screen = [-1 1] in 4 seconds (expressed as microseconds)

class EntityModel : public Subject {
public:
    explicit EntityModel(std::tuple<double, double, double, double> position);
    std::tuple<double, double, double, double> getPosition();
    bool overlapsWith(shared_ptr<EntityModel> entityModel);
    bool overlapsWith(shared_ptr<EntityModel> entityModel, double percentage);
    virtual void update();

protected:
    std::tuple<double, double, double, double> position;
    void nudgeToGrid();

//double manhattanDistance(std::tuple<double, double, double, double> a, std::tuple<double, double, double, double> b);
std::tuple<double, double, double, double> step(Direction direction, std::tuple<double, double, double, double> &startPosition);
};

#endif //AP_PROJECT_PAC_MAN_ENTITYMODEL_H
