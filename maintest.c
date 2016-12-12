
#include "printf.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(void)
{
	char *a;
	int *ui;
//	int i = 51235;
	ui = (int *)malloc(12);
	a = (char *)malloc(1);
	ft_printf("\n\n");
	ft_printf("\n\n");
	ft_printf("fsgresh\n");
printf("libc : gdf1g%%gg%c%s  %p %d %C %S\n", 'a',  "jhgfd", a, 1, L'A', L"ASD");
ft_printf("lib%C : gdf1g%%gg%c%s  %p %d %C %S\n", 0x1F984, 'a',  "jhgfd", a, 1, L'A', L"ASD");
//printf("%d %ud\n", 'c', L'c' - 'c' - 1);
//return(printf("gdf1g%%gg%c%d%s %d %p i%Si %s\n", 'a', 'a', "jhgfd", (int)a, a, ui, "54"));
	ft_printf("\n\n");
}
