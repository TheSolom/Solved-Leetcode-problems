class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size()); // Store positions
        stack <pair<int, int>> st; // Store i that not bigger than i + 1  && Position

        for (int i = 0; i < temperatures.size() - 1; i++)
        {
            if (temperatures[i] < temperatures[i + 1]) 
            {
                res[i] = 1;

                while (!st.empty() && st.top().first < temperatures[i + 1])
                {
                    res[st.top().second] = i + 1 - st.top().second; // Store position
                    st.pop();
                }
            }
            else
                st.push({ temperatures[i], i });
        }

        return res;
    }
};