#include <SDL.h>
#include <iostream>

#include "Ghost.h"
#include "Map.h"
#include "CollisionManager.h"
#include "MovableGameObject.h"
#include "Player.h"
#include "GameController.h"
#include "DotSmall.h"

#define DEBUG_MODE 1

SDL_Window* pWindow = nullptr;
SDL_Surface* win_surf = nullptr;
SDL_Surface* plancheSprites = nullptr;
SDL_Renderer* renderer = nullptr;

SDL_Rect src_bg = { 368,3, 168,216 }; // x,y, w,h (0,0) en haut a gauche
SDL_Rect bg = { 0,0, 672,864 }; // ici scale x4

SDL_Rect ghost_r = { 3,123, 14,14 }; 
SDL_Rect ghost_l = { 37,123, 14,14 }; 
SDL_Rect ghost_d = { 105,123, 14,14 }; 
SDL_Rect ghost_u = { 71,123, 14,14 }; 


Blinky blinky{32, 32};
Pinky pinky{64, 32};
Inky inky{96, 32};
Clyde clyde{128, 32};
Player player{32,32,2};

std::vector<shared_ptr<DotSmall>> dotSmalls;

void init()
{
	pWindow = SDL_CreateWindow("PacMan", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 700, 900, SDL_WINDOW_SHOWN);
	win_surf = SDL_GetWindowSurface(pWindow);

    renderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_SOFTWARE);

	plancheSprites = SDL_LoadBMP("./pacman_sprites.bmp");

    auto dots = GameController::spawnDotObjects();
    for (const auto dot : dots) {
        dotSmalls.push_back(dot);
    }
}

void draw_collider(const GameObject& obj, int r = 255, int g = 0, int b = 9) {
    // set renderer color
    SDL_SetRenderDrawColor(renderer, r, g, b, 255);
    //SDL_RenderClear( renderer );
    SDL_Rect debugRect = obj.getRect();
    // Render rect
    SDL_RenderDrawRect(renderer, &debugRect);
    // Render the rect to the screen
    SDL_RenderPresent(renderer);
}

// fonction qui met à jour la surface de la fenetre "win_surf"
void draw()
{
    SDL_SetColorKey(plancheSprites, false, 0);
    SDL_BlitScaled(plancheSprites, &src_bg, win_surf, &bg);

    // couleur transparente
    SDL_SetColorKey(plancheSprites, true, 0);
    // copie du sprite zoomé
    blinky.draw(plancheSprites, win_surf);
    pinky.draw(plancheSprites, win_surf);
    inky.draw(plancheSprites, win_surf);
    clyde.draw(plancheSprites, win_surf);

    player.draw(plancheSprites, win_surf);

    for (auto & dotSmall : dotSmalls) {
        dotSmall->draw(plancheSprites, win_surf);
    }

    if(DEBUG_MODE) {
        // Draw the collider boxes on the screen
        draw_collider(player);
        draw_collider(blinky);
        draw_collider(pinky);
        draw_collider(inky);
        draw_collider(clyde);

//        for (auto & dotSmall : dotSmalls) {
//            draw_collider(*dotSmall);
//        }
    }
}

int main(int argc, char** argv)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0 )
    {
		std::cerr <<"Echec de l'initialisation de la SDL "<<SDL_GetError() << std::endl;
		return 1;
    }

	init();



    // BOUCLE PRINCIPALE
	bool quit = false;
	while (!quit)
	{
        GameController::animationCounter++;
        
		SDL_Event event;
		while (!quit && SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				quit = true;
				break;
			default: break;
			}
		}

        MoveDirection nextPlayerMove = player.getMoveDirection();

        // Gestion du clavier        
        int nbk;
        const Uint8* keys = SDL_GetKeyboardState(&nbk);
        if (keys[SDL_SCANCODE_ESCAPE])
            quit = true;
        if (keys[SDL_SCANCODE_LEFT])
            nextPlayerMove = MoveDirection::LEFT;
        else if (keys[SDL_SCANCODE_RIGHT])
            nextPlayerMove = MoveDirection::RIGHT;
        else if (keys[SDL_SCANCODE_UP])
            nextPlayerMove = MoveDirection::UP;
        else if (keys[SDL_SCANCODE_DOWN])
            nextPlayerMove = MoveDirection::DOWN;

        // AFFICHAGE

        blinky.setNextPos(Map::map, MoveDirection::NONE);
        pinky.setNextPos(Map::map, MoveDirection::NONE);
        inky.setNextPos(Map::map, MoveDirection::NONE);
        clyde.setNextPos(Map::map, MoveDirection::NONE);

        if (!CollisionManager::isCollision(Map::map, blinky, MTYPE::GHOST, SDL_Rect())) {
            blinky.move();
        } else {
            blinky.resetNextPos();
        }

        if (!CollisionManager::isCollision(Map::map, pinky, MTYPE::GHOST, SDL_Rect())) {
            pinky.move();
        } else {
            pinky.resetNextPos();
        }
        
        if (!CollisionManager::isCollision(Map::map, inky, MTYPE::GHOST, SDL_Rect())) {
            inky.move();
        } else {
            inky.resetNextPos();
        }
        
        if (!CollisionManager::isCollision(Map::map, clyde, MTYPE::GHOST, SDL_Rect())) {
            clyde.move();
        } else {
            clyde.resetNextPos();
        }
        
        player.setNextPos(Map::map, nextPlayerMove);

        SDL_Rect nextPos = player.getNextPos();

        SDL_Rect collisionOffset;
        collisionOffset.w = player.getRect().w;
        collisionOffset.w = player.getRect().h;

        collisionOffset.x = nextPlayerMove == MoveDirection::RIGHT ? 1 : 0;
        collisionOffset.y = nextPlayerMove == MoveDirection::DOWN ? 1 : 0;
    

        if (!CollisionManager::isCollision(Map::map, player, MTYPE::PACMAN, collisionOffset)) {
            player.setMoveDirection(nextPlayerMove);
            player.move();
        } else {
            MTYPE nextCol = CollisionManager::getNextCOLOBJ(Map::map, player.getNextPos());
            if (nextCol == MTYPE::ITEM) {
                //TODO: delete coin
                Map::map[nextPos.y/32][nextPos.x/32] = MTYPE::EMPTY;
                player.move();
                player.setMoveDirection(nextPlayerMove);
            } else {
                if (player.getMoveDirection() != nextPlayerMove) {
                    player.resetNextPos(); // resetting next move
                    player.setNextPos(Map::map, player.getMoveDirection());
                    player.move();
                } else {
                    player.resetNextPos();
                }

            }
        }

		draw();
		SDL_UpdateWindowSurface(pWindow); 
        // LIMITE A 60 FPS
		SDL_Delay(16); // utiliser SDL_GetTicks64() pour plus de precisions
    }
    SDL_Quit(); // ON SORT
    return 0;
}
