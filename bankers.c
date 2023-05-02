# include <stdio.h>
int r,p,resource[5],need[10][5],allocated[10][5],maximum[10][5],i,j,l,finish[10],safesequence[10],safecount=0,k;
int main()
{
    printf("Enter number of resources ");
    scanf("%d",&r);

    for(i=0;i<r;i++)
    {
        printf("Enter size of resource %d ",(i+1));
        scanf("%d",&resource[i]);
    }

    printf("Enter number of process ");
    scanf("%d",&p);

    printf("Enter maximum need of processes\n");

    for(i=0;i<p;i++)
    {
        for(j=0;j<r;j++)
        {
            printf("Enter maximum need of process %d and resource %d ",(i+1),(j+1));
            scanf("%d",&maximum[i][j]);
        }
    }

    printf("Enter allocated resources to processes\n");
    for(i=0;i<p;i++)
    {
        for(j=0;j<r;j++)
        {
            printf("Enter allocation process %d and resource %d ",(i+1),(j+1));
            scanf("%d",&allocated[i][j]);

            need[i][j]=maximum[i][j]-allocated[i][j];
        }
    }

    for(i=0;i<p;i++)
    {
        finish[i]=0;
    }

for(k=0;k<p;k++)
        {for(i=0;i<p;i++)
    {
        if(finish[i]==0);
       {
        for(j=0;j<r;j++)
        {
            if(need[i][j]>resource[j])
            break;
        }
        if(j==r)
            {
                for(l=0;l<r;l++)
                    resource[l]+=allocated[i][l];
                    finish[i]=1;
                    safesequence[safecount++]=i+1;
            }
        }
    }
}

    for(i=0;i<p;i++)
    {
        if(finish[i]==0)
            printf("%d process in unsafe state",i);
    }

    printf("\nSafe sequence is : ");
    for(i=0;i<p;i++)
    {
        printf("%d\t",safesequence[i]);
    }

    return 0;
}
