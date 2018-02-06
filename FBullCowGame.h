//
// Created by bryan on 2/4/18.
//
#import <iostream>

using FString = std::string;
using int32 = int;

struct FBullCowCount{
    int32 Bulls =0;
    int32 Cows = 0;
};

class FBullCowGame {
public:
    FBullCowGame();
    int32 GetMaxTries() const;
    int32 GetCurrentTry() const;
    bool IsGameWon() const;
    int32 GetHiddenWordLength() const;
    void Reset();
    bool CheckGuessValidity(FString) const;
    FBullCowCount SubmitGuess(FString);
private:
    int32 MyCurrentTry;
    int32 MyMaxTries;
    FString MyHiddenWord;


};


