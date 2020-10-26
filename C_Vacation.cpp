#include<bits/stdc++.h>

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
#define mod 			10000000007
#define INF 			1e18
#define ps(x, y) 		fixed << setprecision(y) << x
#define tc(x) 			int x; cin>>x; while(x--)
#define endl 			"\n"
#define rep(i, st, k)    for(int i = st; i < k; i++)


int dp[100005][3];

void solve() {
	int n;
	cin >> n;
	int arr[n][3];
	rep(i, 0, n) {
		rep(j, 0, 3)
		cin >> arr[i][j];
	}
	memset(dp, 0, sizeof dp);

	// BASE CASE

	dp[0][0] = arr[0][0];
	dp[0][1] = arr[0][1];
	dp[0][2] = arr[0][2];

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			if (j == 0)
				dp[i][j] = arr[i][j] + max(dp[i - 1][j + 1], dp[i - 1][j + 2]);
			if (j == 1)
				dp[i][j] = arr[i][j] + max(dp[i - 1][j + 1], dp[i - 1][j - 1]);
			if (j == 2)
				dp[i][j] = arr[i][j] + max(dp[i - 1][j - 1], dp[i - 1][j - 2]);
		}
	}



	cout << max(dp[n - 1][0], max(dp[n - 1][1], dp[n - 1][2])) << endl;

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