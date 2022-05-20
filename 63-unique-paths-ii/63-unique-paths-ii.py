class Solution(object):
    def uniquePathsWithObstacles(self, obstacleGrid):
        if obstacleGrid[-1][-1] == 1 or obstacleGrid[0][0] == 1:
            return 0

        dp = [[0] * len(obstacleGrid[0]) for i in range(len(obstacleGrid))] # DP Matrix of size m*n intialized to 0
        dp[0][0] = 1

        for r in range(len(obstacleGrid)):
            for c in range(len(obstacleGrid[0])):
                if obstacleGrid[r][c] == 0:
                    #dp[r][c] += dp[r - 1][c] if r - 1 >= 0 else 0
                    #dp[r][c] += dp[r][c - 1] if c - 1 >= 0 else 0
                    if r-1 >= 0:
                        dp[r][c] += dp[r - 1][c]
                    else: dp[r][c]+=0
                        
                    if c-1 >=0:
                        dp[r][c] += dp[r][c - 1]
                    else: dp[r][c]+=0
                    
        return dp[-1][-1]
