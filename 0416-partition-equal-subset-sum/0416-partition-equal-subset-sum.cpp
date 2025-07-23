class Solution {
public:
    bool subsetSumK(int n,int k,vector<int>&nums){
        vector<bool> prev(k+1,0),curr(k+1,0);
        prev[0] = curr[0] = true;
        if (n > 0 && nums[0] <= k) {
            prev[nums[0]] = true;
        }
        for(int i = 1;i < n;i++){
            for(int target = 1;target <= k;target++){
                bool not_take = prev[target];
                bool take = false;
                if(nums[i] <= target) take = prev[target - nums[i]];
                curr[target] = take | not_take;
            }
            prev = curr;
        }
        return prev[k];
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0;i<n;i++) sum += nums[i];
        if(sum % 2 != 0) return false;
        int target = sum / 2;
        
        return subsetSumK(n,target,nums);
        
    }
};