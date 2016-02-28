#pragma once

inline int GroupNum(int num);

struct Team{
public:
	int Num = 0;
	int Friend = 0;
	int Enemy = 0;

	Team();
	Team* SetNum(int);
	Team* SetEnemy(int);
	Team* SetFriend(int);
	void AddEnemy(int);
	void AddFriend(int);

	int GetNum();

	bool Infriend(int);
	bool Inenemy(int);

	int operator()();
	Team* copy();
};