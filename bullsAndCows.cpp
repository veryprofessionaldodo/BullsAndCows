#include "bullsAndCows.h"

using int32 = int;
using FString = std::string;

FBullsAndCows::FBullsAndCows() 
{
    Reset();
}

void FBullsAndCows::StartGame() 
{
    std::cout << "Howdy!\n" << "Let's play with words, shall we?\n"; 
}

void FBullsAndCows::EndGame() 
{
    std::cout << "\n\nThanks for playing!\n\n";
}


void FBullsAndCows::PrintIntro() 
{
    std::cout  << "The word has " << WordHandlerInstance.GetWordLength() << " letters. " <<
    "Try and guess what it is!\n";
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
    
    return WordHandlerInstance.AnalyseWordContent(Guess);
}



void FBullsAndCows::PrintRemainingTries() 
{
    std::cout << "\nYou have " << CurrentTriesRemaining << " tries remaining.\n";
    std::cout << "Write your word of " << WordHandlerInstance.GetWordLength() << " letters: ";
}


bool FBullsAndCows::GameOver(int result) 
{
    if (result == CORRECT_GUESS)
    {
        std::cout << "\n\nNice!!! Wanna try again? (y/n) \n";
        return WordHandlerInstance.WroteYes();
        
    } else // No tries remaining
    {
        bool WantsToPlayAgain = false;
       
        std::cout << "\n\nHang in there, you'll get'em next time! Want to try again? (y/n) \n";

        WantsToPlayAgain = WordHandlerInstance.WroteYes();

        std::cout << "\nWith the same word? (y/n) \n";

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




