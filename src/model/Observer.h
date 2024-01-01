#ifndef AP_PROJECT_PAC_MAN_OBSERVER_H
#define AP_PROJECT_PAC_MAN_OBSERVER_H


class Observer {
public:
    Observer();

    // TODO use Events like EntityModelChanged, EntityModelDestroyed?,
    virtual void update() = 0;

    virtual ~Observer() = default;

};


#endif //AP_PROJECT_PAC_MAN_OBSERVER_H
