#pragma once

#include "Core/Command.h"
#include "Core/GameState.h"

class ChangeStateCommand : public Command {
    private:
        GameState* state;
        
    public:
        ChangeStateCommand(GameState* state);
        void Execute();
};
