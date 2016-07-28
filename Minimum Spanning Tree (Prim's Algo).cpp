/* -------------------------------- */
/* Name: MD. Khairul Basar          */
/* Institute: HSTU                  */
/* Dept: CSE                        */
/* Email: khairul.basar93@gmail.com */
/* -------------------------------- */

#include <bits/stdc++.h>
/* all header files included */

#define mod         1000000007
#define pi          acos(-1.0)
#define eps         1e-9

#define fs          first
#define sc          second
#define pb(a)       push_back(a)
#define mp(a,b)     make_pair(a,b)
#define sp          printf(" ")
#define nl          printf("\n")

#define set0(a)     memset(a,0,sizeof(a))
#define setneg(a)   memset(a,-1,sizeof(a))
#define setinf(a)   memset(a,126,sizeof(a))

#define tc1(x)      printf("Case %d: ",x)
#define tc2(x)      printf("Case #%d: ",x)
#define tc3(x)      printf("Case %d:\n",x)
#define tc4(x)      printf("Case #%d:\n",x)

#define pr1(x)      cout<<x<<"\n"
#define pr2(x,y)    cout<<x<<" "<<y<<"\n"
#define pr3(x,y,z)  cout<<x<<" "<<y<<" "<<z<<"\n"
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
template <class T> inline T _sqrt(T a)
{
    return (T)sqrt((double)a);
}
template <class T, class X> inline T _pow(T a, X b)
{
    T res=1;
    for(int i=1; i<=b; i++)
        res*=a;
    return res;
}
/* template functions */

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int>pii;
typedef pair<LL, LL>pll;
typedef pair<double, double>pdd;
typedef vector<int>vi;
typedef vector<LL>vll;
typedef vector<double>vd;
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
const long long int mx=100000;
/* global declaration */
class graph
{
public:
    int u,v;                    /* u=node number, v=weight */
    graph()
    {

    }
    graph(int a, int b)
    {
        u=a;
        v=b;
    }
};

bool operator<(graph A, graph B)
{
    return B.v<A.v;
}

int main()
{
    int node1,node2,i,j,u,v,w,n,m,parent[100],visited[100],count,ans;

    while(cin>>n>>m)
    {
        if(n==0 && m==0)
            break;

        vi adj[100],cost[100];
        priority_queue<graph>PQ;

        for(i=0; i<=n; i++)
        {
            parent[i]=visited[i]=0;
        }
        for(i=1; i<=m; i++)
        {
            scanf("%d %d %d",&u,&v,&w);
            adj[u].pb(v);
            adj[v].pb(u);
            cost[u].pb(w);
            cost[v].pb(w);
        }
        cin>>node1>>node2;
        count=0;
        ans=0;
        //visited[node1]=1;
        parent[node1]=0;
        PQ.push(graph(node1,0));
        graph top;

        while(true)
        {
            top=PQ.top();
            PQ.pop();
            u=top.u;
            if(visited[u]==0)
            {
                for(i=0; i<adj[u].size(); i++)
                {
                    PQ.push(graph(adj[u][i],cost[u][i]));
                }
                visited[u]=1;
                count++;
                ans+=top.v;
                if(count==n-1)
                    break;
            }
        }
        pr1(ans);
    }
    return 0;
}
