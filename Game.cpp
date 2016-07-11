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
	cout << word;
}
void Game::Play(Player player, Dictionary dictionary) 
{

}
void Game::winOrLoss(Player player)
{

}
void Game::getDisplayGuessedLetter(Player player)
{

}
void Game::resetGame(Player player, Dictionary dictionary)
{

}
