# include <stdio.h>
int p[10],b[10],allocation[10],min,ind,m,n,i,j;
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
void best ()
{
    for(i=0;i<n;i++)
    {
        allocation[i]=-1;
    }
    for(i=0;i<n;i++)
    {
        min=9999;
        ind=-1;
        for(j=0;j<m;j++)
        {
            if(p[i]<=b[j])
            {
                if(b[j]<min)
                {
                    min=b[j];
                    ind=j;
                }
            }
        }
        b[ind]=b[ind]-p[i];
        allocation[i]=ind;
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
    best();
    display();
    return 0;
}
