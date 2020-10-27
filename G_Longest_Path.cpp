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

int dp[100006];


void dfs(int n, std::vector<std::vector<int>>& graph, std::vector<bool>& vis, int node) {

	vis[node] = true; // Mark the current node as visited.

	for (int i = 0; i < graph[node].size(); i++) {
		if (vis[graph[node][i]] == false)
			dfs(n, graph, vis, graph[node][i]);
		dp[node] = max(dp[node], 1 + dp[graph[node][i]]); // dp(i) stores the max value path that is possible from the current "NODE" as a source....
	}
}

void solve() {

	int n, m;
	cin >> n >> m;

	std::vector<vector<int>> graph(n + 1); // Adjecency List
	std::vector<bool> vis(n + 1, false); // Visited array

	memset(dp, 0, sizeof dp);

	rep(i, 0, m) {
		int u, v;
		cin >> u >> v;
		graph[u].pb(v);
	}


	for (int i = 1; i <= n; i++) {
		if (!vis[i])				// Perform DFS if the node is not visited
			dfs(n, graph, vis, i);
	}

	int ans = INT_MIN;
	for (int i = 1; i <= n; i++) { // Each Node has their own Longest Path length..
		ans = max(ans, dp[i]); // Find the largest amoung them.
	}

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