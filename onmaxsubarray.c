// 分治算法时间复杂度为nlogn,clrs中提出有线性算法，下为实现

#include <stdio.h>
#include <string.h>
int sub_Arr(int arr[],int n)
{
	int dp[n];//最大子数组
	int dpcur[n];
	memset(dp,0,sizeof(dp));
	memset(dpcur,0,sizeof(dp));
	dpcur[0] = dp[0] = arr[0];
	for(int i = 0 ; i < n - 1; i++)
	{
		if(dpcur[i] < 0)
			dpcur[i+1] = arr[i+1];
		else
			dpcur[i+1] = dpcur[i] + arr[i+1];
	}
	for(int i = 0 ; i < n - 1; i++)
	{
		if(dp[i] > dpcur[i + 1])
		{
			dp[i + 1] = dp[i];
		}
		else
		{
			dp[i + 1] = dpcur[i + 1];
		} 
	}
	return dp[n-1];
}
int main()
{
	int array[16] = {13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
	int res = sub_Arr(array,16);
	/*for(int i = 0 ; i < 3;i++)
	{
		printf("%d\t",res[i]);
	}
	printf("\n");
*/
	printf("%d\n",res);
	return 0;
}
