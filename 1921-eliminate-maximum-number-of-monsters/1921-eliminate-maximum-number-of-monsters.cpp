class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<int> time;
        for (int i = 0; i < dist.size(); i++) {
            if (dist[i] % speed[i] == 0)
                time.push_back(dist[i] / speed[i]);
            else
                time.push_back(dist[i] / speed[i] + 1);
        }
        
        sort(time.begin(), time.end());

        int ans{};
        for (int i = 0; i < dist.size() && i < time[i]; i++)
            ans++;

        return ans;
    }
};