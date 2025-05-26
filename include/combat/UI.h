#ifndef UI_COMBAT_MODE
#define UI_COMBAT_MODE


#include "SDL.h"
#include "imgui.h"
#include <string>
class UI
{
private:
	
	static bool isDisplayingText;
	static std::string textToDisplay;
	static bool hasClickedThisFrame;
	
	static void useAttack(int i);

	static void setSelectWindow();
	static void setFightWindow();

	static void displaySelectWindow();
	static void displayFightWindow();

	static void setTextMessage(std::string message);
	static void displayTextMessage();

	static void drawHealthBar(int hp, int maxHP, ImVec2 pos);

public:
	static void processEvent(const SDL_Event* event);

	static void render(SDL_Renderer* renderer);
	static void setupUI(SDL_Window * window, SDL_Renderer* renderer);
	
	static void displayUI();
	static void flushUI();


	static void stopDisplayingText();
};

#endif
