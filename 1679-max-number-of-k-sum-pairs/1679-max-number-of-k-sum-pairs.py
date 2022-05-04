class Solution:
    def maxOperations(self, nums: List[int], k: int) -> int:
        c=Counter(nums)
        ans=0
        seen=set()
        
        for x in c:
            if x not in seen and (k-x) in c:
                if x==(k-x):
                    ans+=c[x]//2
                else:
                    ans+=min(c[x],c[k-x])
                
                seen.add(x)
                seen.add(k-x)
                
        return ans         
                
                    
        