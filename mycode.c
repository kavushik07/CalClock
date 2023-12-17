#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<windows.h>
#include <time.h>


int inputValdCal();
int calInputs(char);
int cal(int,int,int);
int zellersAlg(int,int);
void clock_1();
void currentTime();
void special_event();
int user_event();
int main()
{
    system("Color E4");
    char choice;
    int a,b,x;
    while(1)
    {
        printf("Enter your choice:\n");
        printf("\t\t\tC for Calendar\n");
        printf("\t\t\tL for Clock\n");
        printf("\t\t\tT to know today's special day\n");
        printf("\t\t\tS for special day\n");
        printf("\t\t\tE for exit\n");
        scanf("%c",&choice);
        if(choice=='C' || choice =='c')
        {
            a=calInputs(choice);

        }

        else if(choice=='L' || choice == 'l')
        {
            clock_1();

        }
        else if(choice=='s' || choice=='S')
        {
            x=user_event();

        }
        else if(choice=='T' || choice=='t')
        {
            special_event();
        }
        else if(choice=='e' || choice=='E')
        {
            exit(0);
        }
    }

}


int calInputs(char userChoice)
{
    int month,year;
    int firstDay;
    int a;
    int r,ans;
    system("Color B0");
    printf("\t\t\tCalendar:\n\n\n ");
    printf("Enter a year :");
    scanf("%d",&year);
    printf("Enter a month:\n 1-January\n 2-February\n 2-March\n 4-April\n 5-May\n 6-June\n 7-July\n 8-August\n 9-September\n 10-October\n 11-November\n 12-December\n Your choice of month:");
    scanf("%d",&month);
    a=inputValdCal(month,year);
    //printf("a=%d\n ",a);
    if(a==1)
    {
        firstDay=zellersAlg(month,year);
        //printf("\n%d\n",firstDay);
         r=cal(month,year,firstDay);
         if(r==1)
         {
         printf("\n\n\nPress 'M' to go to the menu bar:\n");
         scanf("%c",&ans);
         if(ans=='m' || ans=='M')
         {
            return 1;
         }

         }
    }
}

int inputValdCal(int month,int year)

{
    if(year<1)
    {
        printf("Invalid year\n");
    }

    else if(month<0||month>12)
    {
        printf("Invalid month\n");
    }

    else
    {
        return 1;
    }


}
//This function prints the calendar
int cal(int mon,int yr,int fD)
{
    /*int y=yr;
    int i,j;
    int first=fD;*/
    int i,j;
    char ans;
    printf("%d",5);
    char monName[12][15]={"January","February","March","April","May","June","July","August","September","October","November","December"};
    int monthDays[]={31,28,31,30,31,30,31,31,30,31,30,31};
    //  Leap year condition.
    if(yr%4==0&&yr%100==0||yr%400==0)
    {
        monthDays[1]=29;
    }
    system("cls");
    system("Color 57");
    printf("\n\n\n---------------------%s--------------------------------\n",monName[mon-1]);
    printf("Sun\tMon\tTue\tWed\tThurs\tFri\tSat\n");
    printf("-------------------------------------------------------------\n");
    system ("Color 5B");
    for(i=0;i<fD;i++)//To leave space before the days begin.
    {
        printf("\t");
    }

    for(j=1;j<=monthDays[mon-1];j++)//To enter the next line after date reaches saturday
    {
       if(i>6)
       {
           printf("\n");
           i=1;//It has to start again from beginning
       }
       else
       {
           i++;//Until it reaches 6
       }
       printf("%d\t",j);
    }
    return 1;
   /* printf("\n\n\nPress 'M' to go to the menu bar:\n");
    scanf("%c",&ans);
    if(ans=='m' || ans=='M')
    {
       return 1;
    }*/

}




/*This function is to find the first day of the particular month. We need to find the first day in order to leave gaps in the beginning
i.e. to match the days and dates correctly
 According to this algorithm, 0-Saturday, 6- Friday, but in our program 6-Saturday, other days will be minus 1.
 That is why there are some if conditions given below*/
int zellersAlg(int month,int yr)
{
    int d=1,y,c,firstDay,newFd;
    int mon;
    if(month>2)
    {
      mon=month;
    }
    else
    {
     mon=month+12;
     yr=yr-1;
    }


    /*y=last two digits of the year
    c=first two digits of the year
    d=day Always 1 because we need to find the day name of the first day*/


    y=yr%100;
    c=yr/100;
    int fD;
    firstDay=d+floor((13*(mon+1))/5)+y+floor(y/4)+floor(c/4)+(5*c);
    firstDay=firstDay%7;
    //printf("%d\n",firstDay);
    if(firstDay==0)
    {
        firstDay=6;

    }
    else if(firstDay==1 || firstDay==2 || firstDay==3 || firstDay==4 || firstDay==5 || firstDay==6)
    {
        firstDay=firstDay-1;

    }
    printf("\n%d\n",firstDay);

    return firstDay;
}

//The program for clock starts from here.

void clock_1()
{
    int hrs,min,sec,h,m,s,r;
    currentTime(&hrs,&min,&sec);
    alarm(hrs,min,sec);


}
void currentTime(int *hour,int *min,int *second)
{

    int ans;
    time_t rawtime;
    struct tm * timeinfo;
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
    int i,j;
    printf("Enter the alarm time:(in 24-hour format)\n");
    printf("Hours: ");
    scanf("%d",&almHr);
    printf("Minutes: ");
    scanf("%d",&almMin);

    while(1)
    {

        time ( &rawtime );
        timeinfo = localtime ( &rawtime );
        *hour=timeinfo->tm_hour;
        *min=timeinfo->tm_min;
        *second=timeinfo->tm_sec;

        if(*hour==almHr && *min==almMin)
        {
            Beep(523,8000);
            break;
        }

        else
        {
            Sleep((60-*second)*1000);
        }

        //Check the equality
        //if equal
        //ring and break

        //if not equal
        //Sleep((60-second)*1000);multiplie by 1000 because sleep accepts in milliseconds
        //continue;


    }
    /*printf("\n\n\nPress 'M' to go to the menu bar:\n");
    scanf("%c",&ans);
    if(ans=='m' || ans=='M')
    {
       return 1;
    }*/
}

void special_event()
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

    for(i=0;i<tot;i++)
    {
        for(j=0;j<128;j++)
        {
            day=(((line[i][0])-'0')*10)+((line[i][1])-'0');
            month=(((line[i][3])-'0')*10)+((line[i][4])-'0');


            if(day==curDay&&month==curMonth)
            {
                printf("%s\n",line[i]);
                break;
            }

        }

    }


}

int user_event()
{
    int userDay,userMonth,day,month;
    system("cls");
    system("color 0B");
    printf("Do you want to know the important dates?\n");
    printf("Enter the month:(1-January.......12-December): ");
    scanf("%d",&userMonth);
    printf("Enter the date:");
    scanf("%d",&userDay);
    int LSIZ=128;
    int RSIZ=100;
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

    for(i=0;i<tot;i++)
    {
        for(j=0;j<128;j++)
        {
            day=(((line[i][0])-'0')*10)+((line[i][1])-'0');
            month=(((line[i][3])-'0')*10)+((line[i][4])-'0');


            if(day==userDay&&month==userMonth)
            {
                printf("%s\n",line[i]);
                break;
            }

        }

    }
    return 1;
}
















