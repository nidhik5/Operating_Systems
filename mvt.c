# include <stdio.h>
int p[10],n,i,total;
int main ()
{
    printf("Enter number of pages");
    scanf("%d",&n);
    printf("Enter size of memeory");
    scanf("%d",&total);

    for(i=0;i<n;i++)
    {
        printf("Enter size of page %d ",(i));
        scanf("%d",&p[i]);
    }

    for(i=0;i<n;i++)
    {
        if(total>p[i])
        {
            printf("Memory allocated to %d process is %d\n",i,p[i]);
            total=total-p[i];
            printf("Memory present after allocation %d\n",total);
        }

    }

    printf("External fragmentation is %d",total);
}
