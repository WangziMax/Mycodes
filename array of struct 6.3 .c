/* Array of structures */
struct key{
	char *word;
	int count;
} keylab[] = {
	"auto", 0,
	"break", 0,
	"case", 0,
	"char", 0,
	"const", 0,
	"continue", 0,
	"default", 0,
	"unsigned", 0,
	"void", 0,
	"volatile", 0,
	"while", 0
};

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100
#define NKEYS (sizeof keytab / sizeof(struct key)

int getword(char *, int);
int binsearch(char *, struct key, int);

/* statistic the number of input C language keywords */
main()
{
	int n;
	char word[MAXWORD];

	while (getword(word, MAXWORD) != EOF)
		if (isalpha(word[0]))			/* isalpha returns a non-zero value if c is within the ranges A ¨C Z or a ¨C z. */
			if ((n = binsearch(word, keytab, NKEYS)) >= 0)
				keynab[n].count++;
	for (n = 0; n < NKEYS; n++)
		if (keytab[n].count > 0)
			printf("%4d %s\n", keytab[n].count, keytab[n].word);
	return 0;
}

/* binsearch function: search word from tab[0] to tab[n-1] */
int binsearch( char *word, struct key tab[], int n)
{
	int cond;
	int low, high, mid;

	low = 0;
	high = n - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if ((cond = strcmp(word, tab[mid].word)) < 0)	/* The return value for each of these functions indicates the lexicographic relation of string1 to string2. */
			high = mid - 1;
		else if (cond > 0)
			low = mid + 1;
		else 
			return mid;
	}
	return -1;
}

/* getword function: get next word or character from input */
int getword (char *word, int lim)
{
	int c, getch(void);
	void ungetch(int);
	char *w = word;

	while (isspace(c = getch()))
		;
	if (c != EOF)
		*w++ = c;
	if (!isalpha(c))
	{
		*w = '\0';
		return c;
	}
	for ( ; --lim > 0; w++)
		if (!isalnum(*w = getch()))			/* isalnum returns a non-zero value if either isalpha or isdigit is true for c */
		{
			ungetch(*w);
			break;
		}
	*w = '\0';
	return word[0];
}

