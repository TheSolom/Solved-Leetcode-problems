class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> sorted{ nums };
        sort(sorted.begin(), sorted.end());

        int left = -1, right = -1;
        for (int i = 0; i < (int)nums.size(); i++) {
            if (nums[i] != sorted[i]) {
                if (left == -1)
                    left = i;
                else
                    right = i;
            }
        }

        if (left == -1)
            left = 0;

        return right - left + 1;
    }
};