#include "wordHandler.h"

int FWordHandler::CheckIfValidWord(std::string Guess) 
{
    if (Guess.length() != CurrentWord.length()) 
    {
        std::cout << "\nA tua palavra não tem " << CurrentWord.length() << " letras... Tenta outra vez!\n";
        return WRONG_NUM_LETTERS;
    }

    return VALID_WORD;
}

int FWordHandler::AnalyseWordContent(std::string Guess)
{
    return INCORRECT_GUESS;
}

bool FWordHandler::WroteYes()
{
    std::string Answer;
    
    std::getline(std::cin, Answer);

    return Answer[0] == 'y' || Answer == "yes" || Answer[0] == 'Y' || Answer == "Yes";
}

void FWordHandler::GenerateNewWord() {
    CurrentWord = "merda";

}
