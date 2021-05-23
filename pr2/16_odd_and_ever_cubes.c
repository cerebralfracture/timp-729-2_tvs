#include <stdio.h>
#include <math.h>
int main() 
{
    int n=0,m=0,w=0;
    double x=0,r=0,sum=0;
    (void)scanf("%d", &n);
    for(m=1; m<=n; m++)
    {
        x=(double)m+1;
        r=pow(-1,x);
        (void)scanf("%d", &w);
        sum+=r*(w*w*w);
    }
    printf("%lf", sum);
    return 0;
}
