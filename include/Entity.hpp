/*

HANDLES ENTITIES

*/

#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Entity
{
public:
	Entity(float p_x, float p_y, int p_w, int p_h, SDL_Texture* p_texture); //Loads Entity
	float getX(); //Gets entity x
	float getY(); //Gets entity y
	SDL_Texture* getTexture(); //Gets entity texture
	SDL_Rect getCurrentFrame(); //Gets current animaiton frame
private:
	float x, y; //Entity location
	SDL_Rect currentFrame; //Animation frame
	SDL_Texture* texture; //Entity texture
};