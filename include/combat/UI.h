#ifndef UI_COMBAT_MODE
#define UI_COMBAT_MODE


#include "SDL.h"
class UI
{
private:

	static void useAttack(int i);


	static void setWindow();

	static void displayAttacks();

public:
	static void processEvent(const SDL_Event* event);

	static void render(SDL_Renderer* renderer);
	static void setUI(SDL_Window * window, SDL_Renderer* renderer);
	static void displayUI();
	static void flushUI();
};

#endif
