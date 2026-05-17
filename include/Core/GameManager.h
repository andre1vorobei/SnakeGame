#pragma once

#include "GameState.h"
#include "Command.h"

class GameManager {
    private:
        GameState *state;

        GameManager();

    public:
        GameManager(const GameManager&) = delete;

        static GameManager *GetInstance();

        void ChangeState(GameState *new_state);

        void Run();

        Command* InputHandler(char input);

        void Update();
        void Render();

        void test() {
            state->Render();
            state->Update();
        }

};
