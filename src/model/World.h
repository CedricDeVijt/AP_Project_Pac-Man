#ifndef AP_PROJECT_PAC_MAN_WORLD_H
#define AP_PROJECT_PAC_MAN_WORLD_H

#include <memory>
#include <vector>

#include "AbstractFactory.h"
#include "Score.h"
#include "Subject.h"

using std::shared_ptr;

/**
 * @class World
 * @brief Represents the game world containing walls, coins, fruits, ghosts, and PacMan.
 */
class World {
public:
    /**
     * @brief Constructs a World object with the specified parameters.
     * @param factory The factory used to create game entities.
     * @param level The current level of the game.
     * @param score The score object to track the game score and lives remaining.
     */
    explicit World(const shared_ptr<AbstractFactory>& factory, int level, const shared_ptr<Score>& score);

    ~World() = default;

    /**
     * @brief Updates the state of the game world.
     */
    void update();

    /**
     * @brief Sets the target direction for PacMan.
     * @param direction The target direction for PacMan.
     */
    void setDirectionPacMan(const Direction& direction) const;

    /**
     * @brief Checks if the current level is complete.
     * @return True if the level is complete, false otherwise.
     */
    bool isLevelComplete() const;

    /**
     * @brief Checks if all levels are complete.
     * @return True if all levels are complete, false otherwise.
     */
    bool isAllLevelsComplete() const;

    /**
     * @brief Checks if game is over
     * @return True if all lives of pacman are exhausted, false otherwise.
     */
    bool isGameOver() const;

private:
    std::vector<shared_ptr<Wall>> walls;   ///< Vector of walls in the game.
    std::vector<shared_ptr<Coin>> coins;   ///< Vector of coins in the game.
    std::vector<shared_ptr<Fruit>> fruits; ///< Vector of fruits in the game.
    std::vector<shared_ptr<Ghost>> ghosts; ///< Vector of ghosts in the game.
    shared_ptr<PacMan> pacMan;             ///< The PacMan character.
    shared_ptr<Score> score;               ///< The score object to track game score and lives.
    int level;                             ///< The current level of the game.

    /**
     * @brief Gets the possible directions for an entity based on its current position and size.
     * @param entityModel The entity for which to determine possible directions.
     * @param tolerance The tolerance factor for collision detection.
     * @return A vector of possible directions.
     */
    std::vector<Direction> getPossibleDirections(const std::shared_ptr<EntityModel>& entityModel, double tolerance) const;

    /**
     * @brief Collects coins that overlap with PacMan and updates the score.
     * @param coins The vector of collectable items to check for collection.
     */
    void collect(std::vector<std::shared_ptr<Coin>>& coins) const;

    /**
     * @brief Collects fruits that overlap with PacMan, triggers fear mode for ghosts, and updates the score.
     * @param fruits The vector of collectable items to check for collection.
     */
    void collect(std::vector<std::shared_ptr<Fruit>>& fruits) const;
};

#endif // AP_PROJECT_PAC_MAN_WORLD_H
