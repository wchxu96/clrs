#include<stdlib.h>  
#include<stdio.h>  
#include <memory.h>
#include <string.h> 
#include <limits.h> 
    '
#define N 6  
    void Print_OPTIMAL_PARENS(int s[N+1][N+1],int i,int j) //定义函数打印最优全括号的结果  
    {  
        if(i==j)  
            printf("A%d",i);  
        else  
        {  
            printf("(");  
            Print_OPTIMAL_PARENS(s,i,s[i][j]);           //在分裂处进行递归调用  
            Print_OPTIMAL_PARENS(s,s[i][j]+1,j);  
            printf(")");  
        }  
    }  
    int main()  
    {  
        int matrix[N+1];                  //matrix中记录矩阵的维数  
        int i,j,k,q;  
        int m[N+1][N+1];                  //m中记录矩阵连乘的次数  
        int s[N+1][N+1];                  //s[i][j]中记录了对Ai...Aj进行分裂的最优的k值  
        for(i=0;i<=N;i++)  
            scanf("%d",&matrix[i]);  
        memset(m,0,sizeof(m));  
        for(j=1;j<=N;j++)                  
            for (i=j;i>=1;i--)          //当i=j时,m[i][j]=0，                             
            {                           //当i<j时,m[i][j]=min{m[i][k]+m[k+1][j]+p(i-1)p(k)p(j)} i=<k<j                    
                if (j==i)  
                    m[i][j]=0;  
                else  
                {  
                    m[i][j]=INT_MAX;   
                    for (k=i;k<j;k++)  
                    {  
                        q=m[i][k]+m[k+1][j]+matrix[i-1]*matrix[k]*matrix[j];  
                        if (q<m[i][j])  
                        {  
                            m[i][j]=q;  
                            s[i][j]=k;  
                        }  
                    }  
                }  
            }  
    printf("%d\n",m[1][N]);  
    Print_OPTIMAL_PARENS(s,1,N);  
    return 0;  
    }  
