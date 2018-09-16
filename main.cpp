
#include "main.h"
#include "bullsAndCows.h"
#include "wordHandler.h"

 int WORD_LENGTH = 5;
 int LivesRemaining;

 
int main(int argc, char const *argv[])
{
    FBullsAndCows BullsAndCowsGame;

    BullsAndCowsGame.StartGame();
  
    BullsAndCowsGame.PlayGame();

    BullsAndCowsGame.EndGame();

    return 0;
}




