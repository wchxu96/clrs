/*************************************************************************
	> File Name: clrs15-02.c
	> Author: 
	> Mail: 
	> Created Time: Wed 30 Nov 2016 08:50:02 PM
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAXLEN  50
int palindrome(char str[],int n)
{
    int dp[n][n];
    memset(dp,0,sizeof(dp));
    for(int i = 0; i < n;i++)
    {
        dp[i][i] = 1;
    }
    for(int len = 2 ; len <= n; len++)
        for(int j = 0 ; j < n - len + 1; j++)
        {
            if(str[j] == str[j + len - 1])
            {
                dp[j][j + len - 1] = dp[j + 1][j + len - 2] + 2;
            }
            else
            {
               // if(dp[j][j + len - 1] )
                dp[j][j + len - 1] = dp[j + 1][j + len - 1] > dp[j][j + len - 2]?dp[j + 1][j + len - 1]:dp[j][j + len - 2];
            }

        }
    return dp[0][n - 1];
}
int main()
{
    char str[MAXLEN];
    printf("please input your string and press enter\n");
    gets(str);
    int res = palindrome(str,strlen(str));
    printf("%d\n",res);
    return 0;
}
