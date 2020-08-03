/*

RENDERS THE GAME WINDOW
RENDERS TEXTURES TO THE GAME WINDOW

*/

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "RenderWindow.hpp"
#include "Entity.hpp"

//// Creates Window ////
RenderWindow::RenderWindow(const char* p_title, int p_width, int p_height)
	:window(NULL), renderer(NULL)
{
	//Creates window
	window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_width, p_height, SDL_WINDOW_SHOWN);

	//Creates renderer
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	//Window initalization error
	if (window == NULL)
		std::cout << "WINDOW FAILED TO INITALIZE. SDL_ERROR: " << SDL_GetError() << std::endl;
}

//// Creates Texture ////
SDL_Texture* RenderWindow::loadTexture(const char* p_filePath)
{
	//Loads texture
	SDL_Texture* texture = NULL;
	texture = IMG_LoadTexture(renderer, p_filePath);

	//Texture load error
	if (texture == NULL)
		std::cout << "FAILED TO LOAD TEXTURE. SDL_ERROR: " << SDL_GetError() << std::endl;

	//Returns texture
	return texture;
}

//// Cleans Up After Window is Closed ////
void RenderWindow::cleanUp()
{
	SDL_DestroyWindow(window);
}

//// Clears Window ////
void RenderWindow::clear()
{
	SDL_RenderClear(renderer);
}

//// Renders Texture ////
void RenderWindow::render(Entity& p_entity)
{
	//Texture source
	SDL_Rect source;
	source.x = p_entity.getCurrentFrame().x;
	source.y = p_entity.getCurrentFrame().y;
	source.w = p_entity.getCurrentFrame().w;
	source.h = p_entity.getCurrentFrame().h;

	//Texture destination
	SDL_Rect destination;
	destination.x = p_entity.getX();
	destination.y = p_entity.getY();
	destination.w = p_entity.getCurrentFrame().w;
	destination.h = p_entity.getCurrentFrame().h;

	SDL_RenderCopy(renderer, p_entity.getTexture(), &source, &destination);
}

//// Renders Player ////
void RenderWindow::render_player(Player& p_player)
{
	//Texture source
	SDL_Rect source;
	source.x = p_player.getCurrentFrame().x;
	source.y = p_player.getCurrentFrame().y;
	source.w = p_player.getCurrentFrame().w;
	source.h = p_player.getCurrentFrame().h;

	//Texture destination
	SDL_Rect destination;
	destination.x = p_player.getX();
	destination.y = p_player.getY();
	destination.w = p_player.getCurrentFrame().w;
	destination.h = p_player.getCurrentFrame().h;

	SDL_RenderCopy(renderer, p_player.getTexture(), &source, &destination);
}

//// Displays Rendered Textures ////
void RenderWindow::display()
{
	SDL_RenderPresent(renderer);
}