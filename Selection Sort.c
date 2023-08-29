//selection sort
#include <stdio.h>
int main()
{
    int a[10],i,j,l,temp;
    printf("enter the no.of elements:");
    scanf("%d",&l);
    printf("\n");
    for(i=0;i<l;i++)
    {
        printf("enter the element a[%d]:",i);
        scanf("%d",&a[i]);
    }
    printf("\nafter sorting\n");
    for(i=0;i<l;i++)
    {
        for(j=i+1;j<l;j++)
        {
            if(a[i]>a[j])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
        printf("%d ",a[i]);
    }
    return 0;
}
