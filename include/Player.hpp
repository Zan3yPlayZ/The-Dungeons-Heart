/*

HANDLES THE PLAYER

*/

#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Player
{
public:
	Player(float p_x, float p_y, SDL_Texture* p_texture); //Creates player
	void update(); //Updates player
	void move(const char* p_direction); //Moves player
	bool getKeyboard(); //Gets keyboard
	float getX(); //Gets player x
	float getY(); //Gets player y
	SDL_Texture* getTexture(); //Gets player texture
	SDL_Rect getCurrentFrame(); //Gets player animaiton frame
private:
	float x, y, move_x, move_y;
	int movespeed = 10;
	SDL_Rect currentFrame; //Animation frame
	SDL_Texture* texture; //Entity texture
	bool keyboard[1<<30]; //Keyboard input
};