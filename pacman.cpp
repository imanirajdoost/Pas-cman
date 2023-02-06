#include <SDL.h>
#include <iostream>

#include "Ghost.h"
#include "Map.h"
#include "CollisionManager.h"
#include "MovableGameObject.h"
#include "Player.h"


SDL_Window* pWindow = nullptr;
SDL_Surface* win_surf = nullptr;
SDL_Surface* plancheSprites = nullptr;

SDL_Rect src_bg = { 200,3, 168,216 }; // x,y, w,h (0,0) en haut a gauche
SDL_Rect bg = { 4,4, 672,864 }; // ici scale x4

SDL_Rect ghost_r = { 3,123, 16,16 }; 
SDL_Rect ghost_l = { 37,123, 16,16 }; 
SDL_Rect ghost_d = { 105,123, 16,16 }; 
SDL_Rect ghost_u = { 71,123, 16,16 }; 
SDL_Rect ghost = { 34,34, 32,32 };     // ici scale x2


Blinky blinky{34, 34};
Pinky pinky{70, 34};
Inky inky{100, 34};
Clyde clyde{130, 34};
Player player{32,32,2};

Map gameMap;

void init()
{
	pWindow = SDL_CreateWindow("PacMan", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 700, 900, SDL_WINDOW_SHOWN);
	win_surf = SDL_GetWindowSurface(pWindow);

	plancheSprites = SDL_LoadBMP("./pacman_sprites.bmp");
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

        MoveDirection nextPlayerMove = MoveDirection::NONE;

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

        player.setMoveDirection(nextPlayerMove);

        blinky.setNextPos(gameMap, MoveDirection::NONE);
        pinky.setNextPos(gameMap, MoveDirection::NONE);
        inky.setNextPos(gameMap, MoveDirection::NONE);
        clyde.setNextPos(gameMap, MoveDirection::NONE);

        if (!CollisionManager::isCollision(gameMap, blinky.getNextPos(), MTYPE::GHOST, SDL_Rect())) {
            blinky.move();
        } else {
            blinky.resetNextPos();
        }

        if (!CollisionManager::isCollision(gameMap, pinky.getNextPos(), MTYPE::GHOST, SDL_Rect())) {
            pinky.move();
        } else {
            pinky.resetNextPos();
        }
        
        if (!CollisionManager::isCollision(gameMap, inky.getNextPos(), MTYPE::GHOST, SDL_Rect())) {
            inky.move();
        } else {
            inky.resetNextPos();
        }
        
        if (!CollisionManager::isCollision(gameMap, clyde.getNextPos(), MTYPE::GHOST, SDL_Rect())) {
            clyde.move();
        } else {
            clyde.resetNextPos();
        }
        player.setNextPos(gameMap, nextPlayerMove);

        SDL_Rect nextPos = player.getNextPos();

        SDL_Rect collisionOffset;
        collisionOffset.w = player.getRect().w;
        collisionOffset.w = player.getRect().h;

        collisionOffset.x = nextPlayerMove == MoveDirection::RIGHT ? 1 : 0;
        collisionOffset.y = nextPlayerMove == MoveDirection::LEFT ? 1 : 0;
        
        //std::cout << "x: " << player.getNextPos().x << std::endl;
        //std::cout << "y: " << player.getNextPos().y << std::endl;

        // TODO: COLLISION WITH COIN PREVENTS MOVING
        if (!CollisionManager::isCollision(gameMap, nextPos, MTYPE::PACMAN, collisionOffset)) {
            player.move();
        } else {
            MTYPE nextCol = CollisionManager::getNextCOLOBJ(gameMap, player.getNextPos());
            if (nextCol == MTYPE::ITEM) {
                //TODO: delete coin
                gameMap.map[nextPos.y/32][nextPos.x/32] = MTYPE::EMPTY;
                player.move();
            } else {
                std::cout << CollisionManager::isCollision(gameMap, nextPos, MTYPE::PACMAN, collisionOffset) << std::endl;
                player.resetNextPos();
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
