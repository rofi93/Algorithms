/* -------------------------------- */
/* Name: MD. Khairul Basar          */
/* Institute: HSTU                  */
/* Dept: CSE                        */
/* Email: khairul.basar93@gmail.com */
/* -------------------------------- */

#include <bits/stdc++.h>
/* all header files */

#define fs            first
#define sc            second
#define sp            printf(" ")
#define nl            printf("\n")
#define pb(a)         push_back(a)

#define setzero(a)    memset(a,0,sizeof(a))
#define setneg(a)     memset(a,-1,sizeof(a))
#define setinf(a)     memset(a,126,sizeof(a))

#define tc1(x)        printf("Case %d: ",x)
#define tc2(x)        printf("Case #%d: ",x)
#define tc3(x)        printf("Case %d:\n",x)
#define tc4(x)        printf("Case #%d:\n",x)

#define iin(x)        scanf("%d",&x)
#define din(x)        scanf("%lf",&x)
#define lin(x)        scanf("%lld",&x)
#define clin(x)       scanf("%I64d",&x)

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
/* macro definitions */

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int>pii;
typedef pair<LL, LL>pll;
typedef vector<int>vi;
typedef vector<LL>vll;
typedef vector<pii>vpii;
typedef vector<pll>vpll;
/* type definitions */

LL MOD_EXPO(LL b, LL p, LL m)
{
    if(p==0) return 1;
    LL ret=MOD_EXPO(b,p/2,m)%m;
    ret=(ret*ret)%m;
    return ((p&1) ? (ret*b)%m : ret%m);
}
LL POWER(LL N, LL K)
{
    LL i,ans=1;
    for(i=1; i<=K; i++) ans*=N;
    return ans;
}
int SET(int N, int pos)
{
    return (N | (1<<pos));
}
int RESET(int N, int pos)
{
    return (N & !(1<<pos));
}
bool CHECK(int N, int pos)
{
    return (N & (1<<pos));
}
/* necessary functions */

int dx4[]= {1,-1,0,0};
int dy4[]= {0,0,1,-1};
int dx6[]= {0,0,1,-1,0,0};
int dy6[]= {1,-1,0,0,0,0};
int dz6[]= {0,0,0,0,1,-1};
int dx8[]= {1,-1,0,0,-1,1,-1,1};
int dy8[]= {0,0,1,-1,1,1,-1,-1};
int dkx8[]= {-1,1,-1,1,-2,-2,2,2};
int dky8[]= {2,2,-2,-2,1,-1,1,-1};
/* direction arrays */

int tc=1;
const double eps=1e-9;
const double pi=acos(-1.0);
const long long int mx=1e5;
const long long int mod=1e9+7;
/* global declarations */

struct tree_node
{
    int parent;
    int level;
    int sub_tree_size;
    int chain_id;
    int pos_base_arr;
    int heavy;
    bool visited;
};

tree_node node[mx+5];
int base_arr[mx+5];
int tree[4*mx+5];
int chain_head[mx+5];
vector<int>edges[mx+5];
vector<int>weight[mx+5];
int n,m,q,edge_count,current_chain;

void reset(void)
{
    setzero(node);
    setzero(tree);
    for(int i=0; i<=mx; i++)
    {
        chain_head[i]=0;
        edges[i].clear();
        weight[i].clear();
        base_arr[i]=0;
    }
    return;
}

int dfs(int x)
{
    int i,a,sub_tree,max_sub_tree;

    max_sub_tree=0;
    node[x].heavy=-1;
    node[x].visited=true;
    node[x].sub_tree_size=1;

    for(i=0; i<edges[x].size(); i++)
    {
        a=edges[x][i];
        sub_tree=0;
        if(!node[a].visited)
        {
            node[a].parent=x;
            node[a].level=node[x].level+1;
            sub_tree=dfs(a);
            if(sub_tree>max_sub_tree)
            {
                max_sub_tree=sub_tree;
                node[x].heavy=i;
            }
            node[x].sub_tree_size+=sub_tree;
        }
    }
    return node[x].sub_tree_size;
}

