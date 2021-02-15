#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void display()
{
    char ch;
    FILE *fp1, *fp2;
    printf("\n\nThe contents of DEFTAB :\n\n");
    fp1 = fopen("dtab2.txt", "r");
    ch = fgetc(fp1);
    while (ch != EOF){printf("%c", ch);
    ch = fgetc(fp1);
    }
    fclose(fp1);
    printf("\n\nThe contents of NAMTAB file :\n\n");
    fp2 = fopen("ntab2.txt", "r");
    ch = fgetc(fp2);
    while (ch != EOF){printf("%c", ch);
    ch = fgetc(fp2);
    }
    fclose(fp2);
}
void main()
{    FILE *f1,*f2,*f3;    
char mne[20],opnd[20],label[20];   

 f1=fopen("minp2.txt","r");  
   f2=fopen("ntab2.txt","w+"); 
      f3=fopen("dtab2.txt","w+");  
        fscanf(f1,"%s%s%s",label,mne,opnd);  
          while(strcmp(mne,"MEND")!=0)   
           { 
               if(strcmp(mne,"MACRO")==0)
                { fprintf(f2,"%s\n",label);
                  fprintf(f3,"%s\t%s\n",label,opnd);
                 } 
                else
                  fprintf(f3,"%s\t%s\n",mne,opnd); 
                fscanf(f1,"%s%s%s",label,mne,opnd);  
            }    
            fprintf(f3,"%s",mne);   
            fclose(f1);  
            fclose(f2);  
            fclose(f3);

            display();
            }