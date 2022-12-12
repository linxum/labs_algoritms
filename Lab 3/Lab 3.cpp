#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int dist[1001][1001];
int n, m;
char a[1001][1001];
int used[1001][1001];
queue <pair <int, int> > q;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int CanGo(int i, int j) {
	if ((i < 0) || (i >= n) || (j < 0) || (j >= n)) return 0;
	if (dist[i][j] != -1) {
		return 0;
	}
	else {
		return 1;
	}
}
void bfs(int sx, int sy, int ex, int ey) {
	q.push(make_pair(sx, sy));
	used[sx][sy] = 1;
	dist[sx][sy] = 0;
	while (!q.empty()) {
		pair <int, int> c = q.front();
		int x = c.first, y = c.second;
		q.pop();
		if (x == ex && y == ey) {
			return;
		}
		for (int i = 0; i < 4; i++) {
			int x1 = x + dx[i];
			int y1 = y + dy[i];
			if (CanGo(x1, y1) && !used[x1][y1]) {
				q.push(make_pair(x1, y1));
				dist[x1][y1] = dist[x][y] + 1;
				used[x1][y1] = 1;
			}
		}
	}
}
int main()
{
	int startx, starty, endx, endy;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			dist[i][j] = -1;
			if (a[i][j] == '@') {
				startx = i;
				starty = j;
			}
			if (a[i][j] == 'X') {
				endx = i;
				endy = j;
			}
			if (a[i][j] == 'O') {
				dist[i][j] = -2;
			}
		}
	}

	bfs(startx, starty, endx, endy);

	if (dist[endx][endy] == -1) {
		cout << "N" << endl;
		return 0;
	}
	else {
		int x = endx;
		int y = endy;
		while (dist[x][y] != 1) {
			if ((x - 1) >= 0 && (x - 1) < n && (dist[x - 1][y] == dist[x][y] - 1)) {
				x--;
				a[x][y] = '+';
			}
			else if ((x + 1) >= 0 && (x + 1) < n && (dist[x + 1][y] == dist[x][y] - 1)) {
				x++;
				a[x][y] = '+';
			}
			else if ((y - 1) >= 0 && (y - 1) < n && (dist[x][y - 1] == dist[x][y] - 1)) {
				y--;
				a[x][y] = '+';
			}
			else if ((y + 1) >= 0 && (y + 1) < n && (dist[x][y + 1] == dist[x][y] - 1)) {
				y++;
				a[x][y] = '+';
			}
		}
		a[endx][endy] = '+';
		cout << "Y" << endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << a[i][j];
			}
			cout << endl;
		}
	}
	return 0;
}
