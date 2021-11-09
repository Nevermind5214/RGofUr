#include "Game.h"
#include "TextureManager.h"

SDL_Texture* gameBoard;
SDL_Texture* gameBoardPath;
SDL_Rect scrR, destR;

Game::Game()
{}
Game::~Game()
{}

void Game::init(const char *title, int width, int height, bool fullscreen)
{

	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "SDL_Init done" << std::endl;
		window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
		if (window) std::cout << "Window created" << std::endl;

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer created" << std::endl;
		}
		isRunning = true;
	}
	else isRunning = false;

	gameBoard = TextureManager::LoadTexture("assets/Board1.png", renderer);
	gameBoardPath = TextureManager::LoadTexture("assets/path.png", renderer);

}

void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;

	default:
		break;
	}
}

void Game::update()
{
	cnt++;
	destR.h = 300;
	destR.w = 800;
	destR.y = 150;

	std::cout << cnt << std::endl;
}

void Game::render()
{
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, gameBoard, NULL, &destR);
	SDL_RenderCopy(renderer, gameBoardPath, NULL, &destR);
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game Cleaned" << std::endl;
}