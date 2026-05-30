class Solution {
public:
    bool checkeatall(vector<int>& piles, int k, int h){
        int time = 0; 
        for(int i = 0; i < piles.size(); i++){
            if(piles[i] % k == 0){
                time = time + piles[i] / k;
            } else {
                time = time + (piles[i] / k) + 1;
            }
        }
        if(time <= h){
            return true;
        } else {
            return false;
        }
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        long long left = 1, right = piles[piles.size() - 1];
        long long mid;
        while(left <= right){
            mid = left + (right - left)/2;
            if(checkeatall(piles, mid, h) == true){
                right = mid - 1;
            } else if(checkeatall(piles, mid, h) == false){
                left = mid + 1;
            }
        }
        return left;
    }
};
