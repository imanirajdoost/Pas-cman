
#include "header/controller/LevelController.h"
LevelController::LevelController(): levelIndex{0} {

}

int LevelController::getCurrentLevelIndex() {
    return levelIndex;
}

void LevelController::goToNextLevel() {
    levelIndex++;
}
