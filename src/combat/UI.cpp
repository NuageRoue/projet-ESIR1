#include <combat/UI.h>
#include <iostream>
#include <string>

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
void UI::setUI(SDL_Window* window, SDL_Renderer* renderer)
{
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();

    UI::isDisplayingText = false;
    ImGui_ImplSDL2_InitForSDLRenderer(window, renderer);
    ImGui_ImplSDLRenderer2_Init(renderer);

}
void UI::setWindow()
{
        ImGui_ImplSDLRenderer2_NewFrame();
        ImGui_ImplSDL2_NewFrame();
        ImGui::NewFrame();

        ImGui::SetNextWindowPos(ImVec2(0, 600 - 200));
        ImGui::SetNextWindowSize(ImVec2(800, 200));

        ImGui::Begin("Fixed Bottom Panel", nullptr,
            ImGuiWindowFlags_NoMove |
            ImGuiWindowFlags_NoResize |
            ImGuiWindowFlags_NoCollapse |
            ImGuiWindowFlags_NoTitleBar);
	
}

void UI::displayAttacks()
{
    bool disabled = UI::isDisplayingText;
    if (disabled)
        ImGui::BeginDisabled();

    ImGui::SetCursorPos(ImVec2(100, 40));
    if (ImGui::Button("Action 1", ImVec2(250, 40)))
        useAttack(1);

    ImGui::SetCursorPos(ImVec2(450, 40));
    if (ImGui::Button("Action 2", ImVec2(250, 40)))
        useAttack(2);

    ImGui::SetCursorPos(ImVec2(100, 120));
    if (ImGui::Button("Action 3", ImVec2(250, 40)))
        useAttack(3);

    ImGui::SetCursorPos(ImVec2(450, 120));
    if (ImGui::Button("Action 4", ImVec2(250, 40)))
        useAttack(4);

    if (disabled)
        ImGui::EndDisabled();
    	
	if(hasClickedThisFrame)
	{
		hasClickedThisFrame = false;
		isDisplayingText = false;
	}
}

void UI::useAttack(int id)
{
	if (UI::isDisplayingText)
		return;
	std::cout << "Using attack " << id << "." << std::endl ;
	//std::string message = "attaque " + std::to_string(id);
	displayTextMessage("attaque " + std::to_string(id));
}

void UI::displayUI()
{
	setWindow();
	displayAttacks();
	renderMessages();

        ImGui::End();
        ImGui::Render();
}

void UI::flushUI()
{
    ImGui_ImplSDLRenderer2_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();
}

void UI::displayTextMessage(std::string message)
{
	std::cout << "displaying text" << std::endl;
	UI::isDisplayingText = true;
	UI::textToDisplay = message;
	//ImGui::SetCursorPos(ImVec2(20,20));

}

void UI::renderMessages()
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
	}
}
