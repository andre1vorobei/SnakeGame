#pragma once

#include "Core/GameState.h"
#include "Core/GameManager.h"

class GameOverState : public GameState {
    public: 
        void Update();
        void Render();
};
