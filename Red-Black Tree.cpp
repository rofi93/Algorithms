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
    if(p==0)
        return 1;
    LL ret=MOD_EXPO(b,p/2,m)%m;
    ret=(ret*ret)%m;
    return ((p&1) ? (ret*b)%m : ret%m);
}
LL POWER(LL N, LL K)
{
    LL i,ans=1;
    for(i=1; i<=K; i++)
        ans*=N;
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

struct node
{
    int key;
    int value;
    bool color;

    node *left;
    node *right;
    node *parent;
};

node *root, *nil;

node* create_node(int key_, int value_)
{
    node *new_node = new node;

    new_node->key = key_;
    new_node->color = false;
    new_node->value = value_;

    new_node->left = NULL;
    new_node->right = NULL;
    new_node->right = NULL;

    return new_node;
}

void tree_initialize(void)
{
    nil = NULL;
    root = NULL;
    return;
}

void tree_rotate_left(node *x)
{
    node *y;

    y = x->right;
    x->right = y->left;

    if(y->left != nil)
        y->left->parent = x;
    y->parent = x->parent;

    if(x->parent == nil)
    {
        root = y;
    }
    else
    {
        if(x == x->parent->left)
            x->parent->left = y;
        else
            x->parent->right = y;
    }

    y->left = x;
    x->parent = y;
    return;
}

void tree_rotate_right(node *y)
{
    node *x;

    x = y->left;
    y->left = x->right;

    if(x->right != nil)
        x->right->parent = y;
    x->parent = y->parent;

    if(y->parent == nil)
    {
        root = x;
    }
    else
    {
        if(y == y->parent->right)
            y->parent->right = x;
        else
            y->parent->left = x;
    }

    x->right = y;
    y->parent = x;
    return;
}

void tree_insert_fixup(node *z)
{
    node *y;
    while(z->parent && z->parent->color)
    {
        if(z->parent == z->parent->parent->left)
        {
            y = z->parent->parent->right;
            if(y->color)
            {
                z->parent->color = false;
                y->color = false;
                z->parent->parent->color = true;
                z = z->parent->parent;
            }
            else
            {
                if(z == z->parent->right)
                {
                    z = z->parent;
                    tree_rotate_left(z);
                }
                z->parent->color = false;
                z->parent->parent->color = true;
                tree_rotate_right(z->parent->parent);
            }
        }
        else
        {
            y = z->parent->parent->left;
            if(y->color)
            {
                z->parent->color = false;
                y->color = false;
                z->parent->parent->color = true;
                z = z->parent->parent;
            }
            else
            {
                if(z == z->parent->left)
                {
                    z = z->parent;
                    tree_rotate_right(z);
                }
                z->parent->color = false;
                z->parent->parent->color = true;
                tree_rotate_left(z->parent->parent);
            }
        }
    }
    return;
}

void tree_insert(node *z)
{
    node *y = nil;
    node *x = root;
    while(x != nil)
    {
        y = x;
        if(z->key < x->key)
            x = x->left;
        else
            x = x->right;
    }
    z->parent = y;

    if(y == nil)
    {
        root = z;
    }
    else
    {
        if(z->key < y->key)
            y->left = z;
        else
            y->right = z;
    }
    z->left = nil;
    z->right = nil;
    z->color = true;

    return;
}

node* tree_minimum(node *x)
{
    while(x->left != nil)
    {
        x = x->left;
    }
    return x;
}

void tree_transplant(node *u, node *v)
{
    if(u->parent == nil)
    {
        root = v;
    }
    else
    {
        if(u == u->parent->left)
            u->parent->left = v;
        else
            u->parent->right = v;
    }
    v->parent = u->parent;
    return;
}

void tree_delete_fixup(node *x)
{
    node *w;

    while(x != root && !x->color)
    {
        if(x == x->parent->left)
        {
            w = x->parent->right;
            if(w->color)
            {
                w->color = false;
                x->parent->color = true;
                tree_rotate_left(x->parent);
                w = x->parent->right;
            }
            if(!w->left->color && !w->right->color)
            {
                w->color = true;
                x = x->parent;
            }
            else
            {
                if(!w->right->color)
                {
                    w->left->color = false;
                    w->color = true;
                    tree_rotate_right(w);
                    w = x->parent->right;
                }
                w->color = x->parent->color;
                x->parent->color = false;
                w->right->color = false;
                tree_rotate_left(x->parent);
                x = root;
            }
        }
        else
        {
            w = x->parent->left;
            if(w->color)
            {
                w->color = false;
                x->parent->color = true;
                tree_rotate_right(x->parent);
                w = x->parent->left;
            }
            if(!w->right->color && !w->left->color)
            {
                w->color = true;
                x = x->parent;
            }
            else
            {
                if(!w->left->color)
                {
                    w->right->color = false;
                    w->color = true;
                    tree_rotate_left(w);
                    w = x->parent->left;
                }
                w->color = x->parent->color;
                x->parent->color = false;
                w->left->color = false;
                tree_rotate_right(x->parent);
                x = root;
            }
        }
    }

    x->color = false;
    return;
}

void tree_delete(node *z)
{
    node *x;
    node *y = z;
    bool y_original_color = y->color;

    if(z->left == nil)
    {
        x = z->right;
        tree_transplant(z, z->right);
    }
    else if(z->right == nil)
    {
        x = z->left;
        tree_transplant(z, z->left);
    }
    else
    {
        y = tree_minimum(z->right);
        y_original_color = y->color;
        x = y->right;

        if(y->parent == z)
        {
            x->parent = y;
        }
        else
        {
            tree_transplant(y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }

        tree_transplant(z, y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }

    if(!y_original_color)
        tree_delete_fixup(x);
    return;
}

void tree_destroy(node *x)
{
    if(x == nil)
    {
        delete x;
        return;
    }
    tree_destroy(x->left);
    tree_destroy(x->right);
    return;
}

void tree_deinitialize(void)
{
    tree_destroy(root);

    delete nil;
    delete root;
    return;
}


int main()
{
    tree_initialize();
    tree_insert(create_node(1, 1));
    tree_deinitialize();
    return 0;
}

