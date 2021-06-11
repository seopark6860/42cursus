#include "ft_printf.h"
#include <stdio.h>

int		main()
{
//	printf("\n------d--------\n");
//	int res1 = ft_printf("|%d|\n", 214);	
//	int res2 = printf("|%d|\n", 214);

//	printf("\n------s--------\n");
//	int res1 = ft_printf("| %.*s |\n", -3, "abcd");	
//	int res2 = printf("| %.*s |\n", -3, "abcd");

	printf("\n------c--------\n");
	int res1 = ft_printf("-->|%-4.c|<--\n", 'y');
	int res2 = printf("-->|%-4.c|<--\n", 'y');

    printf("ft_printf return : %d\n", res1);
	printf("printf return : %d\n", res2);
}
