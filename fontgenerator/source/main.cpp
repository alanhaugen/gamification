#include <SDL.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <string>
#include "main.h"

int main(int numberOfArguments, char* argumentArray[])
{
	if (TTF_Init() != 0)
	{
		printf("Failed to initalise SDL2 ttf, quitting.\n");
		return -1;
	}

	TTF_Font* font = TTF_OpenFont("fonts/NotoSansJP-Regular.ttf", 36);

	if (font == nullptr)
	{
		printf("Failed to open font, quitting.\n");
		return -1;
	}

	SDL_Color bg = { 255, 255, 255, 255 };
	SDL_Color color = { 0, 0, 0, 0 };

	std::wstring text = L"あいうえおかきくけこさしすせそたちつてとなにぬねのはひふへほまみむめもやゆよらりるれろわをん 。";

	for (int i = 0; i < 48; i++)
	{
		std::wstring letter = text.substr(i, i+1);
		SDL_Surface* surf = TTF_RenderUNICODE(font, (const Uint16*) letter.c_str(), color, bg);

		if (surf == nullptr){
			TTF_CloseFont(font);
			printf("Failed to create surface, quitting.\n");
			return -1;
		}

		char dest[256];
		snprintf(dest, 256, "output_%d.bmp", i);

		SDL_SaveBMP(surf, dest);

		SDL_FreeSurface(surf);
	}

	TTF_CloseFont(font);

    return 0;
}

