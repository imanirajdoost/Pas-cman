#ifndef PAS_CMAN_DATACONTROLLER_H
#define PAS_CMAN_DATACONTROLLER_H

#include <iostream>
#include <fstream>

class DataController {
public:
    DataController();

    void saveHighscore(int highscore);

    int loadHighscore();

private:
    const std::string HIGH_SCORE_FILE_NAME = "highscore.txt";
};


#endif //PAS_CMAN_DATACONTROLLER_H
