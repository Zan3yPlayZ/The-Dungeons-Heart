#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "RenderWindow.hpp"
#include "Entity.hpp"
#include "Player.hpp"

int main(int argc, char* args[])
{
	//Setup FPS
	const int fps = 75;
	const int frameDelay = 1000/fps;
	Uint32 frameStart;
	int frameTime;

	//SDL initialize error
	if (SDL_Init(SDL_INIT_VIDEO) > 0)
		std::cout << "SDL_Init HAS FAILED. SDL_ERROR: " << SDL_GetError() << std::endl;

	//SDL image error
	if (!(IMG_Init(IMG_INIT_PNG)))
		std::cout << "IMG_Init has failed. SDL_ERROR: " << SDL_GetError() << std::endl;

	//Create window
	RenderWindow window("The Dungeons Heart Alpha", 1920, 1080);

	//Load textures
	SDL_Texture* testSceneTexture = window.loadTexture("res/video/test_scene.png");
	SDL_Texture* playerTexture = window.loadTexture("res/video/player.png");

	//Create entity
	Entity testScene(0, 0, 1920, 1080, testSceneTexture);

	//Create player entity
	Player player(100, 200, playerTexture);

	//Event handler
	SDL_Event event;

	//Keyboard input
	//bool keyboard[1<<30];

	////////////////////////// GAME LOOP START //////////////////////////

	bool gameRunning = true;

	while (gameRunning)
	{
		//Start frame counting for FPS
		frameStart = SDL_GetTicks();

		while (SDL_PollEvent(&event))
		{
			switch (event.type) 
			{
				case SDL_QUIT:
					gameRunning = false;

				/*
				case SDL_KEYDOWN:
					keyboard[event.key.keysym.sym] = true;
					break;
				case SDL_KEYUP:
					keyboard[event.key.keysym.sym] = false;
					player.move("stop");
					break;
				*/
				///////
			}
		}

		//Render and display images
		window.clear();
		window.render(testScene);
		window.render_player(player);
		player.update();
		window.display();

		//Calculate frame time for FPS
		frameTime = SDL_GetTicks() - frameStart;

		if(frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}

	////////////////////////// GAME LOOP END //////////////////////////

	//Cleans up after you close the game
	window.cleanUp();
	SDL_Quit();

	return 0;
}