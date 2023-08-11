class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int count = 0, n = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; i++) {
            int k = i + 2;	// observe k shared between js
            // k: the first invalid index: c >= a+b
            // We don't need to keep compute it for each j
            // Last j found its k. We can that keep pushing it
            // as anyway positions < k are valid
            for (int j = i + 1; j < n - 1 && nums[i] != 0; j++) {
                while (k < n && nums[i] + nums[j] > nums[k])
                	++k;
                count += k - j - 1;
            }
        }
        return count;
    }
};