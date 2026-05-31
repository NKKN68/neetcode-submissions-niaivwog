class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> win;
        for(int i = 0; i < nums.size(); i++){
            if(win.count(nums[i]) > 0){
                return true;
            } else {
                win.insert(nums[i]);
            }
            if(win.size() > k){
                win.erase(nums[i - k]);
            }
        }
        return false;
    }
};