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
#define ps(x, y) 		fixed<<setprecision(y)<<x
#define tc(x) 			int x; cin>>x; while(x--)
#define endl 			"\n"
#define rep(i, st, k)   for(int i = st; i < k; i++)
#define all(x)			x.begin(), x.end()

ll dp[3005][3005][2];


ll helper(std::vector<ll>& arr, int start, int end, int turn) {
	if (start > end)
		return 0;

	if (dp[start][end][turn] != -1)
		return dp[start][end][turn];

	if (turn == 1)
		return dp[start][end][turn] = max(arr[start] + helper(arr, start + 1, end, 0), arr[end] + helper(arr, start, end - 1, 0));
	else
		return dp[start][end][turn] = min(helper(arr, start + 1, end, 1), helper(arr, start, end - 1, 1));
}


void solve() {
	int n;
	cin >> n;
	std::vector<ll> arr(n);
	ll sum = 0;
	memset(dp, -1, sizeof dp);
	rep(i, 0, n) {
		cin >> arr[i];
		sum += arr[i];
	}
	ll tr = helper(arr, 0, n - 1, 1);
	cout << tr -  (sum - tr) << endl;
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