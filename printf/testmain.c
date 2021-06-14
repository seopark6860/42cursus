#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int		main()
{
//	printf("\n------d--------\n");

	int *p;
	p = NULL;
	int res1 = ft_printf(" %-4.d ", -135);	
	int res2 = printf(" %-4.d ", -135);
//	int res1 = ft_printf("|%010d|\n", 2134);
//	int res2 = printf("|%010d|\n", 2134);
//	int res3 = ft_printf("|0*%0*.10d|\n",  21, -2147483648);
//	int res4 = printf("|0*%0*.10d\n", 21, -2147483648);

//	printf("\n------s--------\n");
//	int res1 = ft_printf("|%s|\n", 0);	
//	int res2 = printf("|%s|\n", 0);

//	printf("\n------c--------\n");pw
//	int res1 = ft_printf("-->|%10c|<--\n", '0');
//	int res2 = printf("-->|%10c|<--\n", '0');
//	int res1 = ft_printf("-->|%.*s|<--\n",2,"abc");
//	int res2 = printf("-->|%.*s|<--\n", 2,"abd");

   	printf("ft_printf return : %d\n", res1);
	printf("printf return : %d\n", res2);
}
