#include <iostream>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
FText GetGuess();
void PlayGame();
bool AskToPlayAgain();

FBullCowGame BCGame;

int main() {

    bool bPlayAgain = false;

    do{
        PrintIntro();
        PlayGame();
        bPlayAgain = AskToPlayAgain();
    }
    while(bPlayAgain == true);
    return 0;
}

bool AskToPlayAgain() {
    std::cout << "Do you want to play again?";
    FText response = "";
    getline(std::cin, response);
    return response[0] == 'y' || response[0] == 'Y' ? true : false;
}

void PlayGame() {
    BCGame.Reset();
    int32 MaxTries = BCGame.GetMaxTries();

    for(int32 count = 1; count <=MaxTries; count++){
        FText Guess = GetGuess();

        FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);

        std::cout << "Bulls: " << BullCowCount.Bulls << " Cows: " << BullCowCount.Cows << std::endl;
    }
    return;
}

void PrintIntro() {
    std::cout << "Welcome to Bulls and Cows\n";
    std::cout << "Can you guess the " << BCGame.GetHiddenWordLength() << " letter isogram I'm thinking of?\n";
    return;
}

FText GetGuess(){
    FText WordGuess = "";
    int32 CurrentTry = BCGame.GetCurrentTry();
    std::cout << "Try " << CurrentTry << " try.\n";
    getline(std::cin, WordGuess);
    return WordGuess;
}