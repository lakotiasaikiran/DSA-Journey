
class Solution {
public:
    int solve(vector<int>& nums, int left, int right) {
        if (left == right) {
            return nums[left];
        }

        int mid = left + (right - left) / 2;

        int leftMax = solve(nums, left, mid);
        int rightMax = solve(nums, mid + 1, right);

        int sum = 0;
        int bestLeft = INT_MIN;

        for (int i = mid; i >= left; i--) {
            sum += nums[i];
            bestLeft = max(bestLeft, sum);
        }

        sum = 0;
        int bestRight = INT_MIN;

        for (int i = mid + 1; i <= right; i++) {
            sum += nums[i];
            bestRight = max(bestRight, sum);
        }

        return max({leftMax, rightMax, bestLeft + bestRight});
    }

    int maxSubArray(vector<int>& nums) {
        return solve(nums, 0, nums.size() - 1);
    }
};