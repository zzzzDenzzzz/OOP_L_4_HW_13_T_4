#pragma once

class NoSequence
{
	bool init;
	int prevEl;
	int N;
	int count;
public:
	NoSequence();
	NoSequence(int N);
	bool operator()(int el);
};