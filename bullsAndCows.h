#pragma once

#include "values.h"
#include "wordHandler.h"

using int32 = int;

class FBullsAndCows 
{
public:
    FBullsAndCows();

    void StartGame();

    void EndGame();

    void PrintIntro();

    void PrintRemainingTries();

    void GameLoop();

    int32 DoGuess();

    void PrintGuessResult();

    void PlayGame();

    bool GameOver(int result);

    void Reset();

private:
    int32 CurrentTriesRemaining;
    FWordHandler WordHandlerInstance;
};