#include "ft_printf.h"

int	main(void)
{
	int i;
	char *str = 0;
	char c = 0;

	i = ft_printf("Qwerty%cQwerty\n", 'f');
	ft_printf("%i\n", i);
	printf("%i\n", i);
	printf("printf:\n");
	i = printf("Qwerty%cQwerty\n", 'f');
	ft_printf("%i\n", i);
	printf("%i\n", i);
	printf("\n");
	//---------------------------------------------
	i = ft_printf("%c\n", c);
	ft_printf("%i\n", i);
	printf("%i\n", i);
	printf("printf:\n");
	i = printf("%c\n", c);
	ft_printf("%i\n", i);
	printf("%i\n", i);
	printf("\n");
	//---------------------------------------------
	i = ft_printf("%X\n", 459);
	ft_printf("%i\n", i);
	printf("%i\n", i);
	printf("printf:\n");
	i = printf("%X\n", 459);
	ft_printf("%i\n", i);
	printf("%i\n", i);
	printf("\n");
	//---------------------------------------------
	i = ft_printf("%i\n", 459);
	ft_printf("%i\n", i);
	printf("%i\n", i);
	printf("printf:\n");
	i = printf("%i\n", 459);
	ft_printf("%i\n", i);
	printf("%i\n", i);
	printf("\n");
	//---------------------------------------------
	i = ft_printf("%s\n", "string");
	ft_printf("%i\n", i);
	printf("%i\n", i);
	printf("printf:\n");
	i = printf("%s\n", "string");
	ft_printf("%i\n", i);
	printf("%i\n", i);
	printf("\n");
	//---------------------------------------------
	i = ft_printf("%s\n", str);
	ft_printf("%i\n", i);
	printf("%i\n", i);
	printf("printf:\n");
	i = printf("%s\n", str);
	ft_printf("%i\n", i);
	printf("%i\n", i);
	printf("\n");
	//---------------------------------------------
	i = ft_printf("%p\n", (void *)0);
	ft_printf("%i\n", i);
	printf("%i\n", i);
	printf("printf:\n");
	i = printf("%p\n", (void *)0);
	ft_printf("%i\n", i);
	printf("%i\n", i);
	printf("\n");
	//---------------------------------------------
	i = ft_printf("%p\n", (void *)-3567);
	ft_printf("%i\n", i);
	printf("%i\n", i);
	printf("printf:\n");
	i = printf("%p\n", (void *)-3567);
	ft_printf("%i\n", i);
	printf("%i\n", i);
	printf("\n");
	//---------------------------------------------
	i = ft_printf("%i\n", 03567);
	ft_printf("%i\n", i);
	printf("%i\n", i);
	printf("printf:\n");
	i = printf("%i\n", 03567);
	ft_printf("%i\n", i);
	printf("%i\n", i);
	printf("\n");
	//---------------------------------------------
	i = ft_printf("%i\n", 0x3567);
	ft_printf("%i\n", i);
	printf("%i\n", i);
	printf("printf:\n");
	i = printf("%i\n", 0x3567);
	ft_printf("%i\n", i);
	printf("%i\n", i);
	printf("\n");
	return (0);
}