class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        long long left = 0, right = nums.size() - 1;
        long long mid;
        if(nums[left] > nums[left + 1]) return left;
        if(nums[right] > nums[right -1]) return right;
        while(left <= right){
            mid = left + (right - left)/2;
            if(nums[mid] > nums[mid + 1] && nums[mid] > nums[mid - 1]) return mid;
            else if(nums[mid] < nums[mid + 1]){
                left = mid + 1;
            } else if(nums[mid] > nums[mid + 1]){
                right = mid - 1;
            }
        }
        return 0;
    }
};