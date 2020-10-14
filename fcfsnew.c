#include <stdio.h>
#include<string.h>
struct process{
    char pname[50];
    int at,bt,wt,tt,status;
}p[30];
struct gantt{
    char pname[50];
    int st,ct;
}g[30];

int main()
{
    int n,i,j,k,temp,idle,count;
    float avgwt=0.0,avgtt=0.0;
    char tempname[30];
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    for(i=0;i<n;i++)
    {
        printf("Enter the process name: ");
        scanf("%s",&p[i].pname);
        printf("Enter arrival time: ");
        scanf("%d",&p[i].at);
        printf("Enter the burst time: ");
        scanf("%d",&p[i].bt);
        p[i].status=0;
    }
	count=n;
    for (i = 0; i < n; ++i)
    {
        for (j = i + 1; j < n; ++j)
        {
            if (p[i].at > p[j].at)
            {
                temp =  p[i].at;
                p[i].at = p[j].at;
                p[j].at = temp;
               
                temp =  p[i].bt;
                p[i].bt = p[j].bt;
                p[j].bt = temp;
               
                strcpy(tempname,p[i].pname);
                strcpy(p[i].pname,p[j].pname);
                strcpy(p[j].pname, tempname);
           
            }
        }
    }
   

     for(i=0,j=0,k=-1;j<n;)
    {
        if((p[j].at<=i)&&(p[j].status==0))
        {   k++; 
	        idle=0;
            strcpy(g[k].pname,p[j].pname);
            g[k].st=i;
            g[k].ct=i+p[j].bt;
            p[j].tt = g[k].ct-p[j].at;
            p[j].wt=p[j].tt-p[j].bt;
            p[j].status=1;
            i=g[k].ct;
            j++;
               
        }
	else
	{
		if(idle==0)
		{	k++;
			strcpy(g[k].pname,"idle");
			g[k].st=i;
			i++; idle=1;
			count++;g[k].ct=i;

		}
		else
		{
			g[k].ct=i+1;
			//k++;
			i++;
			
			
		}
	}	
    }

    printf("\n\nGantt Chart \n");
    for(i=0;i<count;i++)
    {
        printf("|   %s   ", g[i].pname);
    }
    printf("|\n");
    printf("%d      ", g[0].st);
    for(i=0;i<count-1;i++)
    {
 	printf("%d          ", g[i].ct);
    }
    printf("\n\n");
	

    
    printf("Pname|Arrival time|Burst time|Turnaround time|Waiting time \n  ");
    for(i=0;i<n;i++)
    {
        printf("%s    ", p[i].pname);
        printf("%d            ", p[i].at);
        printf("%d          ", p[i].bt);
        printf("%d               ", p[i].tt);
        printf("%d \n  ", p[i].wt);
	avgtt=avgtt+p[i].tt;
	avgwt=avgwt+p[i].wt;
	
    }
   
    printf("\nAverage turnaround time: %f \n", avgtt/n);
    printf("Average waiting time: %f\n\n ", avgwt/n);

   


    return 0;
}

