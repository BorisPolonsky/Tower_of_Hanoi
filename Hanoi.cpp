#include "Hanoi.h"

bool SearchSolution(Hanoi &Puzzle,int Origin,int Target,int num)
{
	if (Origin > 0 && Origin < 4 && Target>0 && Target < 4 && Origin != Target&&(num <= Puzzle.numofdisks(Origin)))
	{
		if (num == 3)
		{
			Puzzle.Move(Origin, Target);
			Puzzle.Move(Origin, 6 - Origin - Target);
			Puzzle.Move(Target, 6 - Origin - Target);
			Puzzle.Move(Origin, Target);
			Puzzle.Move(6 - Origin - Target, Origin);
			Puzzle.Move(6 - Origin - Target, Target);
			Puzzle.Move(Origin, Target);
			return(true);
		}
		else if (num == 2)
		{
			Puzzle.Move(Origin, 6 - Target - Origin);
			Puzzle.Move(Origin, Target);
			Puzzle.Move(6 - Target - Origin, Target);
			return(true);
		}
		else if (num == 1)
		{
			Puzzle.Move(Origin, Target);
			return (true);
		}
		else
		{
			SearchSolution(Puzzle, Origin, 6 - Origin - Target, num - 1);
			Puzzle.Move(Origin, Target);
			SearchSolution(Puzzle, 6 - Origin - Target, Target, num - 1);
			return(true);
		}
	}
	else
	{
		cout << "Invalid Input! " << endl;
		return(false);
	}
}

bool Hanoi::Move(int Origin,int Target)
{
	if (Origin > 0 && Origin < 4 && Target>0 && Target < 4&&Origin!=Target)
	{
		int num = 0;
		switch (Origin)
		{
		case 1:
			num = this->a.back();
			this->a.pop_back();
			break;
		case 2:
			num = this->b.back();
			this->b.pop_back();
			break;
		case 3:
			num = this->c.back();
			this->c.pop_back();
			break;
		}

		switch (Target)
		{
		case 1:
			this->a.push_back(num);
			break;
		case 2:
			this->b.push_back(num);
			break;
		case 3:
			this->c.push_back(num);
			break;
		}
		cout << "Move disk " << num << " from rod " << Origin << " to rod " << Target << ". " << endl;
		return (true);
	}
	else
	{
		cout << "Unable to move from rod " << Origin << " to rod " << Target << ". " << endl;
		return (false);
	}
}

int Hanoi::numofdisks(int rodnum)
{
	switch (rodnum)
	{
	case 1:
		return(this->a.size());
	case 2:
		return(this->b.size());
	case 3:
		return(this->c.size());
	default:
		return (0);
	}
}