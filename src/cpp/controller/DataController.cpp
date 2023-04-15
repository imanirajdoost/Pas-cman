#include "header/controller/DataController.h"
#include "header/GameVars.h"

DataController::DataController() {

}

void DataController::saveHighscore(int highscore) {
    std::ofstream outputFile(HIGH_SCORE_FILE_NAME);

    if (outputFile.is_open()) {
        outputFile << highscore;
        outputFile.close();
    } else {
        std::cerr << "Unable to open file for writing!" << std::endl;
    }
}

int DataController::loadHighscore() {
    int highscore = 0;
    std::ifstream inputFile(HIGH_SCORE_FILE_NAME);

    if (inputFile.is_open()) {
        inputFile >> highscore;
        inputFile.close();
    } else {
        std::cerr << "Unable to open file for reading!" << std::endl;
    }

    return highscore;
}
