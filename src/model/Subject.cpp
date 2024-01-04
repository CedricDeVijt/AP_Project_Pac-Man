#include "Subject.h"

void Subject::registerObserver(const shared_ptr<Observer>& observer) { observers.push_back(observer); }

void Subject::notifyObservers(EventType eventType) const {
    for (const auto& observer : observers) {
        observer->processEvent(eventType);
    }
}
