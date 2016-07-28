#include<iostream>
#include<list>
#include<string>
#include<cstring>
#include<sstream>
#include<cctype>
#include<string.h>
#include<algorithm>
#include<cmath>
#include<stack>
#include<fstream>
#include<cstdlib>
#include<vector>
#include<map>
#include<utility>
#include<iomanip>
#include<queue>
using namespace std;
#define clr(a) memset(a,0,sizeof(a))
#define PB push_back
#define pi 3.1415926535897932384626433832795
int n,order[120][120],indegree[120],taken[120];


void topsort()
{
    vector<int>task;
    int i,j,k;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            if(!taken[j] && !indegree[j])
            {
                taken[j]=1;
                task.PB(j);
                for(k=1; k<=n; k++)
                    if(order[j][k])
                        --indegree[k];
                break;
            }
        }
    }
    cout<<task[0];
    for(i=1; i<n; i++)
        cout<<" "<<task[i];
    cout<<endl;
    task.clear();
}

int main()
{
    int a,b,i,m;
    while(cin>>n>>m)
    {
        if(n==0 && m==0)    break;
        for(i=1; i<=m; i++)
        {
            cin>>a>>b;
            order[a][b]=1;
            indegree[b]++;
        }
        topsort();
        clr(order);
        clr(indegree);
        clr(taken);
    }
    return 0;
}
