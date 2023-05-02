# include <stdio.h>
# include <math.h>
# include <stdlib.h>

int r[10],n,current,movement=0;

int main()
{
    printf("Enter Number of requests ");
    scanf("%d",&n);

    for(int i=0; i<n ; i++)
    {
        printf("Enter request %d",(i+1));
        scanf("%d",&r[i]);
    }

    printf("Enter current position ");
    scanf("%d",&current);

    movement=movement+(abs(current-r[0]));
    printf("\n%d ---> %d : %d",current,r[0],movement);

    for(int i=1;i<n;i++)
    {
        movement=movement+(abs(r[i]-r[i-1]));
        printf("\n%d ---> %d : %d",r[i-1],r[i],movement);
    }

    printf("\nTotal head movement is %d",movement);
    return 0;
}
