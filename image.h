#ifndef image_H
#define image_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#define SCREEN_W 1083
#define SCREEN_H 500

struct image {
	SDL_Rect pos1;
	SDL_Rect pos2;
	SDL_Surface *img;
	int hidden;
};
typedef struct image image;

void initImage(image *pic, char path[], int x, int y, int hidden);
void afficher (image p,SDL_Surface *screen);
void liberer (image A);

#endif
