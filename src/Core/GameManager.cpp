#include "Core/GameManager.h"


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
