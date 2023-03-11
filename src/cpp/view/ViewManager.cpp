#include <iostream>
#include "../../header/view/ViewManager.h"

int ViewManager::FONT_SIZE = 16;
int ViewManager::FONT_SPACE = 22;

SDL_Rect ViewManager::letter_a = {12, 61, 7, 7};
SDL_Rect ViewManager::letter_b = {20, 61, 7, 7};
SDL_Rect ViewManager::letter_c = {28, 61, 7, 7};
SDL_Rect ViewManager::letter_d = {36, 61, 7, 7};
SDL_Rect ViewManager::letter_e = {44, 61, 7, 7};
SDL_Rect ViewManager::letter_f = {52, 61, 7, 7};
SDL_Rect ViewManager::letter_g = {60, 61, 7, 7};
SDL_Rect ViewManager::letter_h = {68, 61, 7, 7};
SDL_Rect ViewManager::letter_i = {76, 61, 7, 7};
SDL_Rect ViewManager::letter_j = {84, 61, 7, 7};
SDL_Rect ViewManager::letter_k = {92, 61, 7, 7};
SDL_Rect ViewManager::letter_l = {100, 61, 7, 7};
SDL_Rect ViewManager::letter_m = {108, 61, 7, 7};
SDL_Rect ViewManager::letter_n = {116, 61, 7, 7};
SDL_Rect ViewManager::letter_o = {124, 61, 7, 7};
SDL_Rect ViewManager::letter_p = {4, 69, 7, 7};
SDL_Rect ViewManager::letter_q = {12, 69, 7, 7};
SDL_Rect ViewManager::letter_r = {20, 69, 7, 7};
SDL_Rect ViewManager::letter_s = {28, 69, 7, 7};
SDL_Rect ViewManager::letter_t = {36, 69, 7, 7};
SDL_Rect ViewManager::letter_u = {44, 69, 7, 7};
SDL_Rect ViewManager::letter_v = {52, 69, 7, 7};
SDL_Rect ViewManager::letter_w = {60, 69, 7, 7};
SDL_Rect ViewManager::letter_x = {68, 69, 7, 7};
SDL_Rect ViewManager::letter_y = {76, 69, 7, 7};
SDL_Rect ViewManager::letter_z = {84, 69, 7, 7};

SDL_Rect ViewManager::digit_0 = {4, 53, 7, 7};
SDL_Rect ViewManager::digit_1 = {12, 53, 7, 7};
SDL_Rect ViewManager::digit_2 = {20, 53, 7, 7};
SDL_Rect ViewManager::digit_3 = {28, 53, 7, 7};
SDL_Rect ViewManager::digit_4 = {36, 53, 7, 7};
SDL_Rect ViewManager::digit_5 = {44, 53, 7, 7};
SDL_Rect ViewManager::digit_6 = {52, 53, 7, 7};
SDL_Rect ViewManager::digit_7 = {60, 53, 7, 7};
SDL_Rect ViewManager::digit_8 = {68, 53, 7, 7};
SDL_Rect ViewManager::digit_9 = {76, 53, 7, 7};

SDL_Rect ViewManager::symbol_Dot = {92, 69, 7, 7};
SDL_Rect ViewManager::symbol_GreaterThan = {100, 69, 7, 7};
SDL_Rect ViewManager::symbol_Dollar = {116, 69, 8, 8};
SDL_Rect ViewManager::symbol_Dash = {84, 53, 7, 7};
SDL_Rect ViewManager::symbol_Slash = {92, 53, 7, 7};
SDL_Rect ViewManager::symbol_Exclamation = {100, 53, 7, 7};
SDL_Rect ViewManager::symbol_Comma = {109, 50, 8, 8};

SDL_Rect ViewManager::playerHealth = {169, 76, 10, 12};

