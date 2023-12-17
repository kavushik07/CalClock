#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<windows.h>
#include<time.h>
#include<stdbool.h>
#include<conio.h>

int inputValdCal();
int calInputs(char);
void cal(int,int,int);
int zellersAlg(int,int);
int clock_1();
void currentTime();
int special_event();
int user_event();

int main()
{
    system("cls");
    system("Color E4");
    char choice;
    char ans;
    int a,b,x,y;
    //to get back to the menu bar after each output.
    while(1)
    {
        printf("\n\n\nEnter your choice:\n");
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
            b=clock_1();
        }
        else if(choice=='s' || choice=='S')
        {
            x=user_event();
        }
        else if(choice=='T' || choice=='t')
        {
            y=special_event();
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
    int ans;
    char ch;
    system("Color B0");
    printf("\t\t\tCalendar:\n\n\n ");
    printf("Enter a year :");
    scanf("%d",&year);
    int tmpYr=year;
    printf("Enter a month:\n 1-January\n 2-February\n 2-March\n 4-April\n 5-May\n 6-June\n 7-July\n 8-August\n 9-September\n 10-October\n 11-November\n 12-December\n Your choice of month:");
    scanf("%d",&month);
    a=inputValdCal(month,year);
    if(a==1)
    {
        firstDay=zellersAlg(month,year);
        //printf("\n%d\n",firstDay);
        cal(month,year,firstDay);
    }
    int temp_month;
    temp_month=month;
    while(1)
    {
            char c = getch();

            //c==72(down),c==80(up)

            if(c==75)//Left arrow key
            {
                if(month==1)
                {
                    month=12;
                    year=year-1;
                    cal(month,year,firstDay);
                    continue;
                }
                else
                {
                    month=month-1;
                    cal(month,year,firstDay);
                    continue;
                }
            }
            if(c==77)//Right arrow key
            {
               if(month==12)
               {
                    year=year+1;
                    month=1;
                    cal(month,year,firstDay);
                    continue;
               }
             else
                {
                    month=month+1;
                    cal(month,year,firstDay);
                    continue;
                }
            }
            if(c=='e'|| c=='E')
            {
                char ans;
                system("cls");
                system("color FD");
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
            continue;
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
void cal(int mon,int yr,int fD)
{
    int i,j;
    char ans,ch;
    char monName[12][15]={"January","February","March","April","May","June","July","August","September","October","November","December"};
    int monthDays[]={31,28,31,30,31,30,31,31,30,31,30,31};
    //  Leap year condition.
    if(yr%4==0&&yr%100==0||yr%400==0)
    {
        monthDays[1]=29;
    }
    system("cls");
    system("Color 57");
    printf("-------------------------%d--------------------------------",yr);
    printf("\n\n\n---------------------%s--------------------------------\n",monName[mon-1]);
    printf("Sun\tMon\tTue\tWed\tThurs\tFri\tSat\n");
    printf("-------------------------------------------------------------\n");
    system ("Color 06");
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
        printf("\n\n\n\t\t Press: -> Right arrow key for the next month:");
        printf("\n\t\t Press: <- Left arrow key for the previous month:");
        printf("\n\t\t Press E to exit:");
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























