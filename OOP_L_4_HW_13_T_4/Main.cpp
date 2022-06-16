#include<iostream>
#include"NoSequence.h"
#include<algorithm>

template<typename T>
void print(T *begin, T *end, char delimiter = ' ')
{
	while (begin != end)
	{
		std::cout << *begin++ << delimiter;
	}
	std::cout << "\n";
}

template<typename T, typename Predicate>
int copy_if(T *srcB, T *srcE, T *destB, T *destE, Predicate pred)
{
	int copyCount{ 0 };
	while (destB != destE and srcB != srcE)
	{
		if (pred(*srcB))
		{
			*destB++ = *srcB;
			++copyCount;
		}
		++srcB;
	}
	return copyCount;
}

int main()
{
	const int size{ 16 };
	int arr1[size]{ 9,8,9,8,9,8,1,5,4,5,4,5,1,7,1,1 };
	//int arr1[size]{ 1,1,1,1,4,4,5,5,5,7,8,8,8,9,9,9 };
	int arr2[size]{};

	int *const arr1Begin{ arr1 };
	int *const arr1End{ arr1 + size };
	int *const arr2Begin{ arr2 };
	int *const arr2End{ arr2 + size };
	int *arr2NewEnd{};

	std::cout << "Original arr1:\n";
	std::sort(arr1, arr1 + size);
	print(arr1, arr1 + size);

	std::cout << "Original arr2:\n";
	print(arr2, arr2 + size);
	std::cout << '\n';
	std::cout << "arr2 copy of arr1 without sequencing duplicates:\n";

	arr2NewEnd = arr2Begin + copy_if(arr1Begin, arr1End, arr2Begin, arr2End, NoSequence{1});
	print(arr2, arr2NewEnd);
	std::cout << '\n';

	return 0;
}