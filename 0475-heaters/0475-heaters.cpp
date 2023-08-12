class Solution
{
    public:
        int find_nearest_heater(vector<int> &heaters, int house)
        {
            int start = 0, end = (int) heaters.size() - 1;

            while (start <= end)
            {
                int mid = start + (end - start) / 2;

                if (heaters[mid] == house)
                    return mid;
                else if (heaters[mid] > house)
                    end = mid - 1;
                else
                    start = mid + 1;
            }
            return start;
        }

    int findRadius(vector<int> &houses, vector<int> &heaters)
    {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());

        int max_radius = 0;
        for (int house: houses)
        {
            int closest_heater_index = find_nearest_heater(heaters, house);

            int distance = 0;
            if (closest_heater_index == 0)
            {
                distance = heaters[0] - house;
            }
            else if (closest_heater_index == heaters.size())
            {
                distance = house - heaters.back();
            }
            else
            {
                distance = min(heaters[closest_heater_index] - house, house - heaters[closest_heater_index - 1]);
            }

            max_radius = max(max_radius, distance);
        }

        return max_radius;
    }
};