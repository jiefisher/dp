#include<iostream>
#include<algorithm>
using namespace std;
int N, M,s=0;
int dp[100][100];
int main()
{
	int a[100];
	int i, j,mins=999;
	cin >> N >> M;
	for (i = 0; i < N; i++)
	{
		cin >> a[i];
		s += a[i];
	}
	for (i = 0; i < 100; i++)
		dp[0][i] = 0;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j <= s; j++)
		{
			if (j < a[i])
				dp[i + 1][j] = dp[i][j];
			else {
				if (dp[i][j] - M < 0 && dp[i][j-a[i]]+a[i]-M < 0)
				{
					dp[i + 1][j] = max(dp[i][j], dp[i][j - a[i]] + a[i]);
				}
				else if (dp[i][j] - M < 0 || dp[i][j - a[i]] + a[i] - M < 0)
				{
					dp[i + 1][j] = max(dp[i][j], dp[i][j - a[i]] + a[i]);
					if(dp[i + 1][j] - M<mins)
						mins = dp[i + 1][j] - M;
				}
				else
				{
					dp[i + 1][j] = min(dp[i][j]-M, dp[i][j - a[i]] + a[i]-M)+M;
					if (dp[i + 1][j] - M<mins)
						mins = dp[i + 1][j] - M;
				}
			}
		}
		
	}
	cout << mins << endl;
}