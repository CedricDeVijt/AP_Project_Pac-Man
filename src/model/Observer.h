#ifndef AP_PROJECT_PAC_MAN_OBSERVER_H
#define AP_PROJECT_PAC_MAN_OBSERVER_H

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
     */
    virtual void update() = 0;
};

#endif // AP_PROJECT_PAC_MAN_OBSERVER_H
