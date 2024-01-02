#ifndef AP_PROJECT_PAC_MAN_ENTITYMODEL_H
#define AP_PROJECT_PAC_MAN_ENTITYMODEL_H

#include "Direction.h"
#include "Subject.h"
#include <tuple>

static const double SPEED = 2.0 / 4000000; // full screen = [-1 1] in 4 seconds (expressed as microseconds)

/**
 * @class EntityModel
 * @brief Represents a generic entity in the game with position and movement functionality.
 */
class EntityModel : public Subject {
public:
    /**
     * @brief Constructor for the EntityModel class.
     * @param position A tuple representing the initial position (x, y, width, height) of the entity.
     */
    explicit EntityModel(std::tuple<double, double, double, double> position);

    /**
     * @brief Gets the current position of the entity.
     * @return A tuple representing the current position (x, y, width, height) of the entity.
     */
    std::tuple<double, double, double, double> getPosition();

    /**
     * @brief Checks if the entity overlaps with another entity.
     * @param entityModel A shared pointer to another entity.
     * @return True if there is an overlap, false otherwise.
     */
    bool overlapsWith(shared_ptr<EntityModel> entityModel);

    /**
     * @brief Checks if the entity overlaps with another entity with a given percentage overlap.
     * @param entityModel A shared pointer to another entity.
     * @param percentage The required percentage overlap.
     * @return True if there is an overlap, false otherwise.
     */
    bool overlapsWith(shared_ptr<EntityModel> entityModel, double percentage);

    /**
     * @brief Updates the entity and notifies observers.
     */
    virtual void update();

protected:
    std::tuple<double, double, double, double> position; ///< The current position (x, y, width, height) of the entity.

    /**
     * @brief Nudges the entity's position to align with the grid.
     */
    void nudgeToGrid();

    /**
     * @brief Calculates the position after taking a step in a given direction.
     * @param direction The direction of the step.
     * @param startPosition A reference to the starting position.
     * @param accelerator The factor that determines the relevant acceleration to take into account
     * @return A tuple representing the new position after the step.
     */
    std::tuple<double, double, double, double> step(Direction direction,
                                                    std::tuple<double, double, double, double>& startPosition, double accelerator);
};

#endif // AP_PROJECT_PAC_MAN_ENTITYMODEL_H
