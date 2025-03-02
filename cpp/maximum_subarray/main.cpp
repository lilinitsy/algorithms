#include <iostream>
#include <bits/stdc++.h>
#include <vector>

#include "max_subarray.h"

int main()
{
	std::vector<int> test1 = {1, 2, 3, 4};
	std::vector<int> test2 = {2, -1, 2, 3, 4, -5};
	std::vector<int> test3 = {-2, -3, -1, -4, -6};
	std::vector<int> test4 = {2, -1, 2, 3, 4, -5};
	std::vector<int> test5 = {-1, 2, 3, -4, 5, 10};

	std::vector<int> output1 = maxSubarray(test1);
	std::vector<int> output2 = maxSubarray(test2);
	std::vector<int> output3 = maxSubarray(test3);
	std::vector<int> output4 = maxSubarray(test4);
	std::vector<int> output5 = maxSubarray(test5);

	printf("Test1: %d %d\n", output1[0], output1[1]);
	printf("Test2: %d %d\n", output2[0], output2[1]);
	printf("Test3: %d %d\n", output3[0], output3[1]);
	printf("Test4: %d %d\n", output4[0], output4[1]);
	printf("Test5: %d %d\n", output5[0], output5[1]);

	return 0;
}
