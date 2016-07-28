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

struct node;
class comparator;
void codes(node *head, string str);
node* create_node(char ch, int f);
void huffman(void);

struct node
{
    int freq;
    char key;
    string prefix_code;
    node *left;
    node *right;
};

class comparator
{
public:
    bool operator()(node *a, node *b)
    {
        return b->freq < a->freq;
    }
};

priority_queue<node *, vector<node *>, comparator>PQ;

node* create_node(char ch, int f)
{
    node *temp=new node;
    temp->freq=f;
    temp->key=ch;
    temp->prefix_code="";
    temp->left=temp->right=NULL;

    return temp;
}

void huffman(void)
{
    node *tmp, *top1,*top2;
    while(PQ.size()>1)
    {
        top1=PQ.top(); PQ.pop();
        top2=PQ.top(); PQ.pop();
        int a=top1->freq+top2->freq;
        tmp=create_node('\0',a);
        tmp->left=top1;
        tmp->right=top2;
        PQ.push(tmp);
    }
    tmp=PQ.top(); PQ.pop();
    codes(tmp,"");
}

void codes(node *head, string str)
{
    if(head==NULL)
        return;
    if(head->left==NULL && head->right==NULL)
    {
        cout<<head->key<<": "<<str<<endl;
        delete head;
        return;
    }
    codes(head->left,str+"0");
    codes(head->right,str+"1");
}

int main()
{
    int i,n,f;
    char ch;

    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>ch>>f;
        node *leaf=create_node(ch,f);
        PQ.push(leaf);
    }
    nl;
    huffman();

    return 0;
}
