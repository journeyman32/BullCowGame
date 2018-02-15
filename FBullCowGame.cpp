//
// Created by bryan on 2/4/18.
//

#include "FBullCowGame.h"
#include <map>

#define TMap std::map


void FBullCowGame::Reset() {
    constexpr int32 MAX_TRIES = 3;
    const FString HIDDEN_WORD = "ant";
    MyMaxTries = MAX_TRIES;
    MyHiddenWord = HIDDEN_WORD;
    MyCurrentTry = 1;
    bGameIsWon = false;
    return;
}

int32 FBullCowGame::GetMaxTries() const {

    return MyMaxTries;
}

EWordStatus FBullCowGame::CheckGuessValidity(FString Guess) const {

    if (!IsIsogram(Guess)) {
        return EWordStatus::Not_Isogram;
    } else if (!IsLowerCase(Guess)){
        return EWordStatus::Not_Lowercase;
    } else if (Guess.length() != GetHiddenWordLength()){
        return EWordStatus::Wrong_Length;
    }else{
        return EWordStatus::Ok;
    }

}

bool FBullCowGame::IsGameWon() const {
    return bGameIsWon;
}

int32 FBullCowGame::GetCurrentTry() const {
    return MyCurrentTry;
}

FBullCowGame::FBullCowGame() {
    Reset();
}

FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess) {
    //increment the turn number
    MyCurrentTry++;

    //setup return variable
    FBullCowCount BullCowCount;
    int32 HiddenWordLength = GetHiddenWordLength();
    int32 GuessLength = Guess.length();
    //loop through letters in the guess
    for(int32 i = 0; i < GuessLength; i++) {
        //compare letters against the hidden word
        for(int32 j = 0; j < HiddenWordLength; j++) {
            //if they match then
            if(Guess[i] == MyHiddenWord[j]) {
                //increment bulls if they are in the same place
                if(Guess[j] == MyHiddenWord[j]){
                    BullCowCount.Bulls++;
                }
                else {
                    //increment cows if now
                    BullCowCount.Cows++;
                }
            }
        }
    }
    if(BullCowCount.Bulls == HiddenWordLength){
        bGameIsWon = true;
    }
    else{
        bGameIsWon = false;
    }
    return BullCowCount;
}

int32 FBullCowGame::GetHiddenWordLength() const {
    return MyHiddenWord.length();
}
//cat
bool FBullCowGame::IsIsogram(FString basic_string) const {

    TMap<char,bool> LetterSeen;
    for(auto Letter: basic_string){
        Letter = tolower(Letter);
        if(LetterSeen[Letter]){
            return false;
        }else{
            LetterSeen[Letter] = true;
        }
    }
    return true;
}

bool FBullCowGame::IsLowerCase(FString basic_string) const {

    for(int i=0; i < basic_string.length(); i++) {
        if(std::tolower(basic_string[i]) != basic_string[i]) {
            return false;
        }
    }

    return true;

}
