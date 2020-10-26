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


int dp[100005];

int recc(int arr[], int idx, int k) {
	if (idx == 0)
		return 0;
	if (dp[idx] != -1)return dp[idx];
	int ans = INT_MAX;

	for (int i = 1; i <= k; i++) {
		if (idx - i < 0) break;
		int temp = recc(arr, idx - i, k);
		ans = min(ans, temp + abs(arr[idx] - arr[idx - i]));
	}

	return dp[idx] = ans;

}

void solve() {
	int n, k;
	cin >> n >> k;
	int arr[n];
	rep(i, 0, n) {
		cin >> arr[i];
	}
	memset(dp, -1, sizeof dp);

	int ans = recc(arr, n - 1, k);
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