class Solution {
public:
int sumafterdivision(vector<int> &nums, int div) {
	int sum = 0;
	for (int i = 0; i < (int) nums.size(); i++)
		sum += (nums[i] + div - 1) / div;	// ceil equation
	return sum;
}

int smallestDivisor(vector<int> &nums, int threshold) {
	int start = 1, end = *max_element(nums.begin(), nums.end());
	int divisor = end;	// then all values add 1

	while (start <= end) {
		int mid = start + (end - start) / 2;
		if (sumafterdivision(nums, mid) <= threshold)
			end = mid - 1, divisor = mid;
		else
			start = mid + 1;
	}
	return divisor;
}
};