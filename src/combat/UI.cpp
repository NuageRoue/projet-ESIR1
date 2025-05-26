#include <combat/UI.h>
#include <iostream>

#include "imgui.h"
#include "backends/imgui_impl_sdl2.h"
#include "backends/imgui_impl_sdlrenderer2.h"

void UI::processEvent(const SDL_Event *event)
{
            ImGui_ImplSDL2_ProcessEvent(event);
}
void UI::render(SDL_Renderer *renderer)
{
        ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData(), renderer);
}
void UI::setUI(SDL_Window* window, SDL_Renderer* renderer)
{
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();

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
	// a terme, les attaques viendront du joueur;
	
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
}

void UI::useAttack(int id)
{
	std::cout << "Using attack " << id << "." << std::endl ;
}

void UI::displayUI()
{
	setWindow();
	displayAttacks();

        ImGui::End();
        ImGui::Render();
}

void UI::flushUI()
{
    ImGui_ImplSDLRenderer2_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();
}
