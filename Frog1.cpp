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

ll cc[100001];

void solve() {
	memset(cc, 0, sizeof cc);
	ll n;
	cin >> n;
	std::vector<ll> v(n);
	rep(i, 0 , n)
	cin >> v[i];
	cc[0] = INT_MAX;
	cc[1] = 0;
	cc[2] = abs(v[1] - v[0]);
	rep(i, 2, n) {
		cc[i + 1] = min(cc[i] + abs(v[i] - v[i - 1]), cc[i - 1] + abs(v[i] - v[i - 2]));
	}
	cout << cc[n] << endl;
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