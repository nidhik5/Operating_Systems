# include<stdio.h>
#include<limits.h>
int page[50],frames[10],p,f,numfaults=0,h=0,m=0;

void read()
{
    printf("Enter number of frames ");
    scanf("%d",&f);

    printf("Enter number of pages ");
    scanf("%d",&p);
    for(int i=0;i<p;i++)
    {
        printf("Enter size of page %d",(i+1));
        scanf("%d",&page[i]);
    }
}

int inmemeory(int pg)
{
    int flag;

        for(int j=0;j<f;j++)
        {
            if(frames[j]==pg)
                return 0;
        }
        return 1;

}

void optimal()
{
    for(int i=0;i<f;i++)
    {
        frames[i]=-1;
    }

    for(int i=0;i<p;i++)
    {
        if(inmemeory(page[i]))
        { m++;
        int maxdistance=INT_MIN;
        int replaceindex=-1;
        for(int j=0;j<f;j++)
        {
            int pagefound=0;
            for(int k=i+1;k<p;k++)
            {
                if(page[k]==frames[j])
                {

                    pagefound=1;
                    if(k>maxdistance)
                    {
                        maxdistance=k;
                        replaceindex=j;
                    }
                    break;
                }
            }
            if(pagefound==0)
            {
                replaceindex=j;
                break;
            }
        }
        frames[replaceindex] = page[i];
            numfaults++;
            printf("Page %d frames :",page[i]);
            for(int j=0;j<f;j++)
            {
                printf("%d\t",frames[j]);
            }
            printf("\n");
    }
    else
        {
            printf("Page %d frames :",page[i]);
            for(int j=0;j<f;j++)
            {
                printf("%d\t",frames[j]);
            }
            printf("\n");
            h++;
        }
}
}

int main ()
{
    read();
    optimal();

    printf("\n number of hits %d",h);
    printf("\n number of miss %d",m);
    printf("\n hit ratio is %f",(float)h/p);
    printf("\n miss ratio is %f",(float)m/p);
    return 0;
}
