#include "get_next_line.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
    int i = 50;
	int fd = open(argv[1], O_RDONLY);
	char *res;
    while (i--)
	{
		res = get_next_line(fd);
	    printf("%s", res);
		if (res)
			free (res);
	}
	return (0);
}
