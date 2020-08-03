/*

HANDLES ENTITIES

*/

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "Entity.hpp"

//// Creates Entity ////
Entity::Entity(float p_x, float p_y, int p_w, int p_h, SDL_Texture* p_texture)
	:x(p_x), y(p_y), texture(p_texture)
{
	//Frame rect
	currentFrame.x = 0;
	currentFrame.y = 0;
	currentFrame.w = p_w;
	currentFrame.h = p_h;
}

//// Gets Entity X ////
float Entity::getX()
{
	return x;
}

//// Gets Entity Y ////
float Entity::getY()
{
	return y;
}

//// Gets Entity Texture ////
SDL_Texture* Entity::getTexture()
{
	return texture;
}

//// Gets Current Frame ////
SDL_Rect Entity::getCurrentFrame()
{
	return currentFrame;
}