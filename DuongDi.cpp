/*
Đề bài:
Tìm đường đi từ đỉnh s đến đỉnh t
*/


#include<bits/stdc++.h>
#define ll long long
#define f1(i, n) for(int i=1;i<=n;++i)
using namespace std;
const int maxn = 1e5 + 1;

// Dinh :
// Parent :

int dinh[maxn], parent[maxn], index = 0;
vector<int> adj[maxn];
bool visited[maxn];
void dfs(int u) {
	visited[u] = true;
	for (auto v : adj[u]) {
		if (!visited[v]) {
			visited[v] = true;
			index++;
			dinh[index] = v;
			parent[index] = dinh[index - 1];
			dfs(v);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, x, y;
	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	int s, t;
	cin >> s >> t;
	dinh[1] = s; parent[1] = 0;
	dfs(s);
	if (!visited[t]) {
		cout << "Khong co duong di";
		return 0;
	}
	cout << s << " ";
	for (int i = 2; i <= index; ++i) cout << parent[i] << " ";


}
