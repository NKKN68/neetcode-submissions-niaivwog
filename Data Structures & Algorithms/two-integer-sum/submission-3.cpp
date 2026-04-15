class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int k = 0;
        for (int i = 0; i < nums.size(); i++) {
            k = target - nums[i];
            for (int j = i + 1; j < nums.size(); j++) {
                if (k == nums[j]) {
                    return {i, j};
                }
            } 
        }
    }
};
