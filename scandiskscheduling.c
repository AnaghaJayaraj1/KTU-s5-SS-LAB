#include<stdio.h>
#include <stdlib.h>
int main()
{
    int tnum,t[20],i,head,sum=0,seq[20],temp,j,k,m,headpos,left_close;
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
 
    printf("Enter the starting: ");
    scanf("%d",&t[tnum+1]);
    printf("Enter the ending: ");
    scanf("%d", &t[tnum+2]);

    for(i=0;i<=tnum+2;i++)
    {
        for(j=i+1;j<=tnum+2;j++)
        {
            if(t[i]>t[j])
            {
                temp = t[i];
                t[i] = t[j];
                t[j] = temp;
            }
        }
    }

    for(i=0;i<tnum+2;i++)
    {
        if(t[i]==head)
        {
            headpos=i;
        }
    }
    left_close = abs(head-t[0]);
    printf("Sequence: ");
    if(left_close<abs(head-t[tnum+2]))
    {
         k=headpos;
            m=headpos+1;
        for(i=0;i<=tnum+1;i++)
        {
            if(k<=headpos&&k>=0)
            {
                seq[i]=t[k];
                k--;
            }
            else if(m>headpos&&m<tnum+2)
            {
                seq[i]=t[m];
                m++;
            }
        }
    }
    else
    {
        k=headpos-1;
        m=headpos;
        for(i=0;i<=tnum+1;i++)
        {
            if(m>=headpos&&m<=tnum+2)
            {
                seq[i]=t[m];
                m++;
            }
            else if(k<headpos&&k>0)
            {
                seq[i]=t[k];
                k--;
            }
        }
    }

    
    sum=0;
    for(i=0;i<=tnum+1;i++)
    {
        printf("%d ", seq[i]);
    }
     for(i=0;i<tnum+1;i++)
    {
        sum=sum+abs(seq[i+1]-seq[i]);
    }
    printf("\nTotal track movement: %d \n",sum);


    return 0;
}