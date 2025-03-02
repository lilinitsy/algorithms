#ifndef MAX_SUBARRAY_H
#define MAX_SUBARRAY_H


// Use Kadane's algortihm
// Traverses left to right over the array, finding the max sum across all subarrays ending at that element
// To calculate the max sum of a subarray ending at the given index, we can use the max sum ending at the previous elements
// Therefore, at any element, the max subarray can be extended, adding the current element to it, or
// The subarray can start from the current element
//

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'maxSubarray' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY arr as parameter.
 *
 * First output: Max sum of the subsequence with the largest sum
 * Second output: max sum of any subsequence
 *
 * This is a stupid problem from hackerrank (https://www.hackerrank.com/challenges/maxsubarray/problem)
 * */

vector<int> maxSubarray(vector<int> arr) {
	// Many of the indices here aren't really used, because this question
	// just asked to compare the maxes.
	// Still useful to have them for debugging, and for extending this to similar questions

	// Store the best end and global idx's
	size_t best_start_idx = 0;
	size_t best_end_idx = 0;

	// Store current start and end indices
	size_t current_start_idx = 0;
	size_t current_end_idx = 0;
	int max_sum = INT_MIN;
	int intermediary_sum = 0;

	int max_sum_subseq = INT_MIN;

	for(size_t i = 0; i < arr.size(); i++)
	{
		intermediary_sum += arr[i];
		//printf("%d value\t", arr[i]);

		if(intermediary_sum > max_sum)
		{
			max_sum = intermediary_sum;
			best_start_idx = current_start_idx;
			best_end_idx = i;
		}

		if(intermediary_sum < 0)
		{
			intermediary_sum = 0;
			current_start_idx = i + 1;
		}

		// Add to the second part of this question, the sum of the subsequence. There are two cases: All negative values, in which case choose the max negative, or the other case, so sum all positive
		if(arr[i] < 0 && arr[i] > max_sum_subseq) // check against max_sum
		{
			max_sum_subseq = arr[i];
		}

		// max sum is negative, but the value we're checking is positive, assign it to the positive value
		else if(max_sum_subseq < 0 && arr[i] > 0)
		{
			max_sum_subseq = arr[i];
		}

		// max sum subseq is positive
		else if(max_sum_subseq + arr[i] > max_sum_subseq)
		{
			max_sum_subseq += arr[i];
		}

		//printf("Iteration, currstart, currend, currsum, beststart, bestend, max_sum: %lu %lu, %lu, %d, %lu, %lu, %d\n", i, current_start_idx, current_end_idx, intermediary_sum, best_start_idx, best_end_idx, max_sum);
	}

	vector<int> max_sub;
	max_sub.push_back(max_sum);
	max_sub.push_back(max_sum_subseq);
	return max_sub;
}

#endif
