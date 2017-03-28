#include "Player.h"




void Player::setSize(const int & r)
{
	size = r;
}

void Player::setMyShips(const int** t)
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			myShips[i][j] = t[i][j];
		}
	}
}

void Player::setStatistics(const vector<int> t)
{
	statistics = t;
}





int** Player::getMyShips() const
{
	return myShips;
}

vector<int> Player::getStatistics() const
{
	return statistics;
}


void Player::shoot(const int & wiersz, const int & kolumna)
{

	if (wiersz >= size || wiersz < 0 || kolumna >= size || kolumna < 0)
	{
		cout << "wrong coordinates!" << endl;
		statistics.push_back(-1);
	}

	else
	{

		if (myShips[wiersz][kolumna] == 1)
		{
			cout << "hit!" << endl;
			//checking if the ship is only hit or shot:
			if ((kolumna + 1 >= size || myShips[wiersz][kolumna + 1] == 0) &&
				(kolumna - 1 <= size || myShips[wiersz][kolumna - 1] == 0) &&
				(wiersz + 1 >= size || myShips[wiersz + 1][kolumna] == 0) &&
				(wiersz - 1 <= size || myShips[wiersz - 1][kolumna] == 0))
			{
				cout << "hit and shot!" << endl;
			}


			myShips[wiersz][kolumna] = 0;

			opponentShips[wiersz][kolumna] = 1;

			statistics.push_back(1);
		}
		else
		{
			cout << "missed!" << endl;
			statistics.push_back(0);
		}
	}


}

void Player::showStats()
{
	for (const auto& a : statistics)
	{
		cout << a << " ";
	}
	cout << endl;
	cout << "1 - ship hit" << endl << "0 - missed" << endl << "-1 - wrong coordinates" << endl;
}

bool Player::ifEnd()
{
	
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j<size; j++)
		{
			if (myShips[i][j] == 1)
			{
				return false;
			}
		}
	}
	return true;
}


Player::Player(const string & nazwaPliku)
{
	setSize(10);
	myShips = new int*[size];
	for (int i = 0; i < size; i++)
	{
		myShips[i] = new int[size];
	}

	opponentShips = new int*[size];
	for (int i = 0; i < size; i++)
	{
		opponentShips[i] = new int[size];
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			opponentShips[i][j] == 0;
		}
	}

	ifstream odczyt;
	odczyt.open(nazwaPliku);
	if (odczyt.is_open())
	{
		int temp;
		vector<int> pom;
		while (!odczyt.eof())
		{
			odczyt >> temp;
			odczyt.get();
			pom.push_back(temp);
		}
		int idx = 0;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				myShips[i][j] = pom[idx];
				idx++;
			}
		}
		odczyt.close();
	}
	else cout << "blad odczytu" << endl;

}

Player::Player(const Player & p)
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			this->myShips[i][j] = p.myShips[i][j];
		}
	}
}

Player::~Player()
{
	for (int i = 0; i < size; i++)
	{
		delete myShips[i];
	}
	delete[] myShips;

	for (int i = 0; i < size; i++)
	{
		delete opponentShips[i];
	}
	delete[] opponentShips;
}



ostream & operator<<(ostream & out, const Player & p1)
{
	for (int i = 0; i < p1.size; i++)
	{
		for (int j = 0; j < p1.size; j++)
		{
			out << p1.opponentShips[i][j] << " ";
		}
		out << endl;
	}
	return out;
}
