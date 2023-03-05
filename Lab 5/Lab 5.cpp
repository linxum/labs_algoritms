#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
 
using namespace std;
 
unsigned long long chmod[10];
char sym[10];
 
int getIndex(char* word, char ch)
{
	for (int i = 0; i < 10; i++)
	{
		if (sym[i] == ch)
		{
			return i;
		}
	}
}
 
unsigned long long task(int n, string* words)
{
	for (int i = 0; i < 10; i++)
	{
		chmod[i] = 0;
	}
 
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < words[i].length(); j++)
		{
			chmod[words[i][j] - 'A'] += pow(10, words[i].length() - j);
		}
	}
 
 
	for (int i = 0; i < 10; i++)
	{
		sym[i] = char('A' + i);
	}
 
	int min_idx;
	for (int i = 0; i < 10; i++)
	{
		min_idx = i;
		for (int j = i + 1; j < 10; j++)
		{
			if (chmod[j] > chmod[min_idx])
				min_idx = j;
		}
		if (chmod[min_idx] == 0)
			break;
		swap(chmod[min_idx], chmod[i]);
		swap(sym[min_idx], sym[i]);
	}
 
	unsigned long long max = 0;
	for (int i = 0; i < n; i++)
	{
		unsigned long long tmp = 0;
		for (int j = 0; j < words[i].length(); j++)
		{
			tmp = tmp * 10 + 9 - getIndex(sym, words[i][j]);
		}
		max += tmp;
	}
	return max;
}
 
int main()
{
	int n;
	cin >> n;
	string* words = new string[n];
	for (int i = 0; i < n; i++)
	{
		cin >> words[i];
	}
	unsigned long long max = task(n, words);
	cout << max;
}
