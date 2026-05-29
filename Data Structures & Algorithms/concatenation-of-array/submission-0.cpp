class Solution {
public:
    vector<int> copy(vector<int>& nums, vector<int>& ans){
        for(int i = 0; i < nums.size(); i++){
            ans.push_back(nums[i]);
        }
        return ans;
    }
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector <int> ans;
        copy(nums, ans);
        copy(nums, ans);
        return ans;
    }
};