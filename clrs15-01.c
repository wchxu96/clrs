/*************************************************************************
	> File Name: clrs15-01.c
	> Author: 
	> Mail: 
	> Created Time: Tue 29 Nov 2016 08:29:39 PM
 ************************************************************************/
#define MAXALLOC 10
#define MAXEDGELENGTH 2000
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

// 顶点定义
typedef struct _Node
{
    int ivex; //该边所指向的顶点的位置,节点标识,不能重复
    //struct _ENode * next_edge;
    char info[MAXALLOC];//节点信息
}Node, *PNode;

//边定义
typedef struct _Edge
{
    PNode out;
    PNode in;
    float weight;
}Edge, *PEdge;

typedef struct _Graph
{
    int vertexnum;//节点数:
    int edgenum;//边数
    Edge edge[MAXEDGELENGTH];
}Graph, *PGraph;

typedef struct _edgelist
{
    PNode cur;
    float weight;
    struct _edgelist * next;
}edgelist, *Pedgelist;

//typedef struct _nodelist
//{
//
//PNode cur;
//    struct _nodelist* next;
//}nodelist, *pnodelist;


pedgelist inEdge(PGraph pg,int ivex)//返回指向给定节点的节点及边
{
    Pedgelist p = (Pedgelist)malloc(sizeof(edgelist));
    memset(p,0,sizeof(edgelist));
    Pedgelist head = p;
    for(PEdge e = pg->edge; e < &pg->edge[MAXEDGELENGTH]; e++)
    {
        if(e->in->ivex == ivex)
        {
                Pedgelist next_edge = (Pedgelist)malloc(sizeof(edgelist));
                p.next = next_edge;
                next_edge->cur = e;
                next_edge->weight = e->weight;
                next_edge->next = NULL;
                p =  next_edge;
        }
    }
    return head->next;
}
PGraph readGraph()
{
    int node_num;
    printf("please input your node number:");
    scanf("%d",&node_num);
    for(int i = 0 ;i < node_num; i++)
    {
        int node_id;
        char node_info[MAXALLOC];
        printf("please input each vertex's num:");
        scanf("%d",&node_id);
        pNode pnode = (PNode)malloc(sizeof(Node));
        pnode->ivex = node_id;
        printf("please input that vertex's additional infomation:");
        gets(PNode->info);
        
    }    
}
