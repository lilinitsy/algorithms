#include <iostream>
#include <bits/stdc++.h>
#include <vector>

#include "max_roads_2285.h"

int main()
{
	int n = 5;
	vector<vector<int>> roads = {{0, 1}, {1, 2}, {2, 3}, {0, 2}, {1, 3}, {2, 4}};
	long long ret = maximumImportance(n, roads);
	printf("%llu\n\n", ret);
	n = 5;
	roads = {{0, 3}, {2, 4}, {1, 3}};
	ret = maximumImportance(n, roads);
	printf("%llu\n\n", ret);
	return 0;
}
