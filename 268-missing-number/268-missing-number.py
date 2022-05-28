class Solution(object):
    def missingNumber(self, nums):
        nsum=0
        n =len(nums)
        for e in nums:
            nsum+=e
        total=n*(n+1)/2
        return total-nsum