#include "wordHandler.h"

int32 FWordHandler::CheckIfValidWord(FText Guess) 
{
    if (Guess.length() != CurrentWord.length()) 
    {
        std::cout << "\nYour word doesn't have " << CurrentWord.length() << " letters... Try again!\n";
        return WRONG_NUM_LETTERS;
    }

    for (int i = 0 ; i < int(Guess.length()); i++) 
    {
        for (int j = i + 1 ; j < int(Guess.length()); j++) 
        {
            if (Guess[i] == Guess[j]) 
            {
                std::cout << "\nNot an Isogram! Please try again...\n";
                return NOT_ISOGRAM;
            }
        }
    }

    return VALID_WORD;
}

int32 FWordHandler::AnalyseWordContent(FText Guess)
{
    if (Guess != CurrentWord) {
        int32 bulls = 0;
        int32 cows = 0;

        for (int i = 0 ; i < int(Guess.length()) ;i++) 
        {
            if (Guess[i] == CurrentWord[i])
                bulls++;
            else if (CheckForCow(Guess[i]))
                cows++;

        }

        std::cout << "\nThere are " << bulls << " bulls and " << cows << " cows.\n";

        return INCORRECT_GUESS;
    }

    return CORRECT_GUESS;
}

// Check if the word contains that letter in a different place
bool FWordHandler::CheckForCow(char Letter)
{
    for (int i = 0; i < int(CurrentWord.length());i++) 
    {
        if (CurrentWord[i] == Letter)
            return true;
    }
    return false;
}

bool FWordHandler::WroteYes()
{
    FText Answer;
    
    std::getline(std::cin, Answer);

    std::cout << Answer;

    return Answer[0] == 'y' || Answer == "yes" || Answer[0] == 'Y' || Answer == "Yes" || Answer == "\n";
}

void FWordHandler::GenerateNewWord() {
    CurrentWord = "merda";

}
