/* strcat: concatenate t to the end of s; pointer version */
void strcat(char *s, char *t)
{
	while (*s)
		s++;
	while (*s++ = *t++)
		;
}


void strend(char *s, char *t)
{
	while (*s)
		s++;
	while (*s++ == *t++)
}

/* strend: return 1 if string t occurs at the end of s */
int strend(char *s, char *t)
{
	char *bs = s;				/* remember beginning of strs */
	char *bt = t;

	for ( ; *s; s++)			/* end of the string s */
		;
	for ( ; *t; t++)			/* end of the string t */
		;
	for ( ; *s == *t; s--, t--)
		if (t == bt || s == bs)
			break;				/* at the beginning of a str */
	if ( *s == *t && t == bt && *s != '/0')
		return 1;
	else 
		return 0;
}

/* strncpy: copy n characters from t to s */
void strncpy(char *s, char *t, int n)
{
	while (*t && n-- > 0)
		*s++ = *t++;
	while (n-- > 0)
		*s++ = '\0';
}

/* strncat: concatenate n character of t to the end of s */
void strncat ( char *s, char *t, int n)
{
	void strncpy(char *s, char *t, int n);
	int strlen(char *);

	strncpy(s + strlen(s), t, n);
}

