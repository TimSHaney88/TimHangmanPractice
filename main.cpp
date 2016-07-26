 #include "Dictionary.h"
#include "Player.h"
 #include "Game.h"

using namespace std;

int main()
{
	//Dictionary dictionary;
	//dictionary.readFromFile("Dictionary.txt");
	//Player player;

	Dictionary words;
	Player cPlyr;
	Game game(cPlyr, words);

	//gets  new word
	//getWordFromDictionary( dictionary);
	//calls the function to play game again
	//play(player, dictionary);
	//Player player;
	//dictionary.chooseAWord();
	//Game game();
	//cout << dictionary.returnWord() << endl;
	system("pause");
	return 0;
}