#pragma once

inline int GroupNum(int num);

struct Team{
public:
	int Num;
	int Friend;
	int Enemy;

	Team SetNum(int);
	Team SetEnemy(int);
	Team SetFriend(int);
	void AddEnemy(int);
	void AddFriend(int);

	bool Infriend(int);
	bool Inenemy(int);

	int operator()();
	Team copy();
};