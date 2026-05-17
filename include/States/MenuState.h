#pragma once

#include "Core/GameState.h"
#include "Core/GameManager.h"

class MenuState : public GameState {
    public: 
        void Update();
        void Render();
        Command* InputHandler(char input);
};
