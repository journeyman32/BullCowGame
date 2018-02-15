//
// Created by bryan on 2/4/18.
//
#include <iostream>

using FString = std::string;
using int32 = int;

struct FBullCowCount{
    int32 Bulls =0;
    int32 Cows = 0;
};

enum EWordStatus{
    Invalid,
    Ok,
    Not_Isogram,
    Wrong_Length,
    Not_Lowercase,

};


class FBullCowGame {
public:
    FBullCowGame();
    int32 GetMaxTries() const;
    int32 GetCurrentTry() const;
    bool IsGameWon() const;
    int32 GetHiddenWordLength() const;
    void Reset();
    EWordStatus CheckGuessValidity(FString) const;
    FBullCowCount SubmitValidGuess(FString);
private:
    int32 MyCurrentTry;
    int32 MyMaxTries;
    FString MyHiddenWord;
    bool bGameIsWon;

    bool IsIsogram(FString basic_string) const;

    bool IsLowerCase(FString basic_string) const;
};


