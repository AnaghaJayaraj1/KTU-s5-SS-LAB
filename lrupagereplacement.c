#include<stdio.h>
 
int main()
{
      int frames[10], temp[10], pages[30];
      int npages, i, n, position, k, l, nframes;
      int  flag , page_fault = 0;
      printf("\nEnter Total Number of Frames:\t");
      scanf("%d", &nframes);
      for(i = 0; i < nframes; i++)
      {
            frames[i] = -1;
      }
      printf("Enter Total Number of Pages:\t");
      scanf("%d", &npages);
      printf("Enter Values for Reference String:\n");
      for(i = 0; i < npages; i++)
      {
            scanf("%d", &pages[i]);
      }
      for(n = 0; n < npages; n++)
      {
            flag = 0;
            for(i = 0; i < nframes; i++)
            {
                  if(frames[i] == pages[n])
                  {
                        flag = 1;
                        break;
                  }
		  else
		      if(frames[i] == -1)
                        {
                              frames[i] = pages[n];
                              page_fault++;
                              flag = 1;
                              break;
                        }
            }
            if(flag == 0)
            {
                  for(i = 0; i < nframes; i++)
                  {
                        temp[i] = 0;
                  }
                  for(k = n - 1, l = 1; l < nframes;l++, k--)
                  {
                        for(i = 0; i < nframes; i++)
                        {
                              if(frames[i] == pages[k])
                              {
                                    temp[i] = 1;
                                    break;
                              }
                        }
                  }
                  for(i = 0; i < nframes; i++)
                  {
                        if(temp[i] == 0)
     			    {
                            frames[i]=pages[n];
                            page_fault++;
                            break;
                           }
                            
                  }
            }
            printf("\n");
            for(i = 0; i < nframes; i++)
            {
                  printf("%d\t", frames[i]);
            }
      }
      printf("\nTotal Number of Page Faults:\t%d\n", page_fault);
      return 0;
}