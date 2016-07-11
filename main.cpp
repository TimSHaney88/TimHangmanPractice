 #include "Dictionary.h"
// #include "Player.h"
// #include "Game.h"

using namespace std;

int main()
{
	Dictionary dictionary;
	//dictionary.readFromFile("Dictionary.txt");
	
	//Player player;
	dictionary.chooseAWord();
	//Game game();
	cout << dictionary.returnWord() << endl;
	system("pause");
	return 0;
}