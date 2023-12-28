#ifndef AP_PROJECT_PAC_MAN_PACMAN_H
#define AP_PROJECT_PAC_MAN_PACMAN_H


#include "EntityModel.h"

class PacMan : public EntityModel {
public:
    void goHome();
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();

private:

};


#endif //AP_PROJECT_PAC_MAN_PACMAN_H
