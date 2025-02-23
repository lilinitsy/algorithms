#include <iostream>
#include <vector>

#include "segment_tree.h"


int main()
{
	std::vector<std::vector<long long>> segments = {{1, 1}, {2, 2}, {3, 5}};

	long long max_byte = 0;
	for(std::vector<long long> segment : segments)
	{
		max_byte = std::max(segment[1], max_byte);
	}

	SegmentTree tree(max_byte + 1);

	std::vector<long long> result;
	for(std::vector<long long> segment : segments)
	{
		long long left  = segment[0];
		long long right = segment[1];
		tree.insert(left, right);
		result.push_back(tree.get_total_coverage());
	}

	for(long long value : result)
	{
		printf("%llu ", value);
	}

	printf("\n");

	return 0;
}
