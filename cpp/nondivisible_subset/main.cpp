#include <iostream>
#include <bits/stdc++.h>
#include <vector>

#include "nondivisible_subset.h"

int main()
{
	vector<int> s1 = {19, 10, 12, 10, 24, 25, 22};
	int result = nonDivisibleSubset(4, s1);
	printf("Result: %d\n", result);

	vector<int> s2 = {1, 7, 2, 4};
	result = nonDivisibleSubset(3, s2);
	printf("Result: %d\n", result);

	return 0;
}
