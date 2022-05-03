#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> getres(vector<int>& nums) {
		int n = nums.size();
		if (n == 1) return { 0 };
		if (n == 2 && nums[0] > nums[1]) return { 0 };
		if (n == 2 && nums[0] <= nums[1]) return { 1 };
		vector<vector<int>> dp(n, vector<int>(2, 0));
		dp[0][0] = 0;
		dp[0][1] = nums[0];
		dp[1][0] = nums[0];
		dp[1][1] = nums[1];
		for (int i = 2; i < n; i++) {
			dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
			dp[i][1] = max(dp[i - 2][0], dp[i - 2][1]) + nums[i];
		}
		int target = max(dp[n - 1][0], dp[n - 1][1]);
		vector<int> res;
		for (int i = n - 1; i >= 0; i--) {
			if (dp[i][1] == target) {
				res.push_back(i);
				target -= nums[i];
			}
		}
		return vector<int>(res.rbegin(), res.rend());
	}
};

int main() {
	int n;
	while (cin >> n) {
		vector<int> nums(n);
		for (int i = 0; i < n; i++) {
			cin >> nums[i];
		}
		Solution Sol;
		vector<int> res = Sol.getres(nums);
		for (int i = 0; i < res.size(); i++) {
			cout << res[i] << ' ';
		}
		cout << endl;
	}
	return 0;
}
