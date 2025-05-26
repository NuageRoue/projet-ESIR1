#include <SDL.h>
#include <combat/UI.h>
// Fonctions déclenchées par les boutons
void action1() { SDL_Log("Action 1 exécutée"); }
void action2() { SDL_Log("Action 2 exécutée"); }
void action3() { SDL_Log("Action 3 exécutée"); }

int main(int, char**)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_Log("SDL_Init error: %s", SDL_GetError());
        return -1;
    }

    SDL_Window* window = SDL_CreateWindow("ImGui SDL2 Renderer2",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);

    if (!window) {
        SDL_Log("SDL_CreateWindow error: %s", SDL_GetError());
        SDL_Quit();
        return -1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (!renderer) {
        SDL_Log("SDL_CreateRenderer error: %s", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }

    //UI::setUI(window, renderer);

    bool run = true;
    SDL_Event event;

    while (run)
    {
        while (SDL_PollEvent(&event))
        {
	    UI::processEvent(&event);
            if (event.type == SDL_QUIT)
                run = false;
        }

	UI::displayUI();

        SDL_SetRenderDrawColor(renderer, 114, 144, 154, 255);
        SDL_RenderClear(renderer);
	UI::render(renderer);
        SDL_RenderPresent(renderer);
    }

    UI::flushUI();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
