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
const long long int mx=10000;
/* global declaration */

vi edges[mx+5],revedges[mx+5],sortedlist;
bool visited[mx+5];
int compid[mx+5];

void reset(int n)
{
    sortedlist.clear();
    for(int i=1;i<=n;i++)
    {
        edges[i].clear();
        revedges[i].clear();
        visited[i]=false;
        compid[i]=0;
    }
}

void dfs1(int n)
{
    int i;
    visited[n]=true;
    for(i=0;i<edges[n].size();i++)
    {
        if(!visited[edges[n][i]])
            dfs1(edges[n][i]);
    }
    sortedlist.pb(n);
}

void dfs2(int n, int comp)
{
    int i;
    visited[n]=false;
    compid[n]=comp;
    for(i=0;i<revedges[n].size();i++)
    {
        if(visited[revedges[n][i]])
            dfs2(revedges[n][i],comp);
    }
}

void SCC(int node)
{
    int i,comp;
    for(i=1;i<=node;i++)
    {
        if(!visited[i])
            dfs1(i);
    }
    comp=1;
    for(i=sortedlist.size()-1;i>=0;i--)
    {
        if(visited[sortedlist[i]])
            dfs2(sortedlist[i],comp++);
    }
}

int main()
{
    int edge,node,i,u,v;
    scanf("%d %d",&node,&edge);
    reset(node);
    for(i=1;i<=edge;i++)
    {
        scanf("%d %d",&u,&v);
        edges[u].pb(v);
        revedges[v].pb(u);
    }
    SCC(node);
    for(i=1;i<=node;i++)
    {
        pr1(compid[i]);
    }
    nl;
    return 0;
}
