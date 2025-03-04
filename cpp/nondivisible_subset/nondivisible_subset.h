#ifndef NONDIVISIBLE_SUBSET_H
#define NONDIVISIBLE_SUBSET_H


using namespace std;

/* Nondivisible Subset (https://www.hackerrank.com/challenges/non-divisible-subset/problem?isFullScreen=true)
 *
 * Given a set of distinct integers, print the size of the maximal subset S where the sum of any two numbers in S'
 * is not evenly divisible by k
 *
 * For example, if S = [19, 10, 12, 10, 24, 25, 22], k = 4, three arrays / subsets can be created that fill this critiera:
 * S'[0] = [10, 12, 25], S'[1] = [19, 22, 24], and after testing all permutations, the maxlength solution array has 3 elements.
 *
 * Example 2: If k = 3, and S = [1, 7, 2, 4], first test all permutations of any two elements from S
 * 1 + 7 = 8
 * 1 + 2 = 3
 * 1 + 4 = 5
 * 7 + 2 = 9
 * 7 + 4 = 11
 * 2 + 4 = 6
 *
 * Then take the numbers where the sums do not ever sum to a multiple of k, or S' = [1 7 4], and this returns 3
 *
 * We can take advantage of the fact that if we take A / k, the remainder always ranges from 0 to k - 1.
 * And, if the A + B % k == 0, then the sum of their individual remainders is also divisible by k.
 * For instance, if A = 2, B = 4, k = 3, A + B = 6, 6 % 3 = 0. 2 % 3 = 2, and 4 % 3 = 1, 2 + 1 = 3 is divisible by k.
 * So, if p = (A % k) && q = (B % k) and (A + B) % k == 0, then p + q = 0 or k, and doesn't fulfill the problem requirements.
 **/


int nonDivisibleSubset(int k, vector<int> s)
{
	// Can store an array to track the remainders
	int remainders_array[k];

	for(int i = 0; i < k; i++)
	{
		remainders_array[i] = 0;
	}

	// Possible cases: 
	// 1: p = 0 && q = 0 -> two numbers evenly divisible by k cannot be in the array
	// 2: p + q = k, this also doesn't work
	// 3: k is odd, p = k - q: If there's a subset S where some numbers dividing by k gave remainder p,
	// 		and some numbers dividing by k gave remainder q, we can only include the max of them. max(x1, x2).
	// 4: k is even, p = k - q -> p = q

	for(int e : s)
	{
		int remainder = e % k;
		remainders_array[remainder] += 1;
	}

	int result = min(remainders_array[0], 1); // check if 0; 
	
	// Even:
	if(k % 2 == 0)
	{
		result += min(remainders_array[k / 2], 1);
	}

	for(int i = 1; i < (k + 1) / 2; i++)
	{
		if(i != k - 1)
		{
			result += max(remainders_array[i], remainders_array[k - i]);
		}
	}

	return result;
}




#endif
