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
	int numberOfWrongGuesses = 0;
	//asks user for number of guesses
	cout << "How many guesses do you want? ";
	cin >> numberOfWrongGuesses;
	cout << "You will get " << numberOfWrongGuesses << " before you lose" << endl;
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
	string word = dictionary.returnWord();
	//cout << word;
	//sets wordlength variable equal to number of letters in the word chosen
	wordLength = word.size();
}
void Game::Play(Player player, Dictionary dictionary)
{
	//holds a letter
	char letter;
	//holds the number of correct guesses the player has
	int correctLetters = 0;
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
	while ((player.getNumberOfWrongGuesses() < totalNumberOfGuessesBeforeLoss) && (correctLetters != wordLength))
	{
		//prompts the user to guess a letter
		cout << "Choose a letter: ";
		cin >> letter;

		//checks if input from the user is a valid letter
		if (player.isLetter(letter) == true)
		{
			
			player.alreadyGuessed = false;
			for (int i = 0; i < player.displayGuessedLetters.size(); i++)
			{
				if (player.displayGuessedLetters.at(i))
				{
					player.alreadyGuessed = true;
					cout << "Letter aleady guessed ";
					break;
				}
			}
			if (player.alreadyGuessed == true)
			{

			}
			else
			{
				//loop to check if the letter is the word
				for (int i = 0; wordLength; i++)
				{
					//checks if the letter guessed is equal to every letter
					if (letter == word[i])
					{
						//changes the char underscore for the letter
						guessedLetters[i] = letter;
						correctLetters++;
						bool isGuessCorrect = true;
					}
				}
				bool isGuessCorrect;
				//checks if the isGuessCorrect variable is equal to false
				if (isGuessCorrect == false)
				{
					//lets player know that the letter is not in the word
					cout << "That letter is not in the word, try again " << endl;

					//calls the getNewLetter function from player to increment the number of wrong guesses and total guesses by one
					player.getNewLetter(letter, isGuessCorrect);
					player.displayGuessedLetters = player.getListCharGuessed();
				}
				else
				{
					//lets player know that the letter is in the word
					cout << "You guessed a letter! " << endl;
					//calls getNewLetter function from player to incremet number of total guesses by one
					player.getNewLetter(letter, isGuessCorrect);
					player.displayGuessedLetters = player.getListCharGuessed();
				}
				//loop to display the guessedLetters array so player knows the letters guessed and get an idea of the word
				for (int i = 0; i < wordLength; i++)
				{
					cout << guessedLetters[i] << " ";
				}
				//sets the isGuessCorrect to false again
				isGuessCorrect = false;
			}
		}
		cout << endl;
		cout << endl;
		cout << "Guessed Letters: ";
		getDisplayGuessedLetter(player);
		//calls the GetListCharGuessed function from the player to display list of all the letters guessed
		player.getListCharGuessed();
		cout << endl;
		//calls the getNumOfWrongGuesses from player to display the number of wrong guesses
		cout << "How many wrong guesses?: " << player.getNumberOfWrongGuesses() << endl;
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
	if (player.getNumberOfWrongGuesses == totalNumberOfGuessesBeforeLoss)
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
void Game::getDisplayGuessedLetter(Player player)
{
	for (int i = 0; i < player.displayGuessedLetters.size(); i++)
	{
		cout << player.displayGuessedLetters[i] << " ";
	}
}
void Game::resetGame(Player player, Dictionary dictionary)
{
	//calls the reset function from play to reinitiate the variable from player class
	player.reset();
	//gets  new word
	getWordFromDictionary(dictionary);
	//calls the function to play game again
	Play(player, dictionary);
}
