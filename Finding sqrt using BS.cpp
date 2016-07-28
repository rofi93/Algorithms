#include <bits/stdc++.h>
#define  eps  1e-9
using namespace std;
int main()
{
    double mid,high,low,n;
    while(cin>>n)
    {
        if(n<=1 || n==4)
        {
            if(n<0)
                printf("Can't find out the Square root of %.4lf\n",n);
            else if(n<=1)
                printf("Square root of %.4lf is %.4lf\n",n,n);
            if(n==4)
                printf("Square root of %.4lf is %.4lf\n",n,n/2);

            continue;
        }
        high=n;
        low=0;
        mid=(high+low)/2;
       /* printf("High         Low        Mid       Number\n");
        printf("--------   --------   --------    --------\n"); */
        while((high-low)>eps)
        {
            if(mid*mid==n)
            {
              //  printf("%lf   %lf   %lf    %lf\n",high,low,mid,n);
                break;
            }
            else if(mid*mid>n)
            {
             //  printf("%lf   %lf   %lf    %lf\n",high,low,mid,n);
                high=mid;
            }
            else if(mid*mid<n)
            {
              //  printf("%lf   %lf   %lf    %lf\n",high,low,mid,n);
                low=mid;
            }
            mid=(high+low)/2;
        }
        printf("Square root of %.4lf is %.4lf\n",n,mid);
    }
    return 0;
}
