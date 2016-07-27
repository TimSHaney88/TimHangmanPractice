#include "Game.h"

#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

Game::Game()
{


}
Game::Game(Player player, Dictionary dictionary)
{
	//Welcomes the player
	cout << "Welcome to hangman.  You get a certain number of guesses to figure out the secret word" << endl;
	//asks user for number of guesses
	cout << "How many guesses do you want? ";
	cin >>  GuessesBeforeLoss;
	cout << "You will get " << GuessesBeforeLoss << " before you lose" << endl;
	getWordFromDictionary(dictionary);
	//tells user how many letters are in secret word
	cout << "Your word has " << wordLength << " letters" << endl;
	//calls function to play the game
	Play(player, dictionary);
	//displayGuessedLetters() = player.getListCharGuessed();

}
void Game::getWordFromDictionary(Dictionary dictionary)
{
	string fileName = "Dictionary.txt";
	dictionary.readFromFile(fileName);
	//calls choose a word
	dictionary.chooseAWord();
	//sets string word equal to word from dictionary
	 word = dictionary.returnWord();
	//cout << word;
	//sets wordlength variable equal to number of letters in the word chosen
	wordLength = word.size();
}
void Game::Play(Player player, Dictionary dictionary)
{
	//holds a letter
	char letter;
	//holds the number of correct guesses the player has
	correctLetters = 0;
	//checks if each guess is correct or false
	bool isCorrect = false;
	//new char array equal to the length of the word chosen
	char *guessedLetters = new char[wordLength];
	//loop to set each char in the guessed letters array equals underscore
	for (int i = 0; i < wordLength; i++)
	{
		guessedLetters[i] = '_';
		cout << guessedLetters[i] << " ";
	}
	cout << endl;
	//loop to play game
	while ((GuessesBeforeLoss != 0) && (correctLetters != wordLength))
	{
		//prompts the user to guess a letter
		cout << "Choose a letter: ";
		cin >> letter;

		//checks if input from the user is a valid letter
		bool isLetterValid = player.alreadyGuessed(letter);
		if (isLetterValid == true)
		{
			cout << "Already been guessed or Invalid input" << endl;
		}
		else
		{
			bool correctGuess = false;
			for (int i = 0; i < word.size(); i++)
			{
				if (word[i] == letter)
				{
					guessedLetters[i] = letter;
					correctGuess = true;
				}
			}
			if (correctGuess == true)
			{
				correctLetters++;
			}
			else
			{
				cout << "Wrong Guess" << endl;
				GuessesBeforeLoss--;
			}
		}
		for (int i = 0; i < wordLength; i++)
		{
			
			cout << guessedLetters[i] << " ";
		}
		cout << endl;
		cout << "You have guessed these letters: ";
		player.displayGuessedLetters();
		cout << endl;


	}
		
	//calls the function to check if player wins or loses
	winOrLoss(player);
	//hold yes or no answer
	string answer;
	//prompts the player to play again
	cout << "Would you like to play again? Y or N ";
	cin >> answer;
	//if the answer is yes game resets
	if (answer == "Y" || answer == "y")
	{
		resetGame(player, dictionary);
	}

}
//checks if the player wins or loses
void Game::winOrLoss(Player player)
{
	//checks if the number of wrong guesses is equal to the total number of wrong guesses allowed by game
	if (correctLetters != wordLength)
	{
		//lets player know they lost
		cout << "Sorry, you lost." << endl;
		cout << " The word is " << word << endl;
	}
	else
	{
		cout << " You win!!  The word is " << word << endl;
	}
}

void Game::resetGame(Player player, Dictionary dictionary)
{
	//calls the reset function from play to reinitiate the variable from player class
	player.reset();
	//gets  new word
	getWordFromDictionary(dictionary);
	//calls the function to play game again
	Game(player, dictionary);
}
