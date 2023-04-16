#ifndef PAS_CMAN_DATACONTROLLER_H
#define PAS_CMAN_DATACONTROLLER_H

#include <iostream>
#include <fstream>

class DataController {
public:
    DataController();

    /**
     * @brief Saves the given highscore to a file
     * @param highscore The highscore to save
     */
    void saveHighscore(int highscore);

    /**
     * @brief Loads the highscore from a file
     * @return The highscore
     */
    int loadHighscore();

private:
    const std::string HIGH_SCORE_FILE_NAME = "highscore.txt";
};


#endif //PAS_CMAN_DATACONTROLLER_H
