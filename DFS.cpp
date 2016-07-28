#include<cstdio>
#include<cmath>
#include<cctype>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<list>
#include<algorithm>
#include<utility>
using namespace std;

vector<int>v[100];
int visited[100];

int DFS(int src)
{
    int i,j;
    visited[src]=1;
    printf("%d ",src);
    for(i=0;i<v[src].size();i++)
    {
        j=v[src][i];
        if(visited[j]==0)
        {
            DFS(j);
        }
    }
    return 0;
}
int main()
{
    int i,j,node,edge,node1,node2,source;
    while(scanf("%d %d",&node,&edge)!=EOF)
    {
        if(node==0 && edge==0)
            break;
        memset(visited,0,100);
        for(i=1;i<=edge;i++)
        {
            scanf("%d %d",&node1,&node2);
            v[node1].push_back(node2);
        }
        scanf("%d",&source);
        DFS(source);
    }
    return 0;
}
