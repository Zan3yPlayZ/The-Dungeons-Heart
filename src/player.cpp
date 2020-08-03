/*

HANDLES THE PLAYER

*/

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "Player.hpp"

//// Creates Player ////
Player::Player(float p_x, float p_y, SDL_Texture* p_texture)
	:x(p_x), y(p_y), texture(p_texture)
{
	//Frame rect
	currentFrame.x = 0;
	currentFrame.y = 0;
	currentFrame.w = 144;
	currentFrame.h = 180;
}

//// Updates Player Position and Texture ////
void Player::update()
{
	x += move_x;
	y += move_y;
	/*
	if(keyboard[SDLK_d]){ 
		Player::move("right");
	} 
	if(keyboard[SDLK_a]){ 
		Player::move("left");
	}
	if(keyboard[SDLK_w]){ 
		Player::move("up");
	}
	if(keyboard[SDLK_s]){ 
		Player::move("down");
	}
	*/
}

//// Moves Player ////
void Player::move(const char* p_direction)
{
	std::cout << move_x << std::endl;
	if(strcmp(p_direction, "right") == 0){
		move_x += movespeed;
	}else if(strcmp(p_direction, "left") == 0){
		move_x -= movespeed;
	}else if(strcmp(p_direction, "up") == 0){
		move_y -= movespeed;
	}else if(strcmp(p_direction, "down") == 0){
		move_y += movespeed;
	}else if(strcmp(p_direction, "stop") == 0){
		move_x = 0;
		move_y = 0;
	}else{
		std::cout << "INVALID MOVE INPUT" << std::endl;
	}
	if(move_x > movespeed)
		move_x = movespeed;
	if(move_y > movespeed)
		move_y = movespeed;
}

//// Gets Player Keyboard ////
bool Player::getKeyboard()
{
	return keyboard;
}

//// Gets Player X ////
float Player::getX()
{
	return x;
}

//// Gets Player Y ////
float Player::getY()
{
	return y;
}

//// Gets Player Texture ////
SDL_Texture* Player::getTexture()
{
	return texture;
}

//// Gets Current Frame ////
SDL_Rect Player::getCurrentFrame()
{
	return currentFrame;
}