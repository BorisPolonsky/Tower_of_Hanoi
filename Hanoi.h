#ifndef __HANOI_H
#define __HANOI_H
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


class Hanoi
{
public:
	Hanoi(int num=3)
	{
		if (num < 1)
			num = 1;
		a.clear();
		b.clear();
		c.clear();
		for (int i = num; i > 0; i--)
			a.push_back(i);
	}
	friend bool SearchSolution(Hanoi &Puzzle, int Origin, int Target, int num);
private:vector<int>a, b, c;
		bool Move(int, int);
		int numofdisks(int);
};

#endif