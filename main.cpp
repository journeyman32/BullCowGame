#include <iostream>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
FText GetValidGuess();
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
        FText Guess = GetValidGuess();

        FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);

        std::cout << "Bulls: " << BullCowCount.Bulls << " Cows: " << BullCowCount.Cows << std::endl;
    }
    return;
}

void PrintIntro() {
    std::cout << "Welcome to Bulls and Cows\n";
    std::cout << "Can you guess the " << BCGame.GetHiddenWordLength() << " letter isogram I'm thinking of?\n";
    return;
}

FText GetValidGuess() {
    EWordStatus Status;

    do {
        int32 CurrentTry = BCGame.GetCurrentTry();

        std::cout << "Try " << CurrentTry << ". Enter your guess: ";
        FText Guess = "";
        std::getline(std::cin, Guess);

        Status = BCGame.CheckGuessValidity(Guess);
        switch (Status) {
            case EWordStatus::Wrong_Length:
                std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n";
                break;
            case EWordStatus::Not_Lowercase:
                std::cout << "Please enter word in lowercase.\n";
                break;
            case EWordStatus::Not_Isogram:
                std::cout << "Word entered is not an isogram.\n";
                break;
            default:
                return Guess;
        }

    } while (Status != EWordStatus::Ok);
}