#include <combat/UI.h>
#include <iostream>
#include <string>

#include "combat/CombatManager.h"
#include "combat/Player.h"
#include "imgui.h"
#include "backends/imgui_impl_sdl2.h"
#include "backends/imgui_impl_sdlrenderer2.h"

bool UI::isDisplayingText = false;
bool UI::hasClickedThisFrame = false;
std::string UI::textToDisplay = "";

void UI::processEvent(const SDL_Event *event)
{
    ImGui_ImplSDL2_ProcessEvent(event);
    if (event->type == SDL_MOUSEBUTTONDOWN)
	hasClickedThisFrame = true; 
}

void UI::render(SDL_Renderer *renderer)
{
        ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData(), renderer);
}

void UI::setupUI(SDL_Window* window, SDL_Renderer* renderer)
{
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();

    UI::isDisplayingText = false;
    ImGui_ImplSDL2_InitForSDLRenderer(window, renderer);
    ImGui_ImplSDLRenderer2_Init(renderer);

}


void UI::setSelectWindow()
{
        ImGui::SetNextWindowPos(ImVec2(0, 600 - 200));
        ImGui::SetNextWindowSize(ImVec2(800, 200));

        ImGui::Begin("Fixed Bottom Panel", nullptr,
            ImGuiWindowFlags_NoMove |
            ImGuiWindowFlags_NoResize |
            ImGuiWindowFlags_NoCollapse |
            ImGuiWindowFlags_NoTitleBar);
	
}

void UI::displaySelectWindow(CombatManager *manager)
{
	Player *player = manager->getCurrentHero();
    bool disabled = UI::isDisplayingText;
    if (disabled)
        ImGui::BeginDisabled();

    ImGui::SetCursorPos(ImVec2(100, 40));
    if (player->getAttacks()[0]->canAttack() && ImGui::Button(player->getAttacks()[0]->getName().data(), ImVec2(250, 40)))
        useAttack(0, manager);

    ImGui::SetCursorPos(ImVec2(450, 40));
    if (player->getAttacks()[1]->canAttack() && ImGui::Button(player->getAttacks()[1]->getName().data(), ImVec2(250, 40)))
        useAttack(1, manager);

    ImGui::SetCursorPos(ImVec2(100, 120));
    if (player->getAttacks()[2]->canAttack() && ImGui::Button(player->getAttacks()[2]->getName().data(), ImVec2(250, 40)))
        useAttack(2, manager);

    ImGui::SetCursorPos(ImVec2(450, 120));
    if (player->getAttacks()[3]->canAttack() && ImGui::Button(player->getAttacks()[3]->getName().data(), ImVec2(250, 40)))
        useAttack(3, manager);

    if (disabled)
        ImGui::EndDisabled();
    	


	displayTextMessage(manager);
	ImGui::End();
}

void UI::useAttack(unsigned int id, CombatManager *manager)
{
	if (UI::isDisplayingText)
		return;
	std::cout << "Using attack " << id << "." << std::endl ;
	//std::string message = "attaque " + std::to_string(id);
	manager->handlePlayerInput(id);
	hasClickedThisFrame = false;
	//setTextMessage("attaque " + std::to_string(id));
}

void UI::displayUI(CombatManager *manager)
{
        ImGui_ImplSDLRenderer2_NewFrame();
        ImGui_ImplSDL2_NewFrame();
        ImGui::NewFrame();

	setFightWindow();
	displayFightWindow(manager->getCurrentHero(), manager->getCurrentEnemy());
	setSelectWindow();
	displaySelectWindow(manager);

        ImGui::Render();
}

void UI::flushUI()
{
    ImGui_ImplSDLRenderer2_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();
}

void UI::setTextMessage(std::string message)
{
	//std::cout << "displaying text" << std::endl;
	UI::isDisplayingText = true;
	UI::textToDisplay = message;
	//ImGui::SetCursorPos(ImVec2(20,20));

}

