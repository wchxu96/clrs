//最大子数组问题

#include <stdio.h>
int * find_max_subarray_cross(int array[], int low, int mid, int high, int *res)
{
	int left_sum = -10000;
	int sum = 0;
	int right_sum = -10000;
	int max_left = 0;
	int max_right = 0;
	for(int i = mid ; i >= low ; i--)
	{	
		sum += array[i];
		if(sum > left_sum)
		{
			left_sum = sum;
			max_left = i;
		}
	}
	sum = 0;
	for(int j = mid + 1; j <= high; j++)
	{
		sum += array[j];
		if(sum > right_sum)	
		{	
			right_sum = sum;
			max_right = j;
		}
	}
	//memset(res,0,sizeof(int) * 3);
	res[0] = max_left;
	res[1] = max_right;
	res[2] = left_sum + right_sum;
	return res;
}


int * find_max_subarray(int array[], int low,int high, int *res)
{
	if(low == high)
	{
		res[0] = low;
		res[1] = low;
		res[2] = array[low];
		return res;
	}
	else
	{
		int mid = (low + high) / 2;
		int p1[3] = {0,0,0};
		int p2[3] = {0,0,0};
		int p3[3] = {0,0,0};
		int *pleft = p1;
		int *pright = p2;
		int *pcross = p3;
		pleft = find_max_subarray(array,low,mid,pleft);
		pright = find_max_subarray(array,mid + 1,high,pright);
		pcross = find_max_subarray_cross(array,low,mid,high,pcross);
		if(pleft[2] >= pright[2] && pleft[2] >= pcross[2])
		{
			res[0] = pleft[0];
			res[1] = pleft[1];
			res[2] = pleft[2];
		}
		else if(pright[2] >= pleft[2] && pright[2] >= pcross[2])
		{
			res[0] = pright[0];
			res[1] = pright[1];
			res[2] = pright[2];
		}
		else
		{
			res[0] = pcross[0];
			res[1] = pcross[1];
			res[2] = pcross[2];
		}
		return res;
	}
}


int main()
{
	int arr[16]= {13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
	int p[3]= {1,1,1};
	int *res = p;
	res = find_max_subarray(arr,0,15,p);
	for ( int i = 0 ; i < 3 ; i++)
		printf("%d\t",p[i]);
	printf("\n");
	return 0;
}
