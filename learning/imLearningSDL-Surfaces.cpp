#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

//The window we'll be rendering to
SDL_Window* gWindow = nullptr;

//The surface contained by the window
SDL_Surface* gScreenSurface = nullptr;
SDL_Surface* gScreenSurface2 = nullptr;

//The image we will load and show on the screen
SDL_Surface* gHelloWorld = nullptr;

int main()
{
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
		return(0);
	}
	else
	{
		//Create window
		gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 600, 600, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
			return(0);
		}
		else
		{
			//Get window surface
			gScreenSurface = SDL_GetWindowSurface( gWindow );
			gScreenSurface2 = SDL_GetWindowSurface( gWindow );
			if (gScreenSurface == NULL || gScreenSurface2 == NULL)
			{
				printf( "surfaces could not be created! SDL_Error: %s\n", SDL_GetError() );
				return(0);
			}
		}
	}

	SDL_Surface* tmp;
	tmp = SDL_LoadBMP( "images/purpleBlock.bmp" );
	if( tmp == NULL )
	{
		printf( "Unable to load image %s! SDL Error: %s\n", "02_getting_an_image_on_the_screen/hello_world.bmp", SDL_GetError() );
	}
	gHelloWorld = SDL_ConvertSurface(tmp, gScreenSurface->format, 0);
	SDL_FreeSurface(tmp);
	SDL_Event e;
	SDL_Rect r1;
	r1.x = 300;
	r1.y = 300;
	r1.w = 20;
	r1.h = 20;
	SDL_Rect r2;
	r2.x = 320;
	r2.y = 300;
	r2.w = 20;
	r2.h = 20;
	bool quit = false;
	while( quit == false ){
		SDL_BlitScaled( gHelloWorld, NULL, gScreenSurface, &r1 );
		SDL_BlitScaled( gHelloWorld, NULL, gScreenSurface2, &r2 );
		SDL_UpdateWindowSurface( gWindow );
		while( SDL_PollEvent( &e ) ){ if( e.type == SDL_QUIT || e.key.keysym.sym == SDLK_ESCAPE ) quit = true; }
	}

	SDL_FreeSurface( gHelloWorld );
	gHelloWorld = NULL;

	SDL_DestroyWindow( gWindow );
	gWindow = NULL;

	SDL_Quit();
}
