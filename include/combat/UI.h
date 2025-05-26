#ifndef UI_COMBAT_MODE
#define UI_COMBAT_MODE


#include "SDL.h"
#include <string>
class UI
{
private:

	static bool isDisplayingText;
	static std::string textToDisplay;
	static void useAttack(int i);
	static bool hasClickedThisFrame;

	static void setWindow();

	static void displayAttacks();

public:
	static void processEvent(const SDL_Event* event);

	static void render(SDL_Renderer* renderer);
	static void setUI(SDL_Window * window, SDL_Renderer* renderer);
	static void displayUI();
	static void flushUI();

	static void displayTextMessage(std::string message);
	static void renderMessages();

	static void stopDisplayingText();
};

#endif
