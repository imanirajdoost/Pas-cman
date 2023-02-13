#include "../include/UIController.h"

int UIController::FONT_SIZE = 16;
int UIController::FONT_SPACE = 22;

SDL_Rect UIController::letter_a = {12, 61, 7, 7};
SDL_Rect UIController::letter_b = {20, 61, 7, 7};
SDL_Rect UIController::letter_c = {28, 61, 7, 7};
SDL_Rect UIController::letter_d = {36, 61, 7, 7};
SDL_Rect UIController::letter_e = {44, 61, 7, 7};
SDL_Rect UIController::letter_f = {52, 61, 7, 7};
SDL_Rect UIController::letter_g = {60, 61, 7, 7};
SDL_Rect UIController::letter_h = {68, 61, 7, 7};
SDL_Rect UIController::letter_i = {76, 61, 7, 7};
SDL_Rect UIController::letter_j = {84, 61, 7, 7};
SDL_Rect UIController::letter_k = {92, 61, 7, 7};
SDL_Rect UIController::letter_l = {100, 61, 7, 7};
SDL_Rect UIController::letter_m = {108, 61, 7, 7};
SDL_Rect UIController::letter_n = {116, 61, 7, 7};
SDL_Rect UIController::letter_o = {124, 61, 7, 7};
SDL_Rect UIController::letter_p = {4, 69, 7, 7};
SDL_Rect UIController::letter_q = {12, 69, 7, 7};
SDL_Rect UIController::letter_r = {20, 69, 7, 7};
SDL_Rect UIController::letter_s = {28, 69, 7, 7};
SDL_Rect UIController::letter_t = {36, 69, 7, 7};
SDL_Rect UIController::letter_u = {44, 69, 7, 7};
SDL_Rect UIController::letter_v = {52, 69, 7, 7};
SDL_Rect UIController::letter_w = {60, 69, 7, 7};
SDL_Rect UIController::letter_x = {68, 69, 7, 7};
SDL_Rect UIController::letter_y = {76, 69, 7, 7};
SDL_Rect UIController::letter_z = {84, 69, 7, 7};

SDL_Rect UIController::digit_0 = {4, 53, 7, 7};
SDL_Rect UIController::digit_1 = {12, 53, 7, 7};
SDL_Rect UIController::digit_2 = {20, 53, 7, 7};
SDL_Rect UIController::digit_3 = {28, 53, 7, 7};
SDL_Rect UIController::digit_4 = {36, 53, 7, 7};
SDL_Rect UIController::digit_5 = {44, 53, 7, 7};
SDL_Rect UIController::digit_6 = {52, 53, 7, 7};
SDL_Rect UIController::digit_7 = {60, 53, 7, 7};
SDL_Rect UIController::digit_8 = {68, 53, 7, 7};
SDL_Rect UIController::digit_9 = {76, 53, 7, 7};

SDL_Rect UIController::symbol_Dot = {92, 69, 7, 7};
SDL_Rect UIController::symbol_GreaterThan = {100, 69, 7, 7};
SDL_Rect UIController::symbol_Dollar = {116, 69, 8, 8};
SDL_Rect UIController::symbol_Dash = {84, 53, 7, 7};
SDL_Rect UIController::symbol_Slash = {92, 53, 7, 7};
SDL_Rect UIController::symbol_Exclamation = {100, 53, 7, 7};
SDL_Rect UIController::symbol_Comma = {109, 50, 8, 8};

std::map<std::string, SDL_Rect> UIController::char_map;
std::map<std::string, std::tuple<std::string, std::vector<SDL_Rect>, int, int>> UIController::name_txt_maps;

std::string UIController::SCORE_TEXT_DYNAMIC = "score_dynamic";
int UIController::SCORE_TEXT_DYNAMIC_POSX = 700;
int UIController::SCORE_TEXT_DYNAMIC_POSY = 50;

