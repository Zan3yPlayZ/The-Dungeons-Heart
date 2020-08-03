/*

RENDERS THE GAME WINDOW
RENDERS TEXTURES TO THE GAME WINDOW

*/

#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Entity.hpp"
#include "Player.hpp"

class RenderWindow
{
public:
	RenderWindow(const char* p_title, int p_width, int p_height); //Renders game window
	SDL_Texture* loadTexture(const char* p_filePath); //Loads a texture
	void cleanUp(); //Cleans up after you close the game
	void clear(); //Clears screen
	void render(Entity& p_entity); //Renders texture
	void render_player(Player& p_player); //Renders player
	void display(); //Display texture
private:
	SDL_Window* window; //Game window
	SDL_Renderer* renderer; //Allows images to render to game window
};