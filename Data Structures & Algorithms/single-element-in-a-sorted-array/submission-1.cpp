class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        long long left = 0, right = nums.size() - 1;
        long long mid;
        while(left <= right){
            mid = left + (right - left)/2;
            if(mid % 2 == 0){
                if(nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) return nums[mid];
                else if(nums[mid] == nums[mid + 1]){
                    left = mid + 1 ;
                } else if(nums[mid] != nums[mid + 1]){
                    right = mid - 1;
                }
            } else {
                if(nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) return nums[mid];
                else if(nums[mid] == nums[mid - 1]){
                    left = mid + 1 ;
                } else if(nums[mid] != nums[mid - 1]){
                    right = mid - 1;
                }
            }
        }
        return nums[mid];
    }
};