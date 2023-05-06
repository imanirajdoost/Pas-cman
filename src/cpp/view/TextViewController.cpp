#include "header/view/TextViewController.h"
#include <iostream>
#include <SDL2/SDL.h>

TextViewController::LetterClassPointer TextViewController::isIdExists(const string &id) {
    for (auto item: name_txt_maps) {
        auto id_target = get<0>(*item);
        if (id_target == id)
            return item;
    }
    return nullptr;
}

void TextViewController::writeOnUI(const string &id, const string &text, int posX, int posY) {

    // Rectangles that drawSprites the text
    vector<shared_ptr<SDL_Rect>> rectsToDraw;

    // Get each character of the text as rect
    for (auto ch: text) {
        rectsToDraw.push_back(make_shared<SDL_Rect>(char_map.at(string{ch})));
    }

    // Check to see if ID already exists
    auto target_tuple = isIdExists(id);

    if (target_tuple != nullptr) {

        // id is found, erase it to replace the content
        auto rects = get<4>(*target_tuple);

        rects.clear();

        get<2>(*target_tuple) = posX;
        get<3>(*target_tuple) = posY;

        get<1>(*target_tuple) = text;

        get<4>(*target_tuple) = rectsToDraw;

    } else {
        // create a tuple with text string and its rects
        target_tuple = make_shared<LetterClass>(make_tuple(id, text, posX, posY, rectsToDraw));

        name_txt_maps.push_back(target_tuple);
    }
}

void TextViewController::setLevelOnUI(int level) {
    writeOnUI(LEVEL_TEXT_DYNAMIC, to_string(level), LEVEL_DYNAMIC_POSX,
              LEVEL_DYNAMIC_POSY);
}

void TextViewController::writeScore(int score) {
    writeOnUI(SCORE_TEXT_DYNAMIC, to_string(score), SCORE_TEXT_DYNAMIC_POSX,
              SCORE_TEXT_DYNAMIC_POSY);
}

void TextViewController::writeHighScore(int score) {
    writeOnUI(HIGH_SCORE_TEXT_DYNAMIC, to_string(score), HIGH_SCORE_TEXT_DYNAMIC_POSX,
              HIGH_SCORE_TEXT_DYNAMIC_POSY);
}

void TextViewController::setHealthUI(short health) {
    health_list.clear();
    for (int i = 0; i < health; ++i) {
        auto rect = make_shared<SDL_Rect>();
        rect->x = HEALTH_POSX + (FONT_SPACE * i);
        rect->y = HEALTH_POSY;
        rect->w = FONT_SIZE;
        rect->h = FONT_SIZE;
        health_list.push_back(rect);
    }
}

TextViewController::TextViewController(shared_ptr<DataController> dController) {
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

    dataController = std::move(dController);

    // Write the score text on the UI
    writeOnUI(SCORE_TEXT_STATIC, "score", SCORE_TEXT_STATIC_POSX, SCORE_TEXT_STATIC_POSY);
    writeScore(0);

    // Write the high score text on the UI
    writeOnUI(HIGH_SCORE_TEXT_STATIC, "highscore", HIGH_SCORE_TEXT_STATIC_POSX, HIGH_SCORE_TEXT_STATIC_POSY);
    writeHighScore(dataController->loadHighscore());

    // Write the level text on the UI
    writeOnUI(LEVEL_TEXT_STATIC, "level", LEVEL_STATIC_POSX, LEVEL_STATIC_POSY);

    setLevelOnUI(1);
}

void TextViewController::setFruitUI(const vector<shared_ptr<SDL_Rect>>& fruit_sp) {
    fruit_list_pos.clear();
    fruit_list_sp = fruit_sp;
    // for each fruit sprite in the vector, add it to the UI
    for (int i = 0; i < fruit_list_sp.size(); ++i) {
        auto rect = make_shared<SDL_Rect>();
        rect->x = FRUIT_POSX + ((FONT_SPACE * 2) * i);
        rect->y = FRUIT_POSY;
        rect->w = FONT_SIZE * 2;
        rect->h = FONT_SIZE * 2;
        fruit_list_pos.push_back(rect);
    }
}

void TextViewController::removeFromUI(const string &id) {
    for (int i = 0; i < name_txt_maps.size(); ++i) {
        auto id_target = get<0>(*name_txt_maps.at(i));
        if (id_target == id) {
            name_txt_maps.erase(name_txt_maps.begin() + i);
            break;
        }
    }
}
