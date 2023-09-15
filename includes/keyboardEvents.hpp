#pragma once

union SDL_Event;
class gameClass;

#define PRESSED_KEY event.key.keysym.sym

//https://wiki.libsdl.org/SDL2/SDL_Keycode
class keyboardEvent{
private :
public:
	static int handleKeyDown(gameClass &, SDL_Event &);
};
