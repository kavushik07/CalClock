#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<windows.h>
#include<time.h>
#include<stdbool.h>
#include<conio.h>

int clock_1()
{
    int hrs,min,sec,r;
    currentTime(&hrs,&min,&sec);
    alarm(hrs,min,sec);
    return 1;
}

void currentTime(int *hour,int *min,int *second)
{
    time_t rawtime; //The time_t datatype is a data type in the ISO C library defined for storing system time values. Such values are returned from the standard time().
    struct tm * timeinfo;//consists of calendar date and time which are broken down into components of hrs,mins,secs,day,month...
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    *hour=timeinfo->tm_hour;
    *min=timeinfo->tm_min;
    *second=timeinfo->tm_sec;
    system("cls");
    system("color 03");
    printf("\n\t\t\t\tCurrent time");
    printf("\n\n\t\t\t\t===================\n");
    printf("\t\t\t\t\t%d:%d:%d\n",*hour,*min,*second);
    printf("\t\t\t\t====================\n");

    int almHr,almMin,almSec=0;
    char label[100];
    int i,j;
    printf("Enter the alarm time:(in 24-hour format)\n");
    printf("Hours: ");
    scanf("%d",&almHr);
    printf("Minutes: ");
    scanf("%d",&almMin);
    getchar();
    printf("Label for alarm:");
    scanf("%[^\n]s",label);

    while(1)
    {
        time ( &rawtime );
        timeinfo = localtime ( &rawtime );
        *hour=timeinfo->tm_hour;
        *min=timeinfo->tm_min;
        *second=timeinfo->tm_sec;
        if(*hour==almHr && *min==almMin)
        {
            system("cls");
            printf("\n\n\n\n\n\n\n\n\t\t\t\t======================================================================");
            printf("\n\n\n\n\n\t\t\t\t\t\t\t\t%s",label);
            printf("\n\n\n\n\t\t\t\t=====================================================================\n");
            Beep(523,8000);
            break;
        }

        else
        {
            system("cls");
            printf("\n\n\n\n\n\n\n\n\t\t\t\t======================================================================");
            printf("\n\n\n\n\n\t\t\t\t\t\t\t\t%d:%d:%d\n",*hour,*min,*second);
            printf("\n\n\n\n\t\t\t\t=====================================================================\n");
            sleep(1);
            system("cls");
            continue;
            Sleep((60-*second)*1000);
        }
        //printf("\t\t\t\t\t%d:%d:%d\n",*hour,*min,*second);
    }
        //Check the equality
        //if equal
        //ring and break

        //if not equal
        //Sleep((60-second)*1000);multiplie by 1000 because sleep accepts in milliseconds
        //continue;



    char ans;
    getchar();
    printf("\n\n\n\t\tDo you want to go to the Menu bar:\n\tPress Y -> Yes\n\tPress N -> No:");
    scanf("%c",&ans);
    if(ans=='y'|| ans=='Y')
    {
        getchar();
        main();
    }
    else if(ans=='n' || ans=='N')
    {
        exit(0);
    }
}

