#include "NoSequence.h"

NoSequence::NoSequence()
{
	init = false;
	prevEl = 0;
	count = 0;
	N = 0;
}

NoSequence::NoSequence(int N)
{
	init = false;
	prevEl = 0;
	count = 0;
	this->N = N;
}

bool NoSequence::operator()(int el)
{
	if (init)
	{
		bool result{ prevEl != el };
		if (result)
		{
			prevEl = el;
			count = 0;
		}
		else
		{
			count++;
			if (count <= N)
			{
				return false;
			}
			else
			{
				count = 0;
				return true;
			}
		}
		return result;
	}
	init = true;
	prevEl = el;
	return true;
}