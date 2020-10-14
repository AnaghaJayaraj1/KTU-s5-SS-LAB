#include <stdio.h>
#include<string.h>
struct process{
    char pname[50];
    int pr,at,bt,wt,tt,status;
}p[30];
struct gantt{
    char pname[50];
    int st,ct;
}g[30];


int main()
{
    int n,m=0,i=0,j=0,k=0,idle=0,count=0,found=0,flag=0,np=0;
    float avgwt=0.0,avgtt=0.0;
    int loop;
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
        printf("Enter priority: ");
        scanf("%d",&p[i].pr);
        p[i].status=0;
    }
    loop=n;
    for(i=0,np=0;np<n+count;np++)
    {
        
        found=0;
        flag=0;
        for(j=0;j<n;j++)
        {
            if ((p[j].at<=i) && (p[j].status==0) && (found==0))
            {
                
                found++;
                flag++;
                k=j; 
                
            }
            else if((p[j].at<=i)&&(p[j].status==0)&&(found>0))
            {
                if(p[j].pr<p[k].pr)
                {
                    k=j;
                }
                else if (p[j].pr==p[k].pr)
                {
                    if (p[j].at<p[k].at)
                    {
                        k=j;
                    }
                }
            }
            /*else
            {
                i++;
            }*/
        }
        if(flag>0)
        {
            if (idle==1)
            {
                g[m].ct=i;
                m++;
            }
            strcpy(g[m].pname,p[k].pname); 
            g[m].st=i;
            g[m].ct=i+p[k].bt;
            p[k].tt = g[m].ct-p[k].at;
            p[k].wt=p[k].tt-p[k].bt;
            p[k].status=1;
            i=g[m].ct;
            idle=0;
            //k++;
            m++;
        }
        else if(flag==0 && idle==0)
        {
                
                strcpy(g[m].pname,"idle");
                g[m].st=i;
                i++; idle=1;
                count++;g[m].ct=i;
                loop++;

        }
        else {
                //g[k].ct=i+1;
                //k++;
                i++; count++;
        }

    }

    printf("\n\nGantt Chart \n");
    for(i=0;i<loop;i++)
    {
        printf("|   %s   ", g[i].pname);
    }
    printf("|\n");
    printf("%d      ", g[0].st);
    for(i=0;i<loop;i++)
    {
 	printf("%d        ", g[i].ct);
    }
    printf("\n\n");
	

    
    printf("Pname|Arrival time|Burst time|Priority|Turnaround time|Waiting time\n  ");
    for(i=0;i<n;i++)
    {
        printf("%s    ", p[i].pname);
        printf("%d            ", p[i].at);
        printf("%d          ", p[i].bt);
        printf("%d          ", p[i].pr);
        printf("%d               ", p[i].tt);
        printf("%d \n  ", p[i].wt);
	avgtt=avgtt+p[i].tt;
	avgwt=avgwt+p[i].wt;
	
    }
   
    printf("\nAverage turnaround time: %f \n", avgtt/n);
    printf("Average waiting time: %f\n\n ", avgwt/n);

    return 0;
}
