class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int total_len = nums.size();
        int n = total_len / 2;
        long long total_sum = 0;
        for (int x : nums) {
            total_sum += x;
        }

       
        vector<vector<int>> left_sums(n + 1);
        for (int i = 0; i < (1 << n); ++i) {
            int current_sum = 0;
            int num_elements = 0;
            for (int j = 0; j < n; ++j) {
                if ((i >> j) & 1) { 
                    current_sum += nums[j];
                    num_elements++;
                }
            }
            left_sums[num_elements].push_back(current_sum);
        }

        
        vector<vector<int>> right_sums(n + 1);
        for (int i = 0; i < (1 << n); ++i) {
            int current_sum = 0;
            int num_elements = 0;
            for (int j = 0; j < n; ++j) {
                if ((i >> j) & 1) {
                    current_sum += nums[n + j];
                    num_elements++;
                }
            }
            right_sums[num_elements].push_back(current_sum);
        }

        
        for (int i = 0; i <= n; ++i) {
            sort(right_sums[i].begin(), right_sums[i].end());
        }

        int min_diff = INT_MAX;

        
        for (int i = 0; i <= n; ++i) { 
            int j = n - i;             
            for (int sum1 : left_sums[i]) {
               
                long long target_s2 = (total_sum / 2) - sum1;
                
                auto& candidates = right_sums[j];
                auto it = lower_bound(candidates.begin(), candidates.end(), target_s2);

               
                if (it != candidates.end()) {
                    long long sum2 = *it;
                    long long partition1_sum = sum1 + sum2;
                    long long partition2_sum = total_sum - partition1_sum;
                    min_diff = min(min_diff, (int)abs(partition1_sum - partition2_sum));
                }
                
                
                if (it != candidates.begin()) {
                    long long sum2 = *(--it);
                    long long partition1_sum = sum1 + sum2;
                    long long partition2_sum = total_sum - partition1_sum;
                    min_diff = min(min_diff, (int)abs(partition1_sum - partition2_sum));
                }
            }
        }

        return min_diff;
    }
};