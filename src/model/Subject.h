#ifndef AP_PROJECT_PAC_MAN_SUBJECT_H
#define AP_PROJECT_PAC_MAN_SUBJECT_H

#include <vector>
#include <memory>

#include "Observer.h"

using std::shared_ptr;


class Subject {
public:
    void registerObserver(shared_ptr<Observer> observer);

private:
    std::vector<shared_ptr<Observer>> observers;

protected:
    void notifyObservers();
};


#endif //AP_PROJECT_PAC_MAN_SUBJECT_H
