/* -------------------------------- */
/* Name: MD. Khairul Basar          */
/* Institute: HSTU                  */
/* Dept: CSE                        */
/* Email: khairul.basar93@gmail.com */
/* -------------------------------- */

#include <bits/stdc++.h>
/* all header files included */

#define fs            first
#define sc            second
#define sp            printf(" ")
#define nl            printf("\n")
#define pb(a)         push_back(a)
#define mp(a,b)       make_pair(a,b)

#define setzero(a)    memset(a,0,sizeof(a))
#define setneg(a)     memset(a,-1,sizeof(a))
#define setinf(a)     memset(a,126,sizeof(a))

#define tc1(x)        printf("Case %d: ",x)
#define tc2(x)        printf("Case #%d: ",x)
#define tc3(x)        printf("Case %d:\n",x)
#define tc4(x)        printf("Case #%d:\n",x)

#define pr1(x)        cout<<x<<"\n"
#define pr2(x,y)      cout<<x<<" "<<y<<"\n"
#define pr3(x,y,z)    cout<<x<<" "<<y<<" "<<z<<"\n"
#define pr4(w,x,y,z)  cout<<w<<" "<<x<<" "<<y<<" "<<z<<"\n"
#define fast          ios::sync_with_stdio(0)
#define read          freopen("input.txt","r",stdin)
#define write         freopen("output.txt","w",stdout)
#define prflag1(flag) printf("%s\n",(flag)?"YES":"NO")
#define prflag2(flag) printf("%s\n",(flag)?"Yes":"No")
#define prflag3(flag) printf("%s\n",(flag)?"yes":"no")
/* defining macros */

using namespace std;

template <class T> inline T bigmod(T b, T p, T m)
{
    T ret;
    if(p==0) return 1;
    if(p&1)
    {
        ret=(bigmod(b,p/2,m)%m);
        return ((b%m)*ret*ret)%m;
    }
    else
    {
        ret=(bigmod(b,p/2,m)%m);
        return (ret*ret)%m;
    }
}
/* template functions */

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int>pii;
typedef pair<LL, LL>pll;
typedef vector<int>vi;
typedef vector<LL>vll;
typedef vector<pii>vpii;
typedef vector<pll>vpll;
/* type definition */

int dx4[]= {1,-1,0,0};
int dy4[]= {0,0,1,-1};
int dx6[]= {0,0,1,-1,0,0};
int dy6[]= {1,-1,0,0,0,0};
int dz6[]= {0,0,0,0,1,-1};
int dx8[]= {1,-1,0,0,-1,1,-1,1};
int dy8[]= {0,0,1,-1,1,1,-1,-1};
int dkx8[]= {-1,1,-1,1,-2,-2,2,2};
int dky8[]= {2,2,-2,-2,1,-1,1,-1};
/* direction array */

int tc=1;
const double eps=1e-9;
const double pi=acos(-1.0);
const long long int mx=1e5;
const long long int mod=1e9+7;
/* global declaration */

int main()
{
    vector<int>v[100];
    queue<int>q;
    int i,j,count,parent[100],level[100],visited[100],node1,node2,n,e,source,front,x;
    while(1)
    {
        printf("Enter number of nodes and edges: ");
        scanf("%d %d",&n,&e);
        if(n==0 && e==0)
            break;
        printf("Enter edges:\n");
        for(i=1; i<=e; i++)
        {
            scanf("%d %d",&node1,&node2);
            v[node1].push_back(node2);
            v[node2].push_back(node1);
        }
        memset(visited,0,100);
        memset(level,0,100);
        memset(parent,0,100);
        printf("Enter source: ");
        scanf("%d",&source);
        q.push(source);
        visited[source]=1;
        level[source]=0;
        while(!q.empty())
        {
            front=q.front();
            for(i=0; i<v[front].size(); i++)
            {
                x=v[front][i];
                if(!visited[x])
                {
                    level[x]=level[front]+1;
                    visited[x]=1;
                    parent[x]=front;
                    q.push(x);
                }
            }
            q.pop();
        }
        for(i=1; i<=n; i++)
        {
            printf("%d to %d distance %d\n",source,i,level[i]);
        }
        printf("\n");
        printf("Enter a node to find it's path: ");
        scanf("%d",&node1);
        printf("Path of %d:\n",node1);
        for(i=1 ;; i++)
        {
            x=parent[node1];
            printf("%d",x);
            if(x==source)
                break;
            printf(" > ");
            node1=x;
        }
        printf("\n\n");
    }
    return 0;
}
