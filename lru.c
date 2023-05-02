# include <stdio.h>
# include <limits.h>
int p[10],f[5],i,j,k,m,n,h=0,miss=0,min,ind,pagefound;

void read()
{
    printf("Enter number of pages");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("Enter size of page %d ",(i+1));
        scanf("%d",&p[i]);
    }

    printf("Enter number of frames");
    scanf("%d",&m);
}

int inmemory(int x)
{
    for(i=0;i<m;i++)
    {
        if(x==f[i])
            return 0;
    }
    return 1;
}

void lru ()
{
    for(i=0;i<m;i++)
    {
        f[i]=0;
    }
    for(i=0;i<n;i++)
    {
        if(inmemory(p[i])==1)
        {
            miss++;
            min=INT_MAX;
            ind=-1;
            for(j=0;j<m;j++)
            {
                pagefound=0;
                for(k=i;k>=0;k--)
                {
                    if(p[k]==f[j])
                    {
                        pagefound=1;
                        if(k<min)
                        {
                            min=k;
                            ind=j;
                        }
                        break;
                    }

                }
                if(pagefound==0)
                {
                    ind=j;
                    break;
                }

            }
            f[ind]=p[i];
            printf("page %d : ",p[i]);
            for(int l=0;l<m;l++)
                {
                printf("%d\t",f[l]);
            }
            printf("\n");
        }
        else
        {
            printf("Page %d frames :",p[i]);
            for(int l=0;l<m;l++)
            {
                printf("%d\t",f[l]);
            }
            printf("\n");
            h++;
        }

    }
}

int main ()
{
    read();
    lru();
    printf("\nHits is %d ",(h));
    printf("\nmiss is %d ",(miss));
    return 0;

}
