class Solution {
public:
    int mySqrt(int x) {
        long long left = 0, right = x;
        long long mid, can;
        while(left <= right){
            mid = left + (right - left)/2;
            can = mid * mid;
            if(x == can){
                return mid;
            } else if (x < can) {
                right = mid - 1;;
            } else if(x > can){
                left = mid + 1;
            }
        }
        return right;
    }
};