#pragma once

#include "values.h"
#include "wordHandler.h"


class FBullsAndCows 
{
public:
    void StartGame();

    void EndGame();

    void PrintIntro();

    void PrintRemainingTries();

    void GameLoop();

    int DoGuess();

    void PlayGame();

    bool GameOver(int result);

    void ResetLivesNumber();


private:
    int CurrentTriesRemaining;
    FWordHandler WordHandlerInstance;
};