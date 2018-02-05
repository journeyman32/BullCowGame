#include <iostream>
#include <string>
#include "FBullCowGame.h"

void PrintIntro();
std::string GetGuess();
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
    std::string response = "";
    getline(std::cin, response);
    return response[0] == 'y' || response[0] == 'Y' ? true : false;
}

void PlayGame() {
    BCGame.Reset();
    int MaxTries = BCGame.GetMaxTries();
    std::cout << MaxTries;

    for(int count = 1; count <=MaxTries; count++){
        std::string Guess = GetGuess();
    }
}

void PrintIntro() {
    constexpr int WORD_LENGTH = 5;
    std::cout << "Welcome to Bulls and Cows\n";
    std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?\n";
    return;
}

std::string GetGuess(){
    std::string WordGuess = "";
    int CurrentTry = BCGame.GetCurrentTry();
    std::cout << "Try " << CurrentTry << " try.\n";
    getline(std::cin, WordGuess);
    return WordGuess;
}