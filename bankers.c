struct process{
    int alloc[10];
    int max[10];
    int flag;
    int need[10];
}p[10];
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n=0,r=0,i=0,res[10],j=0,avail[i],req[10],num=0,k=0,b=0,g=0,safeseq[10],flag=0,cnt=0,count=0,work[10];
    printf("Enter the number of resources(max=10): ");
    scanf("%d", &r);

    printf("Enter the number of processes(max=10): ");
    scanf("%d", &n);
   
    printf("Enter the following details\n");
    //reading allocation details
    printf("Enter the allocation details\n");
    for(i=0;i<n;i++)
    {   printf("P%d\n",i);
        for(j=0;j<r;j++)
        {
            printf("allocation for r%d: ", j+1);
            scanf("%d", &p[i].alloc[j]);
        }
        p[i].flag=0;
    }
    //reading max details
    printf("Enter the max details\n");
    for(i=0;i<n;i++)
    {   printf("P%d\n",i);
        for(j=0;j<r;j++)
        {
            printf("max for r%d: ", j+1);
            scanf("%d", &p[i].max[j]);
        }
    }

    //calculating need matrix
    for(i=0;i<n;i++)
    {
        for(j=0;j<r;j++)
        {
            if(p[i].alloc>p[i].max)
                p[i].need[j]=0;
            else
                p[i].need[j]=p[i].max[j]-p[i].alloc[j];
        }
        printf("\n");
    }


  /*  //printing allocation matrix
    printf("Allocation matrix\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<r;j++)
        {
            printf("%d  ",p[i].alloc[j]);
        }
        printf("\n");
    }

    //printing max matrix
    printf("Max matrix\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<r;j++)
        {
            printf("%d  ",p[i].max[j] );
        }
        printf("\n");
    }

   //printing need matrix
    printf("Need matrix\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<r;j++)
        {
            printf("%d  ",p[i].need[j] );
        }
        printf("\n");
    }


*/






   for(i=0;i<r;i++)
    {
        printf("Enter available resources for r%d: ",i+1);
        scanf("%d",&avail[i]);
    }
/*
    printf("if a new request has come\n");
    printf("Enter the process number\n");
    scanf("%d", &num); 
    printf("Enter the request for resources\n");
    for(i=0;i<r;i++)
    {
        printf("for r%d: ",i+1);
        scanf("%d", &req[i]);
    }



    for(i=0;i<r;i++)
    {
        if(req[num]<=p[num].need[i])
            cnt++;
    }
    
    if (cnt==r)
    {
        cnt=0;
        for(i=0;i<r;i++)
        {
            if(req[num]<=p[num].alloc[i])
                cnt++;
        }
    }
    if(cnt==r)
    {
        for(i=0;i<r;i++)
        {
            avail[i]=avail[i]-req[i];
            p[num].alloc[i]= p[num].alloc[i]+req[i];
            p[num].need[i]=p[num].need[i]-req[i];
        }
    }




*/




 //printing allocation matrix
    printf("Allocation matrix\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<r;j++)
        {
            printf("%d  ",p[i].alloc[j]);
        }
        printf("\n");
    }

    //printing max matrix
    printf("Max matrix\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<r;j++)
        {
            printf("%d  ",p[i].max[j] );
        }
        printf("\n");
    }

   //printing need matrix
    printf("Need matrix\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<r;j++)
        {
            printf("%d  ",p[i].need[j] );
        }
        printf("\n");
    }












     printf("\n Request is coming from which process number: ");
     scanf("%d",&num);
     printf("\n enter the reqested details for all resources: ");
     for(i=0;i<r;i++)
      scanf("%d",&req[i]);
     for(j=0;j<r;j++)
     {
       if(req[j]<=p[num].need[j])  

       {
          if(req[j]<=avail[j])
           {
            avail[j]=avail[j]-req[j];
            p[num].alloc[j]=p[num].alloc[j]+req[j];
            p[num].need[j]=p[num].need[j]-req[j];
            //printf("avail:%d",avail[j]);      

           }
      // printf("\tneed: %d\n",p[num].need[j]);
       }
       else
       {
        printf("\n Process is not in safe state and hence request cannot be granted");
        exit(0);
       }
      }
      printf("\nrequest can be granted");

















       int sseq[10],ss=0,chk=0,chki=0;
     for(j=0;j<r;j++)
       work[j]=avail[j];//initialise work=available
     for(i=0;i<n;i++)
       p[i].flag=0;//initialise finish[i]=false for i=0,1,2...
     while(count!=n)
     {
     for(i=0;i<n;i++)

           {    

             chk=0;
             for(j=0;j<r;j++)
             {
              if(p[i].flag==0)
              {
               if(p[i].need[j]<=work[j])
               chk++;
              }
              if(chk==r)
              {
               for(j=0;j<r;j++)
               {
                work[j]=work[j]+p[i].alloc[j];
                p[i].flag=1;
               }
              sseq[ss]=i;
              ss++;
              count++;
              }
             }
            }
     }
    for(i=0;i<n;i++)
     {
      if(p[i].flag==1)
      chki++;
     }
     if(chki>=n)
     {
      printf("\n System is in safe state: ");
      for(i=0;i<n;i++)
      printf("%d ",sseq[i]);
     }
     else
     printf("\nsystem is not safe");








    return 0;
}