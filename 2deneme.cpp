#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

//The window we'll be rendering to
SDL_Window* gWindow = nullptr;

//The surface contained by the window
SDL_Surface* gScreenSurface = nullptr;

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
		}
	}

	gHelloWorld = SDL_LoadBMP( "images/purpleBlock.bmp" );
	if( gHelloWorld == NULL )
	{
		printf( "Unable to load image %s! SDL Error: %s\n", "02_getting_an_image_on_the_screen/hello_world.bmp", SDL_GetError() );
	}
	SDL_BlitSurface( gHelloWorld, NULL, gScreenSurface, NULL );
	SDL_UpdateWindowSurface( gWindow );
	SDL_Event e; bool quit = false; while( quit == false ){ while( SDL_PollEvent( &e ) ){ if( e.type == SDL_QUIT ) quit = true; } }

	SDL_FreeSurface( gHelloWorld );
	gHelloWorld = NULL;

	SDL_DestroyWindow( gWindow );
	gWindow = NULL;

	SDL_Quit();
}
