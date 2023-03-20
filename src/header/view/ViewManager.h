#ifndef PAS_CMAN_VIEWMANAGER_H
#define PAS_CMAN_VIEWMANAGER_H

#include <memory>
#include <map>
#include <vector>
#include <SDL.h>
#include <string>

using namespace std;

class ViewManager {
public:
    ViewManager();

//    void drawUI(SDL_Surface *plancheSprites, SDL_Surface *win_surf);

    void writeOnUI(const string &id, const string &text, int posX, int posY);

    void writeScore(int score);

    void setHealthUI(u_short health);

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

    const SDL_Rect playerHealth = {169, 76, 10, 12};

    const int FONT_SIZE = 16;
    const int FONT_SPACE = 22;

    const string SCORE_TEXT_DYNAMIC = "score_dynamic";
    const int SCORE_TEXT_DYNAMIC_POSX = 700;
    const int SCORE_TEXT_DYNAMIC_POSY = 50;

    const int HEALTH_POSX = 700;
    const int HEALTH_POSY = 100;

    vector<shared_ptr<SDL_Rect>> health_list;
    map<string, SDL_Rect> char_map;
    vector<shared_ptr<tuple<string, string, int, int, vector<shared_ptr<SDL_Rect>>>>> name_txt_maps;

    shared_ptr<tuple<string, string, int, int, vector<shared_ptr<SDL_Rect>>>> isIdExists(const string &id);
};

#endif //PAS_CMAN_VIEWMANAGER_H
