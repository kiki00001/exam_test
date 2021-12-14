#include <unistd.h>
#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		i++;
	}
	return(i);
}

char	*ft_charappend(char *line, char buff)
{
	int		i;
	char	*ret;

	i = 0;
	if (!(ret = malloc(ft_strlen(line) + 2)))
		return (0);
	while (line[i] != 0)
	{
		ret[i] = line[i];
		i++;
	}
	ret[i] = buff;
	i++;
	ret[i] = 0;
	free(line);
	return (ret);
}

int		get_next_line(char **line)
{
	int		rb;
	char	buff;

	if (!(*line = malloc(1)))
		return (-1);
	(*line)[0] = 0;
	while ((rb = read(0, &buff, 1)) > 0)
	{
		if (buff == '\n')
			return (1);
		*line = ft_charappend(*line, buff);
		if (*line == 0)
			return (-1);
	}
	if (rb == -1)
		return (-1);
	else
		return (0);
}