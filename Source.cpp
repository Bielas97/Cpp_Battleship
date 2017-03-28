#include "Player.h"

int main()
{
	cout << "----------BATTLESHIP GAME----------" << endl << endl;
	cout << "enter row firstly, then column. Both start from 0" << endl << endl;

	Player p1("plansza1.txt");   //maps are loaded from .txt files which you should fill with 1 - ships and 0 - no ships
	Player p2("plansza2.txt");   //there is one ship with one "1" long, two ships with two "1"'s one with three "1"'s and
								 // one with four "1"'s
								// maps are sized 10x10 
								//players should enter columns and rows beginning from 0 to 9
	cout << "Enter your names: " << endl;   //interface
	string user1, user2;
	cout << "first player: ";
	cin >> user1;
	cin.get();
	cout << "second player: ";
	cin >> user2;
	cin.get();

	int row, column;
	int round = 1;
	while (!p1.ifEnd() && !p2.ifEnd())  //GAME!
	{			
		cout << endl;
		cout << "ROUND " << round << endl << endl;
		cout << user1 << " It's your turn!" << endl;
		cout << "row: ";
		cin >> row;
		cin.get();
		cout << "column: ";
		cin >> column;
		cin.get();
		p2.shoot(row, column);
		cout << "enemy's hit ships:" << endl << endl;
		cout << p2;
		cout << endl;

		cout << user2 << " It's your turn!" << endl;
		cout << "row: ";
		cin >> row;
		cin.get();
		cout << "column: ";
		cin >> column;
		cin.get();
		p1.shoot(row, column);
		cout << "enemy's hit ships:" << endl << endl;
		cout << p1;
		cout << endl;

		round++;
	}
									 //end of the game
	if (p1.ifEnd())
	{
		cout << endl << "THE END!" << endl;
		cout << "player " << user2 << " won!" << endl;
		cout << "statistics: " << endl;
		p1.showStats();
	}
	if (p2.ifEnd())
	{
		cout << endl << "THE END!" << endl;
		cout << "player " << user1 << " won!" << endl;
		cout << "statistics: " << endl;
		p2.showStats();
	}
	
	cin.get();
	return 0;
}