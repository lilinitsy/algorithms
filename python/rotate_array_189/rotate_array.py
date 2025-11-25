class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        nums_rotated = [0] * n # List[int]
        for i in range(k, n):
            nums_rotated[i]  = nums[i - k]

        step = 0
        for i in range(n - k, n):
            nums_rotated[step] = nums[i]
            step += 1

        nums[:] = nums_rotated # Python is stupid