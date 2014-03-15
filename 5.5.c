/* strcpy函数：将指针t指向的字符串负值到指针s指向的位置；使用数组下标实现的版本 */
void strcpy(char *s, char *t)
{
	int i;

	i = 0;
	while ((s[i] = t[i]) != '\0')

		i++;
}

/* 使用指针方式实现的版本 */
void strcpy(char *s, char *t)
{
	while ((*s = *t) != '\0')
	{
		s++;
		t++;
	}
}

/* 使用指针方式实现的版本2 */
void strcpy(char *s, char *t)
{
	while ((*s++ = *t++) != '\0')
		;
}

/* 使用指针方式实现的版本3 */
void strcpy(char *s, char *t)
{
	while (*s++ = *t++)
		;
}

/* strcmp函数：根据s按照字典顺序小于、等于、大于t的结果分别返回负整数、0或正整数 */
int strcmp(char *s, char *t)
{
	int i;

	for (i = 0; s[i] == t[i]; i++)
		if (s[i] == '\0')
			return 0;
	return s[i] - t[i];
}

/* 版本2 */
int strcmp(char *s, char *t)
{
	for ( ; *s == *t; s++, t++)
		if (*s == '\0')
			return 0;
	return *s - *t;
}