map<string, SDL_Rect> ViewManager::char_map;
vector<shared_ptr<tuple<string, string, int, int, vector<shared_ptr<SDL_Rect>>>>> ViewManager::name_txt_maps;
vector<shared_ptr<SDL_Rect>> ViewManager::health_list;

string ViewManager::SCORE_TEXT_DYNAMIC = "score_dynamic";
int ViewManager::SCORE_TEXT_DYNAMIC_POSX = 700;
int ViewManager::SCORE_TEXT_DYNAMIC_POSY = 50;

int ViewManager::HEALTH_POSX = 700;
int ViewManager::HEALTH_POSY = 100;

void ViewManager::init() {
    ViewManager::char_map.emplace("a", letter_a);
    ViewManager::char_map.emplace("b", letter_b);
    ViewManager::char_map.emplace("c", letter_c);
    ViewManager::char_map.emplace("d", letter_d);
    ViewManager::char_map.emplace("e", letter_e);
    ViewManager::char_map.emplace("f", letter_f);
    ViewManager::char_map.emplace("g", letter_g);
    ViewManager::char_map.emplace("h", letter_h);
    ViewManager::char_map.emplace("i", letter_i);
    ViewManager::char_map.emplace("j", letter_j);
    ViewManager::char_map.emplace("k", letter_k);
    ViewManager::char_map.emplace("l", letter_l);
    ViewManager::char_map.emplace("m", letter_m);
    ViewManager::char_map.emplace("n", letter_n);
    ViewManager::char_map.emplace("o", letter_o);
    ViewManager::char_map.emplace("p", letter_p);
    ViewManager::char_map.emplace("q", letter_q);
    ViewManager::char_map.emplace("r", letter_r);
    ViewManager::char_map.emplace("s", letter_s);
    ViewManager::char_map.emplace("t", letter_t);
    ViewManager::char_map.emplace("u", letter_u);
    ViewManager::char_map.emplace("v", letter_v);
    ViewManager::char_map.emplace("w", letter_w);
    ViewManager::char_map.emplace("x", letter_x);
    ViewManager::char_map.emplace("y", letter_y);
    ViewManager::char_map.emplace("z", letter_z);

    ViewManager::char_map.emplace("0", digit_0);
    ViewManager::char_map.emplace("1", digit_1);
    ViewManager::char_map.emplace("2", digit_2);
    ViewManager::char_map.emplace("3", digit_3);
    ViewManager::char_map.emplace("4", digit_4);
    ViewManager::char_map.emplace("5", digit_5);
    ViewManager::char_map.emplace("6", digit_6);
    ViewManager::char_map.emplace("7", digit_7);
    ViewManager::char_map.emplace("8", digit_8);
    ViewManager::char_map.emplace("9", digit_9);

    ViewManager::char_map.emplace(".", symbol_Dot);
    ViewManager::char_map.emplace(">", symbol_GreaterThan);
    ViewManager::char_map.emplace("$", symbol_Dollar);
    ViewManager::char_map.emplace("-", symbol_Dash);
    ViewManager::char_map.emplace("/", symbol_Slash);
    ViewManager::char_map.emplace("!", symbol_Exclamation);
    ViewManager::char_map.emplace(",", symbol_Comma);
}

shared_ptr<tuple<string, string, int, int, vector<shared_ptr<SDL_Rect>>>> ViewManager::isIdExists(const string &id) {
    for (auto item: name_txt_maps) {
        auto id_target = get<0>(*item);
        if (id_target == id)
            return item;
    }
    return nullptr;
}

