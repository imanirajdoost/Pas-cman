
#ifndef PAS_CMAN_LEVELCONTROLLER_H
#define PAS_CMAN_LEVELCONTROLLER_H


class LevelController {
public:
    /**
     * Initializes the level controller.
     */
    LevelController();

    /**
     * Returns the current level index.
     * @return the current level index.
     */
    int getCurrentLevelIndex();

    /**
     * Goes to the next level.
     */
    void goToNextLevel();
private:
    int levelIndex;
};


#endif //PAS_CMAN_LEVELCONTROLLER_H
