
#include "printf.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(void)
{
	char *a;
	int *ui;
	int i = -51235;
	ui = (int *)malloc(12);
	a = (char *)malloc(1);
	ft_printf("\n\n");
	ft_printf("\n\n");
	ft_printf("fsgresh\n");
printf("libc :%0015d\n", 15);
printf("libc :%d %D %i %u, %x\n", (unsigned int)-1, -2147483647, i, i, 5);
ft_printf("lib%C :%d %D %i %u %x\n", 0x1F984, (unsigned int)-1, -2147483647, i, i, 5);
printf("libc : gdf1g%%%%%%gg%c%s  %p %d %c %S %D\n", 'a',  "jhgfd", a, 1, L'A', L"ASD", 0);
ft_printf("lib%C : gdf1g%  l2%%%%%gg%   c%s  %p %d %  C %S %D %C %C\n", 0x1F984, 'a',  "jhgfd", a, 1, L'A', L"ASD", 0, 0x1F93C, 0x1F983);
	ft_printf("fsgresh\n");
//printf("%d %ud\n", 'c', L'c' - 'c' - 1);
//return(printf("gdf1g%%gg%c%d%s %d %p i%Si %s\n", 'a', 'a', "jhgfd", (int)a, a, ui, "54"));
	ft_printf("\n\n");
}
