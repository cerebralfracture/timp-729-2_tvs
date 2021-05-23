#include <stdio.h>

int main()
{
int n=0,i=0,z=0,w=0;
(void)scanf("%d", &n);
for (i = 0; i < n; i++)
{
(void)scanf("%d", &w);
if(w>0)
{
    z++;
}
}
printf("%d\n", z);
return 0;
}
