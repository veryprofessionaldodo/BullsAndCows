#pragma once

#include "string"
#include "values.h"

class FWordHandler {
public:
    void GenerateNewWord();

    bool IsValidWord();

    int CheckIfValidWord(std::string Guess);

    bool AnalyseGuess();

    int AnalyseWordContent(std::string Guess);

    bool WroteYes();

    int GetWordLength() 
    {
        return CurrentWord.length();
    }

private:
    std::string CurrentWord;
    
};


