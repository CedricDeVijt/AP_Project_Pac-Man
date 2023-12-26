#ifndef AP_PROJECT_PAC_MAN_OBSERVER_H
#define AP_PROJECT_PAC_MAN_OBSERVER_H


class Observer {
public:
    Observer();

    virtual void update() = 0;

    virtual ~Observer() = default;

};


#endif //AP_PROJECT_PAC_MAN_OBSERVER_H
