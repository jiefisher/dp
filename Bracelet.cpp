#include<iostream>
#include <algorithm>
using namespace std;
int N, M;
int w[5000], d[5000], dp[13000];
int main()
{
	cin >> N >> M;
	int i,j;
	for (i = 0; i < N; i++)
	{
		cin >> w[i] >> d[i];
	}
	for (i = 0; i < N; i++)
	{
		for (j = M; j >= w[i]; j--)
		{
			dp[j] = max(dp[j], dp[j - w[i]] + d[i]);
		}
	}
	cout << dp[M] << endl;
}