void UIController::init() {
    UIController::char_map.emplace("a", letter_a);
    UIController::char_map.emplace("b", letter_b);
    UIController::char_map.emplace("c", letter_c);
    UIController::char_map.emplace("d", letter_d);
    UIController::char_map.emplace("e", letter_e);
    UIController::char_map.emplace("f", letter_f);
    UIController::char_map.emplace("g", letter_g);
    UIController::char_map.emplace("h", letter_h);
    UIController::char_map.emplace("i", letter_i);
    UIController::char_map.emplace("j", letter_j);
    UIController::char_map.emplace("k", letter_k);
    UIController::char_map.emplace("l", letter_l);
    UIController::char_map.emplace("m", letter_m);
    UIController::char_map.emplace("n", letter_n);
    UIController::char_map.emplace("o", letter_o);
    UIController::char_map.emplace("p", letter_p);
    UIController::char_map.emplace("q", letter_q);
    UIController::char_map.emplace("r", letter_r);
    UIController::char_map.emplace("s", letter_s);
    UIController::char_map.emplace("t", letter_t);
    UIController::char_map.emplace("u", letter_u);
    UIController::char_map.emplace("v", letter_v);
    UIController::char_map.emplace("w", letter_w);
    UIController::char_map.emplace("x", letter_x);
    UIController::char_map.emplace("y", letter_y);
    UIController::char_map.emplace("z", letter_z);

    UIController::char_map.emplace("0", digit_0);
    UIController::char_map.emplace("1", digit_1);
    UIController::char_map.emplace("2", digit_2);
    UIController::char_map.emplace("3", digit_3);
    UIController::char_map.emplace("4", digit_4);
    UIController::char_map.emplace("5", digit_5);
    UIController::char_map.emplace("6", digit_6);
    UIController::char_map.emplace("7", digit_7);
    UIController::char_map.emplace("8", digit_8);
    UIController::char_map.emplace("9", digit_9);

    UIController::char_map.emplace(".", symbol_Dot);
    UIController::char_map.emplace(">", symbol_GreaterThan);
    UIController::char_map.emplace("$", symbol_Dollar);
    UIController::char_map.emplace("-", symbol_Dash);
    UIController::char_map.emplace("/", symbol_Slash);
    UIController::char_map.emplace("!", symbol_Exclamation);
    UIController::char_map.emplace(",", symbol_Comma);
}

void UIController::writeOnUI(const std::string &id, const std::string &text, int posX, int posY) {

    // Check to see if ID already exists
    if (UIController::name_txt_maps.find(id) != UIController::name_txt_maps.end()) {
        // id is found, erase it to replace the content
        // @TODO: This can be optimized
        UIController::name_txt_maps.erase(id);
    }

    // Rectangles that draw the text
    std::vector<SDL_Rect> rectsToDraw;

    // Get each character of the text as rect
    for (auto ch: text) {
        rectsToDraw.push_back(UIController::char_map.at(std::string{ch}));
    }

    // create a tuple with text string and its rects
    std::tuple<std::string, std::vector<SDL_Rect>, int, int> tuple;
    tuple = std::make_tuple(text, rectsToDraw, posX, posY);

    // Add the tuple to the list of things to draw to the screen
    UIController::name_txt_maps.emplace(id, tuple);
}

void UIController::drawUI(SDL_Surface *plancheSprites, SDL_Surface *win_surf) {
    for (auto item: UIController::name_txt_maps) {
        auto rects = std::get<1>(std::get<1>(item));
        SDL_Rect posRect;
        posRect.x = std::get<2>(std::get<1>(item));
        posRect.y = std::get<3>(std::get<1>(item));
        posRect.w = UIController::FONT_SIZE;
        posRect.h = UIController::FONT_SIZE;
        for (auto rect: rects) {
            SDL_BlitScaled(plancheSprites, &rect, win_surf, &posRect);
            posRect.x += UIController::FONT_SPACE;
        }
    }
}

void UIController::writeScore(uint score) {
    writeOnUI(UIController::SCORE_TEXT_DYNAMIC, std::to_string(score), UIController::SCORE_TEXT_DYNAMIC_POSX,
              UIController::SCORE_TEXT_DYNAMIC_POSY);
}
