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
#define rep(i, st, k)   for(int i = st; i < k; i++)

double dp[3000][3000];

void solve() {
	int n;
	cin >> n;

	std::vector<double> coins(n);
	rep(i, 0, n) cin >> coins[i];

	cout << fixed;
	cout << setprecision(10);		// To print upto 10 decimal places......

	memset(dp, 0.0, sizeof dp);

	dp[0][0] = 1.0;

	rep(i, 1, n)dp[i][0] = dp[i - 1][0] * (1.0 - coins[i - 1]);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i][j] = dp[i - 1][j] * (1 - coins[i - 1]) + dp[i - 1][j - 1] * (coins[i - 1]);
		}
	}

	double ans = 0.0;
	for (int i = n; i > n / 2; i--)
		ans += dp[n][i];

	cout << ans << endl;
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