void ViewManager::writeOnUI(const string &id, const string &text, int posX, int posY) {

    // Rectangles that draw the text
    vector<shared_ptr<SDL_Rect>> rectsToDraw;

    // Get each character of the text as rect
    for (auto ch: text) {
        rectsToDraw.push_back(make_shared<SDL_Rect>(ViewManager::char_map.at(string{ch})));
    }

    // Check to see if ID already exists
    auto target_tuple = isIdExists(id);
//    shared_ptr<tuple<string, string, int, int, shared_ptr<vector<SDL_Rect>>>> target_tuple = nullptr;
    if (target_tuple != nullptr) {

        // id is found, erase it to replace the content
        auto rects = get<4>(*target_tuple);

        rects.clear();

        get<2>(*target_tuple) = posX;
        get<3>(*target_tuple) = posY;

        get<1>(*target_tuple) = text;

        get<4>(*target_tuple) = rectsToDraw;
//        ViewManager::name_txt_maps.erase(id);
    } else {
        // create a tuple with text string and its rects
        target_tuple = make_shared<tuple<string, string, int, int, vector<shared_ptr<SDL_Rect>>>>(
                make_tuple(id, text, posX, posY, rectsToDraw));

        ViewManager::name_txt_maps.push_back(target_tuple);
    }

    // Add the tuple to the list of things to draw to the screen
//    if (ViewManager::name_txt_maps.find(id) == ViewManager::name_txt_maps.end())
//    ViewManager::name_txt_maps.emplace(id, tuple);
}

void ViewManager::drawUI(SDL_Surface *plancheSprites, SDL_Surface *win_surf) {
    // Update texts on UI
    for (auto j = ViewManager::name_txt_maps.begin(); j < ViewManager::name_txt_maps.end(); j++) {
        auto rects = get<4>(*j->get());
        SDL_Rect posRect;
        posRect.x = get<2>(*j->get());
        posRect.y = get<3>(*j->get());
        posRect.w = ViewManager::FONT_SIZE;
        posRect.h = ViewManager::FONT_SIZE;

        for (auto it = rects.begin(); it != rects.end(); ++it) {
            SDL_BlitScaled(plancheSprites, it->get(), win_surf, &posRect);
            posRect.x += ViewManager::FONT_SPACE;
        }
    }

    // Update Health on UI
    for (auto i = ViewManager::health_list.begin(); i < ViewManager::health_list.end(); i++) {
        SDL_BlitScaled(plancheSprites, &playerHealth, win_surf, i->get());
    }
}

void ViewManager::writeScore(uint score) {
    writeOnUI(ViewManager::SCORE_TEXT_DYNAMIC, to_string(score), ViewManager::SCORE_TEXT_DYNAMIC_POSX,
              ViewManager::SCORE_TEXT_DYNAMIC_POSY);
}

void ViewManager::setHealthUI(u_short health) {
    ViewManager::health_list.clear();
    for (int i = 0; i < health; ++i) {
        auto rect = make_shared<SDL_Rect>();
        rect->x = HEALTH_POSX + (FONT_SPACE * i);
        rect->y = HEALTH_POSY;
        rect->w = FONT_SIZE;
        rect->h = FONT_SIZE;
        ViewManager::health_list.push_back(rect);
    }
}

void ViewManager::draw(SDL_Surface *plancheSprites, SDL_Surface *win_surf) {

    if (current_sp == nullptr) {
        current_sp = make_shared<SDL_Rect>(default_sp);
    }

//    SDL_Rect sprite_in2 = *current_sp;

    if (isAnimated && current_anim != nullptr && GameController::animationCounter % ANIMATION_FRAME_RATE == 0) {
        const auto &anim_rects = current_anim->getSpritesList();
        if (animation_frame >= anim_rects.size())
            animation_frame = 0;

//        cout << "Anim frame: " << animation_frame << " rects size: " << anim_rects.size() << " anim counter:" << GameController::animationCounter << endl;

        current_sp = make_shared<SDL_Rect>(anim_rects[animation_frame]);
        animation_frame++;
//        sprite_in2.x += 14;
    }

    SDL_Rect drawRect = rect;

    if (rect.w < TILESIZE) {
        drawRect.x += rect.w / 2;
    }

    if (rect.h < TILESIZE) {
        drawRect.y += rect.h / 2;
    }

    SDL_BlitScaled(plancheSprites, current_sp.get(), win_surf, &drawRect);
}