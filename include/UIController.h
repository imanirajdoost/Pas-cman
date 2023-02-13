#ifndef PAS_CMAN_UICONTROLLER_H
#define PAS_CMAN_UICONTROLLER_H

#include <SDL2/SDL_rect.h>
#include <string>
#include <map>
#include <SDL2/SDL_surface.h>
#include <vector>
#include <tuple>

class UIController {
public:
    UIController();

    void drawUI(SDL_Surface *plancheSprites, SDL_Surface *win_surf);

    void writeOnUI(const std::string& id, const std::string &text, int posX, int posY);

private:
    SDL_Rect letter_a{};
    SDL_Rect letter_b{};
    SDL_Rect letter_c{};
    SDL_Rect letter_d{};
    SDL_Rect letter_e{};
    SDL_Rect letter_f{};
    SDL_Rect letter_g{};
    SDL_Rect letter_h{};
    SDL_Rect letter_i{};
    SDL_Rect letter_j{};
    SDL_Rect letter_k{};
    SDL_Rect letter_l{};
    SDL_Rect letter_m{};
    SDL_Rect letter_n{};
    SDL_Rect letter_o{};
    SDL_Rect letter_p{};
    SDL_Rect letter_q{};
    SDL_Rect letter_r{};
    SDL_Rect letter_s{};
    SDL_Rect letter_t{};
    SDL_Rect letter_u{};
    SDL_Rect letter_v{};
    SDL_Rect letter_w{};
    SDL_Rect letter_x{};
    SDL_Rect letter_y{};
    SDL_Rect letter_z{};

    SDL_Rect symbol_Dot{};
    SDL_Rect symbol_GreaterThan{};
    SDL_Rect symbol_Dollar{};

    SDL_Rect digit_0{};
    SDL_Rect digit_1{};
    SDL_Rect digit_2{};
    SDL_Rect digit_3{};
    SDL_Rect digit_4{};
    SDL_Rect digit_5{};
    SDL_Rect digit_6{};
    SDL_Rect digit_7{};
    SDL_Rect digit_8{};
    SDL_Rect digit_9{};

    SDL_Rect symbol_Dash{};
    SDL_Rect symbol_Slash{};
    SDL_Rect symbol_Exclamation{};
    SDL_Rect symbol_Comma{};

    std::map<std::string, SDL_Rect> char_map;
    std::map<std::string, std::tuple<std::string, std::vector<SDL_Rect>>> name_txt_maps{};

    void createMap();
};

#endif //PAS_CMAN_UICONTROLLER_H
