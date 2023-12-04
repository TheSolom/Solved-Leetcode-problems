class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        int min_diff = 1e6 + 1;
        for (int i = 1; i < arr.size(); i++)
        {
            int diff = arr[i] - arr[i - 1];
            if (diff < min_diff)
                min_diff = diff;
        }

        vector<vector<int>> ans;
        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i] - arr[i - 1] == min_diff)
                ans.emplace_back(vector<int>{ arr[i - 1], arr[i] });
        }

        return ans;
    }
};