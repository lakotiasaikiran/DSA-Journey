
class Solution {
public:
    void mergeSort(vector<int>& nums, vector<int>& index,
                   vector<int>& temp, vector<int>& result,
                   int left, int right) {
        if (left >= right) {
            return;
        }

        int mid = left + (right - left) / 2;

        mergeSort(nums, index, temp, result, left, mid);
        mergeSort(nums, index, temp, result, mid + 1, right);

        int i = left, j = mid + 1, k = left;
        int count = 0;

        while (i <= mid && j <= right) {
            if (nums[index[j]] < nums[index[i]]) {
                temp[k++] = index[j++];
                count++;
            }
            else {
                result[index[i]] += count;
                temp[k++] = index[i++];
            }
        }

        while (i <= mid) {
            result[index[i]] += count;
            temp[k++] = index[i++];
        }

        while (j <= right) {
            temp[k++] = index[j++];
        }

        for (int p = left; p <= right; p++) {
            index[p] = temp[p];
        }
    }

    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();

        vector<int> index(n), temp(n), result(n, 0);

        for (int i = 0; i < n; i++) {
            index[i] = i;
        }

        if (n > 0) {
            mergeSort(nums, index, temp, result, 0, n - 1);
        }

        return result;
    }
};
