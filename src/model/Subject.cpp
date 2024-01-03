#include "Subject.h"

void Subject::registerObserver(shared_ptr<Observer> observer) { observers.push_back(observer); }

void Subject::notifyObservers(EventType eventType) {
    for (auto& observer : observers) {
        observer->processEvent(eventType);
    }
}
