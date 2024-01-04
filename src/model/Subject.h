#ifndef AP_PROJECT_PAC_MAN_SUBJECT_H
#define AP_PROJECT_PAC_MAN_SUBJECT_H

#include <memory>
#include <vector>

#include "Observer.h"

using std::shared_ptr;

/**
 * @class Subject
 * @brief A class representing the subject in the observer pattern.
 */
class Subject {
public:
    virtual ~Subject() = default;
    /**
     * @brief Registers an observer to receive updates from the subject.
     * @param observer The observer to register.
     */
    void registerObserver(const shared_ptr<Observer>& observer);

protected:
    /**
     * @brief Notifies all registered observers.
     */
    void notifyObservers(EventType eventType) const;

private:
    std::vector<shared_ptr<Observer>> observers; ///< List of registered observers.
};

#endif // AP_PROJECT_PAC_MAN_SUBJECT_H
