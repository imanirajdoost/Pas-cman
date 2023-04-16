/**
@file SDLViewController.h
@brief Header file for SDLViewController class, which manages connections to SDL library
to manage the view and draw the sprites on the screen.
*/

#ifndef PAS_CMAN_SDLVIEWCONTROLLER_H
#define PAS_CMAN_SDLVIEWCONTROLLER_H

#include <list>
#include "header/model/GameObject.h"
#include "header/controller/DotController.h"
#include "header/controller/FruitController.h"
#include "header/view/TextViewController.h"

/**
@brief Class to manage connections to SDL library and manage the view.
*/
class SDLViewController {
public:
    /**
@brief Constructor for SDLViewController class.
@param sps Shared pointer to a list of GameObjects.
@param tViewController Shared pointer to TextViewController object.
@param dController Shared pointer to DotController object.
@param fController Shared pointer to FruitController object.
@param pController Shared pointer to PauseController object.
*/
    SDLViewController(shared_ptr<std::list<shared_ptr<GameObject>>> sps,
                      shared_ptr<TextViewController> tViewController, shared_ptr<DotController>
                      dController,
                      shared_ptr<FruitController> fController, shared_ptr<PauseController> pController
    );

    /**

@brief Tick function to manage game update.
*/
    void tick();

    /**
@brief Function to draw sprites on the screen.
*/
    void drawSprites();

    /**
@brief Function to draw user interface on the screen.
*/
    void drawUI();

    /**
@brief Function to draw dots on the screen.
*/
    void drawDots();

    /**
@brief Function to draw fruit on the screen.
*/
    void drawFruit();

    /**

@brief Function to draw debug objects on the screen.
@param debugList List of shared pointers to GameObjects for which debug objects are to be drawn.
*/
    void drawDebug(const std::list<shared_ptr<GameObject>> &debugList);

private:
    SDL_Window *pWindow = nullptr; ///< SDL window pointer.
    SDL_Surface *win_surf = nullptr; ///< SDL surface pointer to the window surface.
    SDL_Surface *plancheSprites = nullptr; ///< SDL surface pointer to the sprite sheet.
    SDL_Renderer *renderer = nullptr; ///< SDL renderer pointer.

    SDL_Rect playerHealth = {169, 76, 10, 12}; ///< Sprite rectangle for the player's health.

    shared_ptr<DotController> dotController; ///< Shared pointer to the DotController.
    shared_ptr<FruitController> fruitController; ///< Shared pointer to the FruitController.
    shared_ptr<TextViewController> textViewController; ///< Shared pointer to the TextViewController.
    shared_ptr<PauseController> pauseController; ///< Shared pointer to the PauseController.
    shared_ptr<std::list<shared_ptr<GameObject>>> spritesToDraw; ///< List of shared pointers to all the sprites to be drawn.

    /**
@brief Function to draw collider for a game object.
@param obj GameObject for which collider is to be drawn.
@param r Red color value for collider.
@param g Green color value for collider.
@param b Blue color value for collider.
*/
    void draw_collider(const GameObject &obj, int r, int g, int b);

    /**
@brief Function to draw grid on the screen.
@param r Red color value for grid.
@param g Green color value for grid.
@param b Blue color value for grid.
*/
    void draw_grid(int r, int g, int b);

    /**

@brief Function to draw target sprite on the screen.
@param spriteToDraw SDL_Rect for sprite to be drawn.
@param drawRect SDL_Rect for where the sprite should be drawn.
*/
    void drawTarget(SDL_Rect *spriteToDraw, SDL_Rect *drawRect);
};


#endif //PAS_CMAN_SDLVIEWCONTROLLER_H
