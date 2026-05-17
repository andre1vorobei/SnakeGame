#include "Commands/ChangeStateCommand.h"
#include "Core/GameManager.h"

ChangeStateCommand::ChangeStateCommand(GameState *_state) : state(_state) {}

void ChangeStateCommand::Execute() {
    GameManager *gm = GameManager::GetInstance();
    gm->ChangeState(state);
} 
