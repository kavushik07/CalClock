#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<windows.h>
#include<time.h>
#include<stdbool.h>
#include<conio.h>

int special_event()
{
    int LSIZ=128;
    int RSIZ=100;
    int day,month,curDay,curMonth;
    time_t rawtime;
    struct tm * timeinfo;
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    curDay=timeinfo->tm_mday;
    curMonth=timeinfo->tm_mon+1;
    system("cls");
    system("color 04");
    printf("Current day:%d\nCurrent Month:%d\n",curDay,curMonth);
    char line[RSIZ][LSIZ];
    FILE *fptr = NULL;
    int i,j,k ;
    int tot = 0;

    fptr = fopen("C:\\Users\\shine\\Documents\\specialevents.txt", "r");
    while(fgets(line[i], LSIZ, fptr))
    {
        line[i][strlen(line[i]) - 1] = '\0';
        i++;
    }
    tot = i;
    printf("\n\n\n\t\t\t\t Special event:");
    printf("\n\n\n\n\t\t\t\t\t\t***************************\n");
    for(i=0;i<tot;i++)
    {
        for(j=0;j<128;j++)
        {
            day=(((line[i][0])-'0')*10)+((line[i][1])-'0');
            month=(((line[i][3])-'0')*10)+((line[i][4])-'0');


            if(day==curDay&&month==curMonth)
            {
                printf("\t\t\t\t\t\t\t%s\n",line[i]);
                break;
            }

        }

    }
    printf("\t\t\t\t\t\t\**************************");
    char ans;
    printf("\n\nDo you want to go to the Menu bar:");
    printf("\n\t\tPress Y -> Yes ");
    printf("\n\t\tPress N -> No");
    ans=getch();
    if(ans=='y' || ans=='Y')
        {
            getchar();
            main();
        }
    else if(ans=='n' || ans=='N')
        {
            exit(0);
        }
}
