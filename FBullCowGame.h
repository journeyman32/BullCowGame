//
// Created by bryan on 2/4/18.
//
#import <iostream>

#ifndef BULLCOWGAME_FBULLCOWGAME_H
#define BULLCOWGAME_FBULLCOWGAME_H


class FBullCowGame {
public:
    FBullCowGame();
    int GetMaxTries() const;
    int GetCurrentTry() const;
    bool IsGameWon() const;
    void Reset();
    bool CheckGuessValidity(std::string);
private:
    int MyCurrentTry;
    int MyMaxTries;


};


#endif //BULLCOWGAME_FBULLCOWGAME_H
