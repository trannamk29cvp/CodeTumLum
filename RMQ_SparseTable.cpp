/*
Đề bài:
Cho mảng A có n phần tử và q truy vấn. Mỗi truy vấn thực hiện tìm
phần tử bé nhất trong đoạn từ L đến R. (n, q <= 1e5)

Sparse Table
*/

#include<bits/stdc++.h>
#define ll long long
#define f1(i, n) for(int i=1;i<=n;++i)
using namespace std;
const int maxn = 1e5 + 1;
int A[maxn];

int pow2(int n) {
	int res = 1;
	for (int i = 1; i <= n; ++i) {
		res *= 2;
	}
	return res;
}

int main() {
	int n, q;
	cin >> n >> q;
	f1(i, n) {
		cin >> A[i];
	}

	// Khởi tạo Sparse Table
	int k = floor(log2(n)) + 1;
	int st[n + 1][k];
	f1(i, n) {
		st[i][0] = A[i];
	}

	// st[i][j] = min của các phần tử trong range gồm 2^j phần tử tính từ i

	for (int j = 1; j < k; ++j) {
		for (int i = 1; i <= n; ++i) {
			if (i + pow2(j - 1) <= n) {
				st[i][j] = min(st[i][j - 1], st[i + pow2(j - 1)][j - 1]);
			}
		}
	}

	// Query
	int l, r;
	while (q--) {
		cin >> l >> r;
		int j = floor(log2(r - l + 1));
		cout << min(st[l][j], st[r - pow2(j) + 1][j]) << endl;
	}
}