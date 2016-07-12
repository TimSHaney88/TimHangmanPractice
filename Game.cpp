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
	getWordFromDictionary(Dictionary dictionary);
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
}
//checks if the player wins or loses
void Game::winOrLoss(Player player)
{
	//checks if the number of wrong guesses is equal to the total number of wrong guesses allowed by game

}
void Game::getDisplayGuessedLetter(Player player)
{

}
void Game::resetGame(Player player, Dictionary dictionary)
{

}
