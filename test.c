#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	printf("%i\n", printf("%.40s", "la loi c'est moi\n"));
	printf("%d\n", printf("%12s\n", NULL));
	return (1);
}
