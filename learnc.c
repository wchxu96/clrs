#include <stdio.h>

int main()
{
	int p[3] = {0,0,0};
	int *pp = p;
	pp[0] = 1;
	pp[1] = 2;
	pp[2] = 3;
	for (int i = 0 ; i < 3;i++)
	printf("%d\t",pp[i]);
	printf("\n");
	return 0;
}
