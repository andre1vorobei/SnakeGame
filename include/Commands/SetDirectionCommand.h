#pragma once

#include "Core/Command.h"
#include "Core/Snake.h"

class SetDirectionCommand : public Command {
    private:
        Direction dir;
        
    public:
        SetDirectionCommand(Direction dir);
        void Execute();
};
