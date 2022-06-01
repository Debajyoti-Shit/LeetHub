class Solution(object):
    def runningSum(self, nums):
        i=1
        while(i< len(nums)):
            nums[i]+=nums[i-1]
            i+=1
        return nums    