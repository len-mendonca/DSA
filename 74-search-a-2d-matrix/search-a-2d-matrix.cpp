class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()){
             return false;
        }

        int rows = matrix.size();
        int cols = matrix[0].size();

        int start = 0;
        int end = rows * cols - 1;

        while (start <= end) {
            int mid = (start + end) / 2;
            int midX = mid / cols;
            int midY = mid % cols;

            if (matrix[midX][midY] == target) {
                return true;
            } else if (matrix[midX][midY] > target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return false;
        




    }

  
};