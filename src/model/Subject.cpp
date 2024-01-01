#include "Subject.h"

void Subject::registerObserver(shared_ptr<Observer> observer) { observers.push_back(observer); }

void Subject::notifyObservers() {
    for (auto& observer : observers) {
        observer->update();
    }
}
