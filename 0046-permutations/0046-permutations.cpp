class Solution {
private:
    void recurPerm(int index,vector<int> &nums,vector<vector<int>> &ans){
        if(index == nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int  i = index;i < nums.size();i++){
            swap(nums[index],nums[i]);
            recurPerm(index+1,nums,ans);
            swap(nums[index],nums[i]);
        }
    }
public: 
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        recurPerm(0,nums,ans);
        return ans;
        
    }
};