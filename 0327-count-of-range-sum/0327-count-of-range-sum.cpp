
class Solution {
public:
    int mergeSort(vector<long long>& sum, int left, int right,
                  int lower, int upper) {
        if (right - left <= 1) {
            return 0;
        }

        int mid = left + (right - left) / 2;

        int count = mergeSort(sum, left, mid, lower, upper);
        count += mergeSort(sum, mid, right, lower, upper);

        int i = mid, j = mid;

        for (int k = left; k < mid; k++) {
            while (i < right && sum[i] - sum[k] < lower) {
                i++;
            }

            while (j < right && sum[j] - sum[k] <= upper) {
                j++;
            }

            count += j - i;
        }

        vector<long long> temp;
        int a = left, b = mid;

        while (a < mid && b < right) {
            if (sum[a] <= sum[b]) {
                temp.push_back(sum[a++]);
            }
            else {
                temp.push_back(sum[b++]);
            }
        }

        while (a < mid) {
            temp.push_back(sum[a++]);
        }

        while (b < right) {
            temp.push_back(sum[b++]);
        }

        for (int k = 0; k < temp.size(); k++) {
            sum[left + k] = temp[k];
        }

        return count;
    }

    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long long> sum(n + 1, 0);

        for (int i = 0; i < n; i++) {
            sum[i + 1] = sum[i] + nums[i];
        }

        return mergeSort(sum, 0, n + 1, lower, upper);
    }
};
