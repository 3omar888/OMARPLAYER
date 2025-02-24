void afficher(image p,SDL_Surface *screen){
	if (p.hidden){
		SDL_BlitSurface(p.img,NULL,screen,&p.pos2);
	} 
	else{
		SDL_BlitSurface(p.img,NULL,screen,&p.pos1);
	}
}

void liberer (image picture){
	SDL_FreeSurface(picture.img);
}
