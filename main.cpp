#include "main.h"
#include "bullsAndCows.h"
#include "wordHandler.h"
 
int main(int argc, char const *argv[])
{
    FBullsAndCows BullsAndCowsGame;

    BullsAndCowsGame.StartGame();
  
    BullsAndCowsGame.PlayGame();

    BullsAndCowsGame.EndGame();

    return 0;
}




