#include <stdio.h>
#include <string.h>

static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* day_of_year函数：将某月某日的日期表示形式转换为某年中第几天的表示形式 */
int day_of_year(int year, int month, int day)
{
	int leap;
	char *p;

	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	p = daytab[leap];				/* 指针指向leap数组的第一位 */
	while (--month)
		day += *++p;
	return day;
}

/* month_day 函数：将某年中第几天的日期表示形式转换成某月某日的表示形式 */
void month_day( int year, int yearday, int *pmonth, int *pday)
{
	int leap;
	char *p;

	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	p = daytab[leap];
	while(yearday > *++p)
		yearday -= *p;
	*pmonth = p - *(daytab + leap);
	*pday = yearday;
}



main ()
{
	int year = 2014;
	int yearday = 68;
	int n[3] = {1, 2, 3};
	int month=0; 
	int day=0;
	int *p = &month;
	int *pd = &day;


	month_day(year, yearday, p, pd);
	printf("%d month and %d date", *p, *pd);
	return;

	//int year = 2014;
	//int month = 3;
	//int day = 31;
	//int a = 0;

	//a = day_of_year(year,  month,  day);
	//return a;

}