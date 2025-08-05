// Nay hoc do thi
/*
Đồ thị vô hướng:
+ Bậc của đỉnh = số cạnh liên thuộc với đỉnh u, kí hiệu deg(u)
	bậc = 0 = đỉnh cô lập
	bậc = 1 = đỉnh treo
	Đồ thị vô hướng có m cạnh => đồ thị có 2 * m đỉnh
Đồ thị có hướng:
+ Bán bậc ra, vào:
	Bán bậc ra: deg+ (u) = bao nhiêu cung đi ra từ đỉnh u
	Bán bậc vào: deg- (u) = bao nhiêu cung đâm vào đỉnh u
		Tổng deg+ = deg- của cả đồ thị và bằng số cung

Đường đi:
+ Là dãy các đỉnh, hai đỉnh liên tiếp có cạnh nối. Độ dài đường đi là số cạnh
	Đường đi đơn: Các đỉnh trên đường đi phân biệt (A, B, C, D)
	Đường đi không đơn: Các đỉnh trên đường đi có thể giống nhau (A, B, C, A, E)

Chu trình:
+ Là đường đi mà đỉnh đầu trùng với đỉnh cuối (A, B, D, E, A)
	Chu trình đơn là chu trình không có hai đỉnh nào giống nhau ngoại trừ đỉnh đầu và cuối

Đồ thị vô hướng:
{
Liên thông:
+ Là đồ thị mà 2 điểm bất kì đều có đường đi

Nếu đồ thị không liên thông => Các thành phần liên thông
}

Đồ thị có hướng:
{
Liên thông mạnh:
+ Là đồ thị mà 2 điểm bất kì đều có đường đi
Liên thông yếu:
+ Gọi một đồ thị vô hướng tương ứng của G1 là G2
	Nếu G2 liên thông thì G1 là liên thông yếu
	* Đồ thị có hướng liên thông mạnh = Đồ thị có hướng liên thông yếu
	* Đồ thị có hướng liên thông yếu chưa chắc là đồ thị có hướng liên thông mạnh


// https://www.youtube.com/watch?v=JtWcUHRyqkA
MA TRẬN KỀ:

* Đồ thị vô hướng: Cho n đỉnh, m cạnh
 - Nếu đồ thị có n đỉnh thì ta có ma trận kích thước n*n
 	+ Nếu đỉnh i nối với đỉnh j thì A[i][j] = A[j][i] = 1, ngược lại = 0
	+ Tổng các phần tử trên ma trận = 2 * số cạnh
	+ deg(i) = tổng của A[i][1->n]

* Đồ thị có hướng:
 - Nếu đỉnh i -> j thì A[i][j] = 1, ngược lại = 0 (khác đồ thị vô hướng)

* Hai đỉnh có cạnh và có TRỌNG SỐ thì thay giá trị 1 bằng trọng số (Chiều dài cạnh)

INPUT:
- Danh sách cạnh (u, v)
- Dùng pair lưu danh sách cạnh
- Sử dụng struct lưu đỉnh đầu, cuối, trọng số
- Đồ thị vô hướng input khác đồ thị có hướng


DANH SÁCH KỀ:
vector<int> adj[n]
Đỉnh			Danh sách kề
1 					{...}
2 					{...}
3 					{...}
...
}




//https://www.youtube.com/watch?v=JAlNXyfe-p4
THUẬT TOÁN DFS (Depth First Search)
- Tìm kiếm theo chiều sâu: Ưu tiên duyệt xuống nhất có thể trước khi quay lại
Pseudocode:
// Bắt đầu duyệt từ đỉnh u
DFS(u){
	<Thăm đỉnh u>
	visited[u] = true // Đánh dấu là u đã được thăm
	// Duyệt các đỉnh kề với u
	for (v : adj[u]){
		if (!visited[v]){ // Nếu đỉnh v chưa được thăm
			DFS(v)
		}
	}
}
- Trong quá trình thăm, mở rộng từ đỉnh có chỉ số nhỏ nhất

* Edge:
 - Tree Edge
 - Back Edge
 - Forward Edge
 - Cross Edge


THUẬT TOÁN BFS (BREADTH DEPTH SEARCH)
- Tìm kiếm từ đỉnh đầu tiên, mở rộng ra các đỉnh kề trước khi xuống dưới
Pseudocode:
BFS(u){
	queue = [] //khởi tạo queue rỗng
	queue.push(u) //đẩy u vào queue
	visited[u] = true //đỉnh u đã thăm

	while(queue != rỗng){
		v = queue.front() // lấy đỉnh ở cuối
		queue.pop() // xoá đỉnh đó

		< Thăm đỉnh v >

		visited[v] = true
		for(u : adj[v]) { // Duyệt tất cả các đỉnh kề với v
			if (!visited[u]) {
				queue.push(u)
				visited[u] = true
				// Thăm tất cả các đỉnh kề với v
			}
		}
	}
}
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e6 + 1;



// void BieuDienMaTranKe() {
// 	/*
// 		Cho n đỉnh và m cạnh, biểu diễn đồ thị dưới dạng ma trận kề
// 	*/
// 	int n, m;
// 	cin >> n >> m;
// 	int adj[n + 1][n + 1] = {}, u, v;
// 	for (int i = 1; i <= m; ++i) {
// 		cin >> u >> v;
// 		adj[u][v] = adj[u][v] = 1;
// 	}
// 	for (int i = 1; i <= n; ++i) {
// 		for (int j = 1; j <= n; ++j) {
// 			cout << adj[i][j] << " ";
// 		}
// 		cout << endl;
// 	}
// }
// void BieuDienDanhSachKe() {
// 	/*
// 		Cho n đỉnh và m cạnh, biểu diễn đồ thị dưới dạng danh sách kề
// 	*/
// 	int n, m;
// 	cin >> n >> m;
// 	int u, v;
// 	vector<int> adj[n + 1];
// 	for (int i = 1; i <= m; ++i) {
// 		cin >> u >> v;
// 		adj[u].push_back(v);
// 		adj[v].push_back(u);
// 	}
// 	for (int i = 1; i <= n; ++i) {
// 		cout << i << ": { ";
// 		for (int j = 0; j < adj[i].size(); ++j) {
// 			cout << adj[i][j] << ", ";
// 		}
// 		cout << "}" << endl;
// 	}
// }
// void MaTranKe_Sang_DanhSachCanh() {
// 	int n;
// 	cin >> n;
// 	int adj[n + 1][n + 1];
// 	set<pair<int, int>> res;
// 	for (int i = 1; i <= n; ++i) {
// 		for (int j = 1; j <= n; ++j) {
// 			cin >> adj[i][j];
// 			if (adj[i][j] == 1) {
// 				res.insert({min(i, j), max(i, j)});
// 			}
// 		}
// 	}
// 	for (auto x : res) {
// 		cout << x.first << " " << x.second << endl;
// 	}

// }




vector<int> adj[maxn];
int n, m, u, v;
void INPUT() {
	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
}

bool visited[maxn];
void DFS(int u) {
	// tham dinh u
	visited[u] = true;
	// Tham cac dinh ke voi u
	for (auto v : adj[u]) {
		if (!visited[v]) {
			visited[v] = true;
			DFS(v);
		}
	}
}

void solve() {
	INPUT();
	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		if (!visited[i]) {
			cnt++;
			DFS(i);
		}
	}
	cout << cnt;
}

void BFS(int u) {
	INPUT();
	int visited[1001] = {}, v;
	queue<int> q;
	q.push(u);
	visited[u] = true;
	while (!q.empty()) {
		v = q.front();
		q.pop();
		visited[v] = true;
		cout << v << " ";
		for (auto u : adj[v]) {
			if (!visited[u]) {
				visited[u] = true;
				q.push(u);
			}
		}
	}
}
int main() {
	solve();
}