#include <stdio.h>
int fact()

{
    int a;
    int fact=1;
    int i;
    printf("enter the number:",&a);
    scanf("%d",&a);
    for(i=1;i<=a;i++)
    {
        fact=fact*i;
    }
    return fact;
}
int main()
{
    int ans=fact();
    printf("the factorial is %d",ans);
    return 0;
}
