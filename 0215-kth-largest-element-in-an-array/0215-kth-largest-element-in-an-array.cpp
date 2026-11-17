
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0;
        int right = nums.size() - 1;
        int target = nums.size() - k;

        while (left <= right) {
            int pivot = nums[left + (right - left) / 2];
            int i = left, j = left, end = right;

            while (j <= end) {
                if (nums[j] < pivot) {
                    swap(nums[i++], nums[j++]);
                }
                else if (nums[j] > pivot) {
                    swap(nums[j], nums[end--]);
                }
                else {
                    j++;
                }
            }

            if (target < i) {
                right = i - 1;
            }
            else if (target > end) {
                left = end + 1;
            }
            else {
                return nums[target];
            }
        }

        return -1;
    }
};
