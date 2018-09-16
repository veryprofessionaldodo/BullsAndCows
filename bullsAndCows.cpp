#include "bullsAndCows.h"

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
    std::cout  << "A palavra tem " << WordHandlerInstance.GetWordLength() << " letras. Tenta adivinhar qual é!\n";
}

void FBullsAndCows::PlayGame()
{
    bool WantsToPlayAgain = false;


    do 
    {
        WordHandlerInstance.GenerateNewWord();

        PrintIntro( );
        
        ResetLivesNumber();

        int result = -1;
        while (result != CORRECT_GUESS && CurrentTriesRemaining > 0) 
        {
            result = DoGuess();
        }
          
        WantsToPlayAgain = GameOver(result);
    } while (WantsToPlayAgain);

}

int FBullsAndCows::DoGuess() 
{
    std::string Guess;
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
        bool IsSameWord = false;

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



void FBullsAndCows::ResetLivesNumber() 
{
    CurrentTriesRemaining = MAX_TRIES;
}




