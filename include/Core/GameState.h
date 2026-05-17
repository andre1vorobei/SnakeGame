#pragma once

#include "Core/Command.h"

class GameManager;

class GameState {
    protected: 
        GameManager *manager;
        GameState();

    public:
        virtual void Render() =0;
        virtual void Update() =0;
        virtual Command* InputHandler(char input) =0;

};
