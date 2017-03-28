#pragma once
#include "Libs.h"
class Player
{
private:
	int** myShips;
	int size;
	int** opponentShips;
	vector<int> statistics;

	void setSize(const int& r);
public:
	void setMyShips(const int** t);
	void setStatistics(const vector<int> t);

	int** getMyShips() const;
	vector<int> getStatistics() const;

	void shoot(const int& wiersz, const int& kolumna);

	void showStats();

	bool ifEnd();

	Player(const string& nazwaPliku);
	Player(const Player& p);

	friend ostream& operator<<(ostream& out, const Player& p1);

	Player() = default;
	~Player();
};

