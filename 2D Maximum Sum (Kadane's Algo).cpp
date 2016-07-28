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
const long long int mx=1e2;
const long long int mod=1e9+7;
/* global declaration */

int arr[mx+5][mx+5];
int n,m,start,finish;
int temp[mx+5];

int kadane(void)
{
    int i,sum,max_sum;
    sum=max_sum=0;
    start=finish=-1;
    for(i=0; i<n; i++)
    {
        sum+=temp[i];
        if(sum<0)
        {
            sum=0;
            start=i+1;
        }
        if(sum>max_sum)
        {
            max_sum=sum;
            finish=i;
        }
    }
    if(finish==-1)
    {
        max_sum=INT_MIN;
        for(i=0; i<n; i++)
        {
            if(temp[i]>max_sum)
            {
                max_sum=temp[i];
                start=finish=i;
            }
        }
    }
    return max_sum;
}

int main()
{
    int i,j,k,sum,max_sum,left,right,top,bottom;
    while(cin>>n>>m)
    {
        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++) scanf("%d",&arr[i][j]);
        }
        sum=max_sum=INT_MIN;
        left=right=top=bottom=-1;
        for(i=0; i<m; i++)
        {
            setzero(temp);
            for(j=i; j<m; j++)
            {
                for(k=0; k<n; k++) temp[k]+=arr[k][j];
                sum=kadane();
                if(sum>max_sum)
                {
                    left=i;
                    right=j;
                    top=start;
                    bottom=finish;
                    max_sum=sum;
                }
            }
        }
        printf("Maximum Sum: %d\n",max_sum);
        printf("Top = %d, Left = %d, Bottom = %d, Right = %d\n",top,left,bottom,right);
    }
    return 0;
}
