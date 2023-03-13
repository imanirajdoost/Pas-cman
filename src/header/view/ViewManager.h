#ifndef PAS_CMAN_VIEWMANAGER_H
#define PAS_CMAN_VIEWMANAGER_H

#include <memory>
#include <map>
#include <vector>

using namespace std;

class ViewManager {
public:
    static void init();

    static void drawUI(SDL_Surface *plancheSprites, SDL_Surface *win_surf);

    static void writeOnUI(const string &id, const string &text, int posX, int posY);

    static void writeScore(uint score);

    static void setHealthUI(u_short health);

    static string SCORE_TEXT_DYNAMIC;
    static int SCORE_TEXT_DYNAMIC_POSX;
    static int SCORE_TEXT_DYNAMIC_POSY;

    static int HEALTH_POSX;
    static int HEALTH_POSY;

private:
    static SDL_Rect letter_a;
    static SDL_Rect letter_b;
    static SDL_Rect letter_c;
    static SDL_Rect letter_d;
    static SDL_Rect letter_e;
    static SDL_Rect letter_f;
    static SDL_Rect letter_g;
    static SDL_Rect letter_h;
    static SDL_Rect letter_i;
    static SDL_Rect letter_j;
    static SDL_Rect letter_k;
    static SDL_Rect letter_l;
    static SDL_Rect letter_m;
    static SDL_Rect letter_n;
    static SDL_Rect letter_o;
    static SDL_Rect letter_p;
    static SDL_Rect letter_q;
    static SDL_Rect letter_r;
    static SDL_Rect letter_s;
    static SDL_Rect letter_t;
    static SDL_Rect letter_u;
    static SDL_Rect letter_v;
    static SDL_Rect letter_w;
    static SDL_Rect letter_x;
    static SDL_Rect letter_y;
    static SDL_Rect letter_z;
    static SDL_Rect symbol_Dot;
    static SDL_Rect symbol_GreaterThan;
    static SDL_Rect symbol_Dollar;

    static SDL_Rect digit_0;
    static SDL_Rect digit_1;
    static SDL_Rect digit_2;
    static SDL_Rect digit_3;
    static SDL_Rect digit_4;
    static SDL_Rect digit_5;
    static SDL_Rect digit_6;
    static SDL_Rect digit_7;
    static SDL_Rect digit_8;
    static SDL_Rect digit_9;

    static SDL_Rect symbol_Dash;
    static SDL_Rect symbol_Slash;
    static SDL_Rect symbol_Exclamation;
    static SDL_Rect symbol_Comma;

    static SDL_Rect playerHealth;

    static vector<shared_ptr<SDL_Rect>> health_list;
    static map<string, SDL_Rect> char_map;
    static vector<shared_ptr<tuple<string, string, int, int, vector<shared_ptr<SDL_Rect>>>>> name_txt_maps;

    static int FONT_SIZE;
    static int FONT_SPACE;

    static shared_ptr<tuple<string, string, int, int, vector<shared_ptr<SDL_Rect>>>> isIdExists(const string &id);
};

#endif //PAS_CMAN_VIEWMANAGER_H
