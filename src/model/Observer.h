#ifndef AP_PROJECT_PAC_MAN_OBSERVER_H
#define AP_PROJECT_PAC_MAN_OBSERVER_H

enum EventType { PACMAN_CAPTURES_GHOST, PACMAN_CAPTURES_FRUIT, PACMAN_CAPTURES_COIN, PACMAN_DIES, TICK };

/**
 * @class Observer
 * @brief Represents an observer in the observer design pattern.
 */
class Observer {
public:
    /**
     * @brief Default constructor for the Observer class.
     */
    Observer();

    /**
     * @brief Virtual destructor for the Observer class.
     */
    virtual ~Observer() = default;

    // TODO use Events like EntityModelChanged, EntityModelDestroyed?,
    /**
     * @brief Pure virtual function to be implemented by concrete observers.
     * @details This function is called when the observed subject changes its state.
     * @param eventType The type of event that occurred
     */
    virtual void processEvent(EventType eventType) = 0;
};

#endif // AP_PROJECT_PAC_MAN_OBSERVER_H
