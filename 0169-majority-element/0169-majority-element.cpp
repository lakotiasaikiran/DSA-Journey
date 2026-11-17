
class Solution {
public:
    int solve(vector<int>& nums, int left, int right) {
        if (left == right) {
            return nums[left];
        }

        int mid = left + (right - left) / 2;

        int a = solve(nums, left, mid);
        int b = solve(nums, mid + 1, right);

        if (a == b) {
            return a;
        }

        int countA = 0, countB = 0;

        for (int i = left; i <= right; i++) {
            if (nums[i] == a) {
                countA++;
            }

            if (nums[i] == b) {
                countB++;
            }
        }

        return countA > countB ? a : b;
    }

    int majorityElement(vector<int>& nums) {
        return solve(nums, 0, nums.size() - 1);
    }
};