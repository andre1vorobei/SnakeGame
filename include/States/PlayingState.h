#pragma once

#include "Core/GameState.h"
#include "Core/GameManager.h"

class PlayingState : public GameState {
    public: 
        void Update();
        void Render();
};