void UI::displayTextMessage(CombatManager *manager)
{
	if (UI::isDisplayingText)
	{
		ImGui::SetCursorPos(ImVec2(250, 10));
		ImVec2 size = ImVec2(300, 40);

		ImGui::PushStyleColor(ImGuiCol_ChildBg, ImVec4(0.0f, 0.0f, 0.0f, 1.0f)); // couleur de fond opaque (ici gris foncé)

		ImGui::BeginChild("CenteredTextBox", size, true);

		ImVec2 textSize = ImGui::CalcTextSize(UI::textToDisplay.data());
		ImGui::SetCursorPosX((size.x - textSize.x) * 0.5f);

		ImGui::TextUnformatted(UI::textToDisplay.data());

		ImGui::EndChild();

		ImGui::PopStyleColor();


		if(hasClickedThisFrame)
		{
			hasClickedThisFrame = false;
			isDisplayingText = false;
			manager->updateState();
		}

	}
}



void UI::setFightWindow()
{
	ImGui::SetNextWindowPos(ImVec2(0,0));
        ImGui::SetNextWindowSize(ImVec2(800, 400));


        ImGui::Begin("Fixed Top Panel", nullptr,
            ImGuiWindowFlags_NoMove |
            ImGuiWindowFlags_NoResize |
            ImGuiWindowFlags_NoCollapse |
            ImGuiWindowFlags_NoTitleBar);

}

/*void UI::displayFightWindow()
{
	ImGui::BeginGroup();
	ImGui::Text("Joueur");
	//ImGui::Image((void*)(intptr_t)playerTexture, ImVec2(128, 128));  // SDL_Texture à convertir
	drawHealthBar(13, 20, ImVec2(200, 20));
	ImGui::EndGroup();

	ImGui::SameLine(400);  // espace central

	// Ennemi
	ImGui::BeginGroup();
	ImGui::Text("Ennemi");
	//ImGui::Image((void*)(intptr_t)enemyTexture, ImVec2(128, 128));
	drawHealthBar(6, 20, ImVec2(200, 20));
	ImGui::EndGroup();
	ImGui::End();
}*/

void UI::displayFightWindow(Player *player, Enemy *enemy)
{

	ImVec2 spriteSize = ImVec2(128, 128);
	ImVec4 gray = ImVec4(0.5f, 0.5f, 0.5f, 1.0f);
	
	ImGui::SetCursorPos(ImVec2(100,100));
	
	ImGui::BeginGroup();
	ImGui::TextUnformatted(player->getName().data());

	drawHealthBar(player->getActualHP(), player->getMaxHP(), ImVec2(200, 20));
	ImGui::SetCursorPosX(136);
	ImGui::Dummy(spriteSize);
	ImGui::GetWindowDrawList()->AddRectFilled(
		ImGui::GetItemRectMin(), ImGui::GetItemRectMax(),
		ImGui::GetColorU32(gray)
	);

    	// Barre de vie joueur
	ImGui::EndGroup();

	ImGui::SetCursorPos(ImVec2(500,100)); // Espace central pour aérer

	// Groupe Ennemi
	ImGui::BeginGroup();
	ImGui::TextUnformatted(enemy->getName().data());

	drawHealthBar(enemy->getActualHP(), enemy->getMaxHP(), ImVec2(200, 20));
	// Placeholder : rectangle gris
	ImGui::SetCursorPosX(536);
	ImGui::Dummy(spriteSize);
	ImGui::GetWindowDrawList()->AddRectFilled(
		ImGui::GetItemRectMin(), ImGui::GetItemRectMax(),
		ImGui::GetColorU32(gray)
	);

	// Barre de vie ennemi
	ImGui::EndGroup();

	ImGui::End(); // Terminer la fenêtre "Fight Panel"
}

void UI::drawHealthBar(int hp, int maxHP, ImVec2 size)
{
	float fraction = (float)hp / maxHP;

	ImVec4 barColor = ImVec4(0.2f, 0.8f, 0.2f, 1.0f);  // vert

	if (fraction < 0.3f)
		barColor = ImVec4(0.8f, 0.2f, 0.2f, 1.0f);  // rouge
	else if (fraction < 0.6f)
		barColor = ImVec4(0.8f, 0.8f, 0.2f, 1.0f);  // jaune

	ImGui::PushStyleColor(ImGuiCol_PlotHistogram, barColor);
	ImGui::ProgressBar(fraction, size);
	ImGui::PopStyleColor();
}
