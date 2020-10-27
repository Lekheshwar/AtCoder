#include<bits/stdc++.h>
#include <string>
using namespace std;

#define ff 				first
#define ss 				second
#define ll 				long long
#define pb 				push_back
#define mp 				make_pair
#define pii 			pair<int, int>
#define vi 				vector<int>
#define mii 			map<int, int>
#define setbits(x) 		__builtin_popcountll(x)
#define zrobits(x) 		__builtin_ctzll(x)
#define mod 			1000000007
#define INF 			1e18
#define ps(x, y) 		fixed << setprecision(y) << x
#define tc(x) 			int x; cin>>x; while(x--)
#define endl 			"\n"
#define rep(i, st, k)    for(int i = st; i < k; i++)

int dp[1001][1001];

void solve() {
	int m, n;
	cin >> m >> n;

	char grid[m][n];

	rep(i, 0, m) {
		rep(j, 0, n) {
			cin >> grid[i][j];
		}
	}

	memset(dp, 0, sizeof dp);

	bool block = false;
	for (int i = 0; i < n; i++) {

		if (grid[0][i] == '.' && !block)
			dp[0][i] = 1;
		else {block = true; dp[0][i] = 0;}
	}
	block = false;
	for (int i = 0; i < m; i++) {
		if (grid[i][0] == '.' && !block)
			dp[i][0] = 1;
		else {block = true; dp[i][0] = 0;}
	}

	rep(i, 1, m) {
		rep(j, 1, n) {
			if (grid[i][j] == '#')continue;
			dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % mod;
		}
	}
	cout << dp[m - 1][n - 1] << endl;

}


int32_t main() {

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	solve();
	return 0;
}