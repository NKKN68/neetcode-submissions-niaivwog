class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        long long left = 0, right = matrix.size() - 1;
        long long mid;
        while(left <= right){
            mid = left + (right - left)/2;
            if(matrix[mid][matrix[mid].size() - 1] < target){
                left = mid + 1;
            } else if(matrix[mid][matrix[mid].size() - 1] >= target){
                long long leftmin = 0, rightmin = matrix[mid].size() - 1;
                long long midmin;
                while(leftmin <= rightmin){
                    midmin = leftmin + (rightmin - leftmin)/2;
                    if(matrix[mid][midmin] == target){
                        return true;
                    } else if(matrix[mid][midmin] < target){
                        leftmin = midmin + 1;
                    } else if(matrix[mid][midmin] > target){
                        rightmin = midmin - 1;
                    }
                }
                right = mid - 1;
            }
        }
        return false;
    }
};
