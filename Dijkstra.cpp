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

vector<int>v[101];
vector<int>cost[101];
int dist[101],par[101];

class node
{
public:
    int u,v;                   /* u=node number, v=distance */
    node(int a, int b)
    {
        u=a;
        v=b;
    }
    node()
    {

    }
};
bool operator<(node A, node B)
{
    return B.v<A.v;
}
int Dijkstra(int n)
{
    node top;
    int x,i,a;
    memset(dist,100,sizeof(dist));
    memset(par,100,sizeof(par));
    priority_queue<node>Q;
    Q.push(node(1,0));
    par[1]=0;
    dist[1]=0;
    while(!Q.empty())
    {
        top=Q.top();
        Q.pop();
        x=top.u;
        if(x==n)
            return dist[n];
        for(i=0;i<v[x].size();i++)
        {
            a=v[x][i];
            if(dist[x]+cost[x][i]<dist[a])
            {
                dist[a]=dist[x]+cost[x][i];
                par[a]=x;
                Q.push(node(a,dist[a]));
            }
        }
    }
    return -1;
}
int main()
{
    vector<int>out;
    int node,edge,node1,node2,cst,ret,u,i;
    scanf("%d %d",&node,&edge);
    for(i=0;i<edge;i++)
    {
        scanf("%d %d %d",&node1,&node2,&cst);
        v[node1].push_back(node2);
        v[node2].push_back(node1);
        cost[node1].push_back(cst);
        cost[node2].push_back(cst);
    }
    ret=Dijkstra(node);
    if(ret==-1)
    {
        printf("No Path\n");
    }
    else
    {
        u=node;
        while(u)
        {
            out.push_back(u);
            u=par[u];
        }
        reverse(out.begin(),out.end());
        for(i=0;i<out.size();i++)
        {
            cout<<out[i]<<endl;
        }
    }

    return 0;
}
