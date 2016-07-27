#include "Player.h"

#include <iostream>
#include <vector>

using namespace std;

Player::Player()
{
	
	
}


bool Player::isLetter(char letter) 
{
	if ((letter >= 'A' && letter <= 'Z' || letter >= 'a' && letter <= 'z'))
	{
		return true;
	}
	else return false;
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
	}
	if (isLetter(guessedLetter) == true)
	{
		listCharGuessed.push_back(guessedLetter);
		return false;
	}
	else
	{
		cout << "Invalid Input." << endl;
		return true;
	}
	
}
void Player::reset()
{
	
	listCharGuessed.clear();
}
