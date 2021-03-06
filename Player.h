#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <vector>

using namespace std;

class Player
{
private:

	
	//stores list of characters guessed by the player
	vector<char>listCharGuessed;

public:
	//Constructor
	Player();
	
	//verifies if input is alphabet or not
	bool isLetter(char letter);
	
	//returns a list of charcters guessed
	vector<char>getListCharGuessed();
	//displays guessed letters
	void displayGuessedLetters();
	//returns true or false for if letter was already guessed
	bool alreadyGuessed(char guessedLetter);
	//sets all the variables to zero and clears the guessed list
	void reset();


};

#endif // PLAYER.H