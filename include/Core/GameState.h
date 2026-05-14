#pragma once

class GameManager;

class GameState {
    protected: 
        GameManager *manager;
        GameState();

    public:
        virtual void Render() =0;
        virtual void Update() =0;

};
