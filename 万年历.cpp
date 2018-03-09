
#include<stdio.h>
#include<iostream.h>
struct time
{unsigned int hour;
	unsigned int minitue;
	unsigned int second;
};
typedef time Time;
struct date
{unsigned int year;
	unsigned int month;
	unsigned int day;
	Time Curtime;
};
typedef date Date;
void main()
{int yearloop,monthloop,dayloop;
	int hourloop,minitueloop,secondloop;
	int Month[]={31,0,31,30,31,30,31,31,30,31,30,31};
	int i;
	Date Curdate;

	for(yearloop=1999;yearloop<=9999;yearloop++)
	{
		for(monthloop=1;monthloop<=12;monthloop++)
		{
			if(Curdate.year%4==0&&Curdate.year%100!=0||Curdate.year%400==0)Month[1]=29;
			else Month[1]=28;
			for(dayloop=1;dayloop<=Month[monthloop-1];dayloop++)
			{
				for(hourloop=0;hourloop<24;hourloop++)
				{
					for(minitueloop=0;minitueloop<60;minitueloop++)
					{
						for(secondloop=0;secondloop<60;secondloop++)
						{
							Curdate.Curtime.second=secondloop;
							Curdate.Curtime.minitue=minitueloop;
							Curdate.Curtime.hour=hourloop;
							Curdate.day=dayloop;
							Curdate.month=monthloop;
							Curdate.year=yearloop;

							for(i=1;i<400000000;i++);
							cout<<Curdate.year<<"年"
								<<Curdate.month<<"月"
								<<Curdate.day<<"日"
								<<Curdate.Curtime.hour<<"时"
								<<Curdate.Curtime.minitue<<"分"
								<<Curdate.Curtime.second<<"秒"<<flush
								<<"\r";
						}

					}

				}

			}

		}

	}
}
