 #include "Dictionary.h"
// #include "Player.h"
// #include "Game.h"

using namespace std;

int main()
{
	Dictionary dictionary;
	dictionary.ReadFromFile("Dictionary.txt");
	dictionary.ChooseAWord();
	cout << dictionary.ReturnWord() << endl;
	system("pause");
	return 0;
}