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
#define rep(i, st, k)    for(int i = st; i < k; i++)

bool dp[100005];

void solve() {
	ll n, k;
	cin >> n >> k;
	std::vector<ll> v(n);
	rep(i, 0, n) {
		cin >> v[i];
	}
	memset(dp, false, sizeof dp);

	for (int i = 1; i <= k; i++) {
		for (auto x : v) {
			if (i >= x && dp[i - x] == false)
				dp[i] = true;
		}
	}

	if (dp[k])
		cout << "First" << endl;
	else
		cout << "Second" << endl;

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