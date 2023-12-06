class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int min{ 101 }, sum{};
        for (int i = 0; i < nums.size(); i++)
        {
            if (k && nums[i] < 0)
                nums[i] *= -1, k--;

            min = std::min(min, nums[i]);
            sum += nums[i];
        }
        if (k % 2)
            sum -= min * 2;

        return sum;
    }
};