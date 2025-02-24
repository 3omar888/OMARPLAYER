#include "image.h"
#include <SDL/SDL_mixer.h>

int main(int argc, char** argv){

	//Needed Intialization
	SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO);
	SDL_Surface *screen;
	SDL_Event event;
	Mix_Chunk *son;
	
	//Init Variables
	int done = 0, mouseOnMonoPlayerButton = 0, mouseOnMultiPlayerButton = 0, mouseOnReturnButton = 0, mouseOnAvatar1Button = 0, mouseOnAvatar2Button = 0, mouseOnInput1Button = 0, mouseOnInput2Button = 0, mouseOnValidateButton = 0, playerModeSelectionWindow = 1, avatarSelectionWindow = 0, mainWindow = 0, bestScoreWindow = 0;

	//Init Image Variables
	image background ,monoPlayerButton , multiPlayerButton, returnButton, avatar1Button, avatar2Button, input1Button, input2Button, validateButton;
	
	//Link Exit Event To SDL_Quit Function
	atexit(SDL_Quit);
	
	//Create Screen
	screen=SDL_SetVideoMode(1083,500,32,SDL_HWSURFACE|SDL_SRCALPHA|SDL_DOUBLEBUF);
	
	//Show Screen Errors
	if (!screen)
	{
		printf("unable to set 1083x500 video:%s\n",SDL_GetError());
		return 1;
	}	
	
	//initialiser_audiobref(son);
	Mix_Music *music;
		
	//Show Audio Errors
	if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
	{
		printf("%s",Mix_GetError());
	}

	//Load Sound and Init Volume	
	son=Mix_LoadWAV("son.wav");
	music =Mix_LoadMUS("music.mp3");
	Mix_PlayMusic(music,-1);
	Mix_VolumeMusic(MIX_MAX_VOLUME);
	Mix_VolumeChunk(son,MIX_MAX_VOLUME);
	int max_volume = Mix_VolumeChunk(son, -1);
	
	//Init All Images (Var, Path, X, Y, Hidden)
	initImage(&background, "./Assets/background.jpg", 0, 0, 0);
	initImage(&monoPlayerButton, "./Assets/bouton.jpg", 300, 175, 0);
	initImage(&multiPlayerButton, "./Assets/bouton.jpg", 700, 175, 0);
	initImage(&returnButton, "./Assets/bouton.jpg", 850, 350, 0);
	initImage(&input1Button, "./Assets/bouton.jpg", 300, 175, 1);
	initImage(&input2Button, "./Assets/bouton.jpg", 700, 175, 1);
	initImage(&avatar1Button, "./Assets/bouton.jpg", 300, 100, 1);
	initImage(&avatar2Button, "./Assets/bouton.jpg", 700, 100, 1);
	initImage(&input1Button, "./Assets/bouton.jpg", 300, 175, 1);
	initImage(&validateButton, "./Assets/bouton.jpg", 500, 250, 1);
	
	//Game Loop
	while(!done)
	{		
		//Refresh Images
		afficher(background,screen);
		afficher(monoPlayerButton,screen);
		afficher(multiPlayerButton,screen);
		afficher(returnButton,screen);
		afficher(avatar1Button,screen);
		afficher(avatar2Button,screen);
		afficher(input1Button,screen);
		afficher(input2Button,screen);
		afficher(validateButton,screen);

		//Refresh Screen
		SDL_Flip(screen);
		
		//Poll Event To not stop the Animation While Waiting for an Event
		if(SDL_PollEvent(&event)){		
			switch(event.type){
				case SDL_QUIT:
					done = 1;
					break;
	 			
	 			case SDL_MOUSEMOTION:
 					//Print Mouse Position (To Know Coordinates)
					printf("Mouse Position: ");
					printf("X= %d, Y= %d\n",event.button.x,event.button.y);

					if (playerModeSelectionWindow){
						//Mouse ON Which Button
						mouseOnMonoPlayerButton = 0;
						mouseOnMultiPlayerButton = 0;
						mouseOnReturnButton = 0;

						if(event.button.x >= 300 && event.button.x <= 450 && event.button.y >=175 && event.button.y <=235){
							printf("Mouse On Mono Player Button\n");
							Mix_PlayChannel(1,son,0);
							
							//Mouse ON Which Button
							mouseOnMonoPlayerButton = 1;
							mouseOnMultiPlayerButton = 0;
							mouseOnReturnButton = 0;

						}
						else if(event.button.x >= 700 && event.button.x <= 850 && event.button.y >=175 && event.button.y <=235){
							printf("Mouse On Multi Player Button\n");
							Mix_PlayChannel(1,son,0);
							
							//Mouse ON Which Button
							mouseOnMonoPlayerButton = 0;
							mouseOnMultiPlayerButton = 1;
							mouseOnReturnButton = 0;
						}
						else if(event.button.x >= 850 && event.button.x <= 1000 && event.button.y >=350 && event.button.y <=410){
							printf("Mouse On Return Button\n");
							Mix_PlayChannel(1,son,0);
							
							//Mouse ON Which Button
							mouseOnMonoPlayerButton = 0;
							mouseOnMultiPlayerButton = 0;
							mouseOnReturnButton = 1;
						}
					}
					else if (avatarSelectionWindow){
						//Mouse ON Which Button
						mouseOnInput1Button = 0;
						mouseOnInput2Button = 0;
						mouseOnAvatar1Button = 0;
						mouseOnAvatar2Button = 0;
						mouseOnValidateButton = 0;
						mouseOnReturnButton = 0;

						if(event.button.x >= 300 && event.button.x <= 450 && event.button.y >=175 && event.button.y <=235){
							printf("Mouse On Input 1 Button\n");
							Mix_PlayChannel(1,son,0);
							
							//Mouse ON Which Button
							mouseOnInput1Button = 1;
							mouseOnInput2Button = 0;
							mouseOnAvatar1Button = 0;
							mouseOnAvatar2Button = 0;
							mouseOnValidateButton = 0;
							mouseOnReturnButton = 0;
						}
						else if(event.button.x >= 700 && event.button.x <= 850 && event.button.y >=175 && event.button.y <=235){
							printf("Mouse On Input 2 Button\n");
							Mix_PlayChannel(1,son,0);
							
							//Mouse ON Which Button
							mouseOnInput1Button = 0;
							mouseOnInput2Button = 1;
							mouseOnAvatar1Button = 0;
							mouseOnAvatar2Button = 0;
							mouseOnValidateButton = 0;
							mouseOnReturnButton = 0;
						}

						else if(event.button.x >= 300 && event.button.x <= 450 && event.button.y >=100 && event.button.y <=160){
							printf("Mouse On Avatar 1 Button\n");
							Mix_PlayChannel(1,son,0);
							
							//Mouse ON Which Button
							mouseOnInput1Button = 0;
							mouseOnInput2Button = 0;
							mouseOnAvatar1Button = 1;
							mouseOnAvatar2Button = 0;
							mouseOnValidateButton = 0;
							mouseOnReturnButton = 0;
						}
						else if(event.button.x >= 700 && event.button.x <= 850 && event.button.y >=100 && event.button.y <=160){
							printf("Mouse On Avatar 2 Button\n");
							Mix_PlayChannel(1,son,0);
							
							//Mouse ON Which Button
							mouseOnInput1Button = 0;
							mouseOnInput2Button = 0;
							mouseOnAvatar1Button = 0;
							mouseOnAvatar2Button = 1;
							mouseOnValidateButton = 0;
							mouseOnReturnButton = 0;
						}
						else if(event.button.x >= 500 && event.button.x <= 650 && event.button.y >=250 && event.button.y <=310){
							printf("Mouse On Validation Button\n");
							Mix_PlayChannel(1,son,0);
							
							//Mouse ON Which Button
							mouseOnInput1Button = 0;
							mouseOnInput2Button = 0;
							mouseOnAvatar1Button = 0;
							mouseOnAvatar2Button = 0;
							mouseOnValidateButton = 1;
							mouseOnReturnButton = 0;
						}
						else if(event.button.x >= 850 && event.button.x <= 1000 && event.button.y >=350 && event.button.y <=410){
							printf("Mouse On Return Button\n");
							Mix_PlayChannel(1,son,0);
							
							//Mouse ON Which Button
							mouseOnInput1Button = 0;
							mouseOnInput2Button = 0;
							mouseOnAvatar1Button = 0;
							mouseOnAvatar2Button = 0;
							mouseOnValidateButton = 0;
							mouseOnReturnButton = 1;
						}
					}
					break;

				case SDL_MOUSEBUTTONUP:
				
					//Select Player Button
					if((mouseOnMonoPlayerButton || mouseOnMultiPlayerButton) && playerModeSelectionWindow){				
						printf("Open Player Menu\n");
						//Mouse ON Which Button
						mouseOnMonoPlayerButton = 0;
						mouseOnMultiPlayerButton = 0;
						mouseOnReturnButton = 0;
									
						//Hide and Show Bottons
						monoPlayerButton.hidden = 1;
						multiPlayerButton.hidden = 1;
						input1Button.hidden = 0;
						input2Button.hidden = 0;
						avatar1Button.hidden = 0;
						avatar2Button.hidden = 0;
						input1Button.hidden = 0;
						validateButton.hidden = 0;

						//Select Window
						playerModeSelectionWindow = 0;
						avatarSelectionWindow = 1;
						bestScoreWindow = 0;
						mainWindow = 0 ;

					}
					else if (mouseOnReturnButton && avatarSelectionWindow){
						//Mouse ON Which Button
						mouseOnInput1Button = 0;
						mouseOnInput2Button = 0;
						mouseOnAvatar1Button = 0;
						mouseOnAvatar2Button = 0;
						mouseOnValidateButton = 0;
						avatarSelectionWindow = 0;

						//Select Window
						playerModeSelectionWindow = 1;
						avatarSelectionWindow = 0;
						bestScoreWindow = 0;
						mainWindow = 0 ;


						//Hide and Show Bottons
						monoPlayerButton.hidden = 0;
						multiPlayerButton.hidden = 0;
						input1Button.hidden = 1;
						input2Button.hidden = 1;
						avatar1Button.hidden = 1;
						avatar2Button.hidden = 1;
						input1Button.hidden = 1;
						validateButton.hidden = 1;
					}
					else if (mouseOnReturnButton && playerModeSelectionWindow){
						//Mouse ON Which Button
						mouseOnMonoPlayerButton = 0;
						mouseOnMultiPlayerButton = 0;
						mouseOnReturnButton = 0;

						//Select Window
						playerModeSelectionWindow = 0;
						avatarSelectionWindow = 0;
						bestScoreWindow = 0;
						mainWindow = 1 ;


						//Hide and Show Bottons
						monoPlayerButton.hidden = 1;
						multiPlayerButton.hidden = 1;
						input1Button.hidden = 1;
						input2Button.hidden = 1;
						avatar1Button.hidden = 1;
						avatar2Button.hidden = 1;
						input1Button.hidden = 1;
						validateButton.hidden = 1;
						returnButton.hidden = 1;


						//Show Main Window (To be integrated)
					}
					else if (mouseOnValidateButton && avatarSelectionWindow){
						//Mouse ON Which Button
						mouseOnInput1Button = 0;
						mouseOnInput2Button = 0;
						mouseOnAvatar1Button = 0;
						mouseOnAvatar2Button = 0;
						mouseOnValidateButton = 0;
						avatarSelectionWindow = 0;

						//Select Window
						playerModeSelectionWindow = 0;
						avatarSelectionWindow = 0;
						bestScoreWindow = 1;
						mainWindow = 0 ;


						//Hide and Show Bottons
						monoPlayerButton.hidden = 1;
						multiPlayerButton.hidden = 1;
						input1Button.hidden = 1;
						input2Button.hidden = 1;
						avatar1Button.hidden = 1;
						avatar2Button.hidden = 1;
						input1Button.hidden = 1;
						validateButton.hidden = 1;
						returnButton.hidden = 1;

						//Show Best Score (To be Integrated)
					}
					
					
					break;

					
				case SDL_KEYDOWN:
					//Go To Best Score Window (ENTER KEY)
		 			if(event.key.keysym.sym == SDLK_RETURN && avatarSelectionWindow)
		 			{		
		 					
						printf("ENTER Button, Best Score Menu\n");
						
						//Mouse ON Which Button
						mouseOnInput1Button = 0;
						mouseOnInput2Button = 0;
						mouseOnAvatar1Button = 0;
						mouseOnAvatar2Button = 0;
						mouseOnValidateButton = 0;
						avatarSelectionWindow = 0;

						//Select Window
						playerModeSelectionWindow = 0;
						avatarSelectionWindow = 0;
						bestScoreWindow = 1;
						mainWindow = 0 ;


						//Hide and Show Bottons
						monoPlayerButton.hidden = 1;
						multiPlayerButton.hidden = 1;
						input1Button.hidden = 1;
						input2Button.hidden = 1;
						avatar1Button.hidden = 1;
						avatar2Button.hidden = 1;
						input1Button.hidden = 1;
						validateButton.hidden = 1;
						returnButton.hidden = 1;

						//Show Best Score (To be Integrated)		
					}
					else if(event.key.keysym.sym == SDLK_ESCAPE){
						done = 1;
					}
					
					break;	
					
				default:
				break;		
			}
		}		
	}
						
	//Free other ressources					
	Mix_FreeMusic(music);
	Mix_FreeChunk(son);
	Mix_CloseAudio();
	liberer(background);
	liberer(monoPlayerButton);
	liberer(multiPlayerButton);
	liberer(input1Button);
	liberer(input2Button);
	liberer(avatar1Button);
	liberer(avatar2Button);
	liberer(validateButton);
	liberer(returnButton);
	
	return 0;
}
