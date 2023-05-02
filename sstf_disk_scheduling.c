# include <stdio.h>
# include <stdlib.h>
# include <math.h>
int r[10],i,j,count=0,min,ind,diff,movement,n,head;

int main ()
{
    printf("Enter number of requests ");
    scanf("%d",&n);

    printf("Enter head ");
    scanf("%d",&head);

    for(i=0;i<n;i++)
    {
        printf("Enter size of request %d",(i+1));
        scanf("%d",&r[i]);
    }

    while(count!=n)
    {
        min=1000;
        for(i=0;i<n;i++)
        {
            diff=abs(r[i]-head);
            if(diff<min)
            {
                min=diff;
                ind=i;
            }
        }
        movement=movement+min;
        head=r[ind];
        r[ind]=1000;
        count++;
    }

    printf("\nTotal head movement is %d ",movement);
}
