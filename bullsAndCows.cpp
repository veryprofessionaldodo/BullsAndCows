#include "bullsAndCows.h"

using int32 = int;
using FString = std::string;

FBullsAndCows::FBullsAndCows() 
{
    Reset();
}

void FBullsAndCows::StartGame() 
{
    std::cout << "Boas maluco!\n" << "Vamos fazer cenas com palavras?\n"; 
}

void FBullsAndCows::EndGame() 
{
    std::cout << "\n\nObrigado por teres jogado!\n\n";
}


void FBullsAndCows::PrintIntro() 
{
    std::cout  << "A palavra tem " << WordHandlerInstance.GetWordLength() << " letras. " <<
    "Tenta adivinhar qual é!\n";
}

void FBullsAndCows::PlayGame()
{
    bool WantsToPlayAgain = false;

    do 
    {
        WordHandlerInstance.GenerateNewWord();

        PrintIntro( );
        
        Reset();

        int32 result = -1;
        while (result != CORRECT_GUESS && CurrentTriesRemaining > 0) 
        {
            result = DoGuess();
        }
          
        WantsToPlayAgain = GameOver(result);
    } while (WantsToPlayAgain);

}

int FBullsAndCows::DoGuess() 
{
    FString Guess;
    int GuessCheck;

    do 
    {
        PrintRemainingTries();

        std::getline(std::cin, Guess, '\n');
        
        GuessCheck = WordHandlerInstance.CheckIfValidWord(Guess);
    } while (GuessCheck != VALID_WORD);

    CurrentTriesRemaining--;

    PrintGuessResult();
    
    return WordHandlerInstance.AnalyseWordContent(Guess);
}

void FBullsAndCows::PrintGuessResult() 
{

}

void FBullsAndCows::PrintRemainingTries() 
{
    std::cout << "\nTens " << CurrentTriesRemaining << " tentativas restantes.\n";
    std::cout << "Escreve a tua palavra de " << WordHandlerInstance.GetWordLength() << " letras: ";
}


bool FBullsAndCows::GameOver(int result) 
{
    if (result == CORRECT_GUESS)
    {
        std::cout << "\n\nBoa!!! Queres jogar outra vez? (y/n) \n";
        return WordHandlerInstance.WroteYes();
        
    } else // No tries remaining
    {
        bool WantsToPlayAgain = false;
       
        std::cout << "\n\nDeixa lá, da próxima consegues! Queres tentar de novo? (y/n) \n";

        WantsToPlayAgain = WordHandlerInstance.WroteYes();

        std::cout << "\nCom a mesma palavra? (y/n) \n";

        if (!WordHandlerInstance.WroteYes()) // Wants to play with a different word
        {  
            WordHandlerInstance.GenerateNewWord();
        }

        return WantsToPlayAgain;
    }
}



void FBullsAndCows::Reset() 
{
    CurrentTriesRemaining = MAX_TRIES;
}




