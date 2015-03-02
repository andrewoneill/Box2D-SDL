#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include <LTexture.h>
#include <Game.h>
#include <Menu.h>
#include <KeyboardManager.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
Game g;
Menu m;
int SCREEN_WIDTH, SCREEN_HEIGHT;
//SDL Variables
SDL_Window *window;
SDL_Renderer *gRenderer;
SDL_RendererFlip flipType = SDL_FLIP_NONE;
//using namespace std;

LTexture background;
//The music that will be played
Mix_Music *gMusic = NULL;

//The sound effects 
Mix_Chunk *gScratch = NULL;
Mix_Chunk *gHigh = NULL;
Mix_Chunk *gMedium = NULL;
Mix_Chunk *gLow = NULL;

void SetupEntities() {
	srand(time(NULL));

	background.loadFromFile(".png", gRenderer);//insert image for background
	//g.SetupEntities(gRenderer,SCREEN_WIDTH, SCREEN_HEIGHT);
}

void SetupSDL() {
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK ); //this and next 2 lines needed for using native screen resolution  

	SDL_DisplayMode mode;
	SDL_GetCurrentDisplayMode(0, &mode);
	SCREEN_WIDTH = mode.w;
	SCREEN_HEIGHT = mode.h;
	//window = SDL_CreateWindow( "Final Year Project", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, mode.w, mode.h, SDL_WINDOW_FULLSCREEN);//fullscreen
	window = SDL_CreateWindow( "The Kessel Run", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, mode.w, mode.h, SDL_WINDOW_SHOWN );
	gRenderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
	IMG_Init( IMG_INIT_PNG );
	TTF_Init();
	if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 ){
		printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
	}

	//Load music
	//gMusic = Mix_LoadMUS( ".mp3" );
	if( gMusic == NULL ){
		printf( "Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError() );
	}

	if( Mix_PlayingMusic() == 0 ){//PLAYS MUSIC
		Mix_PlayMusic( gMusic, -1 );
	}
	//m.SetupMain(gRenderer,SCREEN_WIDTH,SCREEN_HEIGHT);
}

void Quit() {
	SDL_DestroyWindow( window );
	SDL_DestroyRenderer( gRenderer );
	IMG_Quit();
	TTF_Quit();
	SDL_Quit();
}

void DrawEntities() {
	//SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
	SDL_RenderClear( gRenderer );
	background.render(0,0,	NULL,0, NULL, flipType, gRenderer );
	//g.DrawEntities(gRenderer, flipType);
	SDL_RenderPresent( gRenderer );
}

void Update() {
	//while (m.GetState() != 2 && m.GetState() != 3) m.Update(&e, gRenderer);//If not playing
	//g.Update();
	//if (KeyboardManager::instance()->IsKeyDown(KeyboardManager::ESC)){
		//m.SetupPause(gRenderer,SCREEN_WIDTH,SCREEN_HEIGHT);
	//}
	DrawEntities();
}

int main( int argc, char* args[] ) {

	SetupSDL();
	//while (m.GetState() != 2 && m.GetState() != 3) m.Update(&e, gRenderer);//while in Menus
	SDL_RenderClear( gRenderer );
	//g.SetupWorld();
	SetupEntities();
	//while (g.IsGameRunning()) {
	//	Update();
	//	while (m.GetState() == 1) m.Update(&e, gRenderer);
	//	if (g.player->GetHealth() <= 0){
	//		g.EndGame();
	//		DisplayText("YOU DIED!!!", b2Vec2_zero);
	//		SDL_RenderPresent( gRenderer );
	//		SDL_Delay(1000);
	//	}
	//	else if (m.GetState() == 3){
	//		g.EndGame();
	//		DisplayText("THE END!!!", b2Vec2_zero);
	//		SDL_RenderPresent( gRenderer );
	//		SDL_Delay(1000);
	//	}
	//}
	
	Quit();
	return 0;
}