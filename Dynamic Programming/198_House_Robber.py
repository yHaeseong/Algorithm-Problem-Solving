class Solution:
    #DP Table
    dp = collections.defaultdict(int)
    def rob(self, nums: List[int]) -> int:
        n = len(nums)

        self.dp[0] = nums[0]
        #DP Initialization
        if n == 1:
            return nums[0]
        
        if n == 2:
            return max(nums[0], nums[1])
        
        self.dp[1] = max(nums[0], nums[1])

        #DP Bottom-Up 
        for i in range(2, n):
            #Recursion
            self.dp[i] = max(self.dp[i-1], self.dp[i-2] + nums[i])
        
        return self.dp[n-1]