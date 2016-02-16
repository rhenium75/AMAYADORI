#pragma once

inline int GroupNum(int num);

struct Group {
private:
	int Num;
	int Friend;
	int Enemy;
public:
	
	Group();
	Group(int);
	Group(int, int);
	Group(int, int, int);
	
	void SetNum(int);
	void SetEnemy(int);
	void SetFriend(int);
	
	void AddEnemy(int);
	void AddFriend(int);

	bool Infriend(int);
	bool Inenemy(int);

	Group copy();
	
	int operator()();
};