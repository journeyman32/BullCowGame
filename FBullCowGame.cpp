//
// Created by bryan on 2/4/18.
//

#include "FBullCowGame.h"

void FBullCowGame::Reset() {
    constexpr MAX_TRIES = 8;
    MyMaxTries = MAX_TRIES;
    MyCurrentTry = 1;
    return;
}

int FBullCowGame::GetMaxTries() const {

    return MyMaxTries;
}

bool FBullCowGame::CheckGuessValidity(std::string) {
    return false;
}

bool FBullCowGame::IsGameWon() const {
    return false;
}

int FBullCowGame::GetCurrentTry() const {
    return MyCurrentTry;
}

FBullCowGame::FBullCowGame() {
    Reset();
}
