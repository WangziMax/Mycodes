/* 运算符 "&" "*" */
int x = 1, y = 2, z[10];
int *ip;			// 声明：ip是指向int类型的指针

ip = &x;			// ip现在指向x
y = *ip;			// y的值现在是1
*ip = 0;			// x的值现在是0
ip = &z[0];			// ip现在指向z[0]

/////////////////////////////////////////////////////////////////////////////////////////
/* 函数参数的改变，swap函数 */
void swap(int *px, int *py)
{
	int temp;
	temp = *px;
	*px = *py;
	*py = temp;
}

/////////////////////////////////////////////////////////////////////////////////////////
int n, array[SIZE], getint(int *);

for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++)
	;
/////////////////////////////////////////////////////////////////////////////////////////
#include <ctype.h>

int getch(void);
void ungetch(int);

/* getint函数：将输入中的下一个整型数赋值给 *pn */
int getin(int *pn)
{
	int c, sign;

	while (isspace(c = getch()))				/* 跳过空白符 */
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-')
	{
		ungetch(c);				/* 输入不是一个数字 */ 
		return 0;
	}
	sign = (c == '-') ? -1: 1;
	if (c == '+' || c == '-')
		c = getch();
	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
	*pn *= sign;
	if (c != EOF)
		ungetch(c);
	return c;
}


