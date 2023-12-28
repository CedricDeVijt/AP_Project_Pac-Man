#ifndef AP_PROJECT_PAC_MAN_ENTITYMODEL_H
#define AP_PROJECT_PAC_MAN_ENTITYMODEL_H

#include "Subject.h"

class EntityModel : public Subject {
public:
//    virtual void update();
    std::tuple<double, double, double, double> getPosition();

    bool overlapsWith(EntityModel entityModel);

    void update();

private:
    std::tuple<double, double, double, double> position;
};

#endif //AP_PROJECT_PAC_MAN_ENTITYMODEL_H
