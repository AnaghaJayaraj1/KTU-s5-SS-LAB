#include<stdio.h>
#include <stdlib.h>
int main()
{
    int tnum,t[20],i,head,sum=0;
    printf("Enter the number of tracks: ");
    scanf("%d",&tnum);
    printf("Enter the tracks: ");
    for(i=1;i<=tnum;i++)
    {
        scanf("%d",&t[i]);
    }
    printf("Enter the head: ");
    scanf("%d",&head);
    t[0]=head;
    printf("Sequence: ");
    for(i=0;i<=tnum;i++)
    {
        printf("%d ",t[i]);
    }
    for(i=0;i<tnum;i++)
    {
        sum=sum+abs(t[i+1]-t[i]);
    }
    printf("\nTotal track movement: %d\n ",sum);


    return 0;
}