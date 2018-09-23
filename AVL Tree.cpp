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
    int height;
    node *left;
    node *right;
};

node* create_node(int key_)
{
    node *child = new node;

    child->key = key_;
    child->height = 1;
    child->left = NULL;
    child->right = NULL;

    return child;
}

int get_height(node *current_node)
{
    if(current_node == NULL)
        return 0;
    return current_node->height;
}

int get_balance(node *current_node)
{
    if(current_node == NULL)
        return 0;
    return get_height(current_node->left) - get_height(current_node->right);
}

node* left_rotate(node *x)
{
    node *y = x->right;
    node *t2 = y->left;

    y->left = x;
    x->right = t2;

    x->height = max(get_height(x->left), get_height(x->right)) + 1;
    y->height = max(get_height(y->left), get_height(y->right)) + 1;

    return y;
}

node* right_rotate(node *x)
{
    node *y = x->left;
    node *t2 = y->right;

    y->right = x;
    x->left = t2;

    x->height = max(get_height(x->left), get_height(x->right)) + 1;
    y->height = max(get_height(y->left), get_height(y->right)) + 1;

    return y;
}

node* left_left_case(node *current_node)
{
    return right_rotate(current_node);
}

node* right_right_case(node *current_node)
{
    return left_rotate(current_node);
}

node* left_right_case(node *current_node)
{
    current_node->left = left_rotate(current_node->left);
    return right_rotate(current_node);
}

node* right_left_case(node *current_node)
{
    current_node->right = right_rotate(current_node->right);
    return left_rotate(current_node);
}

void preorder_traverse(node *current_node)
{
    if(current_node == NULL)
        return;

    printf("%d ",current_node->key);
    preorder_traverse(current_node->left);
    preorder_traverse(current_node->right);
    return;
}

node* find_min(node *current_node)
{
    while(current_node->left != NULL)
        current_node = current_node->left;
    return current_node;
}

node* insert_node(node *current_node, int key_)
{
    if(current_node == NULL)
        return create_node(key_);

    if(key_ < current_node->key)
        current_node->left = insert_node(current_node->left, key_);
    else if(key_ > current_node->key)
        current_node->right = insert_node(current_node->right, key_);
    else
        return current_node;

    current_node->height = max(get_height(current_node->left), get_height(current_node->right)) + 1;

    int balance = get_balance(current_node);

    if(balance > 1 && key_ < current_node->left->key)
        return left_left_case(current_node);

    if(balance < -1 && key_ > current_node->right->key)
        return right_right_case(current_node);

    if(balance > 1 && key_ > current_node->left->key)
        return left_right_case(current_node);

    if(balance < -1 && key_ < current_node->right->key)
        return right_left_case(current_node);

    return current_node;
}

node* search_node(node *current_node, int item)
{
    while(current_node != NULL)
    {
        if(item > current_node->key)
            current_node = current_node->right;
        else if(item < current_node->key)
            current_node = current_node->left;
        else
            break;
    }
    return current_node;
}

node* delete_node(node *current_node, int key_)
{
    if(current_node == NULL)
        return current_node;

    if(key_ < current_node->key)
        current_node->left = delete_node(current_node->left, key_);
    else if(key_ > current_node->key)
        current_node->right = delete_node(current_node->right, key_);
    else
    {
        if(current_node->left == NULL || current_node->right == NULL)
        {
            node *temp = NULL;

            if(current_node->left != NULL)
                temp = current_node->left;
            else
                temp = current_node->right;

            if(temp == NULL)
            {
                temp = current_node;
                current_node = NULL;
            }
            else
            {
                current_node->key = temp->key;
                current_node->left = temp->left;
                current_node->right = temp->right;
                current_node->height = temp->height;
            }

            delete temp;
        }
        else
        {
            node *temp = find_min(current_node->right);

            current_node->key = temp->key;
            current_node->right = delete_node(current_node->right, temp->key);
        }
    }

    if(current_node == NULL)
        return current_node;

    current_node->height = max(get_height(current_node->left), get_height(current_node->right)) + 1;

    int balance = get_balance(current_node);

    if(balance > 1 && get_balance(current_node->left) >= 0)
        return left_left_case(current_node);

    if(balance < -1 && get_balance(current_node->right) <= 0)
        return right_right_case(current_node);

    if(balance > 1 && get_balance(current_node->left) < 0)
        return left_right_case(current_node);

    if(balance < -1 && get_balance(current_node->right) > 0)
        return right_left_case(current_node);

    return current_node;
}

void delete_tree(node *current_node)
{
    if(current_node == NULL)
    {
        delete current_node;
        return;
    }
    delete_tree(current_node->left);
    delete_tree(current_node->right);
    return;
}

int main()
{
    node *root = NULL;

    root = insert_node(root, 9);
    root = insert_node(root, 5);
    root = insert_node(root, 10);
    root = insert_node(root, 0);
    root = insert_node(root, 6);
    root = insert_node(root, 11);
    root = insert_node(root, -1);
    root = insert_node(root, 1);
    root = insert_node(root, 2);

    printf("Pre-order traverse: ");
    preorder_traverse(root);

    root = delete_node(root, 10);

    printf("\nPre-order traverse: ");
    preorder_traverse(root);
    delete_tree(root);
    return 0;
}
