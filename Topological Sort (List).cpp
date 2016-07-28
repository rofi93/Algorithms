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
int main()
{
    vector<int>v[100];
    int i,j,k,n,indegree[100],edge,node,node1,node2,x,count;
    printf("Enter number of nodes and edges: ");
    scanf("%d %d",&node,&edge);
    for(i=0; i<100; i++)
    {
        v[i].clear();
        indegree[i]=0;
    }
    for(i=1; i<=edge; i++)
    {
        scanf("%d %d",&node1,&node2);
        v[node1].push_back(node2);
        indegree[node2]++;
    }
    count=0;
    while(count<node)
    {
        for(i=1; i<=node; i++)
        {
            if(indegree[i]==0)
            {
                printf("%d ",i);
                indegree[i]=-1;
                break;
            }
        }
        for(j=0; j<v[i].size(); j++)
        {
            x=v[i][j];
            indegree[x]--;
        }
        count++;
    }
    return 0;
}
