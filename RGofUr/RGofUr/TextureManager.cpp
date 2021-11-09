#include "TextureManager.h"

SDL_Texture* TextureManager::LoadTexture(const char* texture, SDL_Renderer* ren)
{
	SDL_Surface* tmpSurface = IMG_Load(texture);
	if (tmpSurface == NULL) {
		std::cout << IMG_GetError() << std::endl;
	}
	SDL_Texture* tex = SDL_CreateTextureFromSurface(ren, tmpSurface);
	if (tex == NULL) {
		std::cout << SDL_GetError() << std::endl;
	}
	SDL_FreeSurface(tmpSurface);

	return tex;
}