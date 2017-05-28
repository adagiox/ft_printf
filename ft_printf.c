#include <stdio.h>

int main()
{
	char *str = "Test string.";
	int i = -10;
	int j = 10;

	printf("%s\n", str);
	printf("%+i\n",i);
	printf("% i\n",j);
	return 0;
}
