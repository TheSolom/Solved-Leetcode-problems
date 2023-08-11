class Solution {
public:
	int start(vector<int>& vec, int target) {
		int start = 0, end = (int)vec.size() - 1;

		int ans = -1;
		while (start <= end) {
			int mid = start + (end - start) / 2;

			if (vec[mid] >= target) {
				if (vec[mid] == target)
					ans = mid;
				end = mid - 1;
			}
			else if (vec[mid] < target)
				start = mid + 1;
		}

		return ans;
	}

	int end (vector<int>& vec, int target) {
		int start = 0, end = (int)vec.size() - 1;

		int ans = -1;
		while (start <= end) {
			int mid = start + (end - start) / 2;

			if (vec[mid] <= target) {
				if (vec[mid] == target)
					ans = mid;
				start = mid + 1;
			}
			else if (vec[mid] > target)
				end = mid - 1;
		}

		return ans;
	}

  vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> ans(2);
		ans[0] = start(nums, target);
		ans[1] = end(nums, target);

		return ans;
  }
};