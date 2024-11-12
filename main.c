#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int count  =  4;

	char *tab;
	char *p;

	tab = malloc(count + 1);
	if (!tab)
		return 0;
	p = tab + count;
	memset(p-2, 'g', 1);

	printf("%c\n", tab[2]);

	printf("%p\n", tab);
	printf("%p\n", p);

}
