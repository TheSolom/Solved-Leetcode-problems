class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> jobs;
        for (int i = 0; i < (int)difficulty.size(); i++)
            jobs.push_back({ difficulty[i], profit[i] });

        sort(jobs.begin(), jobs.end());
        sort(worker.begin(), worker.end());

        int max = 0, total_profit = 0;
        for (int i = 0, j = 0; i < worker.size(); i++)
        {
            for (; j < jobs.size() && worker[i] >= jobs[j].first; j++)
            {
                max = std::max(max, jobs[j].second);
            }

            total_profit += max;
        }

        return total_profit;
    }
};