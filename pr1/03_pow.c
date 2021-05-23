#include <stdio.h>
#include <math.h>

int main()
{
    double x, y, s=0;
    int a=0;
    a = scanf("%lf%lf", &x,&y);
    s = pow(x,y);
    printf("%lf", s);
    return a;
}
