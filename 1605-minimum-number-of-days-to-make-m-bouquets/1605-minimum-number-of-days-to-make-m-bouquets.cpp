class Solution
{
    public:
        bool possible(vector<int> &bloomDay, int total_bouquets, int flowers_per_bouquet, int waiting_days)
        {
            int adj_flowers = 0, bouquets = 0;

            for (int i = 0; i < (int) bloomDay.size(); ++i)
            {
                if (bloomDay[i] <= waiting_days)
                {
                    ++adj_flowers;

                    if (adj_flowers >= flowers_per_bouquet)
                        adj_flowers = 0, ++bouquets;	// Start counting for a new bouquet

                    if (bouquets == total_bouquets)	// more efficient to stop early
                        return true;
                }
                else
                    adj_flowers = 0;
            }
            return false;
        }

    int minDays(vector<int> &bloomDay, int total_bouquets, int flowers_per_bouquet)
    {
        if (total_bouquets > (int) bloomDay.size() / flowers_per_bouquet)
            return -1;	// optimization

        int start = *min_element(bloomDay.begin(), bloomDay.end());
        int end = *max_element(bloomDay.begin(), bloomDay.end());

        int min_days = -1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (possible(bloomDay, total_bouquets, flowers_per_bouquet, mid))
                end = mid - 1, min_days = mid;
            else
                start = mid + 1;
        }
        return min_days;
    }
};