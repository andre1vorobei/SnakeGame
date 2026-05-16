#include "Core/GameManager.h"
#include <unistd.h>


GameManager::GameManager() { 
}

GameManager *GameManager::GetInstance() {
    static GameManager manager;
    return &manager;
}

void GameManager::ChangeState(GameState *new_state) {
    delete state;
    state = new_state;
}

void GameManager::Run() {
    while(1) {
        state->Update();
        state->Render();
        sleep(1);
    }
}
