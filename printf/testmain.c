#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int		main()
{
//	printf("\n------d--------\n");


	int res1 = ft_printf("|%-16.*p|\n", -1, 0);
	int res2 = printf("|%-16.*p|\n", -1, 0);
	int res1 = ft_printf("|%-16.*p|\n", 0, 0);
	int res2 = printf("|%-16.*p|\n", 0, 0);
	

//	int res1 = ft_printf("|%-4.x|\n", 4294967161);
//	int res2 = printf("|%-4.x|\n", 4294967161);
//	int res1 = ft_printf("|%-16.d|\n", 0);
//	int res2 = printf("|%-16.d|\n", 0);

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
