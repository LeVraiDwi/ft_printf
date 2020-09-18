#include <stdio.h>
#include <stdarg.h>
#include "printf.h"

int	main()
{
	printf("%*s, %***i, %*i\n", 12, "la", 1,2,3,4,5 );
}
