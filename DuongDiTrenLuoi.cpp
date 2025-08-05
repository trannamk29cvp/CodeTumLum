/*
Đếm thành phần liên thông kí tự x
*/


#include<bits/stdc++.h>
#define ll long long
#define f1(i, n) for(int i=1;i<=n;++i)
using namespace std;
const int maxn = 1e5 + 1;

char A[1001][1001];
bool visited[1001][1001];
int dx[4] = { -1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m, x, y;

void dfs(int i, int j) {
	visited[i][j] = true;
	for (int k = 0; k < 4; ++k) {
		int i1 = i + dx[k];
		int j1 = j + dy[k];
		if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && !visited[i1][j1] && A[i1][j1] == 'x') {
			dfs(i1, j1);
		}

	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> A[i][j];
		}
	}
	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (!visited[i][j] and A[i][j] == 'x') {
				cnt++;
				dfs(i, j);
			}
		}
	}

	cout << cnt;


}
