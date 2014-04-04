#include <stdio.h>

/* 回显程序命令行参数；版本1 */
main (int argc, char *argv[])	// argc用于参数记数， argv是一个指向指针数组的指针
{
	int i;

	for (i = 1; i < argc; i++)
		printf("%s%s", argv[i], (i < argc-1) ? " " : "");
	printf("\n");
	return 0;
} 


/* 回显程序命令行参数；版本2 */
main(int argc, char *argv[])
{
	while (--argc > 0)
		printf("%s%s", *++argv, (argc > 1) ? " " : "");
	printf("\n");
	return 0;
}
