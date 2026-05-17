#include "Core/GameManager.h"
#include "Core/Kbhit.h"
#include <unistd.h>
#include <cstdio>


GameManager::GameManager() : snake(new Snake(defaultH, defaultW)) { 
}

Snake *GameManager::GetSnake() {
    return snake;
}

GameManager *GameManager::GetInstance() {
    static GameManager manager;
    return &manager;
}

void GameManager::ChangeState(GameState *new_state) {
    delete state;
    state = new_state;
}

Command* GameManager::InputHandler(char input) {
    return state->InputHandler(input);
}

void GameManager::Update() {
    state->Update();
}

void GameManager::Render() {
    state->Render();
}

void GameManager::Run() {
    while(1) {
        if (Kbhit()) {
            char input = getchar();
            Command *cmd = InputHandler(input);     
            if (cmd) cmd->Execute();
            delete cmd;
        }

        Update();
        Render();
        usleep(500000);
    }
}
