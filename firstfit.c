# include <stdio.h>
int p[10],b[10],allocation[10],m,n,i,j;
void read()
{
    printf("Enter number of processes");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter size of process %d ",i);
        scanf("%d",&p[i]);
    }

    printf("Enter number of blocks");
    scanf("%d",&m);
    for(i=0;i<m;i++)
    {
       printf("Enter size of block %d ",i);
        scanf("%d",&b[i]);
    }

}
void first()
{
    for(i=0;i<n;i++)
    {
        allocation[i]=-1;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(p[i]<=b[j])
            {

                allocation[i]=j;
                b[j]=b[j]-p[i];
                break;
            }
        }
    }
}

void display()
{
    printf("\n process\t block allocated \n");
    for(i=0;i<n;i++)
    {
        if(allocation[i]!=-1)
            printf("%d\t\t%d\n",p[i],allocation[i]);
        else
            printf("%d \t Not allocated",p[i]);
    }
}

int main()
{
    read();
    first();
    display();
    return 0;
}
