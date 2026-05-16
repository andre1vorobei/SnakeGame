#pragma once

#include "GameState.h"

class GameManager {
    private:
        GameState *state;

        GameManager();

    public:
        GameManager(const GameManager&) = delete;

        static GameManager *GetInstance();

        void ChangeState(GameState *new_state);

        void Run();

        void test() {
            state->Render();
            state->Update();
        }

};
