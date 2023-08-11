class Solution {
public:
	int binarySearch(vector<vector<int>>& vec, int target) {
		int low = 0, high = (int)vec.size() - 1;
		
		if (vec[low][0] > vec[high][0])
			swap(low, high);

		int ans = -1;
		if (low < high)
		{
			while (low <= high) {
				int mid = low + (high - low) / 2;

				if (vec[mid][0] == target)
					return mid;
				if (vec[mid][0] < target)
					low = mid + 1;
				else {
					ans = mid;
					high = mid - 1;
				}
			}

			return ans;
		}
		else
		{
			while (low >= high) {
				int mid = high + (low - high) / 2;

				if (vec[mid][0] == target)
					return mid;
				if (vec[mid][0] < target)
					low = mid - 1;
				else {
					ans = mid;
					high = mid + 1;
				}
			}

			return ans;
		}
	}

	vector<int> findRightInterval(vector<vector<int>>& intervals) {
		vector<int> ans;
		for (int i = 0; i < intervals.size(); i++)
			ans.push_back(binarySearch(intervals, intervals[i][1]));

		return ans;
	}
};