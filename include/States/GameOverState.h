#pragma once

#include "Core/GameState.h"
#include "Core/GameManager.h"

class GameOverState : public GameState {
    public: 
        Command *InputHandler(char input);
        void Update();
        void Render();
};
