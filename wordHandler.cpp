#include "wordHandler.h"

int32 FWordHandler::CheckIfValidWord(FText Guess) 
{
    if (Guess.length() != CurrentWord.length()) 
    {
        std::cout << "\nA tua palavra não tem " << CurrentWord.length() << " letras... Tenta outra vez!\n";
        return WRONG_NUM_LETTERS;
    }

    for (int i = 0 ; i < Guess.length(); i++) 
    {
        for (int j = i + 1 ; j < Guess.length(); j++) 
        {
            if (Guess[i] == Guess[j]) 
            {
                std::cout << "\nNão é um isograma!";
                return NOT_ISOGRAM;

            }
        }
    }

    return VALID_WORD;
}

int FWordHandler::AnalyseWordContent(FText Guess)
{
    return INCORRECT_GUESS;
}

bool FWordHandler::WroteYes()
{
    FText Answer;
    
    std::getline(std::cin, Answer);

    return Answer[0] == 'y' || Answer == "yes" || Answer[0] == 'Y' || Answer == "Yes";
}

void FWordHandler::GenerateNewWord() {
    CurrentWord = "merda";

}
