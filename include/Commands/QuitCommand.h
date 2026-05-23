#pragma once

#include "Core/Command.h"

class QuitCommand : public Command {
    public:
        void Execute();
};