void hld(int x, int wt)
{
    int i,a;

    if(!chain_head[current_chain]) chain_head[current_chain]=x;

    edge_count++;
    base_arr[edge_count]=wt;
    node[x].visited=false;
    node[x].chain_id=current_chain;
    node[x].pos_base_arr=edge_count;

    if(node[x].heavy!=-1)
    {
        a=node[x].heavy;
        hld(edges[x][a],weight[x][a]);
    }

    for(i=0; i<edges[x].size(); i++)
    {
        a=edges[x][i];
        if(node[a].visited && node[x].heavy!=i)
        {
            current_chain++;
            hld(edges[x][i],weight[x][i]);
        }
    }
    return;
}

void build(int st_node, int begin, int end)
{
    if(begin==end)
    {
        tree[st_node]=base_arr[begin];
        return;
    }
    int l,r,mid;
    l=2*st_node;
    r=2*st_node+1;
    mid=(begin+end)/2;

    build(l,begin,mid);
    build(r,mid+1,end);
    tree[st_node]=max(tree[l],tree[r]);
    return;
}

void update(int st_node, int begin, int end, int idx, int val)
{
    if(idx<begin || idx>end) return;
    if(begin==idx && idx==end)
    {
        tree[st_node]=val;
        return;
    }
    int l,r,mid;
    l=2*st_node;
    r=2*st_node+1;
    mid=(begin+end)/2;

    update(l,begin,mid,idx,val);
    update(r,mid+1,end,idx,val);
    tree[st_node]=max(tree[l],tree[r]);
    return;
}

int query(int st_node, int begin, int end, int a, int b)
{
    if(b<begin || a>end) return 0;
    if(begin>=a && end<=b) return tree[st_node];

    int l,r,mid,L,R;
    l=2*st_node;
    r=2*st_node+1;
    mid=(begin+end)/2;

    L=query(l,begin,mid,a,b);
    R=query(r,mid+1,end,a,b);
    return max(L,R);
}

int find_pos(int a)
{
    int x;
    x=node[a].chain_id;
    return chain_head[x];
}

void change(int a, int b, int c)
{
    int x=0;
    if(node[a].parent==b) x=a;
    if(node[b].parent==a) x=b;
    update(1,1,edge_count,node[x].pos_base_arr,c);
    return;
}

int rmq(int a, int b)
{
    int L,R,tmp,x,y,ans;
    ans=0;
    while(true)
    {
        if(node[a].chain_id==node[b].chain_id)
        {
            if(node[a].level<node[b].level) L=a,R=b;
            else L=b,R=a;
            ans=max(ans,query(1,1,edge_count,node[L].pos_base_arr+1,node[R].pos_base_arr));
            break;
        }
        else
        {
            x=find_pos(a);
            y=find_pos(b);
            if(node[x].level>node[y].level)
            {
                L=chain_head[node[a].chain_id];
                R=a;
                a=node[L].parent;
                if(!a) a=1;
            }
            else
            {
                L=chain_head[node[b].chain_id];
                R=b;
                b=node[L].parent;
                if(!b) b=1;
            }
            ans=max(ans,query(1,1,edge_count,node[L].pos_base_arr,node[R].pos_base_arr));
        }
    }
    return ans;
}

int main()
{
    int i,a,b,c,type;
    while(cin>>n>>m>>q)
    {
        reset();
        for(i=0; i<m; i++)
        {
            iin(a);
            iin(b);
            iin(c);
            edges[a].pb(b);
            edges[b].pb(a);
            weight[a].pb(c);
            weight[b].pb(c);
        }
        dfs(1);
        edge_count=0;
        current_chain=1;
        hld(1,-1);
        build(1,1,edge_count);
        while(q--)
        {
            iin(type);
            if(type==1)
            {
                iin(a);
                iin(b);
                iin(c);
                change(a,b,c);
            }
            else
            {
                iin(a);
                iin(b);
                printf("%d\n",rmq(a,b));
            }
        }
    }
    return 0;
}
