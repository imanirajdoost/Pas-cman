#include "../include/UIController.h"

UIController::UIController() {
    letter_a = {12, 61, 7, 7};
    letter_b = {20, 61, 7, 7};
    letter_c = {28, 61, 7, 7};
    letter_d = {36, 61, 7, 7};
    letter_e = {44, 61, 7, 7};
    letter_f = {52, 61, 7, 7};
    letter_g = {60, 61, 7, 7};
    letter_h = {68, 61, 7, 7};
    letter_i = {76, 61, 7, 7};
    letter_j = {84, 61, 7, 7};
    letter_k = {92, 61, 7, 7};
    letter_l = {100, 61, 7, 7};
    letter_m = {108, 61, 7, 7};
    letter_n = {116, 61, 7, 7};
    letter_o = {124, 61, 7, 7};
    letter_p = {4, 69, 7, 7};
    letter_q = {12, 69, 7, 7};
    letter_r = {20, 69, 7, 7};
    letter_s = {28, 69, 7, 7};
    letter_t = {36, 69, 7, 7};
    letter_u = {44, 69, 7, 7};
    letter_v = {52, 69, 7, 7};
    letter_w = {60, 69, 7, 7};
    letter_x = {68, 69, 7, 7};
    letter_y = {76, 69, 7, 7};
    letter_z = {84, 69, 7, 7};

    digit_0 = {4, 53, 7, 7};
    digit_1 = {12, 53, 7, 7};
    digit_2 = {20, 53, 7, 7};
    digit_3 = {28, 53, 7, 7};
    digit_4 = {36, 53, 7, 7};
    digit_5 = {44, 53, 7, 7};
    digit_6 = {52, 53, 7, 7};
    digit_7 = {60, 53, 7, 7};
    digit_8 = {68, 53, 7, 7};
    digit_9 = {76, 53, 7, 7};

    symbol_Dot = {92, 69, 7, 7};
    symbol_GreaterThan = {100, 69, 7, 7};
    symbol_Dollar = {116, 69, 8, 8};
    symbol_Dash = {84, 53, 7, 7};
    symbol_Slash = {92, 53, 7, 7};
    symbol_Exclamation = {100, 53, 7, 7};
    symbol_Comma = {109, 50, 8, 8};

    createMap();
}

void UIController::createMap() {
    char_map.emplace("a", letter_a);
    char_map.emplace("b", letter_b);
    char_map.emplace("c", letter_c);
    char_map.emplace("d", letter_d);
    char_map.emplace("e", letter_e);
    char_map.emplace("f", letter_f);
    char_map.emplace("g", letter_g);
    char_map.emplace("h", letter_h);
    char_map.emplace("i", letter_i);
    char_map.emplace("j", letter_j);
    char_map.emplace("k", letter_k);
    char_map.emplace("l", letter_l);
    char_map.emplace("m", letter_m);
    char_map.emplace("n", letter_n);
    char_map.emplace("o", letter_o);
    char_map.emplace("p", letter_p);
    char_map.emplace("q", letter_q);
    char_map.emplace("r", letter_r);
    char_map.emplace("s", letter_s);
    char_map.emplace("t", letter_t);
    char_map.emplace("u", letter_u);
    char_map.emplace("v", letter_v);
    char_map.emplace("w", letter_w);
    char_map.emplace("x", letter_x);
    char_map.emplace("y", letter_y);
    char_map.emplace("z", letter_z);

    char_map.emplace("0", digit_0);
    char_map.emplace("1", digit_1);
    char_map.emplace("2", digit_2);
    char_map.emplace("3", digit_3);
    char_map.emplace("4", digit_4);
    char_map.emplace("5", digit_5);
    char_map.emplace("6", digit_6);
    char_map.emplace("7", digit_7);
    char_map.emplace("8", digit_8);
    char_map.emplace("9", digit_9);

    char_map.emplace(".", symbol_Dot);
    char_map.emplace(">", symbol_GreaterThan);
    char_map.emplace("$", symbol_Dollar);
    char_map.emplace("-", symbol_Dash);
    char_map.emplace("/", symbol_Slash);
    char_map.emplace("!", symbol_Exclamation);
    char_map.emplace(",", symbol_Comma);
}

void UIController::writeOnUI(const std::string& id, const std::string &text, int posX, int posY) {
    // Rectangles that draw the text
    std::vector<SDL_Rect> rectsToDraw;

    // Get each character of the text as rect
    for (auto ch: text) {
        rectsToDraw.push_back(char_map.at(std::string{ch}));
    }

    // create a tuple with text string and its rects
    std::tuple<std::string, std::vector<SDL_Rect>> tuple;
    tuple = std::make_tuple(text, rectsToDraw);

    // Add the tuple to the list of things to draw to the screen
    name_txt_maps.emplace(id, tuple);
}

void UIController::drawUI(SDL_Surface *plancheSprites, SDL_Surface *win_surf) {
//    SDL_BlitScaled(plancheSprites, &sprite_in2, win_surf, &drawRect);
    for (auto item : name_txt_maps) {
        auto rects = std::get<1>(std::get<1>(item));
        for (auto rect : rects) {
            SDL_BlitScaled(plancheSprites, &rect, win_surf, &rect);
        }
    }
}
