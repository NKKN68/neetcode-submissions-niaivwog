class Solution {
public:
    bool isPerfectSquare(int num) {
        long long left = 0, right = num;
        long long mid, cp;
        while(left <= right){
            int mid = left + (right - left)/2;
            cp = mid * mid;
            if(cp == num){
                return true;
            } else if(cp < num){
                left = mid + 1;
            } else if(cp > num){
                right = mid - 1;
            }
        }
        return false;
    }
};