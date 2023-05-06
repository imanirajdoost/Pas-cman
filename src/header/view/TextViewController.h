#ifndef PAS_CMAN_TEXTVIEWCONTROLLER_H
#define PAS_CMAN_TEXTVIEWCONTROLLER_H

#include <memory>
#include <map>
#include <vector>
#include <SDL.h>
#include <string>
#include "header/controller/DataController.h"

using namespace std;

/**
 * @brief This class is responsible for managing the text UI elements.
 */
class TextViewController {
public:

    /**
     * @brief Constructs the TextViewController object and initializes all the characters.
     */
    TextViewController(shared_ptr<DataController> dController);

    /**
     * @brief Writes text on the screen at the given position and id.
     * @param id The id of the text to write.
     * @param text The text to write.
     * @param posX The x position to write the text.
     * @param posY The y position to write the text.
     */
    void writeOnUI(const string &id, const string &text, int posX, int posY);

    /**
     * @brief Removes the text with the given id from the screen.
     * @param id The id of the text to remove.
     */
    void removeFromUI(const string &id);

    /**
     * @brief Writes the score on the screen.
     * @param score The score to write.
     */
    void writeScore(int score);

    /**
     * @brief Writes the highscore on the screen.
     * @param score The highscore to write.
     */
    void writeHighScore(int score);

    /**
     * @brief Sets the health UI element to the given value.
     * @param health The health value to set.
     */
    void setHealthUI(short health);

    /**
     * @brief Sets the level UI element to the given value.
     * @param level The level value to set.
     */
    void setLevelOnUI(int level);

    /**
     * @brief Sets the fruit UI element to the given value.
     * @param fruit The fruit value to set.
     */
    void setFruitUI(const vector<shared_ptr<SDL_Rect>>& fruit_sp);

    vector<shared_ptr<tuple<string, string, int, int, vector<shared_ptr<SDL_Rect>>>>> name_txt_maps;
    vector<shared_ptr<SDL_Rect>> health_list;
    vector<shared_ptr<SDL_Rect>> fruit_list_pos;
    vector<shared_ptr<SDL_Rect>> fruit_list_sp;

    const int FONT_SIZE = 16;
    const int FONT_SPACE = 22;

    shared_ptr<DataController> dataController;

private:
    const SDL_Rect letter_a = {12, 61, 7, 7};
    const SDL_Rect letter_b = {20, 61, 7, 7};
    const SDL_Rect letter_c = {28, 61, 7, 7};
    const SDL_Rect letter_d = {36, 61, 7, 7};
    const SDL_Rect letter_e = {44, 61, 7, 7};
    const SDL_Rect letter_f = {52, 61, 7, 7};
    const SDL_Rect letter_g = {60, 61, 7, 7};
    const SDL_Rect letter_h = {68, 61, 7, 7};
    const SDL_Rect letter_i = {76, 61, 7, 7};
    const SDL_Rect letter_j = {84, 61, 7, 7};
    const SDL_Rect letter_k = {92, 61, 7, 7};
    const SDL_Rect letter_l = {100, 61, 7, 7};
    const SDL_Rect letter_m = {108, 61, 7, 7};
    const SDL_Rect letter_n = {116, 61, 7, 7};
    const SDL_Rect letter_o = {124, 61, 7, 7};
    const SDL_Rect letter_p = {4, 69, 7, 7};
    const SDL_Rect letter_q = {12, 69, 7, 7};
    const SDL_Rect letter_r = {20, 69, 7, 7};
    const SDL_Rect letter_s = {28, 69, 7, 7};
    const SDL_Rect letter_t = {36, 69, 7, 7};
    const SDL_Rect letter_u = {44, 69, 7, 7};
    const SDL_Rect letter_v = {52, 69, 7, 7};
    const SDL_Rect letter_w = {60, 69, 7, 7};
    const SDL_Rect letter_x = {68, 69, 7, 7};
    const SDL_Rect letter_y = {76, 69, 7, 7};
    const SDL_Rect letter_z = {84, 69, 7, 7};

    const SDL_Rect digit_0 = {4, 53, 7, 7};
    const SDL_Rect digit_1 = {12, 53, 7, 7};
    const SDL_Rect digit_2 = {20, 53, 7, 7};
    const SDL_Rect digit_3 = {28, 53, 7, 7};
    const SDL_Rect digit_4 = {36, 53, 7, 7};
    const SDL_Rect digit_5 = {44, 53, 7, 7};
    const SDL_Rect digit_6 = {52, 53, 7, 7};
    const SDL_Rect digit_7 = {60, 53, 7, 7};
    const SDL_Rect digit_8 = {68, 53, 7, 7};
    const SDL_Rect digit_9 = {76, 53, 7, 7};
 
    const SDL_Rect symbol_Dot = {92, 69, 7, 7};
    const SDL_Rect symbol_GreaterThan = {100, 69, 7, 7};
    const SDL_Rect symbol_Dollar = {116, 69, 8, 8};
    const SDL_Rect symbol_Dash = {84, 53, 7, 7};
    const SDL_Rect symbol_Slash = {92, 53, 7, 7};
    const SDL_Rect symbol_Exclamation = {100, 53, 7, 7};
    const SDL_Rect symbol_Comma = {109, 50, 8, 8};

    const string SCORE_TEXT_DYNAMIC = "score_dynamic";
    const int SCORE_TEXT_DYNAMIC_POSX = 700;
    const int SCORE_TEXT_DYNAMIC_POSY = 50;

    const string SCORE_TEXT_STATIC = "score_static";
    const int SCORE_TEXT_STATIC_POSX = 700;
    const int SCORE_TEXT_STATIC_POSY = 20;

    const string HIGH_SCORE_TEXT_STATIC = "high_score_static";
    const int HIGH_SCORE_TEXT_STATIC_POSX = 700;
    const int HIGH_SCORE_TEXT_STATIC_POSY = 700;

    const string HIGH_SCORE_TEXT_DYNAMIC = "high_score_dynamic";
    const int HIGH_SCORE_TEXT_DYNAMIC_POSX = 700;
    const int HIGH_SCORE_TEXT_DYNAMIC_POSY = 730;

    const int HEALTH_POSX = 700;
    const int HEALTH_POSY = 100;

    const int FRUIT_POSX = 700;
    const int FRUIT_POSY = 800;

    const string LEVEL_TEXT_STATIC = "level_static";
    const int LEVEL_STATIC_POSX = 700;
    const int LEVEL_STATIC_POSY = 600;

    const string LEVEL_TEXT_DYNAMIC = "level_dynamic";
    const int LEVEL_DYNAMIC_POSX = 700;
    const int LEVEL_DYNAMIC_POSY = 630;

    map<string, SDL_Rect> char_map;

    using LetterClassPointer = shared_ptr<tuple<string, string, int, int, vector<shared_ptr<SDL_Rect>>>>;
    using LetterClass = tuple<string, string, int, int, vector<shared_ptr<SDL_Rect>>>;
    LetterClassPointer isIdExists(const string &id);
};

#endif //PAS_CMAN_TEXTVIEWCONTROLLER_H
