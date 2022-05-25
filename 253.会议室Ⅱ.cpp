#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
private:
	static bool cmp(const vector<int>& a, const vector<int>& b) {
		return a[0] < b[0] || (a[0] == b[0] && a[1] < b[0]);
	}
public:
	int getres(vector<vector<int>>& sessions) {
		int n = sessions.size();
		sort(sessions.begin(), sessions.end(), cmp);
		priority_queue<int, vector<int>, greater<int>> pri_que;
		pri_que.push(sessions[0][1]);
		for (int i = 1; i < n; i++) {
			if (sessions[i][0] >= pri_que.top()) {
				pri_que.pop();
			}
			pri_que.push(sessions[i][1]);
		}
		return pri_que.size();
	}
};

int main() {
	int n;
	while (cin >> n) {
		vector<vector<int>> sessions(n, vector<int>(2));
		for (int i = 0; i < n; i++) {
			cin >> sessions[i][0] >> sessions[i][1];
		}
		Solution Sol;
		int res = Sol.getres(sessions);
		cout << res << endl;
	}
	return 0;
}
