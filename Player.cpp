#include "Player.h"

#include <iostream>
#include <vector>

using namespace std;

Player::Player()
{
	int numberOfWrongGuesses = 0;
	int totalNumberOfGuesses = 0;
	vector<char>listCharGuessed;
}
void Player::getNewLetter(char letter, bool isGuessCorrect)
{
	if (!isGuessCorrect)
	{
		++numberOfWrongGuesses;
	}
	++totalNumberOfGuesses;
	listCharGuessed.push_back(letter);
}

bool Player::isLetter(char letter) 
{
	if ((letter >= 'A' && letter <= 'Z' || letter >= 'a' && letter <= 'z'))
	{
		return true;
	}
	else return false;
}
int Player::getNumberOfWrongGuesses()
{
	return numberOfWrongGuesses;
}
int Player::getTotalNumberOfGuesses()
{
	return totalNumberOfGuesses;
}
vector<char> Player::getListCharGuessed()
{
	return listCharGuessed;
}
void Player::displayGuessedLetters()
{
	for (int i = 0; i < listCharGuessed.size(); i++)
	{
		cout << listCharGuessed[i] << " ";
	}
}
bool Player::alreadyGuessed(char guessedLetter)
{
	for (int i = 0; i < listCharGuessed.size(); i++)
	{
		if (guessedLetter == listCharGuessed[i])
		{
			return true;
		}
		else return false;
	}
	
}
void Player::reset()
{
	numberOfWrongGuesses = 0;
	totalNumberOfGuesses = 0;
	listCharGuessed.clear();
}
