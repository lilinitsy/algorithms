#include <iostream>
#include <bits/stdc++.h>
#include <vector>

#include "leaderboard.h"

int main()
{
	vector<int> ranked = {100, 90, 90, 80};
	vector<int> player = {70, 80, 105};

	vector<int> test = climbingLeaderboard(ranked, player);

	for(size_t i = 0; i < test.size(); i++)
	{
		printf("%d ", test[i]);
	}

	return 0;
}
