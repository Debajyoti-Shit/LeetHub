class Solution(object):
    def countSubstrings(self, s):
        count = 0
        n = len(s)
        if n==0:return 0
        for i in range(n):
            count+=1
            left, right = i-1, i+1
            while right< n and s[right] == s[i]:
                right+=1
                count+=1
                
            while left>=0 and right<n and s[left] == s[right]:
                count+=1
                left-=1
                right+=1
                
        return count
