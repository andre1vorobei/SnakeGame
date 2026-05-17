#pragma once

#include "Core/GameState.h"
#include "Core/GameManager.h"
#include "Core/Snake.h"

class PlayingState : public GameState {
    private:
        Snake *snake;
    public: 
        PlayingState(Snake *snake);
        void Update();
        void Render();
        Command *InputHandler(char input); 
};
