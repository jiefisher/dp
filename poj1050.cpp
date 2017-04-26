#include <iostream>
#include <fstream>
#include <string.h>
#include<cstdlib>
using namespace std; 
int N;
int maxsubs(int tb[]);
int main()
{

	int a[101][101];
	int t1[101], t2[101];
	int i, j,k;

	cin >> N;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
			cin >> a[i][j];
	}
	
	//cout << maxsubs(a[1]) << endl;
	i = 0;
	j = 0;
	k = 0;
	int maxm = 0;
	for (i = 0; i < N; i++)
	{
		memset(t1, 0, sizeof(int) * N);
		for (k = i; k < N; k++)
		{
			for (j = 0; j < N; j++)
			{
				t1[j] += a[k][j];
			}
			int tp = maxsubs(t1);

			if (tp > maxm)
				maxm = tp;
		}

	}
	
	cout << maxm << endl;
}

int maxsubs(int tb[])
{
	int i;
	int b = 0, maxm = 0;


	for (i = 0; i < N; i++)
	{
		if (b + tb[i] >= 0)
		{
			b += tb[i];
		}
		else if (b + tb[i] < 0)
		{
			b = 0;


		}

		if (b >= maxm) {
			maxm = b;
		}
	}
	
	return maxm;
}
