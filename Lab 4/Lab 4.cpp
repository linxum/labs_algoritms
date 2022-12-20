#include <iostream>
#include <Windows.h>

using namespace std;

int main() {
	int n, k, val;
	int sum[100000];
	cin >> n;
	cin >> k;
	sum[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> val;
		sum[i] = sum[i - 1] + val;
	}

	int min = 100; int max = -100;
	for (int i = k; i <= n; i++)
	{
		if (sum[i] - sum[i - k] < min)
			min = sum[i] - sum[i - k];
		if (sum[i] - sum[i - k] > max)
			max = sum[i] - sum[i - k];
	}
	cout << min / k << endl << max / k;
}
