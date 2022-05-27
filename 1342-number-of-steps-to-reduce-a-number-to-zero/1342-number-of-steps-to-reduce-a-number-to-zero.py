class Solution(object):
    def numberOfSteps(self, num):
        c=0
        while(num!=0):
            if num%2==0:
                num=num//2
            else:
                num-=1
            c=c+1
        return c