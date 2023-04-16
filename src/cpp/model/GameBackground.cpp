

#include "header/model/GameBackground.h"
#include "header/GameVars.h"
GameBackground::GameBackground() : StaticGameObject(default_sprites::background_sp_default, default_positions::background_default_pos) {
    setSize(default_positions::background_default_pos.w, default_positions::background_default_pos.h);
    addAnimation("default", {default_sprites::background_sp_default,background_sp2}, 1);
    setAnimation("default");
    stopAnimation();
}
