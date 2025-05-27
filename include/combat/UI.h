#ifndef UI_COMBAT_MODE
#define UI_COMBAT_MODE


#include "SDL.h"
#include "combat/CombatManager.h"
#include "imgui.h"
#include <string>
class UI
{
private:
	
	static bool isDisplayingText;
	static std::string textToDisplay;
	static bool hasClickedThisFrame;
	static bool SelectHero;

	static void useAttack(int i, CombatManager *manager);

	static void setSelectWindow();
	static void setFightWindow();

	static void displaySelectWindow(CombatManager *manager);
	static void displaySelectHeroWindow(CombatManager *manager);
	static void displayFightWindow(Player *player, Enemy *enemy);

	static void displayTextMessage(CombatManager *manager);

	static void drawHealthBar(int hp, int maxHP, ImVec2 pos);

public:
	static void processEvent(const SDL_Event* event);
	static void setTextMessage(std::string message);

	static void render(SDL_Renderer* renderer);
	static void setupUI(SDL_Window * window, SDL_Renderer* renderer);
	
	static void displayUI(CombatManager *manager);
	static void flushUI();


	static void stopDisplayingText();
};

#endif
