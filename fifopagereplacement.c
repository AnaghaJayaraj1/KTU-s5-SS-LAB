#include<stdio.h>
int main()
{
    int fno=0,pno=0,i=0,pagestr[30],frame[10], next=0, j=0, pfault=0,k=0,flag=0;
    printf("Enter the number of frames: ");
    scanf("%d", &fno);
    printf("Enter the number of pages: ");
    scanf("%d", &pno);
    printf("Enter the reference string");
    for(i=0;i<pno;i++)
    {
        scanf("%d", &pagestr[i]);
    }
    for(i=0;i<fno;i++)
    {
        frame[i]=-1;
    }


    printf("Frame now: ");
    for(k=0;k<fno;k++)
    {
        printf("%d  ",frame[k]);
    }
    for(i=0;i<pno;i++)
    {
        flag=0;
        for(j=0;j<fno;j++)
        {
            int ps=pagestr[i];
            if(ps==frame[j])
            {
                flag++;
                break;
            }
        }
        if(flag==0)
        {
            frame[next%fno]=pagestr[i];
            next++;
            pfault++; 
        }
        printf("\nFrame now: ");
        for(k=0;k<fno;k++)
        {
            printf("%d  ",frame[k]);
        }
              
    }
    printf("\nNumber of page faults: %d ", pfault);
    return 0;
}