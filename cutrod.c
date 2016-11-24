//dp clrs 老师的进度,clrs第一道dp例题，切钢条问题

#include <stdio.h>
#include <string.h>

int buttomupcutrod(int p[],int n,int x)//p价格表,n是价格表长度-1,x是所要切割的总长度
{
	int dp[n + 1];
	memset(dp,-1,sizeof(dp));
	dp[0] = 0;
	int q;
	for(int i = 1 ; i < n + 1 ; i++)
	{
		q = -1;
		for(int j = 1 ; j <= i ; j++)
		{
			if(p[j] + dp[i - j] > q)
			{
				q = p[j] + dp[i - j];
			}
			dp[i] = q;
			
		}

	}
	return dp[x];
}

int recmemocutrod(int p[],int n,int x)//带备忘的递归实现
{
	int memo[n + 1];
	int res;
	memset(memo,-1,sizeof(memo));
	memo[0] = 0;
	if(memo[x] >= 0)
	{
		return memo[x];
	}
	else
	{
		for(int j = 0; j < x; j ++)
		{
			res = recmemocutrod(p,n,j) + p[x - j];
			if (res > memo[x])
				memo[x] = res;
		}
		return memo[x];
	}

}


int main()
{
	int arr[11] = {-1,1,5,8,9,10,17,17,20,24,30};
	int c = recmemocutrod(arr,10,9);
	printf("%d\n",c);
	return 0;
}
