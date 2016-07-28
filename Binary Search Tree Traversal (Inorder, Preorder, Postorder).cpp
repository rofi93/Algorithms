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

struct node
{
    char data;
    node *left;
    node *right;
};

node* new_node(char data)
{
    node *child = new node;
    child->data=data;
    child->left=NULL;
    child->right=NULL;

    return child;
}

void preorder(node *child)
{
    if(child==NULL)
        return;
    printf("%c ",child->data);
    preorder(child->left);
    preorder(child->right);
}

void inorder(node *child)
{
    if(child==NULL)
        return;
    inorder(child->left);
    printf("%c ",child->data);
    inorder(child->right);
}

void postorder(node *child)
{
    if(child==NULL)
        return;
    postorder(child->left);
    postorder(child->right);
    printf("%c ",child->data);
}

void delete_tree(node *child)
{
    if(child==NULL)
        return;
    delete_tree(child->left);
    delete_tree(child->right);
    delete child;
}

int main()
{
    node *root=new_node('*');
    root->left=new_node('+');
    root->right=new_node('/');
    root->left->left=new_node('a');
    root->left->right=new_node('-');
    root->right->left=new_node('-');
    root->right->right=new_node('-');
    root->left->right->left=new_node('b');
    root->left->right->right=new_node('c');
    root->right->left->left=new_node('d');
    root->right->left->right=new_node('e');
    root->right->right->left=new_node('+');
    root->right->right->right=new_node('h');
    root->right->right->left->left=new_node('f');
    root->right->right->left->right=new_node('g');

    cout<<"Pre-order traversal of binary tree\n";
    preorder(root);

    cout<<"\nIn-order traversal of binary tree\n";
    inorder(root);

    cout<<"\nPost-order traversal of binary tree\n";
    postorder(root);

    cout<<endl;
    delete_tree(root);
    return 0;
}
