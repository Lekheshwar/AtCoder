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


ll dp[101][100005];

void solve() {
	ll n, k;
	cin >> n >> k;
	ll wt[n], v[n];
	rep(i, 0, n) {
		cin >> wt[i] >> v[i];
	}
	memset(dp, 0, sizeof dp);

	rep(i, 1, n + 1) {
		rep(j, 1, k + 1) {
			if (wt[i - 1] > j) {
				dp[i][j] = dp[i - 1][j];
				continue;
			}
			dp[i][j] = max(v[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
		}
	}
	cout << dp[n][k] << endl;
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