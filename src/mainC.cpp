
#include "SDL_log.h"
#include "imgui.h"
#include "backends/imgui_impl_sdl2.h"
#include "backends/imgui_impl_sdlrenderer2.h"
#include "imgui.h"
#include <SDL.h>

void logSomeThing()
{
    SDL_Log("something :)");
}
int main(int, char**)
{
    // Initialisation SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_Log("SDL_Init error: %s", SDL_GetError());
        return -1;
    }

    // Création fenêtre SDL
    SDL_Window* window = SDL_CreateWindow("ImGui SDL2 Renderer2",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);

    if (!window) {
        SDL_Log("SDL_CreateWindow error: %s", SDL_GetError());
        SDL_Quit();
        return -1;
    }

    // Création renderer SDL
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (!renderer) {
        SDL_Log("SDL_CreateRenderer error: %s", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }

    // Setup ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();

    // Setup backends ImGui
    ImGui_ImplSDL2_InitForSDLRenderer(window, renderer);
    ImGui_ImplSDLRenderer2_Init(renderer);

    bool run = true;
    SDL_Event event;

    while (run)
    {
        while (SDL_PollEvent(&event))
        {
            ImGui_ImplSDL2_ProcessEvent(&event);
            if (event.type == SDL_QUIT)
                run = false;
        }

        ImGui_ImplSDLRenderer2_NewFrame();
        ImGui_ImplSDL2_NewFrame();
        ImGui::NewFrame();

        // --- Fenêtre verrouillée en bas ---
        ImGui::SetNextWindowPos(ImVec2(0, 600 - 200)); // position fixe
        ImGui::SetNextWindowSize(ImVec2(800, 200));    // taille fixe

        ImGui::Begin("Fixed Bottom Panel", nullptr,
            ImGuiWindowFlags_NoMove |
            ImGuiWindowFlags_NoResize |
            ImGuiWindowFlags_NoCollapse |
            ImGuiWindowFlags_NoTitleBar);

        ImGui::Text("Interface verrouillée en bas de l'écran.");
        if (ImGui::Button("Click me!"))
            SDL_Log("Bouton pressé 1");
        if (ImGui::Button("Click me!"))
            SDL_Log("Bouton pressé 2");
        if (ImGui::Button("Click me!"))
            SDL_Log("Bouton pressé 3");
        if (ImGui::Button("Click me!"))
            SDL_Log("Bouton pressé 4");

        ImGui::End();

        ImGui::Render();

        SDL_SetRenderDrawColor(renderer, 114, 144, 154, 255);
        SDL_RenderClear(renderer);
        ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData(), renderer);
        SDL_RenderPresent(renderer);
    }

    // Cleanup ImGui
    ImGui_ImplSDLRenderer2_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();

    // Cleanup SDL
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

