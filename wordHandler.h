#pragma once

#include "string"
#include "values.h"

using int32 = int;
using FText = std::string;

class FWordHandler {
public:
    void GenerateNewWord();

    bool IsValidWord();

    int CheckIfValidWord(std::string Guess);

    bool AnalyseGuess();

    int32 AnalyseWordContent(std::string Guess);

    bool WroteYes();

    bool CheckForCow(char Letter);

    int GetWordLength() 
    {
        return CurrentWord.length();
    }

    int32 GetBulls() { return Bulls; }
    int32 GetCows() { return Cows; }

private:
    FText CurrentWord;
    int32 Bulls;
    int32 Cows;
    
};


