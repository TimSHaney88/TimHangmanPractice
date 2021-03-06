#pragma once
#ifndef GAME_H
#define GAME_H
#include "Dictionary.h"
#include "Player.h"

#include <iostream>
#include <vector>

using namespace std;

class Game
{
private:
	//total number of wrong guesses a player can have before losing
	int GuessesBeforeLoss;
	//how many letters in word chosen
	int wordLength;
	//holds chosen word
	string word;
	//vector<char> display_char_guessed
	//stores total number of guesses
	int totalNumberOfGuesses;
	//holds the number of correct guesses the player has
	int correctLetters;

public:
	//initializes game
	Game();
	Game(Player player, Dictionary dictionary);
	//gets word from dictionary
	void getWordFromDictionary(Dictionary dictionary);
	//keeps the game playing
	void Play(Player player, Dictionary dictionary);
	//checks if player wins or loses
	void winOrLoss(Player player);
	
	//resets the game
	void resetGame(Player player, Dictionary dictionary);


};


#endif

