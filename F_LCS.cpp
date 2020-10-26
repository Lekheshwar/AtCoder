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
#define mod 			10000000007
#define INF 			1e18
#define ps(x, y) 		fixed << setprecision(y) << x
#define tc(x) 			int x; cin>>x; while(x--)
#define endl 			"\n"
#define rep(i, st, k)    for(int i = st; i < k; i++)


ll dp[3001][3001];

void solve() {
	string t1, t2;
	cin >> t1 >> t2;
	string s, t;
	if (t1.size() > t2.size()) {s = t1; t = t2;}
	else {t = t1; s = t2;}

	// cout << s << " " << t;
	int m = t.size();
	int n = s.size();

	rep(i, 0, n)dp[0][i] = 0;
	rep(i, 0, m)dp[i][0] = 0;

	rep(i, 1, m + 1) {
		rep(j, 1, n + 1) {
			if (s[j - 1] == t[i - 1])
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	// cout << dp[m][n] << endl;
	string res = "";
	int i = m - 1, j = n - 1;
	while (i >= 0 && j >= 0) {
		if (s[j] == t[i]) {
			res += t[i];
			i--;
			j--;
		}
		else if (dp[i][j + 1] > dp[i + 1][j]) {
			i--;
		}
		else j--;
	}
	for (int i = res.size() - 1; i >= 0; i--)
		cout << res[i];

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