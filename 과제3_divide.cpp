#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

vector<vector<int>>v;
int visit[100005];
int arr[100005][2];
int ans[100005];
int check2[100005];

void dfs(int now) {
	visit[now] = 1;
	int next;
	int cnt = 0;
	for (int i = 0; i < v[now].size(); i++) {
		next = v[now][i];
		if (next == 0) {
			cnt++;
			continue;
		}
		if (visit[next]) continue;
		dfs(next);
		check2[now] += check2[next];
	}
}


int main() {
	int n;
	int a;
	int root;
	int check[100005] = { 0 };
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		scanf("%d %d", &arr[a][0], &arr[a][1]);
		check[arr[a][0]] = 1;
		check[arr[a][1]] = 1;
	}
	v.resize(n + 1);

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 2; j++)
			v[i].push_back(arr[i][j]);
	}

	for (int i = 1; i <= n; i++) {
		if (check[i] == 0)
			root = i;
		check2[i] = 1;
	}

	dfs(root);

	int rans = 100005;

	for (int i = 1; i <= n; i++) {
		rans = min(rans, abs(n - (2 * check2[i])));
	}
	printf("%d\n", rans);
	return 0;
}