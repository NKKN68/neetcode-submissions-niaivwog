class Solution {
public:
    int arrangeCoins(int n) {
        long long mid, total;
        long long left = 0, right = n;
        while(left <= right){
            mid = left + (right - left)/2;
            total = mid * (mid + 1)/2;
            if(total == n){
                return (int)mid;
            }
            if(total > n){
                right = mid - 1;
            } else{
                left = mid + 1;
            }
        }
        return (int)right;
    }
};