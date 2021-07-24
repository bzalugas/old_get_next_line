#include <fcntl.h>
#include <sys/errno.h>
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	char	*name;
	int		fd;
	char	*line;
	int		result;
	int		nb;

	if (argc == 1)
		fd = 0;
	else
	{
		name = argv[1];
		fd = open(name, O_RDONLY);
		if (fd < 0)
			return (-1);
//		printf("contenu de %s : \n\n", name);
	}
	nb = 1;
	while ((result = get_next_line(fd, &line)) > 0)
	{
		printf("%s\n", line);
        free(line);
        line = NULL;
	}
	if (line && *line)
		free(line);
	close(fd);
}
