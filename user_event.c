#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<windows.h>
#include<time.h>
#include<stdbool.h>
#include<conio.h>

int user_event()
{
    int userDay,userMonth,day,month;
    system("cls");
    system("color 0B");
    printf("Do you want to know the important dates?\n");
    while(1)
    {
    printf("Enter the month:(1-January.......12-December): ");
    scanf("%d",&userMonth);
    printf("Enter the date:");
    scanf("%d",&userDay);
        if(userMonth<1 || userMonth>12 || userDay<1 || userDay>31)
        {
            printf("\n\n\t\t\t\tInvalid inputs\n\n");
            continue;
        }
        else
        {
            break;
        }
    }
    int LSIZ=128;
    int RSIZ=100;
    char line[RSIZ][LSIZ];
    FILE *fptr = NULL;
    int i=0,j,k ;
    int tot = 0;

    fptr = fopen("C:\\Users\\shine\\Documents\\specialevents.txt", "r");
    while(fgets(line[i], LSIZ, fptr))
    {
        line[i][strlen(line[i]) - 1] = '\0';
        i++;
    }
    tot = i;
    printf("\n\n\n\n\t\t\t************************\n");
    for(i=0;i<tot;i++)
    {
        for(j=0;j<128;j++)
        {
            day=(((line[i][0])-'0')*10)+((line[i][1])-'0');
            month=(((line[i][3])-'0')*10)+((line[i][4])-'0');


            if(day==userDay&&month==userMonth)
            {
                printf("\t\t\t%s\n",line[i]);
                break;
            }
        }
    }
    printf("\t\t\t**************************");
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
