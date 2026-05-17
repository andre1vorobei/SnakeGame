#pragma once

#include "GameState.h"
#include "Command.h"
#include "Snake.h"

const int defaultH = 23;
const int defaultW = 42;


class GameManager {
    private:
        GameState *state;
        Snake *snake;

        GameManager();

    public:
        Snake *GetSnake();
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
