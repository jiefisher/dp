#include<iostream>
#include<cmath>
#include<string.h>
#include<stdlib.h>
using namespace std;
int N, M, dp[10005][200];
int main()
{
	int a[10005];
	int i, j;
	cin >> N >> M;
	for (i = 0; i < N; i++)
	{
		cin >> a[i];
		
	}
	memset(dp, 0, sizeof(dp));
	dp[0][abs(a[0]%M)] = 1;
	for (i = 1; i <= N; i++)
	{
		for (j = 0; j < M; j++)
		{
			if (dp[i-1][j])
			{
				
				dp[i][(j + a[i]%M+M) % M] = 1;
				dp[i][(j - a[i]%M+M) % M] = 1;
				
			}
		}
	}
	//for (i = 0; i < N; i++)
	//{
	//	for (j = 0; j < M; j++)
	//	{
	//		cout << dp[i][j] << ' ';
	//	}
	//	cout << endl;
	//}
	if(dp[N-1][0])
		cout << "Divisible" << endl;
	else
	{
		cout << "Not divisible" << endl;
	}
}