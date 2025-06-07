class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i = 0;i<n;i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            for(int j = i+1;j<n;j++){
                if(j > i+1 && nums[j] == nums[j-1]) continue;
                int k = j+1;
                int d = n-1;
                while(k<d){
                    long long sum = nums[i]; 
                    sum += nums[j]; 
                    sum += nums[k]; 
                    sum += nums[d];
                    if(sum < target) k++;
                    else if(sum > target) d--;
                    else{
                        ans.push_back({nums[i],nums[j],nums[k],nums[d]});
                        k++;
                        d--;
                        while(k<d && nums[k] == nums[k-1]) k++;
                        while(k<d && nums[d] == nums[d+1]) d--;
                    }
                }
            }
        }
        return ans;
    }
};